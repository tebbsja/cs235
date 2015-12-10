//
//  AVL.cpp
//  Lab6
//
//  Created by Austin Tebbs on 11/11/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "AVL.h"
#include <cmath>
#include <sstream>


AVL::AVL()
{
    root = NULL;
    num_items = 0;
}

int AVL::getNHeight(Node* n)
{
    if (n == NULL)
    {
        return -1;
    }
    return n->getHeight();
}

int AVL::updateHeight(Node* n)
{
    if (n->left != NULL)
    {
        updateHeight(n->left);
    }
    if (n->right != NULL)
    {
        updateHeight(n->right);
    }
    n->height = max(getNHeight(n->left),getNHeight(n->right)) +1;
    return n->getHeight();
}

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
bool AVL::isBalanced(Node*& local_root)
{
    return false;
}
NodeInterface* AVL::getRootNode()
{
    return root;
}
void AVL::balance(Node*& n)
{
    if ((getNHeight(n->left)) - (getNHeight(n->right)) > 1)
    {
        balanceRight(n);
    }
    else if ((getNHeight(n->right)) - (getNHeight(n->left)) > 1)
    {
        balanceLeft(n);
    }
}

void AVL::balanceLeft(Node*& n)
{
    Node* RL = n->right->left;
    Node* RR = n->right->right;
    
    if (getNHeight(RL) > getNHeight(RR))
    {
        rotateRight(n->right);
    }
    rotateLeft(n);
}
void AVL::balanceRight(Node*& n)
{
    Node* LL = n->left->left;
    Node* LR = n->left->right;
    
    if (getNHeight(LL) < getNHeight(LR))
    {
        rotateLeft(n->left);
    }
    rotateRight(n);
}

void AVL::rotateLeft(Node*& n)
{
    Node* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n = temp;
}

void AVL::rotateRight(Node*& n)
{
    Node* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n = temp;
}

/*
 * Attempts to add the given int to the AVL tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */

bool AVL::add(Node*& local_root, int data)
{
    if (local_root == NULL) // if tree is empty set the root to the data
    {
        local_root = new Node(data);
        updateHeight(root);
        balance(local_root);
        num_items++;
        return true;
    }
    else if ( data < local_root->data) // if data is less than root
    {
        bool added = AVL::add(local_root->left, data);
        updateHeight(root);// add to left recursively
        balance(local_root);
        return added;
    }
    else if ( data > local_root->data) // if data is greather than root
    {
        bool added = AVL::add(local_root->right, data);
        updateHeight(root);// add to left recursively
        balance(local_root);
        return added; // add right recursively
    }
    else // anything else is false
    {
        return false;
    }
    return true;
}

bool AVL::add(int data)
{
    if (AVL::add(root, data))
    {
        //check if balanced;
        //root->updateHeight();
        //cout << "Height: " << root->getHeight() << " \n\n\n\n\n\n";
        return true;
    }
    return false;
}


/*
 * Attempts to remove the given int from the AVL tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
int AVL::maxValue(Node* n)
{
    if (!n->right)
    {
        return n->data;
    }
    else
    {
        return maxValue(n->right);
    }
}
bool AVL::remove(int data)
{
    return AVL::remove(root, data);
}

bool AVL::replace(Node*& n, int old, int updated)
{
    if (n)
    {
        if (n->getData() < old) {
            return replace(n->right, old, updated);
        }
        else if (n->getData() > old) {
            return replace(n->left, old, updated);
        }
        else {
            n->data = updated;
            return true;
        }
    }
    return false;
}

bool AVL::replace(int old, int updated)
{
    return replace(root, old, updated);
}

bool AVL::remove(Node*& local_root, int data)
{
    if (local_root == NULL)
    {
        return false;
    }
    else
    {
        if (data < local_root->data) // if node to remove is less than
        {
            bool removed = remove(local_root->left, data);
            updateHeight(root);
            balance(local_root);
            return removed;
        }
        else if ( data > local_root->data) //if node to remove is greater than
        {
            bool removed = remove(local_root->right, data);
            updateHeight(root);
            balance(local_root);
            return removed;
        }
        else // found node
        {
            Node* to_delete = local_root;
            if ((!local_root->left) && (!local_root->right))
            {
                local_root = NULL;
                delete to_delete;
            }
            else if (local_root->left == NULL)
            {
                local_root = local_root->right;
                delete to_delete;
            }
            else if (local_root->right == NULL)
            {
                local_root = local_root->left;
                delete to_delete;
            }
            else
            {
                int temp = maxValue(local_root->left);
                remove(temp);
                replace(data, temp);
                updateHeight(root);
                balance(local_root);
            }
            return true;
        }
    }
    return false;
}

/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
void AVL::clear()
{
    while (root != NULL)
    {
        remove(root->data);
    }
}

void AVL::print() {
    int levels = AVL::getLevels(root);
    int BOX_LEN = 3;
    int OVER_BOX = 0;
    
    for (int row=0; row<levels; row++) {
        
        
        int spaces_per_side = AVL::getSpaces(levels - row);
        int dashes_per_side = spaces_per_side - AVL::getBlanks( levels - row);
        
        
        int cols_in_row = pow(2, row);
        for (int col=0; col<cols_in_row; col++) {
            cout << string(spaces_per_side - (dashes_per_side + OVER_BOX), ' ') << string(dashes_per_side + OVER_BOX, '-');
            int index = (row + col) + (cols_in_row - row) - 1;
            
            string data = AVL::getNodeData(index);
            cout << AVL::makeBox(data);
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

int AVL::getBlanks(int level) {
    if (level == 1) {
        return 0;
    } else if (level == 2) {
        return 2;
    } else if (level == 3) {
        return 6;
    } else {
        return 2 * AVL::getBlanks(level - 1);
    }
}

int AVL::getSpaces(int level) {
    if (level == 1) {
        return 0;
    } else if (level == 2) {
        return 4;
    } else {
        return (AVL::getBlanks(level) * 2) - 2;
    }
}

int AVL::getLevels(Node* n) {
    if (n == NULL) {
        return 0;
    } else if (n->left == NULL && n->right == NULL) {
        return 1;
    } else if (n->left != NULL && n->right == NULL) {
        return AVL::getLevels(n->left) + 1;
    } else if (n->left == NULL && n->right != NULL) {
        return AVL::getLevels(n->right) + 1;
    } else {
        int left_count = AVL::getLevels(n->left);
        int right_count = AVL::getLevels(n->right);
        int count = (left_count > right_count) ? left_count : right_count;
        return count + 1;
    }
}

string AVL::makeBox(string s) {
    if (s.length() == 1) {
        return "*" + s + "*";
    } else if (s.length() == 2) {
        return "*" + s;
    } else {
        return s;
    }
}


string AVL::getNodeData(int index) {
    string data;
    if (AVL::getNodeData(root, data, 0, 0, index)) {
        return data;
    }
    return " ";
}

bool AVL::getNodeData(Node* n, string& data, int row, int col, int desired_index) {
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
    
    
    if (AVL::getNodeData(n->left, data, row+1, (col*2), desired_index)) {
        if (debug) cout << endl << "LEFT" << endl;
        return true;
    } else if (AVL::getNodeData(n->right, data, row+1, ((col*2)+1), desired_index)) {
        if (debug) cout << endl << "RIGHT" << endl;
        return true;
    }
    
    
    return false;
}