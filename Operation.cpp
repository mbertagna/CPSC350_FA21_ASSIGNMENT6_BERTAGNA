// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Operation.cpp is a class which implements the object to hold a type, a student, and a faculty (for rollback). */

#include "Operation.h"

// default constructor
Operation::Operation(){}

// overloaded constructor
Operation::Operation(string type/*as = add student,rs = remove student*/, Student s){
    m_type = type;
    m_s = s;
}

// overloaded constructor
Operation::Operation(string type/*af = add faculty,df = remove faculty*/, Faculty f){
    m_type = type;
    m_f = f;
}

// gets type
string Operation::getType(){
    return m_type;
}

// gets student
Student Operation::getStudent(){
    return m_s;
}

// gets faculty
Faculty Operation::getFaculty(){
    return m_f;
}

// destructor
Operation::~Operation(){}