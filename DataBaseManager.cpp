
#include "DataBaseManager.h"

// default constructor
DataBaseManager::DataBaseManager(){
    m_dataBase = new DataBase();
}

// destructor
DataBaseManager::~DataBaseManager(){
    delete m_dataBase;
}

// allows the user to manage the database, prompting them for which operations they would like to perform
void DataBaseManager::manageDataBase(){
    string operationStr = "";
    int operationInt = 0;
    bool exit = false;
    int *advArr;
    string name;
    string level;
    string dept;
    int numAdv;

    cout << endl;
    cout << "WELCOME TO THE STUDENT-FACULTY DATABASE!" << endl;

    while(exit == false){
        cout << endl;
        cout << "PLEASE SELECT AN OPERATION FROM THE LIST BY INPUTTING ITS CORRESPONDING NUMBER: " << endl;
        cout << "1  – DISPLAY ALL STUDENTS AND THEIR INFORMATION (SORTED BY ASCENDING ID #)." << endl;
        cout << "2  – DISPLAY ALL FACULTY MEMBERS AND THEIR INFORMATION (SORTED BY ASCENDING ID #)." << endl;
        cout << "3  – FIND AND DISPLAY A STUDENT'S INFORMATION BY STUDENT ID #." << endl;
        cout << "4  – FIND AND DISPLAY A FACULTY MEMEBER'S INFORMATION BY FACULTY ID #." << endl;
        cout << "5  – DISPLAY THE INFO OF A STUDENT'S FACULTY ADVISOR BY STUDENT ID #." << endl;
        cout << "6  – DISPLAY THE INFO OF A FACULTY MEMEBER'S STUDENT ADVISEES BY FACULTY ID #." << endl;
        cout << "7  – ADD A NEW STUDENT." << endl;
        cout << "8  – DELETE A STUDENT BY ID #." << endl;
        cout << "9  – ADD A NEW FACULTY MEMBER." << endl;
        cout << "10 – DELETE A FACULTY MEMBER BY ID #." << endl;
        cout << "11 – CHANGE A STUDENT’S FACULTY ADVISOR BY STUDENT ID # AND THE NEW FACULTY ID #." << endl;
        cout << "12 – REMOVE A STUDENT ADVISEE FROM A FACULTY MEMBER GIVEN THE ID #'S OF THE FACULTY MEMBER AND THE STUDENT ADVISEE." << endl;
        cout << "13 – ROLLBACK." << endl;
        cout << "14 – EXIT." << endl;

        cout << endl;

        cout << "OPERATION: ";
        cin >> (operationStr);
        cout << endl;

        while((operationStr != "1") && (operationStr != "2") && (operationStr != "3") && (operationStr != "4") && (operationStr != "5") && (operationStr != "6") && (operationStr != "7") && (operationStr != "8") && (operationStr != "9") && (operationStr != "10") && (operationStr != "11") && (operationStr != "12") && (operationStr != "13") && (operationStr != "14")){
            cout << "INVALID OPERATION NUMBER: PLEASE INPUT A VALID OPERATION NUMBER (1-14)." << endl;
            cout << endl;
            cout << "OPERATION: ";
            cin >> operationStr;
            cout << endl;
        }

        operationInt = stoi(operationStr);

        switch(operationInt){
            case 1:
                m_dataBase->printStudents();
                break;
            case 2:
                m_dataBase->printFaculty();
                break;
            case 3:
                m_dataBase->printStudentInfo(getInt('s'));
                break;
            case 4:
                m_dataBase->printFacultyInfo(getInt('f'));
                break;
            case 5:
                m_dataBase->printFacultyAdvisor(getInt('s'));
                break;
            case 6:
                m_dataBase->printFacultyAdvisees(getInt('f'));
                break;
            case 7:
                m_dataBase->addStudent(getStr('n'), getStr('l'), getStr('m'),getGpa(),getInt('a'));
                break;
            case 8:
                m_dataBase->deleteStudent(getInt('s'));
                break;
            case 9:
                name = getStr('n');
                level = getStr('l');
                dept = getStr('d');
                numAdv = getInt('n');
                advArr = new int[numAdv];
                for(int i = 0 ; i < numAdv ; ++i){
                    advArr[i] = getInt('e');
                }
                m_dataBase->addFaculty(name,level,dept,advArr,numAdv);
                break;
            case 10:
                m_dataBase->deleteFaculty(getInt('f'));
                break;
            case 11:
                m_dataBase->setAdvisor(getInt('s'),getInt('a'));
                break;
            case 12:
                m_dataBase->removeAdvisee(getInt('f'),getInt('e'));
                break;
            case 13:
                //FIXMEEEE
                break;
            case 14:
                cout << "SAVING DATABASE." << endl;
                m_dataBase->serialize();
                exit = true;
                cout << "DATABASE SAVED." << endl;
                cout << "GOODBYE!" << endl;
                break;
        }
    }
}



