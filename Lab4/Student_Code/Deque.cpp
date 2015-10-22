//
//  Deque.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Deque.h"

bool Deque::exists(int car)
{
    if (my_deque.isDuplicate(car))
    {
        return true;
    }
    return false;
}

bool Deque::pushLeft(int car)
{
    my_deque.insertHead(car);
    return true;
    
}

bool Deque::pushRight(int car)
{
    my_deque.insertTail(car);
    return true;
}

bool Deque::empty()
{
    if (my_deque.size() == 0)
    {
        return true;
    }
    return false;
}

int Deque::right()
{
    int last;
    last = my_deque.size() - 1;
    return my_deque.at(last);
}

int Deque::left()
{
    return my_deque.at(0);
}

int Deque::size()
{
    return my_deque.size();
}

bool Deque::popRight()
{
    if (empty())
    {
        return false;
    }
    else
    {
        int last;
        last = my_deque.size() - 1;
        
        int remove;
        remove = my_deque.at(last);
        
        my_deque.remove(remove);
    }
    return false;
}

bool Deque::popLeft()
{
    if (empty())
    {
        return false;
    }
    else
    {
        my_deque.remove(left());
    }
    return true;
}