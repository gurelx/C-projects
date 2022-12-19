/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN, 0);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    max = MAX_PETS;
    int i;
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
        }
    }

    if (patient == 0)
    {
        printf("*** No records found ***");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    max = MAX_PETS;
    int selection = 0;

    do
    {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        selection = inputIntRange(0, 2);
        printf("\n");

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }

        if (selection)
        {
            clearInputBuffer();
            suspend();
        }
    } while (selection);
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    max = MAX_PETS;
    int i;
    int record = -1;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            record = i;
            i = max;
        }
    }

    if (record > -1)
    {
        patient[record].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[record]);
        clearInputBuffer();
        printf("\n");
        inputPhoneData(&patient[record].phone);
        printf("*** New patient record added ***\n");
        clearInputBuffer();
    }
    else
    {
        printf("ERROR: Patient listing is FULL!\n");
    }
    printf("\n");
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    max = MAX_PETS;
    int n;
    int patientNum;
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);

    if (findPatientIndexByPatientNum(patientNum, patient, max) != -1)
    {
        printf("\n");
        n = findPatientIndexByPatientNum(patientNum, patient, max);
        menuPatientEdit(&patient[n]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    max = MAX_PETS;
    int fmt = FMT_FORM;
    int patientNum, patientIndex;
    char validchars[3] = { 'y','n' };
    char prompt;
    printf("Enter the patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    if (findPatientIndexByPatientNum(patientNum, patient, max) != -1)
    {
        patientIndex = findPatientIndexByPatientNum(patientNum, patient, max);
        displayPatientData(&patient[patientIndex], fmt);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        do
        {
            prompt = inputCharOption(validchars);

        } while (prompt == 'b');

        if (prompt == 'y')
        {
            patient[patientIndex].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
        else if (prompt == 'n')
        {
            printf("Operation aborted.\n\n");
        }
        else
        {
            printf("ERROR: Character must be one of [yn]: ");
        }

    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    clearInputBuffer();
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(const struct ClinicData* data)
{
    int i = 0, j;
    displayScheduleTableHeader(&data->appointments->date, 1);
    sortByDate(&data->appointments[0], &data->patients[0], data->maxAppointments);

    for (i = 0, j = 0; i < data->maxAppointments; i++)
    {

        if (data->appointments[i].date.year != 0)
        {
            j = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, MAX_PETS);
            displayScheduleData(&data->patients[j], &data->appointments[i], 1);
        }
    }
    printf("\n");
}


// View appointment schedule for the user input date
void viewAppointmentSchedule(const struct ClinicData* data)
{
    struct Date prompt;
    int i, j;

    printf("Year        : ");
    prompt.year = inputIntRange(2000, 2100);
    printf("Month (1-12): ");
    prompt.month = inputIntRange(1, 12);
    prompt.day = daysOfMonthsByYear(prompt);


    printf("\n");
    sortByDate(&data->appointments[0], &data->patients[0], data->maxAppointments);
    displayScheduleTableHeader(&prompt, 0);

    for (i = 0, j = 0; i < data->maxAppointments; i++)
    {
        if ((data->appointments[i].date.year == prompt.year) && (data->appointments[i].date.month == prompt.month) 
            && (data->appointments[i].date.day == prompt.day))
        {
            j = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, MAX_PETS);
            displayScheduleData(&data->patients[j], &data->appointments[i], 0);
        }
    }
    printf("\n");
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appointments, int maxAppointments,
    const struct Patient* patients, int maxPatient)
{
    struct Appointment prompt ={0};
    int i, check, availability;
    int record = -1;
    maxAppointments = MAX_APPOINTMENTS;

    // Checking if there are any free appointment spaces
    for ( i = 0; i < maxAppointments; i++)
    {
        if (appointments[i].patientNumber < 1)
        {
            record = i;
            i = maxAppointments;
        }
    }

    i = 0;
    check = 0;
    if (record > -1)
    {
        checkPatientNumber(patients, appointments, prompt, MAX_PETS, MAX_APPOINTMENTS, 0);

        do
        {
            check = 0;
            availability = 1;

            printf("Year        : ");
            prompt.date.year = inputIntRange(2000, 2100);
            printf("Month (1-12): ");
            prompt.date.month = inputIntRange(1, 12);
            prompt.date.day = daysOfMonthsByYear(prompt.date);

            // Checking if the time is between 10:00 and 14:00 in 30 minute intervals
            check = 0;
            do
            {
                printf("Hour (0-23)  : ");
                prompt.time.hour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                prompt.time.min = inputIntRange(0, 59);

                if ((prompt.time.hour >= MIN_HOUR && prompt.time.hour <= MAX_HOUR) && (prompt.time.min % 30 == 0))
                {
                    if (!(prompt.time.hour == MAX_HOUR && prompt.time.min == 30))
                    {
                        check = 1;
                    }
                    else
                    {
                        printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", MIN_HOUR, MAX_HOUR);
                    }
                }
                else
                {
                    printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", MIN_HOUR, MAX_HOUR);
                }

            } while (!check);

            // Checking if the appoitment timeslot is available
            for (i = 0; i < maxAppointments; i++)
            {
                if ((prompt.date.year == appointments[i].date.year) && (prompt.date.month == appointments[i].date.month) && 
                    (prompt.date.day == appointments[i].date.day) && (prompt.time.hour == appointments[i].time.hour) && 
                    (prompt.time.min == appointments[i].time.min))
                {
                    putchar('\n');
                    printf("ERROR: Appointment timeslot is not available!\n\n");
                    availability = 0;
                }
            }
        } while (!availability);

        appointments[record] = prompt;
        putchar('\n');
        printf("*** Appointment scheduled! ***\n\n");
    }
}



// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    const struct Patient* patients, int maxPatient)
{
    maxAppointments = MAX_APPOINTMENTS;
    maxPatient = MAX_PETS;

    int appointIndex, patientIndex;
    char check;
    char validchars[3] = { 'y', 'n' };
    struct Appointment prompt = { 0 };

    prompt.patientNumber = checkPatientNumber(patients, appointments, prompt, MAX_PETS, MAX_APPOINTMENTS, 0);

    if (prompt.patientNumber != -1)
    {
        printf("Year        : ");
        prompt.date.year = inputIntRange(2000, 2100);
        printf("Month (1-12): ");
        prompt.date.month = inputIntRange(1, 12);
        prompt.date.day = daysOfMonthsByYear(prompt.date);
        putchar('\n');

        appointIndex = checkPatientNumber(patients, appointments, prompt, MAX_PETS, MAX_APPOINTMENTS, 1);
        patientIndex = findPatientIndexByPatientNum(appointments[appointIndex].patientNumber, patients, maxPatient);

        if (appointIndex != -1)
        {
            if ((prompt.date.year == appointments[appointIndex].date.year) && (prompt.date.month == appointments[appointIndex].date.month) &&
                (prompt.date.day == appointments[appointIndex].date.day))
            {
                displayPatientData(&patients[patientIndex], FMT_FORM);

                printf("Are you sure you want to remove this appointment (y,n): ");

                do
                {
                    check = inputCharOption(validchars);
                } while (check == 'b');

                if (check == 'y')
                {
                    appointments[appointIndex].patientNumber = 0;
                    appointments[appointIndex].date.year = 0;
                    appointments[appointIndex].date.month = 0;
                    appointments[appointIndex].date.day = 0;
                    appointments[appointIndex].time.hour = 0;
                    appointments[appointIndex].time.min = 0;

                    putchar('\n');
                    printf("Appointment record has been removed!\n\n");
                    clearInputBuffer();
                }
                else
                {
                    putchar('\n');
                    printf("Operation aborted!\n");
                    clearInputBuffer();
                }
            }
        }
        else
        {
            printf("ERROR:Appointment record cannot be found!\n\n");
        }
    }
    else
    {
        clearInputBuffer();
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    max = MAX_PETS;
    int n;
    int patientNum;
    int fmt = FMT_FORM;
    printf("Search by patient number: ");
    scanf("%d", &patientNum);
    printf("\n");

    if (findPatientIndexByPatientNum(patientNum, patient, max) != -1)
    {
        n = findPatientIndexByPatientNum(patientNum, patient, max);
        displayPatientData(&patient[n], fmt);
    }
    else
    {
        printf("*** No records found ***\n");
    }

    printf("\n");
}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    max = MAX_PETS;
    int i;
    int n = 0;
    int fmt = FMT_TABLE;
    char phoneNum[PHONE_LEN + 1] = { 0 };
    printf("Search by phone number: ");
    inputCString(phoneNum, 10,10,1);
    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            displayPatientData(&patient[i], fmt);
        }
        else
        {
            n++;
        }
    }
    if (n == 7)
    {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");
}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    max = MAX_PETS;
    int i;
    int maximum = patient[0].patientNumber;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maximum)
        {
            maximum = patient[i].patientNumber;
        }
    }
    return maximum + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    max = MAX_PETS;
    int n = -1;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            n = i;
        }
    }
    return n;
}

