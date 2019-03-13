//
//  Linkedlist.h
//  knight problem csci362
//
//  Created by Tonouewa King kefil on 1/30/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#ifndef Linkedlist_h
#define Linkedlist_h


struct knightLocation
{
    int xa;
    int ya;
};
//knightLocation firstElement;
struct knightLocation_start //This holds the information regarding the location of the knight at any location
{
    int i; //----->Location on x axis
    int j; //------>Location on y axis
    knightLocation_start * next;
};
//knightLocation firstElement;
class linkedList
{
private:
    knightLocation_start *head, *tail;
public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    
    void createnode(int, int);
    void display(int);
    void delete_position(int);
    void delete_first();
    bool isEmpty();
    int getSize();
    knightLocation getfirst();
    
};

#endif /* Linkedlist_h */
