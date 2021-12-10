// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Student.cpp is a class which implements the elements of the a basic student, including a major, gpa, and advisor id (inherits from Person). */

#include "Student.h"

// default constructor
Student::Student() : Person(){
    m_major = "";
    m_gpa = 0.0;
    m_advisorId = 0;
}

// overloaded constructor
Student::Student(int id, string name, string level, string major, double gpa, int advisorId) : Person(id, name, level){
    m_major = major;
    m_gpa = gpa;
    m_advisorId = advisorId;
}

// returns a string of a Students information
string Student::getInfo(){
    string infoString = "";
    infoString += (to_string(getId()) + "\n");
    infoString += (getName() + "\n");
    infoString += (getLevel() + "\n");
    infoString += (getMajor() + "\n");
    infoString += to_string(getGpa());
    infoString += "\n";
    infoString += (to_string(getAdvisorId()));
    infoString += "\n";
    return infoString;
}

// returns student's major
string Student::getMajor(){
    return m_major;
}

// returns student's gpa
double Student::getGpa(){
    return m_gpa;
}

// returns student's advisor id
int Student::getAdvisorId(){
    return m_advisorId;
}

// sets student's advisor id
void Student::setAdvisorId(int advisorId){
    m_advisorId = advisorId;
}

// overloaded method for <<
ostream& operator<<(ostream& os, Student other){
    Student temp = other;
    cout << "STUDENT ID: " << temp.getId() << endl;
    cout << "   NAME: " << temp.getName() << endl;
    cout << "   LEVEL: " << temp.getLevel() << endl;
    cout << "   MAJOR: " << temp.getMajor() << endl;
    cout << "   GPA: " << temp.getGpa() << endl;
    cout << "   ADVISOR ID: " << temp.getAdvisorId() << endl;
    return os;
}