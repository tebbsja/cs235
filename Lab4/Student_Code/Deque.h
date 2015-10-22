//
//  Deque.hpp
//  Lab4
//
//  Created by Austin Tebbs on 10/17/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Deque_h
#define Deque_h

#include "LinkedList.h"
#include <stdio.h>

class Deque
{
private:
    LinkedList <int> my_deque;
    
public:
    bool exists(int car);
    bool pushLeft(int car);
    bool pushRight(int car);
    Deque(){};
    int left();
    int right();
    bool empty();
    bool popLeft();
    bool popRight();
    int size();
    
};
#endif /* Deque_h */
