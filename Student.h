// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Student.h is a header file which lays out the elements of the Student class. */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person{
    protected:
        int m_id;
        string m_name;
        string m_level;
        string m_major;
        double m_gpa;
        int m_advisorId;
    
    public:
        // default constructor
        Student();

        // overloaded constructor
        Student(int id, string name, string level, string major, double gpa, int advisorId);

        // overloaded method for <<
        friend ostream& operator<<(ostream& os, Student);

        // returns a string of a Students information
        string getInfo() override;

        // returns student's major
        string getMajor();

        // returns student's gpa
        double getGpa();

        // returns student's advisor id
        int getAdvisorId();

        // sets student's advisor id
        void setAdvisorId(int advisorId);
};
#endif