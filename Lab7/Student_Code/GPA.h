//
//  GPA.h
//  Lab7
//
//  Created by Austin Tebbs on 11/19/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef GPA_h
#define GPA_h

#include "GPAInterface.h"
#include "Student.h"
#include <stdio.h>

class GPA : public GPAInterface
{
    
public:
    
    set <StudentInterface*, Comparator> mySet;
    map <unsigned long long int, StudentInterface*> myMap;
    
    GPA(){};
    ~GPA();
 
    virtual map<unsigned long long int,StudentInterface*> getMap();

    virtual set<StudentInterface*,Comparator> getSet();

    virtual bool importStudents(string mapFileName, string setFileName);
    
    virtual bool importGrades(string fileName);
    
    virtual string querySet(string fileName);

    virtual string queryMap(string fileName);

    virtual void clear();
    
    bool isValidStudent(string fileName);
    bool isValidClass(string fileName);
    
};

#endif /* GPA_h */
