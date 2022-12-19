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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument);;

int getIntPositive(int* wholeNum)
{	
	int valueInteger;
	do
	{
		scanf("%d", &valueInteger);
		if (valueInteger < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (valueInteger < 1);

	if (wholeNum != NULL)
	{
		*wholeNum = valueInteger;
	}
	
		return valueInteger;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* decimalNum)
{
	double valueDecimal;
	do
	{
		scanf("%lf", &valueDecimal);
		if (valueDecimal < 1)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (valueDecimal < 1);

	if (decimalNum != NULL)
	{
		*decimalNum = valueDecimal;
	}

	return valueDecimal;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int products)
{
	
	printf("Cat Food Cost Analysis\n"
		"======================\n\n"

		"Enter the details for %d dry food bags of product data for analysis.\n"
		"NOTE: A 'serving' is %dg\n\n", products, SERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence)
{

	struct CatFoodInfo productInfo = { 0 };

	printf("Cat Food Product #%d\n"
		"--------------------\n", sequence);

	printf("SKU           : ");
	getIntPositive(&productInfo.sku);

	printf("PRICE         : $");
	getDoublePositive(&productInfo.price);

	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&productInfo.weight);

	printf("CALORIES/SERV.: ");
	getIntPositive(&productInfo.calories);

	printf("\n");

	return productInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight)
{

	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);
	
}


// 7. Logic entry point
void start()
{
	struct CatFoodInfo products[MAX_PRODUCTS] = { {0} };

	const int productNum = 3;

	openingMessage(productNum);

	int i;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		products[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();

	for ( i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(products[i].sku, &products[i].price, products[i].calories, &products[i].weight);
	}

}