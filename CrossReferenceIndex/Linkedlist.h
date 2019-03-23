//
//  Linkedlist.h
//  knight problem csci362
//
//  Created by Tonouewa King kefil on 1/30/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#ifndef Linkedlist_h
#define Linkedlist_h
#include <fstream>


struct LineNumbers
{
    int LineNum;
    LineNumbers * next;
};

class linkedList
{
private:
    LineNumbers *head, *tail;
public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    
    LineNumbers createnode(int);
    void addToLinkedList(int);
    void display(FILE*);
    int getFirst();
    void deleteall();
    bool isEmpty();
    
};

#endif /* Linkedlist_h */
