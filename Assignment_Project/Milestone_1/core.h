/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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

// I had to define a constant to size the strings in the first place, because if you enter 'horse' (5 chars) before 'chicken' (7 chars) it sizes accordingly and overflows
#define MAX_STRING_INPUT 100 

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int min, int max);

char inputCharOption(const char validChars[]);

void inputCString(char* str, int min, int max);

void displayFormattedPhone(char * str);
