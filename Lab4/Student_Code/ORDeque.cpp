//
//  ORDeque.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/20/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "ORDeque.h"



bool ORDeque::exists(int car)
{
    if (my_ordeque.isDuplicate(car))
    {
        return true;
    }
    return false;
}

bool ORDeque::pushLeft(int car)
{
    my_ordeque.insertHead(car);
    return true;
    
}

bool ORDeque::pushRight(int car)
{
    my_ordeque.insertTail(car);
    return true;
}

bool ORDeque::empty()
{
    if (my_ordeque.size() == 0)
    {
        return true;
    }
    return false;
}

int ORDeque::right()
{
    int last;
    last = my_ordeque.size() - 1;
    return my_ordeque.at(last);
}

int ORDeque::left()
{
    return my_ordeque.at(0);
}

int ORDeque::size()
{
    return my_ordeque.size();
}

bool ORDeque::popRight()
{
    if (empty())
    {
        return false;
    }
    else
    {
        int last;
        last = my_ordeque.size() - 1;
        
        int remove;
        remove = my_ordeque.at(last);
        
        my_ordeque.remove(remove);
    }
    return false;
}

bool ORDeque::popLeft()
{
    if (empty())
    {
        return false;
    }
    else
    {
        my_ordeque.remove(left());
    }
    return true;
}