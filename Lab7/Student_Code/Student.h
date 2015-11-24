//
//  Student.h
//  Lab7
//
//  Created by Austin Tebbs on 11/19/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include "StudentInterface.h"
#include <stdio.h>

class Student : public StudentInterface
{
private:
    unsigned long long int ID;
    string name;
    double total_GPA;
    double total_classes;
    string address;
    string phone_number;
    
    
public:

    Student(unsigned long long int student_id, string student_name, string student_address, string student_phone_number);
    ~Student(){};
    
    virtual unsigned long long int getID();
    
    virtual string getName();

    virtual string getGPA();
    
    virtual void addGPA(double classGrade);

    virtual string toString();
    
    void incr_classes();

};

#endif /* Student_h */
