#include "../ccprog2-mp/search.h"

int dFirstOccurrence(reportType fReport[], int numReports, dateType temp)
{
    int low = 0, high = numReports - 1;
    int firstIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (temp.month == fReport[mid].date.month && temp.day == fReport[mid].date.day 
            && temp.year == fReport[mid].date.year) {
            firstIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (temp.month < fReport[mid].date.month || temp.day < fReport[mid].date.day 
              || temp.year < fReport[mid].date.year) {
            high = mid - 1;
        }
        else if(temp.month > fReport[mid].date.month || temp.day > fReport[mid].date.day 
            || temp.year > fReport[mid].date.year){
            low = mid + 1;
        }
    }
    
    return firstIndex;
}


int dLastOccurrence(reportType fReport[], int numReports, dateType temp)
{
    int low = 0, high = numReports - 1;
    int lastIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (temp.month == fReport[mid].date.month && temp.day == fReport[mid].date.day 
            && temp.year == fReport[mid].date.year) {
            lastIndex = mid;
            low = mid + 1;  // Continue searching right
        }
        else if (temp.month < fReport[mid].date.month || temp.day < fReport[mid].date.day 
              || temp.year < fReport[mid].date.year) { 
            high = mid - 1;
        }
        else if(temp.month > fReport[mid].date.month || temp.day > fReport[mid].date.day 
            || temp.year > fReport[mid].date.year) {
            low = mid + 1;
        }
    }
    
    return lastIndex;
}

/*
  DO searchByDate
  1. Get the user-inputted data 
  2. Pass & get the sorted structure of dates
  3. Do a binary search 
  4. Get the lower bounds and upper bounds (check for duplicates)
  5. Get the index values with similar date info
  6. Print the information

*/

void searchByDate(reportType fReport[], int numReports)
{
    dateType temp;
    int first, last;
    int dateFound = 0;  
	reportType dReports[MAX_REPORTS]; // Struct store similar records

     temp = getDate(); // Convert from str -> int
   
    first = dFirstOccurrence(fReport, numReports, temp);  // Find initial mid & Search the LHS of all structs
    
   if (first == -1) {
        dateFound = 0;  // Date not found
    } else {
        dateFound = 1;  // Date found
    }
    
    if (dateFound == 0) {
        printf("\nThis date is not in the database");
    }
    
    if (dateFound == 1) {
        last = dLastOccurrence(fReport, numReports, temp); // Search the RHS of all structs
        
        int count = last - first + 1; // Calculate the total number of similar occurences
        
        for (int i = 0; i < count; i++) {
            dReports[i] = fReport[first + i];  // first = found mid + index 
        }
        
        printByDate(dReports, count);
    }
}

int mFirstOccurrence(reportType fReport[], int numReports, reportType temp)
{
    int low = 0, high = numReports - 1;
    int firstIndex = -1;
    
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (temp.magnitude == fReport[mid].magnitude) {
            firstIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (temp.magnitude < fReport[mid].magnitude) {
            high = mid - 1;
        }
        else if(temp.magnitude > fReport[mid].magnitude){
            low = mid + 1;
        }
    }
    
    return firstIndex;
}


int mLastOccurrence(reportType fReport[], int numReports, reportType temp)
{
    int low = 0, high = numReports - 1;
    int lastIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (temp.magnitude == fReport[mid].magnitude) {
            lastIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (temp.magnitude < fReport[mid].magnitude) {
            high = mid - 1;
        }
        else if(temp.magnitude > fReport[mid].magnitude){
            low = mid + 1;
        }
    }
    
    return lastIndex;
}



void searchByMagnitude(reportType fReport[], int numReports)
{
    reportType temp;
    int first, last;
    int magFound = 0;
	reportType mReports[MAX_REPORTS]; // Struct store similar records

    printf("Enter Magnitude: ");
	scanf("%f", &temp.magnitude);
   
    first = mFirstOccurrence(fReport, numReports, temp);  // Find initial mid & Search the LHS of all structs
    
     if (first == -1) {
        magFound = 0;  // Date not found
    } else {
        magFound = 1;  // Date found
    }
    
    if (magFound == 0) {
        printf("\nThis date is not in the database");
    }
    
    if (magFound == 1) {
        last = mLastOccurrence(fReport, numReports, temp); // Search the RHS of all structs
        
        int count = last - first + 1; // Calculate the total number of similar occurences
        
        for (int i = 0; i < count; i++) {
            mReports[i] = fReport[first + i];  // first = found mid + index 
        }
        
        printByDate(mReports, count);
    }
}


