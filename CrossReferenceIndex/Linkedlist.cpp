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
#include <fstream>
using namespace std;



  void linkedList:: addToLinkedList(int x)
{
    LineNumbers *temp=new LineNumbers;
    temp->LineNum=x;
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


void linkedList:: display(FILE * OUT)
    {
        
        LineNumbers *temp=new LineNumbers;
        temp=head;
        while(temp!=NULL)
        {
            fprintf(OUT,"\t%2d",temp->LineNum);
            temp=temp->next;
        }
       
    }

int linkedList:: getFirst()
{
        LineNumbers firstElement;
        LineNumbers *temp=new LineNumbers;
        temp=head;
      return firstElement.LineNum=temp->LineNum;
}

void linkedList:: deleteall()
{
    LineNumbers *temp=new LineNumbers;
    temp=head;
    head=head->next;
    delete temp;
    
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
