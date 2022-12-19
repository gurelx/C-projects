/*
*****************************************************************************
                          Workshop - #8 (P1)
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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"


//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

int inputIntRange(int min, int max)
{
    char newLine = 'x';
    int value;
    int check = 0;

        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
            check = 1;
        }

        if ((value < min || value > max) && !check)
        {
            putchar('\n');
            printf("Invalid menu selection!\n");
        }
        check = 0;

    return value;
}