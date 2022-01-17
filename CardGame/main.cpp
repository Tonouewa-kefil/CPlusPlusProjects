//
//  main.cpp
//  CardGame
//
//  Created by Tonouewa King kefil on 5/29/20.
//  Copyright © 2020 Tonouewa Kefil. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stack>
#include <time.h>
using namespace std;

#define DECK_SIZE 28
#define MAX_PLAYER 5
#define CARDS_PER_PLAYER 5

/*
 **Create a deck of card
 ***Heart {7,8,9,10,J,Q,K}
 ***Spade {7,8,9,10,J,Q,K}
 ***Clubs {7,8,9,10,J,Q,K}
 ***Diamonds {7,8,9,10,J,Q,K}
*/

string Deck_of_Cards[DECK_SIZE] = {"H7","H8","H9","H10","HJ","HQ","HK","S7","S8","S9","S10","SJ","SQ","SK","C7","C8","C9","C10","CJ","CQ","CK","D7","D8","D9","D10","DJ","DQ","DK"};

stack<string> Shuffle();//Function that will shuffle the cards using Fisher-Yates Shuffle Algorithm
void swap (string*,string*); // Used to swap two cards in the Deck of card while it is being sufffled
void Deal_Cards(stack<string>,string**);//This will be used to deal the cards to each player.
int number_of_player;//This is the number of player playing (MIN = 2, MAX = 5)



int main(int argc, const char * argv[])
{
    srand(unsigned (time(NULL)));//This ensures that we don't get duplicate while generating random numbers
    
    //*******************Section Used To Get the Number Of Players***************
    number_of_player = 0;
    cout<<"Enter the number of player (2-5): ";
    cin>>number_of_player;
    cout<<endl;
    
    while (number_of_player <2 || number_of_player >5)
    {
        cout<<"THE MAXIMUM IS 5 AND THE MINIMUM IS 2"<<endl;
        cout<<"Enter the number of player (2-5): ";
        cin>>number_of_player;
        cout<<endl;
    }
    
    //*******************Section Used To Shuffle Cards And Deal******************
    //string** Partition;
    string Player_Partition [number_of_player][CARDS_PER_PLAYER];
    /*Partition = (string**)malloc(CARDS_PER_PLAYER * sizeof(string*));
    
    for (int i = 0; i < CARDS_PER_PLAYER; i++) {
        Partition[i] = (string*)malloc(number_of_player * sizeof(Partition[0]));
    }
    */
    stack<string> Shuffled_Deck = Shuffle();//Deck_of_Cards);//Shuffling the deck of Cards
    //Create a function that will Distribute 5 cards to each particitants (5 MAX)
    Deal_Cards(Shuffled_Deck,(string**)Player_Partition);
    
    //*******************Showing Each Player Partion*****************************
    
    for (int i =0; i<number_of_player; i++) {
        for (int j = 0; j<CARDS_PER_PLAYER; j++)
        {
            printf("%3s",Player_Partition[i][j].c_str());
            cout<<Player_Partition[i][j]<<" ";
        }
        cout<<endl;
    }
  

    
    return 0;
}

//Here Fisher-Yates Shuffle Algorithm is used to shuffle the Card (ARRAY)
stack<string> Shuffle()
{
    stack<string> Shuffled_Deck;
    int j = 0;
    int i = 0;
    
     for (i=0 ; i<DECK_SIZE ; i++)
    {
        j = rand()%(DECK_SIZE-i);//Generate random number between 0 and and 28-i+1
        swap(Deck_of_Cards[j],Deck_of_Cards[DECK_SIZE-(i+1)]);
    }
    
    
    for (i=0 ; i<DECK_SIZE ; i++)
    {
        Shuffled_Deck.push(Deck_of_Cards[i]);
    }
   
    return Shuffled_Deck;
}

void swap(string*a, string*b)
{
        string temp = *a;
        *a = *b;
        *b = temp;
}

void Deal_Cards(stack<string> Shuffled_Deck , string** Partition)
{
    //Each player first get 3 cards and then 2 cards.
    for(int i = 0; i<2; i++)
    {
        for (int j = 0; j<number_of_player; j++)
        {
            if (i == 0 )
            {
                Partition[j][0] = Shuffled_Deck.top();
                Shuffled_Deck.pop();
                Partition[j][1] = Shuffled_Deck.top();
                Shuffled_Deck.pop();
                Partition[j][2] = Shuffled_Deck.top();
                Shuffled_Deck.pop();
            }
            if (i == 1 )
            {
                Partition[j][3] = Shuffled_Deck.top();
                Shuffled_Deck.pop();
                Partition[j][4] = Shuffled_Deck.top();
                Shuffled_Deck.pop();
                
            }
        }
    }
    
    
}
