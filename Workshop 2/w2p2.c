/*
*****************************************************************************
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    //Prices of the shirts in $
    double sShirtDollars = 0.0;
    double mShirtDollars = 0.0;
    double lShirtDollars = 0.0;

    //Quantities, subtotals, totals etc.
    int shirtQtyPat = 0, shirtQtyTom = 0, shirtQtySal = 0;
    int subTotalPat, subTotalTom, subTotalSal;
    int totalTaxPat, totalTaxTom, totalTaxSal;
    int totalPat, totalTom, totalSal;

    //Coins without tax
    int toonie, loonie, quarter, dime, nickel, penny;
    int toonieQty, loonieQty, quarterQty, dimeQty, nickelQty, pennyQty;
    //Coins with tax
    int toonieTax, loonieTax, quarterTax, dimeTax, nickelTax, pennyTax;
    int toonieTaxQty, loonieTaxQty, quarterTaxQty, dimeTaxQty, nickelTaxQty, pennyTaxQty;

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
    scanf("%d", &shirtQtyPat);
    printf("\n");

    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &shirtQtyTom);
    printf("\n");

    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &shirtQtySal);
    printf("\n");

    //Total,sub-total,taxes---Patty
    subTotalPat = (int)(((sShirtDollars * shirtQtyPat) + .005) * 100);
    totalTaxPat = (int)((subTotalPat * TAX) + 0.5);
    totalPat = subTotalPat + totalTaxPat;

    //Total,sub-total,taxes---Tommy
    subTotalTom = (int)(((lShirtDollars * shirtQtyTom) + .005) * 100);
    totalTaxTom = (int)((subTotalTom * TAX) + 0.5);
    totalTom = subTotalTom + totalTaxTom;

    //Total,sub-total,taxes---Sally
    subTotalSal = (int)(((mShirtDollars * shirtQtySal) + .005) * 100);
    totalTaxSal = (int)((subTotalSal * TAX) + 0.5);
    totalSal = subTotalSal + totalTaxSal;

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n"
           "-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, sShirtDollars, shirtQtyPat, (subTotalPat / (double)100), (totalTaxPat / (double)100), (totalPat / (double)100));
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mShirtDollars, shirtQtySal, (subTotalSal / (double)100), (totalTaxSal / (double)100), (totalSal / (double)100));
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lShirtDollars, shirtQtyTom, (subTotalTom / (double)100), (totalTaxTom / (double)100), (totalTom / (double)100));
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", (((double)(subTotalPat + subTotalSal + subTotalTom)) / 100), (((double)(totalTaxPat + totalTaxSal + totalTaxTom)) / 100), (((double)(totalPat + totalSal + totalTom)) / 100));
    
    //Remainders without tax
    toonieQty = (subTotalPat + subTotalSal + subTotalTom) / 200;
    toonie = (subTotalPat + subTotalSal + subTotalTom) % 200;

    loonieQty = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200)) / 100;
    loonie = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200)) % 100;

    quarterQty = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100)) / 25;
    quarter = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100)) % 25;

    dimeQty = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25)) / 10;
    dime = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25)) % 10;

    nickelQty = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25) - (dimeQty * 10)) / 5;
    nickel = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25) - (dimeQty * 10)) % 5;

    pennyQty = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25) - (dimeQty * 10) - (nickelQty * 5)) / 1;
    penny = ((subTotalPat + subTotalSal + subTotalTom) - (toonieQty * 200) - (loonieQty * 100) - (quarterQty * 25) - (dimeQty * 10) - (nickelQty * 5)) % 1;

    printf("Daily retail sales represented by coins\n"     
           "=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n"
           "-------- --- ---------\n");
    printf("%22.4lf\n", (((double)(subTotalPat + subTotalSal + subTotalTom)) / 100));
    printf("Toonies  %3d %9.4lf\n", toonieQty, toonie / 100.0);
    printf("Loonies  %3d %9.4lf\n", loonieQty, loonie / 100.0);
    printf("Quarters %3d %9.4lf\n", quarterQty, quarter / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimeQty, dime / 100.0);
    printf("Nickels  %3d %9.4lf\n", nickelQty, nickel / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", pennyQty, penny / 100.0);

    printf("Average cost/shirt: $%.4lf\n\n", (subTotalPat + subTotalSal + subTotalTom) / (double)100 / (shirtQtyPat + shirtQtySal + shirtQtyTom));

    //Remainders with tax
    toonieTaxQty = (totalPat + totalSal + totalTom) / 200;
    toonieTax = (totalPat + totalSal + totalTom) % 200;

    loonieTaxQty = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200)) / 100;
    loonieTax = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200)) % 100;

    quarterTaxQty = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100)) / 25;
    quarterTax = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100)) % 25;

    dimeTaxQty = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25)) / 10;
    dimeTax = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25)) % 10;

    nickelTaxQty = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25) - (dimeTaxQty * 10)) / 5;
    nickelTax = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25) - (dimeTaxQty * 10)) % 5;

    pennyTaxQty = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25) - (dimeTaxQty * 10) - (nickelTaxQty * 5)) / 1;
    pennyTax = ((totalPat + totalSal + totalTom) - (toonieTaxQty * 200) - (loonieTaxQty * 100) - (quarterTaxQty * 25) - (dimeTaxQty * 10) - (nickelTaxQty * 5)) % 1;

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n"
           "-------- --- ---------\n");
    printf("%22.4lf\n", (((double)(totalPat + totalSal + totalTom)) / 100));
    printf("Toonies  %3d %9.4lf\n", toonieTaxQty, toonieTax / 100.0);
    printf("Loonies  %3d %9.4lf\n", loonieTaxQty, loonieTax / 100.0);
    printf("Quarters %3d %9.4lf\n", quarterTaxQty, quarterTax / 100.0);
    printf("Dimes    %3d %9.4lf\n", dimeTaxQty, dimeTax / 100.0);
    printf("Nickels  %3d %9.4lf\n", nickelTaxQty, nickelTax / 100.0);
    printf("Pennies  %3d %9.4lf\n\n", pennyTaxQty, pennyTax / 100.0);

    printf("Average cost/shirt: $%.4lf\n", (totalPat + totalSal + totalTom) / (double)100 / (shirtQtyPat + shirtQtySal + shirtQtyTom));
    
    return 0;
}