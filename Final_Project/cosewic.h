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

#ifndef COSEWIC_H
#define COSEWIC_H

#define MAX_RECORDS 6500
#define MAX_YEAR 2019
#define MIN_YEAR 2010

// C Strings: array sizes
#define MAX_TAXON_LEN 15
#define MAX_STATUS_LEN 15
#define MAX_PROVINCE_LEN 2

//////////////////////////////////////
// Structures
//////////////////////////////////////

struct FileData
{
	int year;
	char taxons[MAX_TAXON_LEN + 1];
	char status[MAX_STATUS_LEN + 1];
	int count;
	char province[MAX_PROVINCE_LEN + 1];
};


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Entry point to application
void mainLogic(struct FileData data[], int records);

// Menu for selectng provinces
char* provinceMenu(void);

// Menu for selectng taxons
char* taxonMenu(void);


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display table header for different filters
void displayTableHeader(int selection);

// Display total by status
void displayTotals(struct FileData data[], int max);

// Display by year
void viewByYear(struct FileData data[], int max);

// Display for only one year
void displayOneYear(struct FileData data[], int year, int max);

//Display by province
void viewByProvince(struct FileData data[], int max);

// Display for only one provimce
void displayOneProvince(struct FileData data[], char province[MAX_PROVINCE_LEN + 1], int max);

// Display by taxons
void viewByTaxon(struct FileData data[], int max);

// Display for only one taxon
void displayOneTaxon(struct FileData data[], char taxon[MAX_TAXON_LEN + 1], int max);

// Filtering by province and taxon
void displayByProvinceAndTaxon(struct FileData data[], int max);


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import data from the txt
int loadData(const char* datafile, struct FileData data[], int max);


#endif // !COSEWIC_H