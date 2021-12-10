// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* DataBase.cpp is a class which implements the elements of the a basic student-faculty database. It contains two tables masterFaculty and masterStudent 
which hold data about fauclty and students, respectively. The class allows for the modification of these tables and saves them upon program end. */

#include "DataBase.h"

// default constructor
DataBase::DataBase(){
    deserialize();
}

// destructor
DataBase::~DataBase(){
    delete masterFaculty;
    delete masterStudent;
}

// imports tables from files if they exist
void DataBase::deserialize(){
    masterFaculty = new BST<Faculty>();
    masterStudent = new BST<Student>();

    ifstream inFSF;// input file stream

    inFSF.open("facultyTable");// open input file

    // if input file cannot be opened print error to user
    if (inFSF.is_open()) {

        string f_id = "";
        string f_name = "";
        string f_level = "";
        string f_dept = "";
        string f_numAdvisees = "";
        string *f_adviseesIds;
        int *f_adviseesIdsInt;

        while(!inFSF.fail()){//loop through data and grab faculty (each one taking up 5 + numAdvisees lines until fail)
            getline(inFSF, f_id);
            if(f_id == "\n" || f_id == ""){
                break;
            }

            if(masterFaculty->contains(Faculty(stoi(f_id), "", "", "", NULL, 0))){
                break;
            }

            getline(inFSF, f_name);
            getline(inFSF, f_level);
            getline(inFSF, f_dept);
            getline(inFSF, f_numAdvisees);
            if(f_numAdvisees == "0"){
                f_adviseesIds = NULL;
            }
            else{
                f_adviseesIds = new string[stoi(f_numAdvisees)];
                f_adviseesIdsInt = new int[stoi(f_numAdvisees)];

                for(int i = 0 ; i < stoi(f_numAdvisees) ; ++i){
                    getline(inFSF, f_adviseesIds[i]);
                }


                for(int i = 0 ; i < stoi(f_numAdvisees) ; ++i){
                    f_adviseesIdsInt[i] = stoi(f_adviseesIds[i]);
                }
            }
            masterFaculty->insert(Faculty(stoi(f_id),f_name,f_level,f_dept,f_adviseesIdsInt,stoi(f_numAdvisees)));
        }
        if(!(masterFaculty->isEmpty())){
            cout << "FACULTY MEMEBER(S) FROM PREVIOUS SESSION RESTORED." << endl;
        }
    }
    inFSF.close();// close input file stream  

    // ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

    ifstream inFSS;// input file stream

    inFSS.open("studentTable");// open input file

    // if input file cannot be opened print error to user
    if (inFSS.is_open()) {

        string s_id = "";
        string s_name = "";
        string s_level = "";
        string s_major = "";
        string s_gpa = "";
        string s_advisiorId = "";

        while(!inFSS.fail()){//loop through data and grab student (each one taking up 6 lines until fail)
            getline(inFSS, s_id);
            if(s_id == "\n" || s_id == "")
                break;
            if(masterStudent->contains(Student(stoi(s_id),"","","",0.0,0)))
                break;
            getline(inFSS, s_name);
            getline(inFSS, s_level);
            getline(inFSS, s_major);
            getline(inFSS, s_gpa);
            getline(inFSS, s_advisiorId);
            if(s_advisiorId == "\n" || s_advisiorId == "")
                break;
            masterStudent->insert(Student(stoi(s_id),s_name,s_level,s_major,std::stod(s_gpa),stoi(s_advisiorId)));
        }
        if(!(masterStudent->isEmpty())){
            cout << "STUDENT(S) FROM PREVIOUS SESSION RESTORED." << endl;
        }
    }
    inFSS.close();// close input file stream
}

// exports tables to files
void DataBase::serialize(){
    ofstream outFSF;// output file stream for faculty

    outFSF.open("facultyTable");// open output file and overwrite

    // if output file cannot be opened print error to user and do nothing else
    if (!outFSF.is_open()) {
        throw runtime_error("ERROR: FACULTY TABLE COULD NOT BE SAVED.");
    }
    // if file successfully opened begin writing to file
    else{
        while(!(masterFaculty->isEmpty())){
            outFSF << (masterFaculty->deleteRootNodeReturnValue().getInfo());
        }
    }
    outFSF.close();// close output file stream

    ofstream outFSS;// output file stream for students

    outFSS.open("studentTable");// open output file and overwrite

    // if output file cannot be opened print error to user and do nothing else
    if (!outFSS.is_open()) {
        throw runtime_error("ERROR: FACULTY TABLE COULD NOT BE SAVED.");
    }
    // if file successfully opened begin writing to file
    else{
        while(!(masterStudent->isEmpty())){
            outFSS << (masterStudent->deleteRootNodeReturnValue().getInfo());
        }
    }
    outFSS.close();// close output file stream
}

