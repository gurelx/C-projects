/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Gurel Sezgin
Student ID#: 174331215
Email      : gurel-sezgin@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #1 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// I had to define a constant to size the strings in the first place, because if you enter 'horse' (5 chars) before 'chicken' (7 chars) it sizes accordingly and overflows
#define MAX_STRING_INPUT 100 

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// Return an integer value
int inputInt(void);

// Return a positive integer value
int inputIntPositive(void);

// Return an integer between specified range
int inputIntRange(int min, int max);

// Return a char between valid chars
char inputCharOption(const char validChars[]);

// Return a string between max and min char numbers
void inputCString(char* str, int min, int max);

// Display 10 digit phone number
void displayFormattedPhone(const char* str);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////














// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
