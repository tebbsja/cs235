//
//  IRDeque.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/20/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "IRDeque.h"

bool IRDeque::exists(int car)
{
    if (my_irdeque.isDuplicate(car))
    {
        return true;
    }
    return false;
}

bool IRDeque::pushLeft(int car)
{
    my_irdeque.insertHead(car);
    return true;
    
}

bool IRDeque::pushRight(int car)
{
    my_irdeque.insertTail(car);
    return true;
}

bool IRDeque::empty()
{
    if (my_irdeque.size() == 0)
    {
        return true;
    }
    return false;
}

int IRDeque::right()
{
    int last;
    last = my_irdeque.size() - 1;
    return my_irdeque.at(last);
}

int IRDeque::left()
{
    return my_irdeque.at(0);
}

int IRDeque::size()
{
    return my_irdeque.size();
}

bool IRDeque::popRight()
{
    if (empty())
    {
        return false;
    }
    else
    {
        int last;
        last = my_irdeque.size() - 1;
        
        int remove;
        remove = my_irdeque.at(last);
        
        my_irdeque.remove(remove);
    }
    return false;
}

bool IRDeque::popLeft()
{
    if (empty())
    {
        return false;
    }
    else
    {
        my_irdeque.remove(left());
    }
    return true;
}