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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "cosewic" where the function prototypes are declared
#include "cosewic.h"


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Entry point to application
void mainLogic(struct FileData data[], int records)
{
    int selection;

    do {
        printf("=======================================================\n"
            "         Canada Species at Risk Analysis\n"
            "            (Data Years: 2010 - 2019)\n"
            "=======================================================\n"
            "1. View by year (sorted ASCENDING by year)\n"
            "2. View by province (sorted DESCENDING by totals)\n"
            "3. View by taxon (sorted ASCENDING by totals)\n"
            "4. View by province and taxon\n"
            "-------------------------------------------------------\n"
            "0. Exit\n"
            "-------------------------------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 0:
            putchar('\n');
            if (!selection)
            {
                printf("Application Terminated!\n\n");
            }
            break;
        case 1:
            viewByYear(data, MAX_RECORDS);
            break;
        case 2:
            viewByProvince(data, MAX_RECORDS);
            break;
        case 3:
            viewByTaxon(data, MAX_RECORDS);
            break;
        case 4:
            displayByProvinceAndTaxon(data, MAX_RECORDS);
            break;
        }
    } while (selection);
}

// Menu for selectng provinces
char* provinceMenu(void)
{
    int selection = 0;
    char* province = { 0 };

    do
    {
        printf("Choose a Province\n"
            "----------------------------------\n"
            " 1) AB (Alberta)\n"
            " 2) BC (British Columbia)\n"
            " 3) MB (Manitoba)\n"
            " 4) NB (New Brunswick)\n"
            " 5) NL (Newfoundland)\n"
            " 6) NS (Nova Scotia)\n"
            " 7) NT (Northwest Territories)\n"
            " 8) NU (Nunavut)\n"
            " 9) ON (Ontario)\n"
            "10) PE (Prince Edward Island)\n"
            "11) QC (Quebec)\n"
            "12) SK (Saskatchewan)\n"
            "13) YT (Yukon Territory)\n"
            "Selection: ");

        selection = inputIntRange(1, 13);
        putchar('\n');

        switch (selection)
        {
        case 1:
            province = "AB";
            break;
        case 2:
            province = "BC";
            break;
        case 3:
            province = "MB";
            break;
        case 4:
            province = "NB";
            break;
        case 5:
            province = "NL";
            break;
        case 6:
            province = "NS";
            break;
        case 7:
            province = "NT";
            break;
        case 8:
            province = "NU";
            break;
        case 9:
            province = "ON";
            break;
        case 10:
            province = "PE";
            break;
        case 11:
            province = "QC";
            break;
        case 12:
            province = "SK";
            break;
        case 13:
            province = "YT";
            break;
        }

    } while (selection < 1 || selection > 13);

    return province;
}