// For sorting the appointments by date 
void sortByDate(struct Appointment *appoints, struct Patient* patients, int max)
{
    int i, j;
    struct Appointment appointTmp;
    
    for (i = 0; i < max - 1; i++)
    {
       for (j = 0; j < max - 1 - i; j++)
       {
           if (appoints[j].date.year > appoints[j + 1].date.year)
           {
               appointTmp = appoints[j];
               appoints[j] = appoints[j+1];
               appoints[j+1] = appointTmp;
    
           }
           else if ((appoints[j].date.year == appoints[j + 1].date.year) && (appoints[j].date.month > appoints[j + 1].date.month))
           {
               appointTmp = appoints[j + 1];
               appoints[j + 1] = appoints[j];
               appoints[j] = appointTmp;
    
    
           }
           else if ((appoints[j].date.year == appoints[j + 1].date.year) && (appoints[j].date.month == appoints[j + 1].date.month) &&
               (appoints[j].date.day > appoints[j + 1].date.day))
           {
               appointTmp = appoints[j + 1];
               appoints[j + 1] = appoints[j];
               appoints[j] = appointTmp;
    
           }
           else if ((appoints[j].date.year == appoints[j + 1].date.year) && (appoints[j].date.month == appoints[j + 1].date.month) &&
               (appoints[j].date.day == appoints[j + 1].date.day) && (appoints[j].time.hour > appoints[j + 1].time.hour))
           {
               appointTmp = appoints[j + 1];
               appoints[j + 1] = appoints[j];
               appoints[j] = appointTmp;
    
           }
           else if ((appoints[j].date.year == appoints[j + 1].date.year) && (appoints[j].date.month == appoints[j + 1].date.month) &&
               (appoints[j].date.day == appoints[j + 1].date.day) && (appoints[j].time.hour == appoints[j + 1].time.hour) && 
               (appoints[j].time.min > appoints[j + 1].time.min))
           {
               appointTmp = appoints[j + 1];
               appoints[j + 1] = appoints[j];
               appoints[j] = appointTmp;
    
           }
       }           
    }
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n"
        "Number: 0%d\n"
        "Name  : ", patient->patientNumber);
        inputCString(patient->name, 1, 15, 0);
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int selection;
    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);
    printf("\n");

    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("Contact: %s\n"
            "Number : ", phone->description);
        inputCString(phone->number, 10, 10, 1);
        printf("\n");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("Contact: %s\n"
            "Number : ", phone->description);
        inputCString(phone->number, 10, 10, 1);
        printf("\n");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("Contact: %s\n"
            "Number : ", phone->description);
        inputCString(phone->number, 10, 10, 1);
        printf("\n");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        *phone->number = 0;
        break;
    }
}

