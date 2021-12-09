// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* DataBase.h is a header file which lays out the elements of the DataBase class. */

#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <cstdlib> //for srand/rand
#include <time.h> //for time
#include <fstream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
using namespace std;

class DataBase{
    private:
        // table of faculty
        BST<Faculty> *masterFaculty;

        // table of students
        BST<Student> *masterStudent;
        
    public:
        // default constructor
        DataBase();

        // destructor
        ~DataBase();

        // exports tables to files
        void serialize();

        // imports tables from files if they exist
        void deserialize();

        // prints all students
        void printStudents();

        // prints all faculty
        void printFaculty();

        // prints specified student info by id
        void printStudentInfo(int id);

        // prints specified faculty info by id
        void printFacultyInfo(int id);

        // prints name and info of a student's faculty advisor
        void printFacultyAdvisor(int studentId);

        // prints name and info of a all a faculty's advisees
        void printFacultyAdvisees(int facultyId);

        // adds a student
        void addStudent(string name, string level, string major, double gpa, int advisorId);

        // deletes a student
        void deleteStudent(int id);

        // removes a specified advisee from all faculty
        void ensureAdviseeRefInteg(int adviseeId); 

        // adds a faculty
        void addFaculty(string name, string level, string department, int *advisees, int numAdvisees);

        // deletes a faculty
        void deleteFaculty(int id);

        // prompts the user to change the advisor of any student who's faculty advisor has been deleted
        void ensureAdvisorRefInteg(int advisorId);

        // sets a students advisor
        void setAdvisor(int studentId, int facultyId);

        // removes an advisee
        void removeAdvisee(int facultyId, int studentId);

        // returns true if only one faculty left in master faculty tree
        bool oneFaculty();

        // returns a 6 digit numerical student id
        int generateStudentId();

        // returns a 7 digit numerical faculty id
        int generateFacultyId();
};

#endif