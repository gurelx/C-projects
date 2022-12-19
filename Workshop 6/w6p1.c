/*
*****************************************************************************
                          Workshop - #6 (P1)
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

#define MAX_ITEMS 10

int main(void)
{
    const float MIN_INCOME = 500.00;
    const float MAX_INCOME = 400000.00;
    float income;

    int itemNum;
    double cost[MAX_ITEMS] = { 0.0 };
    int priority[MAX_ITEMS] = { 0 };
    char financeOpt[MAX_ITEMS + 1] = { 0 }; 
    char option; // Couldn't fill the char array in a for loop with strings.
    int i;
    double totalCost;

    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%f", &income);

        if (income < MIN_INCOME)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
        }
        else if (income > MAX_INCOME)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME); // Moron would be more appropriate...
        }

    } while (income > MAX_INCOME || income < MIN_INCOME);
    
    printf("\n");
    
    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemNum);

        if (itemNum < 1 || itemNum > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }

    } while (itemNum < 1 || itemNum > MAX_ITEMS);

    printf("\n");

    totalCost = 0.0;
    for ( i = 0; i < itemNum; i++)
    {
        printf("Item-%d Details:\n", i + 1);
        
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            
            if (cost[i] < 100.00)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }

        } while (cost[i] < 100.00);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);

            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }

        } while (priority[i] < 1 || priority[i] > 3);

        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &option);

            if (!(option == 'y' || option == 'n'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            else
            {
                financeOpt[i] = option;
            }

        } while (!(option == 'y' || option == 'n'));

        totalCost += cost[i];
        printf("\n");

    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < itemNum; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOpt[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}