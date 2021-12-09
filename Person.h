// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Person.h is a header file which lays out the elements of the Person class. */

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person{
    protected:
        int m_id;
        string m_name;
        string m_level;
    
    public:
        // default constructor
        Person();
        // overloaded constructor
        Person(int id, string name, string level);
        // destructor
        virtual ~Person();
        
        // overloaded method for ==
        bool operator==(const Person &other);

        // overloaded method for !=
        bool operator!=(const Person &other);

        // overloaded method for >
        bool operator>(const Person &other);

        // overloaded method for <
        bool operator<(const Person &other);

        // overloaded method for >=
        bool operator>=(const Person &other);

        // overloaded method for <=
        bool operator<=(const Person &other);

        // returns a string of a persons information
        virtual string getInfo();

        // returns person's id
        int getId();

        // returns person's name
        string getName();

        // returns person's level
        string getLevel();
};
#endif