/*
*****************************************************************************
                          Workshop - #4 (P1)
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

int main(void)
{
    int iterationNum = 0;
    int i = 0;  //for the loops
    char loopType = 'a';

    printf("+----------------------+\n"
           "Loop application STARTED\n"
           "+----------------------+\n\n");
    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &iterationNum);
        
        if (loopType == 'D')
        {
            if (iterationNum >= 3 && iterationNum <= 20)
            {
                printf("DO-WHILE: ");

                do
                {
                    i++;
                    printf("%c", loopType);

                } while (i < iterationNum);

                i = 0;
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (loopType == 'W')
        {
            if (iterationNum >= 3 && iterationNum <= 20)
            {
                printf("WHILE   : ");

                while (i < iterationNum)
                {
                    i++;
                    printf("%c", loopType);
                }
                
                i = 0;
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (loopType == 'F')
        {
            if (iterationNum >= 3 && iterationNum <= 20)
            {
                printf("FOR     : ");

                for (i = 0; i < iterationNum; i++)
                {
                    printf("%c", loopType);
                }
                
                i = 0;
                printf("\n\n");
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }

        else if (loopType == 'Q')
        {
            if (iterationNum != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
        }

        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

    } while (!(loopType == 'Q' && iterationNum == 0));

      printf("\n");
      printf("+--------------------+\n"
             "Loop application ENDED\n"
             "+--------------------+\n");

    return 0;
}