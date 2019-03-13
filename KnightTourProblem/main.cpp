// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  main.cpp
//  knight problem csci362
//  Created by Tonouewa King kefil on 1/26/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.

#include <iostream>
#include <cstdio>
#include <stack>
#include <list>
#include <string>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <vector>
#include "Linkedlist.h"

using namespace std;

//Global Variables
int n;//This holds the number of possible next moves. we are using this for the heristic algorithm.
int k;//This will hold the number of the knight
string response;
knightLocation nextSquare;//This will hold the next spot the knight is movint to.
int chessBoard[8][8];//This will be used to display our chessBoard
knightLocation nextLocation[8];//This array holds all the possible next location that the knight can go to from the present location
knightLocation nextnextLocation[8];//This array hold all the possible next location that the knight can go to from the next location that the present location generated.
stack<knightLocation> visitedLocation;//This is the stack that will hold the oder in which the knight visits the chessBoard
stack<knightLocation>nextl;//This satck will contain possible next moves.
stack< stack<knightLocation> >nextstack;//This satck will contain a stack of stack of next possible moves generated by each visited square
int knightnumber;//This will hold the number of knight that the user input
linkedList initialPositions;//This will hold all the initial position entered by the user.
knightLocation firstLocation;//This will hold the first location from the list of first location entered by the user on the list.
std::vector<int*> Solutions=std::vector<int*>();//This will be used to store the solutions.
int number;

//Function Prototypes
knightLocation  next_location_Generator(knightLocation presentLocation);//This function will generate the next location that the knight goes to based on the next location generated by the present location
stack<knightLocation>  next_location_Generator_for_backtracking(knightLocation presentLocation);//This will return a stack of next locations for the backtraking method.
int  number_of_next_location_Generator(knightLocation presentLocation);//This function will return the number of next location that the next location can go to.
void addingtoLinkedlist();//This function will take user input and add it to the linkedList.
void populateBoard();//This function will be used to initialize all the squares of the chess board to -1
void DisplayBoard();//This function will be used to display the chess board at the end of the game to the output file
void DisplayBoard_terminal();//This function will be used to disaplay the chess board at the end of the game to the terminal
linkedList User_Interation();//This will be used to interact with the user.

