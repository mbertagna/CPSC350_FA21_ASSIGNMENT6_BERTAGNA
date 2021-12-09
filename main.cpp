// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* main.cpp contains the main method and creates an instance of the OfficeManager class
in order to simulate an day at the registar's office. It takes one command line arguement:
1) file path to input file
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

// int main(int argc, char** argv)
// {
//    BST<Person> *b = new BST<Person>();

//    Person *p = new Person(1,"Bob","Job");
//    Person *g = new Person(3,"Joe","Per");
//    Person *n = new Person(-10,"Bob","Job");
//    Person *m = new Person(324,"Joe","Per");
//    Person *t = new Person(0,"Bob","Job");
//    Person *y = new Person(5,"Joe","Per");
//    Person *l = new Person(4,"Bob","Job");
//    Person *i = new Person(3,"Joe","Per");

//    b->insert(*p);
//    b->insert(*g);
//    b->insert(*n);
//    b->insert(*m);
//    b->insert(*t);
//    b->insert(*y);
//    b->insert(*l);
//    b->insert(*i);

//    b->recPrint(b->getRootNode());
   
//    /* code */
//    delete b;

//    delete p;
//    delete g;
//    return 0;
// }

// int main(int argc, char** argv)
// {
//    GenStack<int> *s = new GenStack<int>();

   

//    s->push(1);
//    s->push(2);
//    s->push(4);
//    s->push(-243);
//    s->push(50);
//    s->push(100);
//    s->push(20);
//    s->push(19);

//    for(int i = 0 ; i < 5 ; ++i)
//       cout << s->pop() << endl;

//    s->printStack();
   
//    /* code */
//    delete s;
//    return 0;
// }

// int main(int argc, char** argv)
// {
//    DoublyLinkedList<int> *d = new DoublyLinkedList<int>();

//    d->insertFront(1);
//    d->insertFront(3);
//    d->insertFront(5);
//    d->insertFront(-3);
//    d->insertBack(-342);

//    d->insertAfterValue(-3, 432);

//    d->printList(1);

//    cout << endl;

//    d->insertSort();

//    d->printList(1);

//    cout << d->getPos(5) << endl;
   
//    /* code */
//    delete d;
//    return 0;
// }

// int main(int argc, char** argv)
// {
   
//    return 0;
// }

// int main(int argc, char** argv)
// {
//    BST<Student> *s = new BST<Student>();

//    Student *b = new Student(69,"Bob","Job","Bio",3.0,32534);

//    s->insert(Student(1347598,"Bob","Job","Bio",3.0,32534));
//    s->insert(Student(438597,"MARK","MAN","CHEM",2.0,34534));
//    s->insert(Student(324,"JOE","DOG","CPSC",1.0,4364));
//    s->insert(Student(23,"BET","Job","YO",5.0,43634));
//    s->insert(Student(344,"JUAN","BEAR","Bio",6.0,6463));
//    s->insert(Student(-24,"JOEY","HI","TO",3.0,74646));
//    s->insert(*b);


//    s->recPrint(s->getRootNode());

//    delete s;

//    return 0;
// }





// int main(int argc, char** argv)
// {
//    BST<Faculty> *f = new BST<Faculty>();

//    int *a = new int[5];
//    for(int i = 0 ; i < 5 ; ++i){
//       a[i] = i;
//    }

//    int *r = new int[20];
//    for(int i = 0 ; i < 20 ; ++i){
//       r[i] = i;
//    }

//    Faculty *y = new Faculty(23,"Joey","hi","we",a,5);

//    Faculty *x = new Faculty(23,"Joey","hi","we",NULL,0);

//    f->insert(Faculty(69,"Bob","Job","Bio",r,20));
//    f->insert(Faculty(435,"Bob","Job","Bio",a,5));
//    f->insert(Faculty(75465,"Bob","Job","Bio",a,5));
//    f->insert(Faculty(135,"Bob","Job","Bio",a,5));
//    f->insert(Faculty(7635,"Bob","Job","Bio",a,5));
//    f->insert(Faculty(43645,"Bob","Job","Bio",a,5));
//    f->insert(*y);

//    f->recPrint(f->getRootNode());
   
//    cout << "––––––––––––––––––––––––––––––––––––––––––––––" << endl;

//    Faculty temp = f->deleteNodeReturnValue(Faculty(75465,"Bob","Job","Bio",a,5));
//    cout << temp << endl;

//    cout << "––––––––––––––––––––––––––––––––––––––––––––––" << endl;

//    f->recPrint(f->getRootNode());
//    cout << "––––––––––––––––––––––––––––––––––––––––––––––" << endl;

//    f->insert(temp);

//    f->recPrint(f->getRootNode());

//    delete f;
//    delete y;
//    delete x;

//    return 0;
// }