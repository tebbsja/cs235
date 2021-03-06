//
//  Student.cpp
//  Lab7
//
//  Created by Austin Tebbs on 11/19/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "Student.h"
#include <iostream>
#include <sstream>
#include <iomanip>


Student::Student(unsigned long long int student_id, string student_name, string student_address,
                 string student_phone_number)
{
    this->name = student_name;
    this->address = student_address;
    this->phone_number = student_phone_number;
    this->ID = student_id;
    this->total_classes = 0;
    this->total_GPA = 0;
    
}
/*
 * getID()
 *
 * Returns the ID of the Student.
 */
unsigned long long int Student::getID()
{
    return ID;
}

/*
 * getName()
 *
 * Returns the name of the Student
 */

string Student::getName()
{
    return name;
}

/*
 * getGPA()
 *
 * Returns the string representation of the Student's GPA.
 */

string Student::getGPA()
{
    stringstream ss;
    
    if (total_classes > 0)
    {
        ss << setprecision(2) << fixed << (total_GPA / total_classes);
        return ss.str();
    }
    else
    {
        ss << setprecision(2) << fixed << total_GPA;
        return ss.str();
    }
    
    return "error";
}

/*
 * addGPA()
 *
 * Incorporates the given course grade into the Student's overall GPA.
 */

void Student::addGPA(double classGrade)
{
    total_GPA += classGrade;
    total_classes++;
}

/*
 * toString()
 *
 * The student object will be put into string representation. Student info will be
 * ordered ID, name, address, phone number, and GPA. Each piece of information will
 * be on its own line. GPA will not have a newline following it and the precision
 * of the GPA will be rounded to two decimal places. For example,
 *
 * 123456789
 * Ben Thompson
 * 17 Russell St, Provo, UT 84606
 * 555-555-5555
 * 3.12
 *
 * Returns a string representation of the student object There is no trailing new line.
 */
string Student::toString()
{
    stringstream ss;
    double avg;
    if (total_classes == 0)
    {
	avg = 0;
    }
    else 
    {
	avg = total_GPA / total_classes;
    }
    
    ss << ID << "\n" << name << "\n" << address << "\n" << phone_number << "\n" << setprecision(2) << fixed << avg;
    
    return ss.str();
}
void Student::incr_classes()
{
    total_classes++;
}
