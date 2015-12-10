//
//  Node.cpp
//  Lab 9
//
//  Created by Austin Tebbs on 12/9/15.
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
/*
 * Returns the height of this node. The height is the number of nodes
 * along the longest path from this node to a leaf.  While a conventional
 * interface only gives information on the functionality of a class and does
 * not comment on how a class should be implemented, this function has been
 * provided to point you in the right direction for your solution.  For an
 * example on height, see page 448 of the text book.
 *
 * @return the height of this tree with this node as the local root.
 */
int Node::getHeight()
{
    return height;
}

void Node::updateHeight()
{
    int left_height = 0, right_height = 0;
    
    if (left == NULL)
    {
        left_height = -1;
    }
    else
    {
        left_height = left->height;
    }
    
    if (right == NULL)
    {
        right_height = -1;
    }
    else
    {
        right_height = right->height;
    }
    
    height = max(left_height, right_height) + 1;
}

int Node::getBalance()
{
    int left_height = 0, right_height = 0, bal = 0;
    
    if (left == NULL)
    {
        left_height = -1;
    }
    else
    {
        left_height = left->height;
    }
    
    if (right == NULL)
    {
        right_height = -1;
    }
    else
    {
        right_height = right->height;
    }
    
    bal = right_height - left_height;
    
    return bal;
}