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


typedef struct reportTag 
{
    String20 date;
    String20 time;
    float magnitude;
    String100 location;
    String500 details;
} reportType;

// From main.c
void printLanding();
void printMainMenu();

// From report.c
void addReport(reportType *reports);
void exportEntries(reportType reports[], int reportCount);
// More to be added

// From info.c
int importRecords(reportType reports[], int *numReports);
void viewRecords(reportType reports[], int *numReports);
// More to be added

// From userAuth.c
void signUp();
void logIn();
void forgotPassword();
void encryptUser(info *data);
void encryptPS(info *data);
void dencryptUser(info *data);
void dencryptPS(info *data);

// From educModel.c
void educationalHub();
void beforeEarthquake();
void duringEarthquake();
void afterEarthquake();
// Content to be added later


#endif
