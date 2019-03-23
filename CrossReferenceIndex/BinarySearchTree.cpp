//
//  BinarySearchTree.cpp
//  CrossReferenceIndex
//
//  Created by Tonouewa King kefil on 2/28/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//
#include <iostream>
#include <stdio.h>
//#include <fstream>
#include "BinarySearchTree.h"
#include "Linkedlist.h"

#include <string>

using namespace std;

//Here if the root is null we will make our current element the root
//if the element that needs to be inserted is greater than the root it will go right
//if the element that need to be inserted is less that the root it will go left
//if the element that need to be inserted is equal to one of the element in the tree, we wil add its data to the list of line number


void BinarySearchTree:: insert(node word)
{
    addTotree(root,word);
}

wordNode* BinarySearchTree::addTotree( wordNode *topNode,node word)
{
    wordNode *wordL = new wordNode;
    wordL->word=word.word;
    wordL->LineIndex.addToLinkedList(word.lineNumber);
    wordL->leftNode=NULL;
    wordL->rightNode=NULL;
    if (topNode==NULL)
    {
        topNode=wordL;
    }
    else if(word.word!="" && topNode->word>word.word)//word less than root's word
    {
        topNode->leftNode=addTotree(topNode->leftNode, word);
    
    }
    else if(word.word!="" && topNode->word<word.word) //word greather than root's word
    {
        topNode->rightNode=addTotree(topNode->rightNode, word);
    }
    else if(word.word==topNode->word) //word equal to root's word
    {
        topNode->LineIndex.addToLinkedList(word.lineNumber);
    }
    root=topNode;
    return root;
}

void BinarySearchTree:: DisplayTree(FILE* out)
{

    DisplayNode(root,out);
    
}

void BinarySearchTree:: DisplayNode(wordNode * TNode,FILE* outfile)
{
    if(TNode!=NULL)
    {
        DisplayNode(TNode->leftNode,outfile);
        fprintf(outfile,"%10s",TNode->word.c_str());
        TNode->LineIndex.display(outfile);
        fprintf(outfile, "\n");
        DisplayNode(TNode->rightNode,outfile);
    }
    
}








