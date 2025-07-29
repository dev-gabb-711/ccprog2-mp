#ifndef SEARCH_H
#define SEARCH_H

#include "../ccprog2-mp/header.h"

// Seaching Features
void searchByDate(reportType fReport[], int numReports);
int dFirstOccurrence(reportType fReport[], int numReports, dateType temp);
int dLastOccurrence(reportType fReport[], int numReports, dateType temp);

void searchByMagnitude(reportType fReport[], int numReports);
int mFirstOccurrence(reportType fReport[], int numReports, reportType temp);
int mLastOccurrence(reportType fReport[], int numReports, reportType temp);

void searchByLocation(reportType fReport[], int numReports);
int locFirstOccurrence(reportType fReport[], int numReports, reportType temp);
int locLastOccurrence(reportType fReport[], int numReports, reportType temp);

void searchByTime(reportType fReport[], int numReports);
int tFirstOccurrence(reportType fReport[], int numReports, timeType temp);
int tLastOccurrence(reportType fReport[], int numReports, timeType temp);


#endif