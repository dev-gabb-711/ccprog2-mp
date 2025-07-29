#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH (256)
#define MAX_REPORTS 100

typedef char String20[21]; // For general inputs
typedef char String100[101]; // For longer text inputs
typedef char String500[501]; // For very long text inputs (like details and descriptions)

typedef struct
{
    char user_name[MAX_LENGTH];
    char password[MAX_LENGTH];
    char encrypted_User[MAX_LENGTH];
    char encrypted_Ps[MAX_LENGTH];
} info;

typedef struct timeTag
{
	int hour;
	int minute;
	String20 hourStr;
	String20 minuteStr;
} timeType;

typedef struct dateTag
{
	int day;
	int month;
	int year;
	String20 dayStr;
	String20 monthStr;
	String20 yearStr;
} dateType;

typedef struct reportTag 
{
    dateType date;
    timeType time;
    float magnitude;
    String100 location;
    String500 details;
} reportType;

// From main.c
void printLanding();
void printMainMenu();
void printReportLanding(reportType reports[], int *numReports);
void printInfoLanding(reportType reports[], int *numReports);

// From userAuth.c
void signUp();
void logIn();
void forgotPassword();
void encryptUser(info *data);
void encryptPS(info *data);
void dencryptUser(info *data);
void dencryptPS(info *data);

// EARTHQUAKE REPORTING SYSTEM
timeType getTime();
dateType getDate();
void addReport(reportType reports[], int *numReports);
void exportRecords(reportType reports[], int numReports);
void editReport(reportType reports[], int *numReports);
void deleteReport(reportType reports[], int *numReports);

// EARTHQUAKE SECTOR INFORMATION HUB
int importRecords(reportType reports[], int *numReports);
void viewRecords(reportType reports[], int *numReports);

// Print Sorted/Seached Information
void printByDate(reportType reports[], int numReports);
void printByMagnitude(reportType reports[], int numReports);
void printByLocation(reportType reports[], int numReports);
void printByTime(reportType reports[], int numReports);

// Sorting Features
void sortByDate(reportType sDate[], int numReports);
void sortByMagnitude(reportType sMag[], int numReports);
void sortByLocation(reportType sLoc[], int numReports);
void sortByTime(reportType sTime[], int numReports);

// Search Features
void searchByDate(reportType sDate[], int numReports);
void searchByMagnitude(reportType sMag[], int numReports);
void searchByLocation(reportType sLoc[], int numReports);
void searchByTime(reportType sTime[], int numReports);

// Computational Features
int frequencyInDateFrame(reportType reports[], int *numReports);
void mostFrequentLocation(reportType reports[], int *numReports);
void monthWithMostEarthquakes(reportType reports[], int *numReports);
void locationMagnitudeCrossTable(reportType reports[], int *numReports);

// EDUCATIONAL MODULE
void educationalHub();
void beforeEarthquake();
void duringEarthquake();
void afterEarthquake();


#endif
