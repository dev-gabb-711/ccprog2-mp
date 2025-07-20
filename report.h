#ifndef USERAUTH_H
#define USERAUTH_H
#include "header.h"

#define MAX_REPORT 100


// Function Declarations
void addReport(reportType *reports);
void viewReports(reportType reports[], int totalReports);


#endif