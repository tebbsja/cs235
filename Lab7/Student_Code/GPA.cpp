//
//  GPA.cpp
//  Lab7
//
//  Created by Austin Tebbs on 11/19/15.
//  Copyright © 2015 Austin Tebbs. All rights reserved.
//

#include "GPA.h"
#include <iostream>
#include <fstream>
#include <sstream>

GPA::~GPA()
{
    clear();
}

/*
 * getMap()
 *
 * Returns the map storing the student information.
 * The key of the map should be the student ID.
 */
map<unsigned long long int,StudentInterface*> GPA::getMap()
{
    return myMap;
}

/*
 * getSet()
 *
 * Returns the set storing the student information.
 */
set<StudentInterface*,Comparator> GPA::getSet()
{
    return mySet;
}

/*
 * importStudents()
 *
 * Read in and parse through the given files. Each part of an entry in a
 * file is given on a separate line in the file. Student ID is first, name is
 * second, address is third, and phone is last. There are no blank lines between
 * students. The following is an example file:
 *
 *	 5291738600
 * 	 Dick B. Smith
 * 	 879 Maple Road, Centralia, Colorado 24222
 * 	 312-000-1000
 * 	 9251738707
 *	 Harry C. Anderson
 *	 635 Main Drive, Midville, California 48444
 * 	 660-050-2200
 *
 * If a valid file is given, the new Students should be added to the existing
 * map and set.
 *
 * If an invalid file name is given or if there is a missing entry for a student,
 * return false. Duplicate student ID numbers and duplicate students will not be
 * tested for. There will never be a student that exists in the map and set. If
 * the function returns false, then no changes should have been made to the
 * existing map or set.
 *
 * The key of the map should be the student ID.
 *
 * Returns false if an invalid filename is given or if there is a missing entry for a
 * student, otherwise true.
 */
bool GPA::isValidStudent(string fileName)
{
    ifstream file;
    file.open(fileName);
    string student_ID, name, address, phone_number;
    
    if (file.fail() || file.bad())
    {
        file.close();
        return false;
    }
    
    while(getline(file,student_ID))
    {
        if (student_ID == "")
        {
            file.close();
            return false;
        }
        
        for (int i=0; i < student_ID.size(); i++)
        {
            if (!isdigit(student_ID[i]))
            {
                file.close();
                return false;
            }
        }
        
        getline(file, name);
        if (name == "")
        {
            file.close();
            return false;
        }
        
        getline(file, address);
        if (address == "")
        {
            file.close();
            return false;
        }
        
        getline(file, phone_number);
        if (phone_number == "")
        {
            file.close();
            return false;
        }
    }
    
    file.close();
    return true;
}

bool GPA::importStudents(string mapFileName, string setFileName)
{
    string student_ID, name, address, phone_number;
    
    ifstream file;
    file.open(mapFileName);

    if (!isValidStudent(setFileName))
    {
        file.close();
        return false;
    }
    
    if (!isValidStudent(mapFileName))
    {
        file.close();
        return false;
    }
    
    while(getline(file, student_ID))
    {
        unsigned long long int ID = atoi(student_ID.c_str());
        
        getline(file, name);
        
        getline(file, address);
        
        getline(file, phone_number);
        
        myMap[ID] = new Student(ID, name,address, phone_number);
    }
    
    file.close();
    
    file.open(setFileName);
    

    
    while(getline(file, student_ID))
    {
        unsigned long long int ID = atoi(student_ID.c_str());
        
        getline(file, name);
        
        getline(file, address);
        
        getline(file, phone_number);
        
        mySet.insert(new Student(ID, name, address, phone_number));
    }
    
    file.close();
    
    return true;
}

bool GPA::isValidClass(string fileName)
{
    ifstream file;
    file.open(fileName);
    string student_ID, course, grade;
    
    if (file.fail() || file.bad())
    {
        file.close();
        return false;
    }
    
    while(getline(file,student_ID))
    {
        if (student_ID == "")
        {
            file.close();
            return false;
        }
        for (int i=0; i < student_ID.size(); i++)
        {
            if (!isdigit(student_ID[i]))
            {
                file.close();
                return false;
            }
        }
        
        getline(file, course);
        if (course == "")
        {
            file.close();
            return false;
        }
        
        getline(file, grade);
        if (grade == "" )
        {
            file.close();
            return false;
        }
    }
    
    file.close();
    return true;
}

/*
 * importGrades()
 *
 * Read in and parse through the given file. Each part of an entry in the file
 * is given on a separate line in the file. Student ID is first, course is
 * second, and grade is last. There are no blank lines between entries. The
 * following is an example file:
 *
 * 	5291738860
 * 	CHEM134
 * 	A
 * 	9251734870
 * 	BOT180
 * 	B
 * 	9251733870
 * 	PE273
 * 	D+
 * 	5291738760
 * 	HIS431
 *  	A-
 *
 * Compute the GPA by finding the average of all the grades with a matching student ID
 * in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
 * dividing by the number of classes taken. If the given student ID has no matching
 * grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
 * names so long as the total number of courses taken is counted.
 *
 * You may assume that the given student ID exists in the map or set.
 *
 * Use the following point values for each grade.
 *
 *		  A = 4.0  A- = 3.7
 *	B+ = 3.4  B = 3.0  B- = 2.7
 *	C+ = 2.4  C = 2.0  C- = 1.7
 *	D+ = 1.4  D = 1.0  D- = 0.7
 *		  E = 0.0
 *
 * Returns false if an invalid filename is given, otherwise true.
 */
