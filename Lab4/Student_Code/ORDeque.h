//
//  ORDeque.hpp
//  Lab4
//
//  Created by Austin Tebbs on 10/20/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef ORDeque_h
#define ORDeque_h

#include "LinkedList.h"
#include <stdio.h>


class ORDeque
{
private:
    LinkedList <int> my_ordeque;
    
public:
    bool exists(int car);
    bool pushLeft(int car);
    bool pushRight(int car);
    ORDeque(){};
    int left();
    int right();
    bool empty();
    bool popLeft();
    bool popRight();
    int size();
    
};
#endif /* ORDeque_h */

