/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    // Declare apples, oranges, pears, tomatoes, cabbages, keepshopping
    int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
    int pickCount;
    int keepShopping = 0;
    
    
    do
    {
        printf("Grocery Shopping\n"
               "================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf(" %d", &apples);

            if (apples < 0)
            { 
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (apples < 0);

        do
        {
            printf("How many ORANGES do you need? : ");
            scanf(" %d", &oranges);

            if (oranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (oranges < 0);

        do
        {
            printf("How many PEARS do you need? : ");
            scanf(" %d", &pears);

            if (pears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (pears < 0);

        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf(" %d", &tomatoes);

            if (tomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (tomatoes < 0);

        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf(" %d", &cabbages);

            if (cabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            else
            {
                printf("\n");
            }
        } while (cabbages < 0);



        printf("--------------------------\n"
               "Time to pick the products!\n"
               "--------------------------\n\n");

        
        if (apples > 0)
        {
            do
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf(" %d", &pickCount);

                if (pickCount < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCount > apples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
                }
                else if (pickCount < apples)
                {
                    printf("Looks like we still need some APPLES...\n");
                    apples -= pickCount;
                    pickCount = 0;
                }
            } while (pickCount != apples);
            
            printf("Great, that's the apples done!\n\n");
        }

        if (oranges > 0)
        {
            do
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf(" %d", &pickCount);

                if (pickCount < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCount > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
                }
                else if (pickCount < oranges)
                {
                    printf("Looks like we still need some ORANGES...\n");
                    oranges -= pickCount;
                    pickCount = 0;
                }
            } while (pickCount != oranges);

            printf("Great, that's the oranges done!\n\n");

        }

        if (pears > 0)
        {
            do
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf(" %d", &pickCount);

                if (pickCount < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCount > pears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
                }
                else if (pickCount < pears)
                {
                    printf("Looks like we still need some PEARS...\n");
                    pears -= pickCount;
                    pickCount = 0;
                }
            } while (pickCount != pears);

            printf("Great, that's the pears done!\n\n");

        }

        if (tomatoes > 0)
        {
            do
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf(" %d", &pickCount);

                if (pickCount < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCount > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
                }
                else if (pickCount < tomatoes)
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    tomatoes -= pickCount;
                    pickCount = 0;
                }
            } while (pickCount != tomatoes);

            printf("Great, that's the tomatoes done!\n\n");

        }

        if (cabbages > 0)
        {
            do
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf(" %d", &pickCount);

                if (pickCount < 1)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (pickCount > cabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
                }
                else if (pickCount < cabbages)
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    cabbages -= pickCount;
                    pickCount = 0;
                }
            } while (pickCount != cabbages);

            printf("Great, that's the cabbages done!\n\n");

        }

        printf("All the items are picked!\n\n"
               "Do another shopping? (0=NO): ");
        scanf(" %d", &keepShopping);
        printf("\n");

    } while (keepShopping);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
