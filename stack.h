/*********************
* Name: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Real Stack
* Purpose: This program creates a stack object that works with the Data struct using pointers.
*          This is the "stack.h" file, which contains the necessary prototypes, attributes, and libraries.
**********************/

#ifndef STACK_H
#define STACK_H

/*
 * notice there are no other includes here because they are not needed.
 * if you do need other things included, they would go here
 */
#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    /* 
     * write all your public method prototypes here
     * this includes you constructor and destructor
     */
    // Constructor
    Stack();
    // Destructor
    ~Stack();

    bool push(int, const char*);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();

private:

    /* 
     * write all your private method prototypes here
     */

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H