// checks to see if the value is a valid GPA (0.0 to 4.0)
bool DataBaseManager::isGpa(string gpa){
    int decimalPoint = false;//checks if decimal point found yet

    if(gpa.length() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < gpa.length(); ++i){//loop through chars in string
        if(!(isdigit(gpa[i]))){//if char is not numeric run body
            if(gpa[i] == '.' && decimalPoint == false){//if it is decimal point and decimal point not found yet, set decimalPoint = true
                decimalPoint = true;
            }
            else{//return false if char is not numeric and not decimal or if multiple decimal points
                return false;
            }
        }
    }
    if(gpa == ".")
        return false;

    if(std::stod(gpa) < 0.0 || std::stod(gpa) > 4.0)//if decimal value is not within [0,4]
        return false;
    
    return true;//if decimal value is within [0,4]
}

// gets a valid GPA value from the user
double DataBaseManager::getGpa(){
    string gpa = "";
    cout << "GPA: ";
    cin >> gpa;

    while(!(isGpa(gpa))){
        cout << "INVAILD INPUT: PLEASE ENTER A VALID GPA (0.0 TO 4.0)" << endl;
        cout << "GPA: ";
        cin >> gpa;
    }
    return std::stod(gpa);
}

// gets an integer from the user//FIXME when alpha inputted
int DataBaseManager::getInt(char type/* s = student id , f = faculty id , n = number of advisees , a = advisor id , e = advisee id*/){
    string i = "1";
    switch(type){
        case 's':
            cout << "STUDENT ID: ";
            cin >> i;
            break;
        case 'f':
            cout << "FACULTY ID: ";
            cin >> i;
            break;
        case 'n':
            cout << "NUMBER OF ADVISEES: ";
            cin >> i;
            break;
        case 'a':
            cout << "FACULTY ADVISIOR ID: ";
            cin >> i;
            break;
        case 'e':
            cout << "STUDENT ADVISEE ID: ";
            cin >> i;
            break;
    }

    while(!(isPosIntOrZero(i))){
        cout << "INVAILD INPUT: PLEASE ENTER AN INTEGER GREATER THAN OR EQUAL TO ZERO." << endl;
        switch(type){
            case 's':
                cout << "STUDENT ID: ";
                cin >> i;
                break;
            case 'f':
                cout << "FACULTY ID: ";
                cin >> i;
                break;
            case 'n':
                cout << "NUMBER OF ADVISEES: ";
                cin >> i;
                break;
            case 'a':
                cout << "FACULTY ADVISIOR ID: ";
                cin >> i;
                break;
            case 'e':
                cout << "STUDENT ADVISEE ID: ";
                cin >> i;
                break;
        }
    }
    return stoi(i);
}

// checks if string is an +integer or 0
bool DataBaseManager::isPosIntOrZero(string maybeInt){
    if(maybeInt.length() == 0)//return false if string has length zero
        return false;

    for(int i = 0; i < maybeInt.length(); ++i){//loop through chars in string
        if(!(isdigit(maybeInt[i])))//if char is not numeric return false
            return false;
    }

    if(std::stoi(maybeInt) < 0)//if int is not > 0
        return false;

    return true;//if all numeric and > 0
}

// gets a string from the user
string DataBaseManager::getStr(char type/* n = name , l = level , m = major , d = department */){
    string s = "";
    switch(type){
        case 'n':
            cout << "NAME: ";
            cin >> s;
            break;
        case 'l':
            cout << "LEVEL: ";
            cin >> s;
            break;
        case 'm':
            cout << "MAJOR: ";
            cin >> s;
            break;
        case 'd':
            cout << "DEPARTMENT: ";
            cin >> s;
            break;
    }
    return s;
}