//***********************************************************************************************************************************************
int main()
{
    k=1;
    number=1;
    knightnumber=0;
    addingtoLinkedlist();
    k=1;
    initialPositions.display(k);
    User_Interation();
   
    while (!initialPositions.isEmpty())
    {
        
        stack<knightLocation>upcoming;
        populateBoard();//This will put -1 everywhere on the chessBoard
        firstLocation= initialPositions.getfirst();//this will get the first location entered by the user
        visitedLocation.push(firstLocation);//Pushing the user input to the stack(visitedLocation)
        chessBoard[firstLocation.xa][firstLocation.ya]=1;//setting the first square to 1
        next_location_Generator(firstLocation);//generating the next location from the user input
        visitedLocation.push(nextSquare);//pushing the next location to the stack.
        chessBoard[nextSquare.xa][nextSquare.ya]=2;//setting the second square visited to 2
        
        //This while loop takes care of the of Warnsdoff Algorithm. Since we are using it for the first 32 moves, what we are doing is countt the number of elements in our visited location stack and comparing it to 32. if it is 32, we will turn off the heristic method and  start with another method of our choice.
        while (visitedLocation.size()!=32)
        {
            next_location_Generator(visitedLocation.top());//we will use the next location generator function to find next location from our current location
            visitedLocation.push(nextSquare);//we are pushing the generated location to the stack of visited location
            chessBoard[nextSquare.xa][nextSquare.ya]=(int)visitedLocation.size();//we are assigning the location to the corresponding move
        }
        
        //This is where we are applying our own algorithm of finding the next moves and also applying backtracking if we ever get stuck at a specific location.
        while (visitedLocation.size()!=64)
        {
            next_location_Generator_for_backtracking(visitedLocation.top());//we are putting the top element of the the stack of visited location into the function that will generate a stack of next moves.
            //This is where we will start applying the bactracking algorithm
            while (nextl.empty())//Whenever the generated stack of next possible moves is empty, it means we are stuck and need to start backtracking
            {
              
               chessBoard[visitedLocation.top().xa][visitedLocation.top().ya]=-1;//we will put a -1 on the chess board at the location we are at at the moment
                visitedLocation.pop();//we will pop the location we where at out of the stack of the satck and our present location will become the one before the current
                upcoming=nextstack.top();//upcoming stack will hold the stack that was generated from the previous move ommiting the location we got stuck at.
                
                while (upcoming.empty())//Whenever upcoming is empty
                {
                    
                    chessBoard[visitedLocation.top().xa][visitedLocation.top().ya]=-1;//we will put a -1 on the chess board at the location we are at at the moment
                    visitedLocation.pop();//we will pop the location we where at out of the stack of the satck and our present location will become the one before the current
                    nextstack.pop();//delete the top of the stack of stack to get the next satck
                    upcoming=nextstack.top();//upcoming stack will hold the stack that was generated from the previous move ommiting the location we got stuck at.
                    
                    
                }
                //in the other hand, if upcoming stack is not empty
                    visitedLocation.push(upcoming.top());//we will push the top element of the upcoming stack into the stack of visted location
                    chessBoard[upcoming.top().xa][upcoming.top().ya]=(int)visitedLocation.size();//we are assigning the location to the corresponding move
                    next_location_Generator_for_backtracking(upcoming.top());//we will pass the top element of the  upcoming stack in
                    nextstack.pop();
                    upcoming.pop();
                    nextstack.push(upcoming);
              }
            
            nextSquare= nextl.top();//The knight next location's will be the top element of the stack of next position that we have obtained
            visitedLocation.push(nextSquare);//We will push that next location onto the stack of visited location.
            nextl.pop();//We will pop the first element that we'have used
            nextstack.push(nextl);//And push the remaining stack into the satck of satck of next location
            chessBoard[nextSquare.xa][nextSquare.ya]=(int)visitedLocation.size();//we are assigning the location to the corresponding move
           
            
        }
    
        //Here we are emtying the satck of visited loction so that we can reuse it in case the user has more that one knight
        while (!visitedLocation.empty())
        {
            visitedLocation.pop();//popint element out of the stack
        }
        
        //Here we are emtying the satck of next stack loction so that we can reuse it in case the user has more that one knight
        while (!nextstack.empty())
        {
            nextstack.pop();//poping element out of the stack
        }
        
        knightnumber++;//incrementing the number of knight for a nice display for the next user input
        //DisplayBoard_terminal();
        Solutions.push_back(*chessBoard);
        cout<<endl;
        DisplayBoard();//Displaying the final solution
        initialPositions.delete_first();//deleting the user first input from the linked list since it has been taken care of.
        number++;
    }
    
    return 0;
}

//***********************************************************************************************************************************************
void addingtoLinkedlist()
{
    int row;
    int col;
    cout << "Enter the initial position of knight number "<<k<<endl;
    cout <<"Row number: ";
    cin>>row;
    while (cin.fail()||row<0||row>7)
    {
        cout<<"Invalid entry!! Enter a number between (0 and 7)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout <<"Row number: ";
        cin>>row;
    }
    cout<<"Column number: ";
    cin>>col;
    while (cin.fail()||col<0||col>7)
    {
        cout<<"Invalid entry!! Enter a number between (0 and 7)"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Column number: ";
        cin>>col;
        
    }
    initialPositions.createnode(row, col);
    
    cout << "would you like to enter more intial location(y/n)?";
    cin>>response;
    cout<<endl;
    while (response=="y")
    {
        k++;
        addingtoLinkedlist();
    }
}
//***********************************************************************************************************************************************
linkedList User_Interation()
{
    int ans;
    cout<<endl;
    cout<<"Enter 1 to add an element to this list"<<endl;
    cout<<"Enter 2 to delete an element from this list"<<endl;
    cout<<"Enter 3 to continue"<<endl;
    
    cin>>ans;
    while (cin.fail())
    {
        cout<<"Invalid input!!!";
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Enter 1 to add an element to this list"<<endl;
        cout<<"Enter 2 to delete an element from this list"<<endl;
        cout<<"Enter 3 to continue"<<endl;
        cin>>ans;
    }
    while(ans == 1)
    {
        addingtoLinkedlist();
        k=1;
        initialPositions.display(k);
        return initialPositions;
        
    }
    while(ans == 2)
    {
        int position;
        cout<<"Enter the position you would like to delete from"<<endl;
        cin>>position;
        initialPositions.delete_position(position);
        k=1;
        initialPositions.display(k);
        return initialPositions;
    }
    while (ans == 3)
    {
        return initialPositions;
        
    }
    
    return initialPositions;
}



