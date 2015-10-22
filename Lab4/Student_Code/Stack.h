//
//  Stack.hpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "LinkedList.h"
#include <stdio.h>

class Stack
{
private:
    LinkedList <int> my_stack;
    
public:
    bool exists(int car);
    bool push(int car);
    Stack(){};
    int top();
    bool empty();
    bool pop();
    int size();
    
};
#endif /* Stack_h */
