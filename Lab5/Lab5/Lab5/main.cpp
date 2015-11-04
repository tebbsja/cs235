//
//  main.cpp
//  Lab5
//
//  Created by Austin Tebbs on 11/3/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//
#include "Pathfinder.h"
#include <iostream>
using namespace std;

int main()
{
    Pathfinder x;
    x.importMaze("/Users/Austin/Desktop/C++/cs235/Lab5/Lab5/Lab5/Mazes/Solvable2.txt");
    cout << x.getMaze();
    vector<string> y;
    y = x.solveMaze();
    cout << "vector: " << endl;
    for (int i=0; i < y.size(); i++)
    {
        cout << y[i] << endl;
    }

    
    return 0;
}