//***********************************************************************************************************************************************
void populateBoard()
{
    for (int y=0; y<8; y++)
    {
        for (int x=0; x<8; x++)
        {
            chessBoard[x][y]=-1;
        }
    }
}
//***********************************************************************************************************************************************
void DisplayBoard()
{
    cout<<"Your solution for knight "<<number<< " is in the file named output.txt"<<endl;
    FILE* outfile;
    outfile = fopen("output.txt","w");
    fprintf(outfile, "For the knight %d located at (%d,%d), the solution is the following: \n",knightnumber,firstLocation.xa,firstLocation.ya);
    for (int y=0; y<8; y++)
    {
        for (int x=0; x<8; x++)
        {
            
            fprintf(outfile, "%2d ",chessBoard[x][y]);
        }
        fprintf(outfile, "\n");
    }
    fprintf(outfile, "\n");
    fclose(outfile);
    

}



//***************************************************************************************************************************************
knightLocation  next_location_Generator( knightLocation presentLocation)
{
    //struct knightLocation nextLocation[8];
    int numberofnextlocation[8];
    //1st possible location (i - 2,j + 1)
    nextLocation[0].xa = presentLocation.xa - 2;
    nextLocation[0].ya = presentLocation.ya+ 1;
    if (nextLocation[0].xa >= 0 && nextLocation[0].ya >= 0 && nextLocation[0].xa <= 7 && nextLocation[0].ya <= 7 && chessBoard[nextLocation[0].xa][nextLocation[0].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[0]);
        numberofnextlocation[0]=n;
    }
    else
        numberofnextlocation[0]=9;
    
    //2nd posssible location (i-1,j +2)
    nextLocation[1].xa = presentLocation.xa - 1;
    nextLocation[1].ya = presentLocation.ya+ 2;
    
    if (nextLocation[1].xa >= 0 && nextLocation[1].ya >= 0 && nextLocation[1].xa <= 7 && nextLocation[1].ya <= 7 && chessBoard[nextLocation[1].xa][nextLocation[1].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[1]);
        numberofnextlocation[1]=n;
    }
    else
        numberofnextlocation[1]=9;
    
    //3rd posssible location (i+1,j +2)
    nextLocation[2].xa = presentLocation.xa + 1;
    nextLocation[2].ya = presentLocation.ya + 2;
    number_of_next_location_Generator(nextLocation[2]);
    if (nextLocation[2].xa >= 0 && nextLocation[2].ya >= 0 && nextLocation[2].xa <= 7 && nextLocation[2].ya <= 7 && chessBoard[nextLocation[2].xa][nextLocation[2].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[2]);
        numberofnextlocation[2]=n;
    }
    else
        numberofnextlocation[2]=9;
    
    //4th posssible location (i+2,j +1)
    nextLocation[3].xa = presentLocation.xa + 2;
    nextLocation[3].ya = presentLocation.ya + 1;
    number_of_next_location_Generator(nextLocation[3]);
    if (nextLocation[3].xa >= 0 && nextLocation[3].ya >= 0 && nextLocation[3].xa <= 7 && nextLocation[3].ya <= 7 && chessBoard[nextLocation[3].xa][nextLocation[3].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[3]);
        numberofnextlocation[3]=n;
    }
    else
        numberofnextlocation[3]=9;
    
    //5th posssible location (i+2,j -1)
    nextLocation[4].xa = presentLocation.xa + 2;
    nextLocation[4].ya = presentLocation.ya - 1;
    number_of_next_location_Generator(nextLocation[4]);
    if (nextLocation[4].xa >= 0 && nextLocation[4].ya >= 0 && nextLocation[4].xa <= 7 && nextLocation[4].ya <= 7 && chessBoard[nextLocation[4].xa][nextLocation[4].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[4]);
        numberofnextlocation[4]=n;
    }
    else
        numberofnextlocation[4]=9;
    
    
    //6th posssible location (i+1,j -2)
    nextLocation[5].xa = presentLocation.xa + 1;
    nextLocation[5].ya = presentLocation.ya- 2;
    number_of_next_location_Generator(nextLocation[5]);
    if (nextLocation[5].xa >= 0 && nextLocation[5].ya >= 0 && nextLocation[5].xa <= 7 && nextLocation[5].ya <= 7 && chessBoard[nextLocation[5].xa][nextLocation[5].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[5]);
        numberofnextlocation[5]=n;
    }
    else
        numberofnextlocation[5]=9;
    
    //7th posssible location (i-1,j -2)
    nextLocation[6].xa = presentLocation.xa- 1;
    nextLocation[6].ya = presentLocation.ya- 2;
    number_of_next_location_Generator(nextLocation[6]);
    if (nextLocation[6].xa >= 0 && nextLocation[6].ya >= 0 && nextLocation[6].xa <= 7 && nextLocation[6].ya <= 7 && chessBoard[nextLocation[6].xa][nextLocation[6].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[6]);
        numberofnextlocation[6]=n;
    }
    else
        numberofnextlocation[6]=9;
    
    //8th posssible location (i-2,j -1)
    nextLocation[7].xa = presentLocation.xa- 2;
    nextLocation[7].ya = presentLocation.ya - 1;
    number_of_next_location_Generator(nextLocation[7]);
    if (nextLocation[7].xa >= 0 && nextLocation[7].ya >= 0 && nextLocation[7].xa <= 7 && nextLocation[7].ya <= 7 && chessBoard[nextLocation[7].xa][nextLocation[7].ya]==-1)
    {
        number_of_next_location_Generator(nextLocation[7]);
        numberofnextlocation[7]=n;
    }
    else
        numberofnextlocation[7]=9;
    
    int smallestIndex = 0;
    
    for (int index = smallestIndex; index < 8; index++)
    {
        if (numberofnextlocation[smallestIndex] > numberofnextlocation[index])
        {       smallestIndex = index;
        }
    }
    
    nextSquare=nextLocation[smallestIndex];
    
    return nextSquare;
}
//***********************************************************************************************************************************************
int  number_of_next_location_Generator(knightLocation presentLocation)
{
    //struct knightLocation nextLocation[8];
    n=0;
    
    //1st possible location (i - 2,j + 1)
    nextnextLocation[0].xa = presentLocation.xa - 2;
    nextnextLocation[0].ya = presentLocation.ya+ 1;
    if (nextnextLocation[0].xa >= 0 && nextnextLocation[0].ya >= 0 && nextnextLocation[0].xa <= 7 && nextnextLocation[0].ya <= 7 && chessBoard[nextnextLocation[0].xa][nextnextLocation[0].ya]==-1)
    {
        n=n+1;
    }
    
    //2nd posssible location (i-1,j +2)
    nextnextLocation[1].xa = presentLocation.xa - 1;
    nextnextLocation[1].ya = presentLocation.ya+ 2;
    if (nextnextLocation[1].xa >= 0 && nextnextLocation[1].ya >= 0 && nextnextLocation[1].xa <= 7 && nextnextLocation[1].ya <= 7 && chessBoard[nextnextLocation[1].xa][nextnextLocation[1].ya]==-1)
    {
        n=n+1;
    }
    
    //3rd posssible location (i+1,j +2)
    nextnextLocation[2].xa = presentLocation.xa + 1;
    nextnextLocation[2].ya = presentLocation.ya + 2;
    if (nextnextLocation[2].xa >= 0 && nextnextLocation[2].ya >= 0 && nextnextLocation[2].xa <= 7 && nextnextLocation[2].ya <= 7 && chessBoard[nextnextLocation[2].xa][nextnextLocation[2].ya]==-1)
    {
        n=n+1;
    }
    
    //4th posssible location (i+2,j +1)
    nextnextLocation[3].xa = presentLocation.xa + 2;
    nextnextLocation[3].ya = presentLocation.ya + 1;
    if (nextnextLocation[3].xa >= 0 && nextnextLocation[3].ya >= 0 && nextnextLocation[3].xa <= 7 && nextnextLocation[3].ya <= 7 && chessBoard[nextnextLocation[3].xa][nextnextLocation[3].ya]==-1)
    {
        n=n+1;
    }
    //5th posssible location (i+2,j -1)
    nextnextLocation[4].xa = presentLocation.xa + 2;
    nextnextLocation[4].ya = presentLocation.ya - 1;
    if (nextnextLocation[4].xa >= 0 && nextnextLocation[4].ya >= 0 && nextnextLocation[4].xa <= 7 && nextnextLocation[4].ya <= 7 && chessBoard[nextnextLocation[4].xa][nextnextLocation[4].ya]==-1)
    {
        n=n+1;
    }
    //6th posssible location (i+1,j -2)
    nextnextLocation[5].xa = presentLocation.xa + 1;
    nextnextLocation[5].ya = presentLocation.ya- 2;
    if (nextnextLocation[5].xa >= 0 && nextnextLocation[5].ya >= 0 && nextnextLocation[5].xa <= 7 && nextnextLocation[5].ya <= 7 && chessBoard[nextnextLocation[5].xa][nextnextLocation[5].ya]==-1)
    {
        n=n+1;
    }
    
    //7th posssible location (i-1,j -2)
    nextnextLocation[6].xa = presentLocation.xa- 1;
    nextnextLocation[6].ya = presentLocation.ya- 2;
    if (nextnextLocation[6].xa >= 0 && nextnextLocation[6].ya >= 0 && nextnextLocation[6].xa <= 7 && nextnextLocation[6].ya <= 7 && chessBoard[nextnextLocation[6].xa][nextnextLocation[6].ya]==-1)
    {
        n=n+1;
    }
    
    //8th posssible location (i-2,j -1)
    nextnextLocation[7].xa = presentLocation.xa- 2;
    nextnextLocation[7].ya = presentLocation.ya - 1;
    if (nextnextLocation[7].xa >= 0 && nextnextLocation[7].ya >= 0 && nextnextLocation[7].xa <= 7 && nextnextLocation[7].ya <= 7 &&chessBoard[nextnextLocation[7].xa][nextnextLocation[7].ya]==-1)
    {
        n=n+1;
    }
    
    return n;
}

