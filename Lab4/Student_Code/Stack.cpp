//
//  Stack.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Stack.h"

bool Stack::exists(int car)
{
    if (my_stack.isDuplicate(car))
    {
        return true;
    }
    return false;
}

bool Stack::push(int car)
{
    my_stack.insertHead(car);
    return true;
    
}

bool Stack::empty()
{
    if (my_stack.size() == 0)
    {
        return true;
    }
    return false;
}

int Stack::top()
{
    return my_stack.at(0);
}

int Stack::size()
{
    return my_stack.size();
}

bool Stack::pop()
{
    if (empty())
    {
        return false;
    }
    else
    {
        my_stack.remove(top());
    }
    return false;
}