//
//  IRDeque.hpp
//  Lab4
//
//  Created by Austin Tebbs on 10/20/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef IRDeque_h
#define IRDeque_h

#include "LinkedList.h"
#include <stdio.h>

class IRDeque
{
private:
    LinkedList <int> my_irdeque;
    
public:
    bool exists(int car);
    bool pushLeft(int car);
    bool pushRight(int car);
    IRDeque(){};
    int left();
    int right();
    bool empty();
    bool popLeft();
    bool popRight();
    int size();
    
};

#endif /* IRDeque_h */
