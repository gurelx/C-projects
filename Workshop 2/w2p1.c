/*
*****************************************************************************
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';

    //Prices of the shirts in $
    double sShirtDollars = 0.0;
    double mShirtDollars = 0.0;
    double lShirtDollars = 0.0;

    int shirtQty = 0;
    int subTotal, totalTax;

    printf("Set Shirt Prices\n"
           "================\n");
    
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &sShirtDollars);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &mShirtDollars);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &lShirtDollars);
    printf("\n");
    

    printf("Shirt Store Price List\n"
           "======================\n");

    printf("SMALL  : $%.2lf\n", sShirtDollars);
    printf("MEDIUM : $%.2lf\n", mShirtDollars);
    printf("LARGE  : $%.2lf\n\n", lShirtDollars);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtQty);
    printf("\n");

    //Total,sub-total,taxes
    subTotal = (int)(((sShirtDollars * shirtQty) + .005) * 100);
    totalTax = (int)((subTotal * TAX) + 0.5);

    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", shirtQty);
    printf("Sub-total: $%8.4lf\n", subTotal / (double)100);
    printf("Taxes    : $%8.4lf\n", totalTax / (double)100);
    printf("Total    : $%8.4lf\n", ((subTotal + totalTax) / (double)100));

    return 0;
}
