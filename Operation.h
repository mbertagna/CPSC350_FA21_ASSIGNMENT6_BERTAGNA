// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Operation.h is a header file which lays out the elements of the Operation class. */

#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

class Operation{
    private:
        Student m_s;
        Faculty m_f;
        string m_type;
        
    public:
        // default constructor
        Operation();

        // overloaded constructor
        Operation(string type/*as,rs*/, Student s);

        // overloaded constructor
        Operation(string type/*af,df*/, Faculty f);

        // gets type
        string getType();

        // gets student
        Student getStudent();

        // gets faculty
        Faculty getFaculty();

        // destructor
        ~Operation();
};

#endif