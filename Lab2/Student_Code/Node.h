//Austin Tebbs
#pragma once
//#include "LinkedList.h"


template<class T>
class Node {

public:

            Node* next;
            T data;
            
            Node(const T& data_item, Node* next_ptr = NULL) :
            data(data_item), next(next_ptr){}
};