// Checking if the patient number exists
int checkPatientNumber(const struct Patient* patients, const struct Appointment* appoint, struct Appointment prompt,
                       int maxPatients, int maxAppointments, int searchAppointment)
{
    int i;
    int n = -1;
    int check = 0;

    // Searching prompted patient number in appointments
    if (searchAppointment)
    {

            for (i = 0; i < maxAppointments ; i++)
            {
                if ((prompt.patientNumber == appoint[i].patientNumber) && (prompt.date.year == appoint[i].date.year) 
                    && (prompt.date.month == appoint[i].date.month) && (prompt.date.day == appoint[i].date.day))
                {
                    n = i;
 
                }
            }

        return n;
    }

    // Prompting and searching prompted patient number in all patients
    else
    {

        printf("Patient Number: ");
        scanf("%d", &prompt.patientNumber);
        for (i = 0; i < maxPatients; i++)
        {
            if (prompt.patientNumber == patients[i].patientNumber)
            {
                check = 1;
            }
        }
        if (!check)
        {
            printf("ERROR: Patient record not found!\n\n");
            return -1;
        }
        else
        {
            return prompt.patientNumber;
        }
    }
}

// Maps the number of days according to the month and year and prompts accordingly
int daysOfMonthsByYear(const struct Date date)
{
    int day = 0;

    switch (date.month)
    {
    default:
        break;
    case 1:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 3:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 4:
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
        break;
    case 5:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 6:
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
        break;
    case 7:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 8:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 9:
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
        break;
    case 10:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    case 11:
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
        break;
    case 12:
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
        break;
    }

    if (date.year == 2025 && date.month == 2)
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else if (date.year == 2024 && date.month == 2)
    {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    else if (date.year == 2026 && date.month == 2)
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else if (date.year == 2027 && date.month == 2)
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }

    return day;
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    max = MAX_PETS;
    int i = 0;
    FILE* fp = fopen(datafile, "r");
    
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return - 1;
    }
    else
    {
        while (i < max && fscanf(fp, "%d|%15[^|]|%[^|]|%10[^\n]\n", &patients[i].patientNumber,
            patients[i].name, patients[i].phone.description, patients[i].phone.number) == 4)
        {
            i++;
        }

        fclose(fp);
        return i;
    }
}


// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    max = MAX_PETS;
    int i = 0;
    FILE* fp = fopen(datafile, "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }
    else
    {
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[i].patientNumber, &appoints[i].date.year, 
            &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) == 6)
        {
            i++;
        }

        fclose(fp);
        return i;
    }
}



