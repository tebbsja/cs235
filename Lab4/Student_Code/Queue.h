//
//  Queue.hpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "LinkedList.h"
#include <stdio.h>

class Queue
{
private:
    LinkedList <int> my_queue;
    
public:
    bool exists(int car);
    bool push(int car);
    Queue(){};
    int top();
    bool empty();
    bool pop();
    int size();
    
};
#endif /* Queue_h */
