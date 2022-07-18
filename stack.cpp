/*********************
* Name: Caleb Drake
* Class: COSC 2436 Data Structures
* Program: Real Stack
* Purpose: This program creates a stack object that works with the Data struct using pointers.
*          This is the "stack.cpp" file, which contains all of the stack methods.
**********************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

/*
 * write all your stack methods here
 */

Stack::Stack() {
	top = -1;
}

Stack::~Stack() {
	for (int i = top; i > -1; i--) {
		delete stack[i];
	}
}

bool Stack::push(int x, const char* stackPointer) {
	bool pushed = false;
	if (top < STACK_SIZE - 1) {
		if ((x >= 0) && (stackPointer != NULL) && (stackPointer[0] != '\0')) {
			Data *data = new Data;
			data->id = x;
			data->information = stackPointer;
			stack[++top] = data;
			pushed = true;
		}
	}
	return pushed;
}

bool Stack::pop(Data* data) {
	bool popped = false;
	if (top != -1) {
		data->id = stack[top]->id;
		data->information = stack[top]->information;
		delete stack[top--];
		popped = true;
	}
	else {
		data->id = -1;
		data->information = "";
	}
	return popped;
}

bool Stack::peek(Data* data) {
	bool peeked = false;
	if (top != -1) {
		
		data->id = stack[top]->id;
		data->information = stack[top]->information;
		peeked = true;
	}
	else {
		data->id = -1;
		data->information = "";
	}
	return peeked;
}

bool Stack::isEmpty() {
	bool empty = true;
	if (top > -1) {
		empty = false;
	}
	return empty;
}