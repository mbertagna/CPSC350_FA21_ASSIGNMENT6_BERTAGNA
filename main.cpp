// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* main.cpp contains the main method and creates an instance of the DataBaseManager class
in order to simulate a student-faculty data base.
*/

#include "DataBaseManager.h"

int main(int argc, char** argv)
{
   DataBaseManager *dbm = new DataBaseManager();
   try{
      dbm->manageDataBase();
   }
   catch(runtime_error &excpt){
      cerr << excpt.what() << endl;
      return -1;
   }
   return 0;
   delete dbm;
}