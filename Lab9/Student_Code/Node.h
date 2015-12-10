//
//  Node.h
//  Lab 9
//
//  Created by Austin Tebbs on 12/9/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "NodeInterface.h"

class Node : public NodeInterface
{

public:
    int data;
    Node* left;
    Node* right;
    int height;
    int balance;
    
    Node(const int& data_item, Node* left_ptr = NULL, Node* right_ptr = NULL) :
    data(data_item), left(left_ptr), right(right_ptr) { height = 0; balance = 0;}

    
    ~Node(){}
    
    virtual int getData();
    virtual NodeInterface* getLeftChild();
    virtual NodeInterface* getRightChild();
    virtual int getHeight();
    
    void updateHeight();
    int getBalance();
};

#endif /* Node_h */
