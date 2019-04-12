//
//  main.cpp
//  You can go your own Way
//
//  Created by Tonouewa King kefil on 4/5/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
#include <ctime>
using namespace std;


struct Location
{
    int i_x;
    int i_y;
};
Location locationGenerator(Location,int**);
int main()
{
    srand(unsigned(time(NULL)));
    int i_N = 0;
    string s_prevPath;
    cout<<"Enter the already taken Path: ";
    cin>>s_prevPath;
    cout<<"Enter N: ";
    cin>>i_N;
    int **Maze;
    Maze= new int *[i_N];
    for (int i = 0; i < i_N; ++i) {
        Maze[i] = new int[i_N];
       
    }
    
    for(int y=0;y<i_N;y++)
    {
        for (int x=0; x<i_N; x++)
        {
            Maze[x][y]=0;
        }
    }
    int i_PrevX=0;
    int i_PrevY=0;
    for (int i=0; i<s_prevPath.size();i++)
    {
       
        if (s_prevPath[i]=='S') {
            i_PrevY++;
            Maze[i_PrevX][i_PrevY]=1;
        }
        else if(s_prevPath[i]=='E')
        {
            i_PrevX++;
            Maze[i_PrevX][i_PrevY]=1;
        }
    }
    Location lastVist;
    lastVist.i_x=0;
    lastVist.i_y=0;
    while (lastVist.i_x!=i_N-1 && lastVist.i_y!=i_N-1  )
    {
        lastVist = locationGenerator(lastVist, Maze);
        Maze[lastVist.i_x][lastVist.i_y]=8;
    
        
    }
    
    for(int y=0;y<i_N;y++)
    {
        for (int x=0; x<i_N; x++)
        {
            cout<<Maze[x][y]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
Location locationGenerator(Location presentLocation,int **Matrix)
{
    string loc;
    int k;
    k=rand()%2;
    Location nextLocations[2];
    Location nextLocation;
    
    nextLocations[0].i_x=presentLocation.i_x+1;
    nextLocations[0].i_y=presentLocation.i_y;
    
    nextLocations[1].i_x=presentLocation.i_x;
    nextLocations[1].i_y=presentLocation.i_y+1;
    
    for (int i =0; i<2; i++) {
        if (nextLocations[i].i_x<5 && nextLocations[i].i_y<5 && Matrix[nextLocations[i].i_x][nextLocations[i].i_y]!=1)
        {
            nextLocation.i_x=nextLocations[i].i_x;
            nextLocation.i_y=nextLocations[i].i_y;
        }
    }
    
    nextLocation=nextLocations[k];
    return nextLocation;
}

