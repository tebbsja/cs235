//
//  Node.h
//  Lab6
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "NodeInterface.h"

#include <stdio.h>

class Node : public NodeInterface
{
public:
    int data;
    Node* left;
    Node* right;
    
    Node(const int& data_item, Node* left_ptr = NULL, Node* right_ptr = NULL) :
    data(data_item), left(left_ptr), right(right_ptr) {}
    
    ~Node(){}
    
    /*
     * Returns the data that is stored in this node
     *
     * @return the data that is stored in this node.
     */
    virtual int getData();
    
    /*
     * Returns the left child of this node or null if it doesn't have one.
     *
     * @return the left child of this node or null if it doesn't have one.
     */
    virtual NodeInterface* getLeftChild();
    
    /*
     * Returns the right child of this node or null if it doesn't have one.
     *
     * @return the right child of this node or null if it doesn't have one.
     */
    virtual NodeInterface* getRightChild();
};

#endif /* Node_h */
