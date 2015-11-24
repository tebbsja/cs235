//
//  main.cpp
//  Lab7
//
//  Created by Austin Tebbs on 11/19/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "GPA.h"
#include <iostream>

using namespace std;

int main()
{
    GPA x;
    
    cout << x.importStudents("/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/studentListMap_Large.txt", "/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/studentListSet_Large.txt");
    
    cout << endl << endl;
    
    
    cout << x.importGrades("/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/classList_Total.txt");
    //x.importGrades("/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/classListSet_Large.txt");
    
    //x.querySet("/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/querySet_Large.txt");
    cout << x.querySet("/Users/Austin/Desktop/C++/cs235/Lab7/Lab7/Lab7/Files/query_Total.txt");
    
    //string myString = "45";
    //int value = atoi(myString.c_str());
    
    return 0;
}