// Menu for selectng taxons
char* taxonMenu(void)
{
    int selection;
    char* taxon = {0};

    do
    {
        printf("Choose a Taxon\n"
            "---------------\n"
            " 1) Mammals\n"
            " 2) Birds\n"
            " 3) Reptiles\n"
            " 4) Amphibians\n"
            " 5) Fishes\n"
            " 6) Arthropods\n"
            " 7) Molluscs\n"
            " 8) Vascular Plants\n"
            " 9) Mosses\n"
            "10) Lichens\n"
            "Selection: ");

        selection = inputIntRange(1, 10);
        putchar('\n');
   
        switch (selection)
        {
        case 1:
            taxon = "Mammals";
            break;
        case 2:
            taxon = "Birds";
            break;
        case 3:
            taxon = "Reptiles";
            break;
        case 4:
            taxon = "Amphibians";
            break;
        case 5:
            taxon = "Fishes";
            break;
        case 6:
            taxon = "Arthropods";
            break;
        case 7:
            taxon = "Molluscs";
            break;
        case 8:
            taxon = "Vascular Plants";
            break;
        case 9:
            taxon = "Mosses";
            break;
        case 10:
            taxon = "Lichens";
            break;
        }

    } while (selection < 1 || selection > 10);

    return taxon;
}

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display table header for different filters
void displayTableHeader(int selection)
{
    // For sorting by year
    if (selection == 1)
    {
        printf("YEAR EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n"
            "---- ------- ---------- ---------- ---------- ------- ---------\n");
    }
    // For sorting by province
    else if (selection == 2)
    {
        printf("PROVINCE             EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n"
            "-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    }
    // For sorting by taxon
    else if (selection == 3)
    {
        printf("TAXON           EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n"
            "--------------- ------- ---------- ---------- ---------- ------- ---------\n");
    }
    // For sorting by province and taxon
    else if (selection == 4)
    {
        printf("EXTINCT EXTIRPATED ENDANGERED THREATENED CONCERN     TOTAL\n"
            "------- ---------- ---------- ---------- ------- ---------\n");
    }
}

// Display total by status
void displayTotals(struct FileData data[], int max)
{
    int i;
    int extinct = 0, extirpated = 0, endangered = 0, threatened = 0, concern = 0, total = 0;

    for (i = 0; i < max; i++)
    {
        if (!strcmp(data[i].status, "EXTINCT"))
        {
            extinct++;
        }
        else if (!strcmp(data[i].status, "EXTIRPATED"))
        {
            extirpated++;
        }
        else if (!strcmp(data[i].status, "ENDANGERED"))
        {
            endangered++;
        }
        else if (!strcmp(data[i].status, "THREATENED"))
        {
            threatened++;
        }
        else if (!strcmp(data[i].status, "SPECIAL CONCERN"))
        {
            concern++;
        }
    }

    total = extinct + extirpated + endangered + threatened + concern;
    printf("%7d%11d%11d%11d%8d%10d\n", extinct, extirpated, endangered, threatened, concern, total);
}

// Display by year
void viewByYear(struct FileData data[], int max)
{
    int i;
    displayTableHeader(1);
    for ( i = MIN_YEAR; i < MAX_YEAR + 1; i++)
    {
        displayOneYear(data, i, MAX_RECORDS);
    }
    printf("     ------- ---------- ---------- ---------- ------- ---------\n");
    printf("     ");
    displayTotals(data, MAX_RECORDS);
    putchar('\n');
}

// Display for only one year
void displayOneYear(struct FileData data[], int year, int max)
{
    int i;
    int extinct = 0, extirpated = 0, endangered = 0, threatened = 0, concern = 0, total = 0;

    
    for (i = 0; i < max; i++)
    {
        if (data[i].year == year)
        {
            if (!strcmp(data[i].status, "EXTINCT"))
            {
                extinct++;
            }
            else if (!strcmp(data[i].status, "EXTIRPATED"))
            {
                extirpated++;
            }
            else if (!strcmp(data[i].status, "ENDANGERED"))
            {
                endangered++;
            }
            else if (!strcmp(data[i].status, "THREATENED"))
            {
                threatened++;
            }
            else
            {
                concern++;
            }
        }
    }
    total = extinct + extirpated + endangered + threatened + concern;
    printf("%d%8d%11d%11d%11d%8d%10d\n", year, extinct, extirpated, endangered, threatened, concern, total);
}

//Display by province
void viewByProvince(struct FileData data[], int max)
{
    displayTableHeader(2);
    displayOneProvince(data, "ON", MAX_RECORDS);
    displayOneProvince(data, "NU", MAX_RECORDS);
    displayOneProvince(data, "MB", MAX_RECORDS);
    displayOneProvince(data, "YT", MAX_RECORDS);
    displayOneProvince(data, "NB", MAX_RECORDS);
    displayOneProvince(data, "QC", MAX_RECORDS);
    displayOneProvince(data, "SK", MAX_RECORDS);
    displayOneProvince(data, "NS", MAX_RECORDS);
    displayOneProvince(data, "NL", MAX_RECORDS);
    displayOneProvince(data, "AB", MAX_RECORDS);
    displayOneProvince(data, "PE", MAX_RECORDS);
    displayOneProvince(data, "BC", MAX_RECORDS);
    displayOneProvince(data, "NT", MAX_RECORDS);
    printf("-------------------- ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                     ");
    displayTotals(data, MAX_RECORDS);
    putchar('\n');
}

// Display for only one provimce
void displayOneProvince(struct FileData data[], char province[MAX_PROVINCE_LEN+1], int max)
{
    char *provinceName ={0};
    int i;
    int extinct = 0, extirpated = 0, endangered = 0, threatened = 0, concern = 0, total = 0;


    for (i = 0; i < max; i++)
    {
        if (!strcmp(data[i].province, province))
        {
            if (!strcmp(data[i].status, "EXTINCT"))
            {
                extinct++;
            }
            else if (!strcmp(data[i].status, "EXTIRPATED"))
            {
                extirpated++;
            }
            else if (!strcmp(data[i].status, "ENDANGERED"))
            {
                endangered++;
            }
            else if (!strcmp(data[i].status, "THREATENED"))
            {
                threatened++;
            }
            else
            {
                concern++;
            }
        }
    }
    
    // Mapping each province code to its full name
    if (province == "ON")
    {
        provinceName = "Ontario";
    }
    else if (province == "NU")
    {
        provinceName = "Nunavut";
    }
    else if (province == "MB")
    {
        provinceName = "Manitoba";
    }
    else if (province == "YT")
    {
        provinceName = "Yukon Territory";
    }
    else if (province == "NB")
    {
        provinceName = "New Brunswick";
    }
    else if (province == "QC")
    {
        provinceName = "Quebec";
    }
    else if (province == "SK")
    {
        provinceName = "Saskatchewan";
    }
    else if (province == "NS")
    {
        provinceName = "Nova Scotia";
    }
    else if (province == "NL")
    {
        provinceName = "Newfoundland";
    }
    else if (province == "AB")
    {
        provinceName = "Alberta";
    }
    else if (province == "PE")
    {
        provinceName = "Prince Edward Island";
    }
    else if (province == "BC")
    {
        provinceName = "British Columbia";
    }
    else
    {
        provinceName = "Northwest Territory";
    }

    total = extinct + extirpated + endangered + threatened + concern;
    printf("%-20s%8d%11d%11d%11d%8d%10d\n", provinceName, extinct, extirpated, endangered, threatened, concern, total);
}

void viewByTaxon(struct FileData data[], int max)
{
    displayTableHeader(3);
    displayOneTaxon(data, "Molluscs", MAX_RECORDS);
    displayOneTaxon(data, "Lichens", MAX_RECORDS);
    displayOneTaxon(data, "Amphibians", MAX_RECORDS);
    displayOneTaxon(data, "Vascular Plants", MAX_RECORDS);
    displayOneTaxon(data, "Reptiles", MAX_RECORDS);
    displayOneTaxon(data, "Mammals", MAX_RECORDS);
    displayOneTaxon(data, "Arthropods", MAX_RECORDS);
    displayOneTaxon(data, "Mosses", MAX_RECORDS);
    displayOneTaxon(data, "Birds", MAX_RECORDS);
    displayOneTaxon(data, "Fishes", MAX_RECORDS);

    printf("--------------- ------- ---------- ---------- ---------- ------- ---------\n");
    printf("                ");
    displayTotals(data, MAX_RECORDS);
    putchar('\n');
}

// Display for only one taxon
void displayOneTaxon(struct FileData data[], char taxon[MAX_TAXON_LEN + 1], int max)
{
    int i;
    int extinct = 0, extirpated = 0, endangered = 0, threatened = 0, concern = 0, total = 0;

    for (i = 0; i < max; i++)
    {
        if (!strcmp(data[i].taxons, taxon))
        {
            if (!strcmp(data[i].status, "EXTINCT"))
            {
                extinct++;
            }
            else if (!strcmp(data[i].status, "EXTIRPATED"))
            {
                extirpated++;
            }
            else if (!strcmp(data[i].status, "ENDANGERED"))
            {
                endangered++;
            }
            else if (!strcmp(data[i].status, "THREATENED"))
            {
                threatened++;
            }
            else
            {
                concern++;
            }
        }
    }

    total = extinct + extirpated + endangered + threatened + concern;
    printf("%-15s%8d%11d%11d%11d%8d%10d\n", taxon, extinct, extirpated, endangered, threatened, concern, total);
}

// Filtering by province and taxon
void displayByProvinceAndTaxon(struct FileData data[], int max)
{
    int i, extinct = 0, extirpated = 0, endangered = 0, threatened = 0, concern = 0, total = 0;

    char* provinceName = { 0 };
    char* province = provinceMenu();
    char* taxon = taxonMenu();

    for (i = 0; i < max; i++)
    {

        if (!strcmp(data[i].taxons, taxon) && !strcmp(data[i].province, province))
        {
            if (!strcmp(data[i].status, "EXTINCT"))
            {
                extinct++;
            }
            else if (!strcmp(data[i].status, "EXTIRPATED"))
            {
                extirpated++;
            }
            else if (!strcmp(data[i].status, "ENDANGERED"))
            {
                endangered++;
            }
            else if (!strcmp(data[i].status, "THREATENED"))
            {
                threatened++;
            }
            else
            {
                concern++;
            }
        }
    }

    if (province == "ON")
    {
        provinceName = "Ontario";
    }
    else if (province == "NU")
    {
        provinceName = "Nunavut";
    }
    else if (province == "MB")
    {
        provinceName = "Manitoba";
    }
    else if (province == "YT")
    {
        provinceName = "Yukon Territory";
    }
    else if (province == "NB")
    {
        provinceName = "New Brunswick";
    }
    else if (province == "QC")
    {
        provinceName = "Quebec";
    }
    else if (province == "SK")
    {
        provinceName = "Saskatchewan";
    }
    else if (province == "NS")
    {
        provinceName = "Nova Scotia";
    }
    else if (province == "NL")
    {
        provinceName = "Newfoundland";
    }
    else if (province == "AB")
    {
        provinceName = "Alberta";
    }
    else if (province == "PE")
    {
        provinceName = "Prince Edward Island";
    }
    else if (province == "BC")
    {
        provinceName = "British Columbia";
    }
    else
    {
        provinceName = "Northwest Territory";
    }

    total = extinct + extirpated + endangered + threatened + concern;



    printf("*** Data filtered by PROVINCE and TAXON ***\n\n"
        "    Province: %s\n"
        "    Taxon   : %s\n\n", provinceName, taxon);

    displayTableHeader(4);
    printf("%7d%11d%11d%11d%8d%10d\n", extinct, extirpated, endangered, threatened, concern, total);
    putchar('\n');
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import data from the txt
int loadData(const char* datafile, struct FileData data[], int max)
{
    int i = 0;
    FILE* fp = fopen(datafile, "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }
    else
    {
        while (i < max && fscanf(fp, "\n%d,%15[^,],%15[^,],%d,%2[^\n]\n", &data[i].year,
            data[i].taxons, data[i].status, &data[i].count, data[i].province) == 5)
        {
            i++;
        }

        fclose(fp);
        return i;
    }
}