// prints all students
void DataBase::printStudents(){
    if(masterStudent->isEmpty()){
        cout << "THERE ARE NO STUDENTS CURRENTLY IN THE DATABASE." << endl;
    }
    else{
        masterStudent->recPrint(masterStudent->getRootNode());
    }
}

// prints all faculty
void DataBase::printFaculty(){
    if(masterFaculty->isEmpty()){
        cout << "THERE ARE NO FACULTY CURRENTLY IN THE DATABASE." << endl;
    }
    else{
        masterFaculty->recPrint(masterFaculty->getRootNode());
    }
}

// prints specified student info by id
void DataBase::printStudentInfo(int id){
    if(masterStudent->contains(Student(id, "", "", "", 0.0, 0))){
        Student temp = masterStudent->deleteNodeReturnValue(Student(id, "", "", "", 0.0, 0));
        cout << temp << endl;
        masterStudent->insert(temp);
    }
    else{
        cout << "CANNOT PERFORM OPERATION: STUDENT WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// prints specified faculty info by id
void DataBase::printFacultyInfo(int id){
    if(masterFaculty->contains(Faculty(id, "", "", "", NULL, 0))){
        Faculty temp = masterFaculty->deleteNodeReturnValue(Faculty(id, "", "", "", NULL, 0));
        cout << temp << endl;
        masterFaculty->insert(temp);
    }
    else{
        cout << "CANNOT PERFORM OPERATION: FACULTY WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// prints name and info of a student's faculty advisor
void DataBase::printFacultyAdvisor(int studentId){
    if(masterStudent->contains(Student(studentId, "", "", "", 0.0, 0))){
        Student tempS = masterStudent->deleteNodeReturnValue(Student(studentId, "", "", "", 0.0, 0));
        Faculty tempF = masterFaculty->deleteNodeReturnValue(Faculty(tempS.getAdvisorId(), "", "", "", NULL, 0));
        cout << tempF << endl;
        masterFaculty->insert(tempF);
        masterStudent->insert(tempS);
    }
    else{
        cout << "CANNOT PERFORM OPERATION: STUDENT WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// prints name and info of a all a faculty's advisees
void DataBase::printFacultyAdvisees(int facultyId){
    if(masterFaculty->contains(Faculty(facultyId, "", "", "", NULL, 0))){
        int numZero = 0;
        Faculty tempF = masterFaculty->deleteNodeReturnValue(Faculty(facultyId, "", "", "", NULL, 0));
        Student tempS;
        for(int i = 0 ; i < tempF.getNumAdvisees() ; ++i){
            if((tempF.getAdvisees())[i] != 0){
                tempS = masterStudent->deleteNodeReturnValue(Student((tempF.getAdvisees())[i], "", "", "", 0.0, 0));
                cout << tempS << endl;
                masterStudent->insert(tempS);
            }
            else{
                ++numZero;
            }
        }
        if(numZero == tempF.getNumAdvisees()){
            cout << "FACULTY WITH SPECIFIED ID DOES NOT HAVE ANY ADVISEES." << endl;
        }
        masterFaculty->insert(tempF);
    }
    else{
        cout << "CANNOT PERFORM OPERATION: FACULTY WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// adds a student
int DataBase::addStudent(string name, string level, string major, double gpa, int advisorId){
    if(masterFaculty->contains(Faculty(advisorId, "", "", "", NULL, 0))){
        int id = generateStudentId();
        masterStudent->insert(Student(id, name, level, major, gpa, advisorId));
        return id;
    }
    cout << "CANNOT PERFORM OPERATION: FACULTY ADVISOR WITH SPECIFIED ID DOES NOT EXIST." << endl;
    return -1;
}

// adds a student
int DataBase::addStudentRB(int id,string name, string level, string major, double gpa, int advisorId){
    if(masterFaculty->contains(Faculty(advisorId, "", "", "", NULL, 0))){
        masterStudent->insert(Student(id, name, level, major, gpa, advisorId));
        return id;
    }
    cout << "CANNOT PERFORM OPERATION: FACULTY ADVISOR WITH SPECIFIED ID DOES NOT EXIST." << endl;
    return -1;
}

// deletes a student
Student DataBase::deleteStudent(int id){
    if(masterStudent->isEmpty()){
        cout << "CANNOT PERFORM OPERATION: NO STUDENTS IN DATABASE." << endl;
        return Student(-1,"","","",0.0,0);
    }
    if(masterStudent->contains(Student(id, "", "", "", 0.0, 0))){
        Student s = masterStudent->deleteNodeReturnValue(Student(id, "", "", "", 0.0, 0));
        ensureAdviseeRefInteg(id);
        return s;
    }
    else{
        cout << "CANNOT PERFORM OPERATION: STUDENT WITH SPECIFIED ID DOES NOT EXIST." << endl;
        return Student(-1,"","","",0.0,0);
    }
    return Student(-1,"","","",0.0,0);
}

// removes a specified advisee from all faculty
void DataBase::ensureAdviseeRefInteg(int adviseeId){
    Faculty tempF;
    BST<Faculty> *checkedFaculty = new BST<Faculty>();

    while(!(masterFaculty->isEmpty())){
        tempF = masterFaculty->deleteRootNodeReturnValue();
        for(int i = 0 ; i < tempF.getNumAdvisees() ; ++i){
            if((tempF.getAdvisees()[i]) == adviseeId){
                tempF.getAdvisees()[i] = 0;
            }
        }
        checkedFaculty->insert(tempF);
    }
    while(!(checkedFaculty->isEmpty())){
        tempF = checkedFaculty->deleteRootNodeReturnValue();
        masterFaculty->insert(tempF);
    }
    delete checkedFaculty;
}

// adds a faculty
int DataBase::addFaculty(string name, string level, string department, int *advisees, int numAdvisees){
    for(int i = 0 ; i < numAdvisees ; ++i){
        if(!(masterStudent->contains(Student(advisees[i], "", "", "", 0.0, 0)))){
            cout << "CANNOT PERFORM OPERATION: STUDENT(S) WITH SPECIFIED ID DOES NOT EXIST." << endl;
            return -1;            
        }
    }
    int id = generateFacultyId();
    masterFaculty->insert(Faculty(generateFacultyId(), name, level, department, advisees, numAdvisees));
    return id;
}

// adds a faculty
int DataBase::addFacultyRB(int id, string name, string level, string department, int *advisees, int numAdvisees){
    for(int i = 0 ; i < numAdvisees ; ++i){
        if(!(masterStudent->contains(Student(advisees[i], "", "", "", 0.0, 0)))){
            cout << "CANNOT PERFORM OPERATION: STUDENT(S) WITH SPECIFIED ID DOES NOT EXIST." << endl;
            return -1;            
        }
    }
    masterFaculty->insert(Faculty(generateFacultyId(), name, level, department, advisees, numAdvisees));
    return id;
}

// deletes a faculty
Faculty DataBase::deleteFaculty(int id){
    if(masterFaculty->isEmpty()){
        cout << "CANNOT PERFORM OPERATION: NO FACULTY IN DATABASE." << endl;
        return Faculty(-1, "", "", "", NULL, 0);
    }
    if((!(oneFaculty())) || masterStudent->isEmpty()){
        if(masterFaculty->contains(Faculty(id, "", "", "", NULL, 0))){
            Faculty f = masterFaculty->deleteNodeReturnValue(Faculty(id, "", "", "", NULL, 0));
            ensureAdvisorRefInteg(id);
            return f;
        }
        else{
            cout << "CANNOT PERFORM OPERATION: FACULTY WITH SPECIFIED ID DOES NOT EXIST." << endl;
            return Faculty(-1, "", "", "", NULL, 0);
        }
    }
    else{
        cout << "CANNOT PERFORM OPERATION: ONLY ONE FACULTY EXISTS. DATABASE WITH STUDENTS MUST HAVE AT LEAST ONE FACULTY." << endl;
        return Faculty(-1, "", "", "", NULL, 0);
    }
    return Faculty(-1, "", "", "", NULL, 0);
}

// returns true if only one faculty left in master faculty tree
bool DataBase::oneFaculty(){
    bool oneValue = false;
    Faculty tempF = masterFaculty->deleteRootNodeReturnValue();
    if(masterFaculty->isEmpty()){
        oneValue = true;
    }
    masterFaculty->insert(tempF);
    return oneValue;
}

// returns true if no students
bool DataBase::zeroStudents(){
    return masterStudent->isEmpty();
}

// prompts the user to change the advisor of any student who's faculty advisor has been deleted
void DataBase::ensureAdvisorRefInteg(int advisorId){
    Student tempS;
    vector<Student> *checkedStudents = new vector<Student>();

    while(!(masterStudent->isEmpty())){
        tempS = masterStudent->deleteRootNodeReturnValue();
        string newAdvisior = "";
        if((tempS.getAdvisorId()) == advisorId){
            cout << "THE FOLLOWING STUDENT DOES NOT HAVE A VALID ADVISOR, AS FACULTY WITH ID = " + to_string(advisorId);
            cout << " HAS BEEN DELETED: " << endl;
            cout << tempS << endl;
            cout << "PLEASE ENTER A VALID ID OF THE DESIRED NEW ADVISOR FOR THE STUDENT: ";
            cin >> newAdvisior;
            while(!isPosIntOrZero(newAdvisior)){
                cout << "PLEASE ENTER A VALID ID OF THE DESIRED NEW ADVISOR FOR THE STUDENT: ";
                cin >> newAdvisior;
                if(isPosIntOrZero(newAdvisior)){
                    if(!(masterFaculty->contains(Faculty(stoi(newAdvisior), "", "", "", NULL, 0))))
                    newAdvisior = -1;
                }
            }
            tempS.setAdvisorId(stoi(newAdvisior));
        }
        checkedStudents->push_back(tempS);
    }

    while(!(checkedStudents->size()==0)){
        masterStudent->insert(checkedStudents->back());
        checkedStudents->pop_back();
    }
    delete checkedStudents;
}

// sets a students advisor
void DataBase::setAdvisor(int studentId, int facultyId){
    if(masterFaculty->contains(Faculty(facultyId, "", "", "", NULL, 0))){
        if(masterStudent->contains(Student(studentId, "", "", "", 0.0, 0))){
            Student tempS = masterStudent->deleteNodeReturnValue(Student(studentId, "", "", "", 0.0, 0));
            tempS.setAdvisorId(facultyId);
            masterStudent->insert(tempS);
        }
        else{
            cout << "CANNOT PERFORM OPERATION: STUDENT WITH SPECIFIED ID DOES NOT EXIST." << endl;
        }
    }
    else{
        cout << "CANNOT PERFORM OPERATION: FACULTY ADVISOR WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// removes an advisee
void DataBase::removeAdvisee(int facultyId, int studentId){
    if(!(masterStudent->contains(Student(studentId, "", "", "", 0.0, 0)))){
        cout << "CANNOT PERFORM OPERATION: STUDENT WITH SPECIFIED ID DOES NOT EXIST." << endl;
        return;            
    }
    if(masterFaculty->contains(Faculty(facultyId, "", "", "", NULL, 0))){
        Faculty tempF = masterFaculty->deleteNodeReturnValue(Faculty(facultyId, "", "", "", NULL, 0));
        for(int i = 0 ; i < tempF.getNumAdvisees() ; ++i){
            if((tempF.getAdvisees()[i]) == studentId){
                tempF.deleteAdvisee(i);
                masterFaculty->insert(tempF);
                return;
            }
        }
        masterFaculty->insert(tempF);
        cout << "CANNOT PERFORM OPERATION: FACULTY DOES NOT HAVE STUDENT ADVISEE WITH SPECIFIED ID." << endl;
    }
    else{
        cout << "CANNOT PERFORM OPERATION: FACULTY WITH SPECIFIED ID DOES NOT EXIST." << endl;
    }
}

// returns a 6 digit numerical student id
int DataBase::generateStudentId(){
    srand(time(0));//use current time as random seed
    int id = rand() % 1000000;
    while(id < 100000){
        id = rand() % 1000000;
    }
    return id;
}

// returns a 7 digit numerical faculty id
int DataBase::generateFacultyId(){
    srand(time(0));//use current time as random seed
    int id = rand() % 10000000;
    while(id < 1000000){
        id = rand() % 10000000;
    }
    return id;
}

// checks if string is an +integer or 0
bool DataBase::isPosIntOrZero(string maybeInt){
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