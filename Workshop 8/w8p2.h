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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define SERVING 64
#define LBS_IN_KG 2.20462


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};

struct ReportData
{
    int sku;
    double price;
    int calories;
    double weightLbs;
    double weightKg;
    int grams;
    double servings;
    double costPerServing;
    double caloriesPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* wholeNum);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* decimalNum);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int products);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calories, const double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* equalKg);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* equalGrams);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* equalKg, int* equalGrams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servings, const int grams, double* servingsNum);

// 12. calculate: cost per serving
double calculateCostPerServing(const double price, const double servings, double* costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double price, const double totalCalories, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo item);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData display, const int cheapOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapest);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
