/*
*****************************************************************************
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    int year, month;
    const int JAN = 1, DEC = 12; //Instructions step 4

    printf("General Well-being Log\n"
           "======================\n");
    do 
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year > MAX_YEAR || year < MIN_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        
    } while ((year > MAX_YEAR || year < MIN_YEAR) || (month < JAN || month > DEC));

    printf("\n");
    printf("*** Log date set! ***\n\n"
           "Log starting date: ");

    if (month == JAN)
    {
        printf("%d-JAN-01\n", year);
    }
    else if (month == 2)
    {
        printf("%d-FEB-01\n", year);
    }
    else if (month == 3)
    {
        printf("%d-MAR-01\n", year);
    }
    else if (month == 4)
    {
        printf("%d-APR-01\n", year);
    }
    else if (month == 5)
    {
        printf("%d-MAY-01\n", year);
    }
    else if (month == 6)
    {
        printf("%d-JUN-01\n", year);
    }
    else if (month == 7)
    {
        printf("%d-JUL-01\n", year);
    }
    else if (month == 8)
    {
        printf("%d-AUG-01\n", year);
    }
    else if (month == 9)
    {
        printf("%d-SEP-01\n", year);
    }
    else if (month == 10)
    {
        printf("%d-OCT-01\n", year);
    }
    else if (month == 11)
    {
        printf("%d-NOV-01\n", year);
    }
    else
    {
        printf("%d-DEC-01\n", year);
    }
   
    return 0;

}