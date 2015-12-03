//
//  QS.h
//  Lab8
//
//  Created by Austin Tebbs on 11/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef QS_h
#define QS_h

#include "QSInterface.h"

class QS : public QSInterface
{
private:
    int* myArray;
    int current_size;
    int total_size;
    
public:

    QS();
    ~QS();
    
    void sort(int left, int right);
    
    virtual void sortAll();
    virtual int medianOfThree(int left, int right);
    virtual int partition(int left, int right, int pivotIndex);
    virtual string getArray();
    virtual int getSize();
    virtual void addToArray(int value);
    virtual bool createArray(int capacity);
    virtual void clear();
    
    void print();
    void swapValues(int first, int second);
};

#endif /* QS_h */
