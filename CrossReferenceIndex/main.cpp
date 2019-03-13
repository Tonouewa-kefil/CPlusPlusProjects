//
//  main.cpp
//  wordTree
//
//  Created by Tonouewa King kefil on 3/6/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <clocale>
#include <cctype>
#include "BinarySearchTree.h"
#include "Linkedlist.h"
using namespace std;

BinarySearchTree WordTree;

int main()
{
    
    ifstream ifile;
    ifile.open("input.txt");
    int nline=0;//this will hold the line number of each word.
    
    //Checking if the file opens or not
    while(ifile.is_open()==false)
    {
        return 1;
    }
    
    //The file succesfully opened
    while(ifile.is_open()==true)
    {
        int NumberOfLines=1;//This will hold the line index
        node LineOfText;//This sturucture will hold a whole line
        while(getline(ifile,LineOfText.word,'\n'))//Getting line from the file
        {
            LineOfText.lineNumber=NumberOfLines;
            node Words;//structure that will hold the word and the line numbers
            istringstream stream1;
            nline=LineOfText.lineNumber;
            
            if (LineOfText.word!="#")//Checking if the present line is the last line of the file ("#")
            {
                stream1.str(LineOfText.word);//Transforming the string into a stream so that we can get information from it
            }
            
            while(getline(stream1,Words.word,' '))//Getting words from the lines
            {
                for(int j=0;j<Words.word.size();++j)
                {
                    if ( isdigit(Words.word[0]))//checking if the first charater of the word is not a number
                    {
                        Words.word.clear();//clear the wordif the first character is a digit
                    }
                    
                    Words.lineNumber=nline;
                    
                    if(Words.word[j]==','||Words.word[j]=='.')//take out "." and ","
                    {
                        Words.word.erase(j,1);
                    }
                    
                    if (Words.word.size()>10)//If the word has more that 10 charater keep 10 and earase the rest
                    {
                        Words.word=Words.word.erase(10,Words.word.size()-10);
                    }
                    
                }
                WordTree.insert(Words);//Insert the word inside the tree
            }
            
            NumberOfLines++;
        }
        
        WordTree.DisplayTree();//Display the binary tree
        ifile.close();// close the file.
    }
    return 0;
}
