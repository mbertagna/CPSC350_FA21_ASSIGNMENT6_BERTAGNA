// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 6

/* GenStack.h is a template class which implements a Linked List based Stack with data type left arbitrary. */

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>
#include "List.h"

using namespace std;

template <class T>
class GenStack{
    public:
        GenStack();//default constructor
        ~GenStack();//destructor

        //core functions
        void push(T data);
        T pop();

        //aux/helper functions
        T peek();//aka top()
        bool isEmpty();
        int getSize();
        void printStack();

    private:  
        List<T> *m_list;
};

template <class T>
GenStack<T>::GenStack(){
    m_list = new List<T>();
}

template <class T>
GenStack<T>::~GenStack(){
    delete m_list;
}

template <class T>
void GenStack<T>::push(T data){
    m_list->prepend(data);
}

template <class T>
T GenStack<T>::pop(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("Stack empty: cannot pop!");
    }

    T temp = m_list->peek();
    m_list->removeFront();
    return temp;
}

template <class T>
T GenStack<T>::peek(){
    //check if empty
    if(isEmpty()){
        throw runtime_error("Stack empty: cannot peek!");
    }

    return m_list->peek();
}

template <class T>
bool GenStack<T>::isEmpty(){
    return (m_list->getLength() == 0);
}

template <class T>
int GenStack<T>::getSize(){
    return (m_list->getLength());
}

template <class T>
void GenStack<T>::printStack(){
    m_list->print();
}

#endif