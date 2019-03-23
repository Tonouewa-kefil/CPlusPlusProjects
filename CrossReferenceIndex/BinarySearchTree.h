//
//  BinarySearchTree.h
//  CrossReferenceIndex
//
//  Created by Tonouewa King kefil on 2/28/19.
//  Copyright © 2019 Tonouewa King kefil. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include "Linkedlist.h"
#include <string>
#include <fstream>
using namespace std;

struct node
{
    string word;
    int lineNumber;
};

struct wordNode //This holds the information regarding the location of the knight at any location
{
    string word;
    linkedList LineIndex;
    wordNode * leftNode;
    wordNode * rightNode;
    
};

//knightLocation firstElement;
class BinarySearchTree
{
private:
    
    wordNode *root;
    wordNode* addTotree(wordNode*,node);
    
public:
    void DisplayTree(FILE*);
    BinarySearchTree()
    {
         root=NULL;
        
    }
    void insert(node);
    void DisplayNode(wordNode*,FILE*);
    
    
  
    
    
};

#endif /* BinarySearchTree_h */
