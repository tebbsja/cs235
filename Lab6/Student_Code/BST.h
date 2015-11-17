//
//  BST.h
//  Lab6
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include "BSTInterface.h"
#include "Node.h"
#include <stdio.h>

class BST : public BSTInterface
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
    
public:
    BST();
    ~BST(){}
    /*
     * Returns the root node for this tree
     *
     * @return the root node for this tree.
     */
    virtual NodeInterface * getRootNode();
    
    /*
     * Attempts to add the given int to the BST tree
     *
     * @return true if added
     * @return false if unsuccessful (i.e. the int is already in tree)
     */
    virtual bool add(int data);
    
    /*
     * Attempts to remove the given int from the BST tree
     *
     * @return true if successfully removed
     * @return false if remove is unsuccessful(i.e. the int is not in the tree)
     */
    virtual bool remove(int data);
    
    /*
     * Removes all nodes from the tree, resulting in an empty tree.
     */
    virtual void clear();
    
    void print();
    void replace(Node*& old_root, Node*& local_root);
};
#endif /* BST_h */
