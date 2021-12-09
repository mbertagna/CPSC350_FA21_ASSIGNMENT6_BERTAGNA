// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Faculty.h is a header file which lays out the elements of the Faculty class. */

#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "Person.h"
using namespace std;

class Faculty : public Person{
    protected:
        int m_id;
        string m_name;
        string m_level;
        string m_department;
        int *m_advisees;
        int m_numAdvisees;
    
    public:
        // default constructor
        Faculty();

        // overloaded constructor
        Faculty(int id, string name, string level, string department, int *advisees, int numAdvisees);

        // overloaded method for <<
        friend ostream& operator<<(ostream& os, Faculty);

        // returns a string of a Facultys information
        string getInfo() override;

        // returns Faculty's department
        string getDepartment();

        // returns Faculty's advisees
        int* getAdvisees();

        // returns Faculty's advisees as a String
        string getAdviseesString(bool whiteSpace);

        // deletes an advisee by id num
        void deleteAdvisee(int index);

        // gets number of advisees
        int getNumAdvisees();
};
#endif