bool GPA::importGrades(string fileName)
{
    string student_id;
    string course_name;
    string grade;
    
    StudentInterface* student = NULL;
    
    ifstream file;
    file.open(fileName);
    
    if (!isValidClass(fileName))
    {
        file.close();
        return false;
    }
    
    typedef set<StudentInterface*, Comparator>::iterator it;
    
    while (getline(file, student_id))
    {
        unsigned long long int ID = atoi(student_id.c_str());
        
        getline(file, course_name);
        
        getline(file, grade);
        
        // grabbed each line, now need to check if the student_id is equal to any in the set and map
        // if it is, add that to the gpa and add to num classes
        // either in set or map
        
        if (myMap[ID] == NULL) // not in map, it is in set
        {
	    myMap.erase(ID);
            it itr;
            for (itr = mySet.begin(); itr != mySet.end(); itr++)
            {
                if ((*itr)->getID() == ID)
                {
                    student = *itr;
                }
            }
        }
        else
        {
            student = myMap[ID];
        }
        
        if (grade == "A")
        {
            student->addGPA(4.0);
        }
        else if (grade == "A-")
        {
            student->addGPA(3.7);
        }
        else if (grade == "B+")
        {
            student->addGPA(3.4);
        }
        else if (grade == "B")
        {
            student->addGPA(3.0);
        }
        else if (grade == "B-")
        {
            student->addGPA(2.7);
        }
        else if (grade == "C+")
        {
            student->addGPA(2.4);
        }
        else if (grade == "C")
        {
            student->addGPA(2.0);
        }
        else if (grade == "C-")
        {
            student->addGPA(1.7);
        }
        else if (grade == "D+")
        {
            student->addGPA(1.4);
        }
        else if (grade == "D")
        {
            student->addGPA(1.0);
        }
        else if (grade == "D-")
        {
            student->addGPA(0.7);
        }
        else if (grade == "E")
        {
            student->addGPA(0.0);
        }
        
    }
    
    file.close();
    
    return true;
}

/*
 * querySet()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your set to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. If an invalid file name is given,
 * then return an empty string. The precision of the GPA will be rounded to two decimal places.
 * There will be a trailing new line.
 */
string GPA::querySet(string fileName)
{
    ifstream file;
    file.open(fileName);
    
    if (file.fail() || file.bad())
    {
        return "";
    }
    unsigned long long int ID = 0;
    stringstream ss;
    
    StudentInterface* student = NULL;
    typedef set<StudentInterface*, Comparator>::iterator it;
    
    while (file >> ID)
    {
        it itr;
        for (itr = mySet.begin(); itr != mySet.end(); itr++)
        {
            if ((*itr)->getID() == ID)
            {
                student = *itr;
                ss << ID << " " << student->getGPA() << " " << student->getName() << "\n";
            }
        }

    }
    
    file.close();

    return ss.str();
}

/*
 * queryMap()
 *
 * Read in and parse through the given file. The 'Query' file contains a list of
 * student ID numbers. Each entry in the Query file is a student ID given on a
 * line by itself. You are to compute and report the GPA for each of the students
 * listed in the Query file. The following is an example Query file:
 *
 * 	5291738860
 * 	9251733870
 *
 * For each student ID given in the Query file, use the student information stored in
 * your map to compute the GPA for the student and create an output string which
 * contains the student ID, GPA, and name. If the given student ID does not match any
 * student, do not give any output for that student ID. Each line of the output string
 * contains student ID, GPA, and name as shown:
 *
 * 	5291738860 2.85 Dick B. Smith
 *	9251733870 3.00 Harry C. Anderson
 *
 * Return a string representation of the given query. if an ivalid file name is given,
 * then return an empty string. The precision of the GPA will be rounded to two decimal places.
 * There will be a trailing new line.
 */
string GPA::queryMap(string fileName)
{
    
    ifstream file;
    file.open(fileName);
    stringstream ss;
    unsigned long long int ID = 0;
    
    while (file >> ID)
    {
        if (myMap[ID] != NULL)
        {
            ss << ID << " " << myMap[ID]->getGPA() << " " << myMap[ID]->getName() << "\n";
        }
    }
    
    file.close();
    return ss.str();
}

/*
 * Clears the students from the map and set.
 */
void GPA::clear()
{
    for (map<unsigned long long int, StudentInterface*>::iterator itr = myMap.begin(); itr != myMap.end(); itr++)
    {		
	delete itr->second;
    }

    myMap.clear();

    for (set<StudentInterface*, Comparator>::iterator itr = mySet.begin(); itr != mySet.end(); itr++)
    {
	StudentInterface* temp = *itr;
	delete temp;
    }
	
    mySet.clear();

}
