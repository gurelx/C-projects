/*
*****************************************************************************
                          Workshop - #6 (P2)
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
    char financeOptions[MAX_ITEMS] = { 0 };
    char option;
    int i;
    double totalCost, amount;
    int selection, priorityFilter, financeNote;

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
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME); 
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

    totalCost = 0.0f;
    for (i = 0; i < itemNum; i++)
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
                financeOptions[i] = option;
            }

        } while (!(option == 'y' || option == 'n'));

        totalCost += cost[i];
        printf("\n");

    }

    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    for (i = 0; i < itemNum; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOptions[i], cost[i]);
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    do
    {
        do
        {
            printf("How do you want to forecast your wish list?\n"
                " 1. All items (no filter)\n"
                " 2. By priority\n"
                " 0. Quit/Exit\n"
                "Selection: ");
            scanf("%d", &selection);

            if (selection > 2)
            {
                printf("\n");
                printf("ERROR: Invalid menu selection.\n\n");
            }
            else
            {
                printf("\n");
            }
        } while (selection > 2);

        amount = 0.0f;     // I reset the values for the next cases
        financeNote = 0;
        if (selection == 1)
        {
            amount = totalCost;

            for ( i = 0; i < itemNum; i++)
            {
                if (financeOptions[i] == 'y')
                {
                    financeNote = 1;
                }
            }
      
        }
        else if (selection == 2)
        {
            do
            { 
                printf("What priority do you want to filter by? [1-3]: ");
                scanf("%d", &priorityFilter);
                printf("\n");

            } while (priorityFilter < 1 || priorityFilter > 3);

            amount = 0.0f;
            financeNote = 0;
            for (i = 0; i < itemNum; i++)
            {
                if (priority[i] == priorityFilter)
                {
                    amount += cost[i];
                }

                if (priority[i] == priorityFilter && financeOptions[i] == 'y')
                {
                    financeNote = 1;
                }
            }
        }

        if (selection)
        {
            printf("====================================================\n");
            printf("Filter:");

            if (selection == 1)
            {
                printf("   All items\n");

            }
            else
            {
                printf("   by priority (%d)\n", priorityFilter);
            }

            printf("Amount:   $%1.2lf\n", amount);
            printf("Forecast: %d years, %d months\n", (int)((amount / income) / 12), ((int)(amount / income) % 12) + 1);

            if (financeNote)
            {
                printf("NOTE: Financing options are available on some items.\n"
                       "      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n\n");
        }

    } while (selection);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}