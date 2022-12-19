/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

	// Note:
	// You can convert Celsius to Fahrenheit given the following formula:
	// fahrenheit = (celsius * 1.8) + 32.0);

    // Coffee features (Initialized them since Visual Studio gives error)
    char coffeeType1 = 'c', coffeeType2 = 'c', coffeeType3 = 'c';
    char grindSize1 = 'g', grindSize2 = 'g', grindSize3 = 'g';
    int bagWeight1 = 0, bagWeight2 = 0, bagWeight3 = 0;
    char bestWithCream1 = 'c', bestWithCream2 = 'c', bestWithCream3 = 'c';
    double temperature1 = 0.00, temperature2 = 0.00, temperature3 = 0.00;

    //Preferences and equipment
    char coffeeStr = 's', isWithCream = 's', maker ='s';
    int dailyServings = 0;

   printf("Take a Break - Coffee Shop\n"
           "==========================\n\n"
           "Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize1);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWithCream1);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temperature1);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize2);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWithCream2);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temperature2);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[B]lend): ");
    scanf(" %c", &coffeeType3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &grindSize3);
    printf("Bag weight (g): ");
    scanf(" %d", &bagWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &bestWithCream3);
    printf("Ideal serving temperature (Celsius): ");
    scanf(" %lf", &temperature3);
    printf("\n");

    printf("---+---------------+---------------+---------------+-------+--------------\n"
           "   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n"
           "   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n"
           "   +---------------+---------------+---------------+ With  +--------------\n"
           "ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n"
           "---+---------------+---------------+---------------+-------+--------------\n");
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffeeType1 == 'l' || coffeeType1 == 'L'), (coffeeType1 == 'b' || coffeeType1 == 'B'), (grindSize1 == 'c' || grindSize1 == 'C'), (grindSize1 == 'f' || grindSize1 == 'F'), bagWeight1, bagWeight1/GRAMS_IN_LBS, (bestWithCream1 == 'y') || (bestWithCream1 == 'Y'), temperature1, (temperature1 * 1.8) + 32.0);
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n", (coffeeType2 == 'l' || coffeeType2 == 'L'), (coffeeType2 == 'b' || coffeeType2 == 'B'), (grindSize2 == 'c' || grindSize2 == 'C'), (grindSize2 == 'f' || grindSize2 == 'F'), bagWeight2, bagWeight2 / GRAMS_IN_LBS, (bestWithCream2 == 'y') || (bestWithCream2 == 'Y'), temperature2, (temperature2 * 1.8) + 32.0);
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n", (coffeeType3 == 'l' || coffeeType3 == 'L'), (coffeeType3 == 'b' || coffeeType3 == 'B'), (grindSize3 == 'c' || grindSize3 == 'C'), (grindSize3 == 'f' || grindSize3 == 'F'), bagWeight3, bagWeight3 / GRAMS_IN_LBS, (bestWithCream3 == 'y') || (bestWithCream3 == 'Y'), temperature3, (temperature3 * 1.8) + 32.0);

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStr);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &isWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n"
           "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
           "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
           "--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffeeStr == 'm' || coffeeStr == 'M') && (coffeeType1 == 'l' || coffeeType1 == 'L')) || ((coffeeStr == 'r' || coffeeStr == 'R') && (coffeeType1 == 'b' || coffeeType1 == 'B')),              // coffee type
                                                                                             ((grindSize1 == 'c' || grindSize1 == 'C')  &&  (maker == 'r'       || maker == 'R'))         ||   ((grindSize1 == 'f' || grindSize1 == 'F')   &&  (maker == 'c'       || maker == 'C')),                    // grind size
                                                                                             (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight1 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight1 == 500)) || ((dailyServings >= 10) && (bagWeight1 == 1000)),         // daily servings
                                                                                             ((bestWithCream1 == 'y' || bestWithCream1 == 'Y') && (isWithCream == 'y'     || isWithCream == 'Y')) || ((bestWithCream1 == 'n' || bestWithCream1 == 'N') && (isWithCream == 'n' || isWithCream == 'N')),   // best served with cream
                                                                                             ((maker == 'r'  || maker == 'R')  &&  ((59.9 < temperature1) && (temperature1 < 70.0))) || ((maker == 'c'  || maker == 'C') && (temperature1 >= 70.0)));                                                                      // temperature
     
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffeeStr == 'm'  || coffeeStr == 'M')  &&  (coffeeType2 == 'l' || coffeeType2 == 'L'))    ||   ((coffeeStr == 'r'  || coffeeStr == 'R')    &&  (coffeeType2 == 'b' || coffeeType2 == 'B')),            
                                                                                             ((grindSize2 == 'c' || grindSize2 == 'C') &&  (maker == 'r'       || maker == 'R'))          ||   ((grindSize2 == 'f' || grindSize2 == 'F')   &&  (maker == 'c' || maker == 'C')),                          
                                                                                             (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight2 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight2 == 500)) || ((dailyServings >= 10) && (bagWeight2 == 1000)),         
                                                                                             ((bestWithCream2 == 'y' || bestWithCream2 == 'Y') && (isWithCream == 'y' || isWithCream == 'Y')) || ((bestWithCream2 == 'n' || bestWithCream2 == 'N') && (isWithCream == 'n' || isWithCream == 'N')),       
                                                                                             ((maker == 'r' || maker == 'R') && ((59.9 < temperature2) && (temperature2 < 70.0))) || ((maker == 'c' || maker == 'C') && (temperature2 >= 70.0)));
    
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", ((coffeeStr == 'm'  || coffeeStr == 'M')   &&  (coffeeType3 == 'l'  || coffeeType3 == 'L'))   || ((coffeeStr == 'r' || coffeeStr == 'R')       &&  (coffeeType3 == 'b' || coffeeType3 == 'B')),        
                                                                                               ((grindSize3 == 'c' || grindSize3 == 'C')  &&  (maker == 'r'        || maker == 'R'))         || ((grindSize3 == 'f' || grindSize3 == 'F')     &&  (maker == 'c'       || maker == 'C')),                 
                                                                                               (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight3 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight3 == 500)) || ((dailyServings >= 10) && (bagWeight3 == 1000)),       
                                                                                               ((bestWithCream3 == 'y' || bestWithCream3 == 'Y') && (isWithCream == 'y'     || isWithCream == 'Y')) || ((bestWithCream3 == 'n' || bestWithCream3 == 'N') && (isWithCream == 'n' || isWithCream == 'N')), 
                                                                                               ((maker == 'r'   || maker == 'R')  && ((59.9 < temperature3) && (temperature3 < 70.0)))   || ((maker == 'c'  || maker == 'C') && (temperature3 >= 70.0)));
    

    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");

    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStr);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &isWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+--------------------+-------------+-------+--------------\n"
           "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
           "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
           "--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffeeStr == 'm' || coffeeStr == 'M') && (coffeeType1 == 'l' || coffeeType1 == 'L')) || ((coffeeStr == 'r' || coffeeStr == 'R') && (coffeeType1 == 'b' || coffeeType1 == 'B')),                    
                                                                                             ((grindSize1 == 'c' || grindSize1 == 'C') && (maker == 'r' || maker == 'R')) || ((grindSize1 == 'f' || grindSize1 == 'F') && (maker == 'c' || maker == 'C')),                                        
                                                                                             (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight1 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight1 == 500)) || ((dailyServings >= 10) && (bagWeight1 == 1000)),  
                                                                                             ((bestWithCream1 == 'y' || bestWithCream1 == 'Y') && (isWithCream == 'y' || isWithCream == 'Y')) || ((bestWithCream1 == 'n' || bestWithCream1 == 'N') && (isWithCream == 'n' || isWithCream == 'N')),
                                                                                             ((maker == 'r' || maker == 'R') && ((59.9 < temperature1) && (temperature1 < 70.0))) || ((maker == 'c' || maker == 'C') && (temperature1 >= 70.0)));

    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n", ((coffeeStr == 'm' || coffeeStr == 'M') && (coffeeType2 == 'l' || coffeeType2 == 'L')) || ((coffeeStr == 'r' || coffeeStr == 'R') && (coffeeType2 == 'b' || coffeeType2 == 'B')),
                                                                                             ((grindSize2 == 'c' || grindSize2 == 'C') && (maker == 'r' || maker == 'R')) || ((grindSize2 == 'f' || grindSize2 == 'F') && (maker == 'c' || maker == 'C')),
                                                                                             (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight2 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight2 == 500)) || ((dailyServings >= 10) && (bagWeight2 == 1000)),
                                                                                             ((bestWithCream2 == 'y' || bestWithCream2 == 'Y') && (isWithCream == 'y' || isWithCream == 'Y')) || ((bestWithCream2 == 'n' || bestWithCream2 == 'N') && (isWithCream == 'n' || isWithCream == 'N')),
                                                                                             ((maker == 'r' || maker == 'R') && ((59.9 < temperature2) && (temperature2 < 70.0))) || ((maker == 'c' || maker == 'C') && (temperature2 >= 70.0)));

    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n", ((coffeeStr == 'm' || coffeeStr == 'M') && (coffeeType3 == 'l' || coffeeType3 == 'L')) || ((coffeeStr == 'r' || coffeeStr == 'R') && (coffeeType3 == 'b' || coffeeType3 == 'B')),
                                                                                               ((grindSize3 == 'c' || grindSize3 == 'C') && (maker == 'r' || maker == 'R')) || ((grindSize3 == 'f' || grindSize3 == 'F') && (maker == 'c' || maker == 'C')),
                                                                                               (((0 < dailyServings) && (dailyServings < 5)) && (bagWeight3 == 250)) || (((5 < dailyServings) && (dailyServings < 10)) && (bagWeight3 == 500)) || ((dailyServings >= 10) && (bagWeight3 == 1000)),
                                                                                               ((bestWithCream3 == 'y' || bestWithCream3 == 'Y') && (isWithCream == 'y' || isWithCream == 'Y')) || ((bestWithCream3 == 'n' || bestWithCream3 == 'N') && (isWithCream == 'n' || isWithCream == 'N')),
                                                                                               ((maker == 'r' || maker == 'R') && ((59.9 < temperature3) && (temperature3 < 70.0))) || ((maker == 'c' || maker == 'C') && (temperature3 >= 70.0)));
    
   
    printf("Hope you found a product that suits your likes!\n");

    return 0;
}
