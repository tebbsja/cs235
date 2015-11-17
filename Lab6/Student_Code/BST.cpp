//
//  BST.cpp
//  Lab6
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "BST.h"
#include <cmath>
#include <sstream>


BST::BST()
{
    root = NULL;
    num_items = 0;
}


/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */

NodeInterface* BST::getRootNode()
{
    return root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */

bool BST::add(Node*& local_root, int data)
{
    if (local_root == NULL) // if tree is empty set the root to the data
    {
        local_root = new Node(data);
        num_items++;
        return true;
    }
    else if ( data < local_root->data) // if data is less than root
    {
        return BST::add(local_root->left, data); // add to left recursively
    }
    else if ( data > local_root->data) // if data is greather than root
    {
        return BST::add(local_root->right, data); // add right recursively
    }
    else // anything else is false
    {
        return false;
    }
    return true;
}

bool BST::add(int data)
{
    return BST::add(root, data);
}


/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */

bool BST::remove(int data)
{
    return BST::remove(root, data);
}

void BST::replace(Node*& old_root, Node*& local_root)
{
    if (local_root->right != NULL)
    {
        replace(old_root, local_root->right);
    }
    else
    {
        old_root->data = local_root->data;
        old_root = local_root;
        local_root = local_root->left;
    }
}

bool BST::remove(Node*& local_root, int data)
{
    if (local_root == NULL)
    {
        return false;
    }
    else
    {
        if (data < local_root->data) // if node to remove is less than
        {
            return remove(local_root->left, data);
        }
        else if ( data > local_root->data) //if node to remove is greater than
        {
            return remove(local_root->right, data);
        }
        else // found node
        {
            Node* old_root = local_root;
            if (local_root->left == NULL)
            {
                local_root = local_root->right;
            }
            else if (local_root->right == NULL)
            {
                local_root = local_root->left;
            }
            else
            {
                replace(old_root, old_root->left);
            }
            delete old_root;
            return true;
        }
    }
    return false;
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void BST::clear()
{
    while (root != NULL)
    {
        remove(root->data);
    }
}

void BST::print() {
    int levels = BST::getLevels(root);
    int BOX_LEN = 3;
    int OVER_BOX = 0;
    
    for (int row=0; row<levels; row++) {

        
        int spaces_per_side = BST::getSpaces(levels - row);
        int dashes_per_side = spaces_per_side - BST::getBlanks( levels - row);
        

        int cols_in_row = pow(2, row);
        for (int col=0; col<cols_in_row; col++) {
            cout << string(spaces_per_side - (dashes_per_side + OVER_BOX), ' ') << string(dashes_per_side + OVER_BOX, '-');
            int index = (row + col) + (cols_in_row - row) - 1;
            
            string data = BST::getNodeData(index);
            cout << BST::makeBox(data);
            cout << string(dashes_per_side + OVER_BOX, '-') << string(spaces_per_side - (dashes_per_side + OVER_BOX), ' ');
            
            if (spaces_per_side == 0 && (col % 2) == 0) {
                cout << string(1 + BOX_LEN + 1, ' ');
            } else {
                cout << " ";
            }
            
        }
        
        cout << endl;
    }
    cout << endl << endl;

}

int BST::getBlanks(int level) {
    if (level == 1) {
        return 0;
    } else if (level == 2) {
        return 2;
    } else if (level == 3) {
        return 6;
    } else {
        return 2 * BST::getBlanks(level - 1);
    }
}

int BST::getSpaces(int level) {
    if (level == 1) {
        return 0;
    } else if (level == 2) {
        return 4;
    } else {
        return (BST::getBlanks(level) * 2) - 2;
    }
}

int BST::getLevels(Node* n) {
    if (n == NULL) {
        return 0;
    } else if (n->left == NULL && n->right == NULL) {
        return 1;
    } else if (n->left != NULL && n->right == NULL) {
        return BST::getLevels(n->left) + 1;
    } else if (n->left == NULL && n->right != NULL) {
        return BST::getLevels(n->right) + 1;
    } else {
        int left_count = BST::getLevels(n->left);
        int right_count = BST::getLevels(n->right);
        int count = (left_count > right_count) ? left_count : right_count;
        return count + 1;
    }
}

string BST::makeBox(string s) {
    if (s.length() == 1) {
        return "*" + s + "*";
    } else if (s.length() == 2) {
        return "*" + s;
    } else {
        return s;
    }
}


string BST::getNodeData(int index) {
    string data;
    if (BST::getNodeData(root, data, 0, 0, index)) {
        return data;
    }
    return " ";
}

bool BST::getNodeData(Node* n, string& data, int row, int col, int desired_index) {
    int cols_in_row = pow(2, row);
    int current_index = (row + col) + (cols_in_row - row) - 1;
    
    string none = " x ";
    
    bool debug = !true;
    
    if (debug) cout << endl << "ROW: " << row << "  COL: " << col << "  CUR: " << current_index << "  DES: " << desired_index;
    
    if (current_index == desired_index) {

        if (debug) cout << " HERE!" << endl;
        
        if (n) {
            stringstream ss;
            ss << n->data;
            data = ss.str();
        } else {
            data = none;
        }
        return true;
    } else if (current_index > (desired_index)) {

        if (debug) cout << " TOO BIG";
        data = none;

        return false;
    } else if (!n) {
        if (debug) cout << " ITS NULL";
        data = none;
        return false;
    }
    

    if (BST::getNodeData(n->left, data, row+1, (col*2), desired_index)) {
        if (debug) cout << endl << "LEFT" << endl;
        return true;
    } else if (BST::getNodeData(n->right, data, row+1, ((col*2)+1), desired_index)) {
        if (debug) cout << endl << "RIGHT" << endl;
        return true;
    }
    

    return false;
}
