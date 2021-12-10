// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* Person.cpp is a base class which implements the elements of the a basic person who has an id, name, and level. */

#include "Person.h"

// default constructor
Person::Person(){
    m_id = 0;
    m_name = "";
    m_level = "";
}

// overloaded constructor
Person::Person(int id, string name, string level){
    m_id = id;
    m_name = name;
    m_level = level;
}

// destructor
Person::~Person(){}

// overloaded method for ==
bool Person::operator==(const Person &other){
    Person temp = other;
    if(this->getId() == temp.getId()){
        return true;
    }
    return false;
}

// overloaded method for !=
bool Person::operator!=(const Person &other){
    return !(*this == other);
}

// overloaded method for >=
bool Person::operator>=(const Person &other){
    Person temp = other;
    if(this->getId() >= temp.getId()){
        return true;
    }
    return false;
}

// overloaded method for <=
bool Person::operator<=(const Person &other){
    Person temp = other;
    if(this->getId() <= temp.getId()){
        return true;
    }
    return false;
}

// overloaded method for >
bool Person::operator>(const Person &other){
    Person temp = other;
    if(this->getId() > temp.getId()){
        return true;
    }
    return false;
}

// overloaded method for <
bool Person::operator<(const Person &other){
    Person temp = other;
    if(this->getId() < temp.getId()){
        return true;
    }
    return false;
}

// returns person's id
int Person::getId(){
    return m_id;
}

// returns person's name
string Person::getName(){
    return m_name;
}

// returns person's level
string Person::getLevel(){
    return m_level;
}

string Person::getInfo(){
    string infoString = "";
    infoString += (getId() + "\n");
    infoString += (getName() + "\n");
    infoString += (getLevel() + "\n");
    return infoString;
}