//
//  main.cpp
//  Lab8
//
//  Created by Austin Tebbs on 11/26/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include <iostream>
#include "QS.h"

using namespace std;

int main()
{
    QS x;
    x.createArray(6);
    x.addToArray(4);
    x.addToArray(6);
    x.addToArray(34);
    x.addToArray(12);
    x.addToArray(17);
    x.addToArray(3);
    
    //x.print();
    cout << endl;
    cout << endl;
    x.sortAll();
    //x.print();
    cout << x.getArray();
    
    return 0;
}
