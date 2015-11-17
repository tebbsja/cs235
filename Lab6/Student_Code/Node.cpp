//
//  Node.cpp
//  Lab6
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Node.h"

/*
 * Returns the data that is stored in this node
 *
 * @return the data that is stored in this node.
 */
int Node::getData()
{
    return data;
}

/*
 * Returns the left child of this node or null if it doesn't have one.
 *
 * @return the left child of this node or null if it doesn't have one.
 */
NodeInterface* Node::getLeftChild()
{
    return left;
}

/*
 * Returns the right child of this node or null if it doesn't have one.
 *
 * @return the right child of this node or null if it doesn't have one.
 */
NodeInterface* Node::getRightChild()
{
    return right;
}