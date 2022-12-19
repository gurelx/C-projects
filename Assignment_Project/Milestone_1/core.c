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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "core.h"

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

int inputInt(void)
{
    char newLine = 'x';
    int value;

    do
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }

    } while (newLine != '\n');

    return value;

}

int inputIntPositive(void)
{
    int value = 0;

    do
    {
        scanf("%d", &value);
        if (value < 1)
        {
            printf("ERROR! Value must be > 0: ");
            clearInputBuffer();
        }

    } while (value < 1);

    return value;
}

int inputIntRange(int min, int max)
{
    char newLine = 'x';
    int value;
    int check = 0;

    do
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
            check = 1;
        }
        
        if ((value < min || value > max) && !check)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
        }
        check = 0;

    } while (value < min || value > max);

    return value;
}

char inputCharOption(const char validChars[])
{
    char character;
    int check;
    int i;

    do
    {
        scanf(" %c", &character);

        check = 0;
        for ( i = 0; validChars[i] != '\0'; i++)
        {
            if (character == validChars[i])
            {
                check = 1;
            }
        }

        if (check == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
    } while (!check);

    return character;

}

void inputCString(char* str, int min, int max)
{
    int i = 0;
    char arr[MAX_STRING_INPUT] = { 0 };
 
    do
    {
        arr[0] = '\0';
        scanf(" %6[^\n]%[^\n]", str, arr); // Store the excess chars (chicke + n) to another arr to prevent overflow error

        for (i = 0; str[i] != '\0'; i++);


        if ((max == min) && ((i != max) || (arr[0] != '\0')))
        {
            printf("ERROR: String length must be exactly %d chars: ", max);
       
        }
        
        if ((max != min) && (arr[0] != '\0'))
        {
            printf("ERROR: String length must be no more than %d chars: ", max);
       
        }
        
        if ((max != min) && (i < min))
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
       
        }


    } while (arr[0] != '\0' || i < min);

    
}

void displayFormattedPhone(char* str)
{
    int i = 0;
    int check = 0;


    if (str == NULL)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] < '0' || str[i] > '9')
            {
                check = 1;
            }
        }

        if (i != 10 || check)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%.3s)", str);
            printf("%c%c%c-%c%c%c%c", str[3], str[4], str[5], str[6], str[7], str[8], str[9]);
        }
        
    }
    check = 0;         
}