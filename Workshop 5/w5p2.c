/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
#define MIN_RATING 0.0
#define MAX_RATING 5.0

int main(void)
{
    int year, month, day;
    const int JAN = 1, DEC = 12; //Instructions step 4
    int i;
    double morningRating, eveningRating, morningSum, eveningSum;

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
    printf("*** Log date set! ***\n\n");

    day = 1;          
    eveningSum = 0.0; 
    morningSum = 0.0;

    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("%d-", year);
        if (month == JAN)
        {
            printf("JAN");
        }
        else if (month == 2)
        {
            printf("FEB");
        }
        else if (month == 3)
        {
            printf("MAR");
        }
        else if (month == 4)
        {
            printf("APR");
        }
        else if (month == 5)
        {
            printf("MAY");
        }
        else if (month == 6)
        {
            printf("JUN");
        }
        else if (month == 7)
        {
            printf("JUL");
        }
        else if (month == 8)
        {
            printf("AUG");
        }
        else if (month == 9)
        {
            printf("SEP");
        }
        else if (month == 10)
        {
            printf("OCT");
        }
        else if (month == 11)
        {
            printf("NOV");
        }
        else
        {
            printf("DEC");
        }
        printf("-0%d\n", day);

        do
        {
            printf("   Morning rating (%.1f-%.1f): ", MIN_RATING, MAX_RATING);
            scanf("%lf", &morningRating);

            if (morningRating > MAX_RATING || morningRating < MIN_RATING)
            {
                printf("      ERROR: Rating must be between %.1f and %.1f inclusive!\n", MIN_RATING, MAX_RATING);
            }

        } while (morningRating > MAX_RATING || morningRating < MIN_RATING);

        do
        {
            printf("   Evening rating (%.1f-%.1f): ", MIN_RATING, MAX_RATING);
            scanf("%lf", &eveningRating);

            if (eveningRating > MAX_RATING || eveningRating < MIN_RATING)
            {
                printf("      ERROR: Rating must be between %.1f and %.1f inclusive!\n", MIN_RATING, MAX_RATING);
            }

        } while (eveningRating > MAX_RATING || eveningRating < MIN_RATING);

        eveningSum += eveningRating;
        morningSum += morningRating;
        day++;
        printf("\n");
    }

    printf("Summary\n"
           "=======\n");
    printf("Morning total rating: %.3lf\n", morningSum);
    printf("Evening total rating:  %.3lf\n", eveningSum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningSum + eveningSum);

    printf("Average morning rating:  %.1lf\n", morningSum / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", eveningSum / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (morningSum + eveningSum) / (LOG_DAYS * 2));

    return 0;
}