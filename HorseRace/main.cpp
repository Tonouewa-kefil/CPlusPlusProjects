//
//  main.cpp
//  horseRace
//
//  Created by Tonouewa King kefil on 3/23/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//
#include <iostream>
#include <time.h>
#include <string>
#define NumberOfHorse 5
#define NumberOfTurn 15
using namespace std;

void Populate_Track(char [NumberOfHorse][NumberOfTurn]);//This will be used to fill the track with horse number and turns.
void Display_Track (char [NumberOfHorse][NumberOfTurn]);//This will be used to display the tarck anytime we need to.
void swap(char*, char*);//This will be used to interchange the horse number with the '.' when the horse moves.
bool keepGoing();//This will decide if the horce moves or not based on the ramdom value generated.

int main()
{
     srand(unsigned (time (NULL)));// This will allow us to have a different random variable from the last one
    char Horse_Track[NumberOfHorse][NumberOfTurn];//2d charater array to hold the horse and track
    int HorsePosition[5]={0,0,0,0,0};//Array holding information about each horse position
    
    //Before the race start we position the hosrse in the track
    Populate_Track(Horse_Track);
    
    //The beginning of the race
    while(!isdigit(Horse_Track[0][14])&& !isdigit(Horse_Track[1][14])&& !isdigit(Horse_Track[2][14])&& !isdigit(Horse_Track[3][14])&&!isdigit(Horse_Track[4][14]))//While none of the horses has reach the finish line keep doing the following
    {
            for (int i=0; i<NumberOfHorse; i++)
            {
                if (keepGoing()&& HorsePosition[i]<(NumberOfTurn-1))
                {
                    swap(&Horse_Track[i][HorsePosition[i]], &Horse_Track[i][HorsePosition[i]+1]);
                    HorsePosition[i]=HorsePosition[i]+1;//Updating the horse position when it moves
                }
                else
                {
                    HorsePosition[i]=HorsePosition[i];//The horse stay stationnary when the random number is not even
                }
            }
            
            Display_Track(Horse_Track);
        cout<<"Press Enter for another turn:";
            cin.get();//Waiting for the user to press enter to display the next turn.
    }
    
    //end of the race
    for (int pos=0; pos< sizeof(HorsePosition); pos++)
    {
        if (HorsePosition[pos]==14)
        {
            cout<<"Horse "<<pos+1 <<" is the winner!"<<endl;
        }
    }
    return 0;
}

void Populate_Track (char track[NumberOfHorse][NumberOfTurn])
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<15; j++)
        {
            if (j==0)
            {
                if(i==0)
                {
                    track[i][j]='1';//Horse 1
                }
                else if(i==1)
                {
                    track[i][j]='2';//Horse 2
                }
                else if(i==2)
                {
                    track[i][j]='3';//Horse 3
                }
                else if(i==3)
                {
                    track[i][j]='4';//Horse 4
                }
                else if(i==4)
                {
                    track[i][j]='5';//Horse 5
                }
            }
            else
            {
                track[i][j]='.';//Turns
            }
            
        }
    }
}
void Display_Track (char track [NumberOfHorse][NumberOfTurn])
{
    for (int i=0;i<5; i++)
    {
        for (int j=0; j<15;j++)
        {
            cout<<track[i][j];
        }
        cout<<endl;
    }
}
void swap(char*a, char*b)
{
    int Position;
    Position = *a;
    *a=*b;
    *b=Position;
};
bool keepGoing()
{
    bool decision;//Move or Stay
    int coint;
    coint = rand()%10;//Generating random number betewen 0 and 9
    
    if (coint%2)//if the number is even the horse moves
    {
        decision=true;
    }
    else// The horse stays at the same position
        decision=false;
    
    return decision;
}
