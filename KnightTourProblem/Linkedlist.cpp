//
//  Linkedlist.cpp
//  knight problem csci362
//
//  Created by Tonouewa King kefil on 1/30/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#include <stdio.h>
#include "Linkedlist.h"
#include <iostream>
using namespace std;

void linkedList:: createnode(int x, int y)
    {
        knightLocation_start *temp=new knightLocation_start;
        temp->i=x;
        temp->j=y;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

void linkedList:: display(int j)
    {
        
        knightLocation_start *temp=new knightLocation_start;
        temp=head;
        while(temp!=NULL)
        {
           
            cout<<"Knight "<<j<<" is located at: "<<"("<<temp->i<<","<<temp->j<<")"<<endl;
            
            temp=temp->next;
            j++;
        }
       
    }

void linkedList:: delete_first()
    {
        knightLocation_start *temp=new knightLocation_start;
        temp=head;
        head=head->next;
        delete temp;
    }
void linkedList::delete_position(int pos)
{
    knightLocation_start *current=new knightLocation_start;
    knightLocation_start *previous=new knightLocation_start;
    current= head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    delete current;
    
}

bool linkedList:: isEmpty()
    {
        if((head)==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

knightLocation linkedList::getfirst()
    {
        knightLocation firstElement;
        knightLocation_start *temp=new knightLocation_start;
        temp=head;
        firstElement.xa=temp->i;
        firstElement.ya=temp->j;
        return firstElement;
    }



int linkedList::getSize()
{
    int count=0;
    knightLocation_start* current = head;
    while(current != NULL)
    {
        count++;
        current=current->next;
        
    }
    return count;
    
}

