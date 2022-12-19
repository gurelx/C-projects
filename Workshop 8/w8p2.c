/*
*****************************************************************************
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* equalKg)
{
	double kg;

	kg = *pounds / LBS_IN_KG;

	if (equalKg != NULL)
	{
		*equalKg = kg;
	}

	return kg;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* equalGrams)
{
	int g;

	g = (*pounds / LBS_IN_KG) * 1000;

	if (equalGrams != NULL)
	{
		*equalGrams = g;
	}

	return g;
}

// 10. convert lbs: kg and g
void convertLbs(const double* pounds, double* equalKg, int* equalGrams)
{
	convertLbsKg(pounds, equalKg);
	convertLbsG(pounds, equalGrams);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servings, const int grams, double* servingsNum)
{
	double total;
	total = (double) grams / servings;

	if (servingsNum != NULL)
	{
		*servingsNum = total;
	}

	return total;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double price, const double servings, double* costPerServing)
{
	double cost;
	cost = price / servings;

	if (costPerServing != NULL)
	{
		*costPerServing = cost;
	}

	return cost;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double price, const double totalCalories, double* costPerCal)
{
	double cost;
	cost = price / totalCalories;

	if (costPerCal != NULL)
	{
		*costPerCal = cost;
	}

	return cost;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo item)
{
	struct ReportData data;
	int* equalizerInt = 0;
	double* equalizerDouble = 0; // If I don't seperate pointers by type matrix compiler gives error. 

	data.sku = item.sku;
	data.price = item.price;
	data.calories = item.calories;
	data.weightLbs = item.weight;

	data.weightKg = convertLbsKg(&data.weightLbs, equalizerDouble);
	data.grams = convertLbsG(&data.weightLbs, equalizerInt);
	data.servings = calculateServings(SERVING, data.grams, equalizerDouble);
	data.costPerServing = calculateCostPerServing(data.price, data.servings, equalizerDouble);
	data.caloriesPerServing = calculateCostPerCal(data.price, data.calories * data.servings, equalizerDouble);

	return data;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData display, const int cheapOption)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", display.sku, display.price, display.weightLbs,
		display.weightKg, display.grams, display.calories, display.servings, display.costPerServing, display.caloriesPerServing);

	if (cheapOption)
	{
		printf(" ***");
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest)
{
	printf("Final Analysis\n"
			"--------------\n"
			"Based on the comparison data, the PURRR-fect economical option is:\n"
			"SKU:%07d Price: $%.2lf\n\n"
			
			"Happy shopping!\n", cheapest.sku, cheapest.price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{
	struct CatFoodInfo products[MAX_PRODUCTS] = { {0} };
	struct ReportData data[MAX_PRODUCTS] = { {0} };
	int cheapest, cheapOption;
	const int productNum = MAX_PRODUCTS;

	openingMessage(productNum);

	int i;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		products[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();


	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(products[i].sku, &products[i].price, products[i].calories, &products[i].weight);

	}

	printf("\n");

	displayReportHeader();

	
	for ( i = 0; i < MAX_PRODUCTS; i++)
	{
		data[i] = calculateReportData(products[i]);
	}

	cheapest = 0;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (data[i].costPerServing < data[cheapest].costPerServing)
		{
			cheapest = i;
		}
	}

	cheapOption = 0;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		if (data[i].sku == data[cheapest].sku)
		{
			cheapOption = 1;
		}
		else
		{
			cheapOption = 0;
		}

		printf("\n");
		displayReportData(data[i], cheapOption);
	}
	printf("\n\n");

	displayFinalAnalysis(products[cheapest]);
}