int locFirstOccurrence(reportType fReport[], int numReports, reportType temp)
{
    int low = 0, high = numReports - 1;
    int firstIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (strcmp(temp.location, fReport[mid].location) == 0) {
            firstIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (strcmp(temp.location, fReport[mid].location) < 0) {
            high = mid - 1;
        }
        else if(strcmp(temp.location, fReport[mid].location) > 0){
            low = mid + 1;
        }
    }
    
    return firstIndex;
}


int locLastOccurrence(reportType fReport[], int numReports, reportType temp)
{
    int low = 0, high = numReports - 1;
    int lastIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (strcmp(temp.location, fReport[mid].location) == 0) {
            lastIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (strcmp(temp.location, fReport[mid].location) < 0) {
            high = mid - 1;
        }
        else if(strcmp(temp.location, fReport[mid].location) > 0){
            low = mid + 1;
        }
    }
    
    return lastIndex;
}


void searchByLocation(reportType fReport[], int numReports)
{
    reportType temp;
    int first, last;
    int locFound = 0;
	reportType lReports[MAX_REPORTS]; // Struct store similar records

    printf("Enter Location: ");
	scanf("%s", temp.location);
   
    first = locFirstOccurrence(fReport, numReports, temp);  // Find initial mid & Search the LHS of all structs
    
    if (first == -1) {
        locFound = 0;  // Date not found
    } else {
        locFound = 1;  // Date found
    }
    
    if (locFound == 0) {
        printf("\nThis date is not in the database\n");
    }
    
    if (locFound == 1) {
        last = locLastOccurrence(fReport, numReports, temp); // Search the RHS of all structs
        
        int count = last - first + 1; // Calculate the total number of similar occurences
        
        for (int i = 0; i < count; i++) {
            lReports[i] = fReport[first + i];  // first = found mid + index 
        }
        
        printByDate(lReports, count);
    }

}

int tFirstOccurrence(reportType fReport[], int numReports, timeType temp)
{
    int low = 0, high = numReports - 1;
    int firstIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (temp.hour == fReport[mid].time.hour && temp.minute == fReport[mid].time.minute) 
         {
            firstIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (temp.hour < fReport[mid].time.hour || temp.minute < fReport[mid].time.minute) 
        {
            high = mid - 1;
        }
        else if(temp.hour > fReport[mid].time.hour || temp.minute > fReport[mid].time.minute)
        {
            low = mid + 1;
        }
    }
    
    return firstIndex;
}


int tLastOccurrence(reportType fReport[], int numReports, timeType temp)
{
    int low = 0, high = numReports - 1;
    int lastIndex = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
     if (temp.hour == fReport[mid].time.hour && temp.minute == fReport[mid].time.minute) 
         {
            lastIndex = mid;
            high = mid - 1;  // Continue searching left
        }
        else if (temp.hour < fReport[mid].time.hour || temp.minute < fReport[mid].time.minute) 
        {
            high = mid - 1;
        }
        else if(temp.hour > fReport[mid].time.hour || temp.minute > fReport[mid].time.minute)
        {
            low = mid + 1;
        }
    }
    
    return lastIndex;
}

void searchByTime(reportType fReport[], int numReports)
{
    timeType temp;
    int first, last;
    int timeFound = 0;
	reportType tReports[MAX_REPORTS]; // Struct store similar records

    
     temp = getTime(); // Convert from str -> int
   
    first = tFirstOccurrence(fReport, numReports, temp);  // Find initial mid & Search the LHS of all structs
    
    if (first == -1) {
        timeFound = 0;  // Date not found
    } else {
        timeFound = 1;  // Date found
    }
    
    if (timeFound == 0) {
        printf("\nThis date is not in the database\n");
    }
    
    if (timeFound == 1) {
        last = tLastOccurrence(fReport, numReports, temp); // Search the RHS of all structs
        
        int count = last - first + 1; // Calculate the total number of similar occurences
        
        for (int i = 0; i < count; i++) {
            tReports[i] = fReport[first + i];  // first = found mid + index 
        }
        
        printByDate(tReports, count);
    }
}



