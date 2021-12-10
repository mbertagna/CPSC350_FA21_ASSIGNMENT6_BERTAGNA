// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* DataBaseManager.h is a header file which lays out the elements of the DataBaseManager class. */

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <iostream>
#include "DataBase.h"
#include "Operation.h"
#include <vector>
using namespace std;

class DataBaseManager{
    private:    
        DataBase *m_dataBase;
        vector<Operation> *m_operations;
        int numRB;
        
    public:
        // default constructor
        DataBaseManager();

        // destructor
        ~DataBaseManager();

        // allows the user to manage the database, prompting them for which operations they would like to perform
        void manageDataBase();

        // gets a valid GPA value from the user
        double getGpa();

        // checks to see if the value is a valid GPA (0.0 to 4.0)
        bool isGpa(string gpa);

        // gets an integer from the user
        int getInt(char type/* s = student id , f = faculty id , n = number of advisees */);

        // gets a string from the user
        string getStr(char type/* n = name , l = level , m = major , d = department */);

        // checks if string is an +integer or 0
        bool isPosIntOrZero(string maybeInt);

        // reverts beck to the last data base before an add or remove
        void rollBack();
};

#endif