/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    Data holder;
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */
    cout << "Empty stack isEmpty check: " << stack.isEmpty() << endl;
    cout << "Empty stack peek check: " << stack.peek(&holder) << "  " << holder.id << "  ." << holder.information << "." << endl;
    cout << "Empty stack pop check: " << stack.pop(&holder) << "  " << holder.id << "  ." << holder.information << "." << endl;
    cout << endl;
    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */

    // Testing mass pushing
    for (int i = 0; i < number_test_cases; i++) {
        cout << "Pushing " << ids[i] << ", " << data[i] << ": " << stack.push(ids[i], data[i]) << endl;
    }
    cout << endl;

    // Testing mass popping
    for (int i = 0; i < number_test_cases; i++) {
        cout << "Popping: " << stack.pop(&holder) << endl;
        cout << "    ID: " << holder.id << "    Information: " << holder.information << endl;
    }
    cout << endl;

    // Testing random pushing, popping, peeking and isEmpty
    int random;
    for (int i = 0; i < STACK_SIZE * 8; i++) {
        random = rand() % 4;
        if (random == 0) {
            cout << "Push:  " << stack.push(i, "barnacles") << endl;
        }
        else if (random == 1) {
            cout << "Pop:   " << stack.pop(&holder) << "            Values: " << holder.id << "  " << holder.information << endl;
        }
        else if (random == 2) {
            cout << "Peek:  " << stack.peek(&holder) << "            Values: " << holder.id << "  " << holder.information << endl;
        }
        else {
            cout << "Empty: " << stack.isEmpty() << endl;
        }
    }
    cout << endl;

    // Testing pushing negative ids and empty strings
    // First I want to empty the stack.
    while (!stack.isEmpty()) {
        cout << "Popping: " << stack.pop(&holder) << endl;
    }
    cout << "Negative ID: -42  | String: \"see you, space cowboy...\" | Pushing: " << stack.push(-42, "see you, space cowboy...") << endl;
    cout << "Positive ID: 3985 | String: \"\"                         | Pushing: " << stack.push(3985, "") << endl;
    cout << "Negative ID: -1   | String: \"\"                         | Pushing: " << stack.push(-1, "") << endl;
    cout << "         ID: 0    | String: \" \"                        | Pushing: " << stack.push(0, " ") << endl;
    cout << "Positive ID: 30   | String: \" \"                        | Pushing: " << stack.push(30, " ") << endl;
    cout << "         ID: 0    | String: \"Ishigami\"                 | Pushing: " << stack.push(0, " ") << endl;
    cout << endl;

    return 0;
}
