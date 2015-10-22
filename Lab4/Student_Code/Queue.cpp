//
//  Queue.cpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Queue.h"

bool Queue::exists(int car)
{
    if (my_queue.isDuplicate(car))
    {
        return true;
    }
    return false;
}

bool Queue::push(int car)
{
    my_queue.insertHead(car);
    return true;
    
}

bool Queue::empty()
{
    if (my_queue.size() == 0)
    {
        return true;
    }
    return false;
}

int Queue::top()
{
    int last;
    last = my_queue.size() - 1;
    return my_queue.at(last);
}

int Queue::size()
{
    return my_queue.size();
}

bool Queue::pop()
{
    if (empty())
    {
        return false;
    }
    else
    {
        int last;
        last = my_queue.size() - 1;
        
        int remove;
        remove = my_queue.at(last);
        
        my_queue.remove(remove);
    }
    return false;
}