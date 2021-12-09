
#include "Faculty.h"

// default constructor
Faculty::Faculty() : Person(){}

// overloaded constructor
Faculty::Faculty(int id, string name, string level, string department, int* advisees, int numAdvisees) : Person(id, name, level){
    m_department = department;
    m_numAdvisees = numAdvisees;
    m_advisees = advisees;
}

// overloaded method for <<
ostream& operator<<(ostream& os, Faculty other){
    Faculty temp = other;
    cout << "ID: " << temp.getId() << endl;
    cout << "   NAME: " << temp.getName() << endl;
    cout << "   LEVEL: " << temp.getLevel() << endl;
    cout << "   DEPARTMENT: " << temp.getDepartment() << endl;
    cout << "   ADVISEE'S: " << "\n" << (temp.getAdviseesString(true));
    return os;
}

// returns a string of a Facultys information
string Faculty::getInfo(){
    string infoString = "";
    infoString += to_string(getId());
    infoString += "\n";
    infoString += getName();
    infoString += "\n";
    infoString += getLevel();
    infoString += "\n";
    infoString += getDepartment();
    infoString += "\n";
    infoString += to_string(getNumAdvisees());
    infoString += "\n";
    infoString += getAdviseesString(false);
    return infoString;
}

// returns Faculty's department
string Faculty::getDepartment(){
    return m_department;
}

// returns Faculty's advisees
int* Faculty::getAdvisees(){
    return m_advisees;
}

// returns Faculty's advisees as a String
string Faculty::getAdviseesString(bool whiteSpace){
    string adviseesStr = "";

    for(int i = 0 ; i < m_numAdvisees ; ++i){
        if(m_advisees[i] != 0){
            if(whiteSpace == true){
                adviseesStr += "        ";
            }
            adviseesStr += (to_string(getAdvisees()[i]));
            adviseesStr += "\n";
        }
    }

    return adviseesStr;
}


// deletes an advisee by id num
void Faculty::deleteAdvisee(int index){
    m_advisees[index] = 0;
}

// gets number of advisees
int Faculty::getNumAdvisees(){
    return m_numAdvisees;
}