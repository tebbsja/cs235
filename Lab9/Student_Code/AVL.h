//
//  AVL.h
//  Lab9
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

#include "AVLInterface.h"
#include "Node.h"
#include <stdio.h>
#include <iostream>

class AVL : public AVLInterface
{
private:
    
    Node* root;
    int num_items;
    bool add(Node*& local_root, int data);
    
    int getBlanks(int level);
    int getSpaces(int level);
    int getLevels(Node* n);
    string makeBox(string s);
    string getNodeData(int index);
    bool getNodeData(Node* n, string& data, int row, int col, int desired_index);
    
    bool remove(Node*& local_root, int data);
    int height = 0;
    
public:
    AVL();
    ~AVL(){ clear(); }

    virtual NodeInterface * getRootNode();
    virtual bool add(int data);
    virtual bool remove(int data);
    
    void clear();
    
    void print();
    
    bool replace(Node*& n, int old, int updated);
    bool replace(int old, int updated);
    
    bool isBalanced(Node*& local_root);
    int updateHeight(Node* n);
    int getNHeight(Node* n);
    
    void balance(Node*& n);
    void balanceRight(Node*& n);
    void balanceLeft(Node*& n);
    void rotateRight(Node*& n);
    void rotateLeft(Node*& n);
    
    int maxValue(Node* n);
};
#endif /* AVL_h */