//***********************************************************************************************************************************************
stack<knightLocation>  next_location_Generator_for_backtracking(knightLocation presentLocation)
{
    
    n=0;
    knightLocation temporyNextLocation;
    while (!nextl.empty()) {
        nextl.pop();
    }
    //1st possible location (i - 2,j + 1)
    temporyNextLocation.xa = presentLocation.xa - 2;
    temporyNextLocation.ya = presentLocation.ya+ 1;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    //2nd posssible location (i-1,j +2)
    temporyNextLocation.xa = presentLocation.xa - 1;
    temporyNextLocation.ya = presentLocation.ya+ 2;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    //3rd posssible location (i+1,j +2)
    temporyNextLocation.xa = presentLocation.xa + 1;
    temporyNextLocation.ya = presentLocation.ya + 2;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    //4th posssible location (i+2,j +1)
    temporyNextLocation.xa = presentLocation.xa + 2;
    temporyNextLocation.ya = presentLocation.ya + 1;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    //5th posssible location (i+2,j -1)
    temporyNextLocation.xa = presentLocation.xa + 2;
    temporyNextLocation.ya = presentLocation.ya - 1;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    //6th posssible location (i+1,j -2)
    temporyNextLocation.xa = presentLocation.xa + 1;
    temporyNextLocation.ya = presentLocation.ya- 2;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    //7th posssible location (i-1,j -2)
    temporyNextLocation.xa = presentLocation.xa- 1;
    temporyNextLocation.ya = presentLocation.ya- 2;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    //8th posssible location (i-2,j -1)
    temporyNextLocation.xa = presentLocation.xa- 2;
    temporyNextLocation.ya = presentLocation.ya - 1;
    if (temporyNextLocation.xa >= 0 && temporyNextLocation.ya >= 0 && temporyNextLocation.xa <= 7 && temporyNextLocation.ya <= 7 && chessBoard[temporyNextLocation.xa][temporyNextLocation.ya]==-1)
    {
        nextl.push(temporyNextLocation);
    }
    
    return nextl;
}