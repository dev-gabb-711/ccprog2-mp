#include "header.h"

// EDUCATIONAL MODULE
void waitForEnter() {
    char temp[2];
    printf("Press Enter to return to the menu...\n");
    scanf("%1[\n]", temp); // Flush leftover newline
    scanf("%1[^\n]", temp); // Wait for actual Enter
    scanf("%1[\n]", temp); // Consume the Enter
}

void beforeEarthquake()
{
    printf("\n");
    printf("PLACEHOLDER: BEFORE\n\n");
    waitForEnter();
    printf("\n");
}

void duringEarthquake()
{
    printf("\n");
    printf("PLACEHOLDER: DURING\n\n");
    waitForEnter();
    printf("\n");
}

void afterEarthquake()
{
    printf("\n");
    printf("PLACEHOLDER: AFTER\n\n");
    waitForEnter();
    printf("\n");
}

void educationalHub()
{
    int choice;

    do {
        printf("\n\033[36mEARTHQUAKE SECTOR EDUCATIONAL HUB\033[0m\n");
        printf("This section will provide educational resources and information related to earthquake preparedness and safety.\n");
        printf("1. What to do BEFORE an earthquake?\n");
        printf("2. What to do DURING an earthquake?\n");
        printf("3. What to do AFTER an earthquake?\n");
        printf("4. Return to Main Menu\n");
        printf("\n");
        printf("Enter your selection: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1: printf("Redirecting to the BEFORE an earthquake module...\n");
                    sleep(3);
                    beforeEarthquake(); 
                    break;
            case 2: printf("Redirecting to the DURING an earthquake module...\n");
                    sleep(3);
                    duringEarthquake(); 
                    break;
            case 3: printf("Redirecting to the AFTER an earthquake module...\n");
                    sleep(3);
                    afterEarthquake(); 
                    break;
            case 4: printf("Returning to Main Menu...\n");
                    sleep(2);
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
}

// EARTHQUAKE REPORTING SYSTEM
timeType getTime()
{
	timeType temp;
	int valid = 0;
	
	while (!valid)
	{
		printf("Enter Time (HH MM): ");
		scanf("%2s %2s", temp.hourStr, temp.minuteStr);
		
		// Compute manually (this is to aid sorting and searching and the STRs are for printing)
		temp.hour = (temp.hourStr[0] - '0') * 10 + (temp.hourStr[1] - '0');
		temp.minute = (temp.minuteStr[0] - '0') * 10 + (temp.minuteStr[1] - '0');
		
		if (temp.hour >= 0 && temp.hour < 24 && temp.minute >= 0 && temp.minute < 60)
		{
			valid = 1;
		}
		else
		{
			printf("Invalid input. Please try again.\n");
		}
	}
	return temp;
}

dateType getDate()
{
	dateType temp;
	int valid = 0;
	
	while (!valid)
	{
		printf("Enter Date (MM DD YYYY): ");
		scanf("%2s %2s %4s", temp.monthStr, temp.dayStr, temp.yearStr);
		
		temp.day = (temp.dayStr[0] - '0') * 10 + (temp.dayStr[1] - '0');
        	temp.month = (temp.monthStr[0] - '0') * 10 + (temp.monthStr[1] - '0');
        	temp.year = (temp.yearStr[0] - '0') * 1000 +
                 	(temp.yearStr[1] - '0') * 100 +
                 	(temp.yearStr[2] - '0') * 10 +
                 	(temp.yearStr[3] - '0');
                 
		if (temp.year > 0 && temp.month >= 1 && temp.month <= 12 && temp.day >= 1 && temp.day <= 31)
		{
			valid = 1;
		}
		else
		{
			printf("Invalid input. Please try again.\n");
		}
	}
	return temp;
}
void addReport(reportType reports[], int *numReports)
{
	if (*numReports >= MAX_REPORTS)
	{
		printf("Maximum report limit reached.\n");
	}
	else
	{
		printf("\nReport an Earthquake\n");
        	printf("========================================\n");
        	sleep(1);
        
		reportType *r = &reports[*numReports];
		r->date = getDate();
		r->time = getTime();
		
		printf("Enter Magnitude: ");
		scanf("%f", &r->magnitude);
		printf("Enter Location: ");
		scanf(" %[^\n]", r->location);
		printf("Enter Details: ");
		scanf(" %[^\n]", r->details);
		
		(*numReports)++;
		printf("\nReport added successfully!\n");
	}
}

void exportRecords(reportType reports[], int numReports)
{
	FILE *fp;
	int i;
	
	if (numReports == 0)
	{
		printf("No data to export.\n");
	}
	else
	{
		fp = fopen("exports.txt", "w");
		if (fp != NULL)
		{
			for (i = 0; i < numReports; i++)
			{
				fprintf(fp, "EARTHQUAKE ENTRY #%d\n", i + 1);
				fprintf(fp, "Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
				fprintf(fp, "Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
				fprintf(fp, "Magnitude: %.1f\n", reports[i].magnitude);
				fprintf(fp, "Location: %s\n", reports[i].location);
				fprintf(fp, "Details: %s\n", reports[i].details);
				fprintf(fp, "\n");
			}
			int close = fclose(fp);
			if (close == 0)
			{
				printf("Data exported successfully to exports.txt!\n");
			}
		}
		else
		{
			printf("Unsuccessful export of data.\n");
		}
	}
}

// EARTHQUAKE SECTOR INFORMATION HUB
void viewRecords(reportType reports[], int *numReports)
{
    int i;
    float totalMagnitude = 0.0;
    float highest = 0.0;
    float lowest = 0.0;

    if (*numReports > 0)
    {
    	printf("\nView All Records\n");
        printf("========================================\n");
        for (i = 0; i < *numReports; i++)
        {
            printf("\nEarthquake Report #%d:\n", i + 1);
            printf("Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
            printf("Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
            printf("Magnitude: %.1f\n", reports[i].magnitude);
            printf("Location: %s\n", reports[i].location);
            printf("Details: %s\n", reports[i].details);
            printf("\n========================================\n");
            totalMagnitude = totalMagnitude + reports[i].magnitude;
            
            if (i == 0)
            {
            	highest = reports[i].magnitude;
            	lowest = reports[i].magnitude;
			}
			else
			{
				if (reports[i].magnitude > highest)
				{
					highest = reports[i].magnitude;
				}
				if (reports[i].magnitude < lowest)
				{
					lowest = reports[i].magnitude;
				}
			}
        }
        printf("\n---SUMMARY STATISTICS---\n");
        printf("Total Reports: %d\n", *numReports);
        printf("Average Magnitude: %.2f\n", totalMagnitude / *numReports);
        printf("Highest Recorded Magnitude: %.1f\n", highest);
        printf("Lowest Recorded Magnitude: %.1f\n", lowest);
        printf("------------------------\n\n");
    }
    else
    {
        printf("No records available.\n");
    }
}

int importRecords(reportType reports[], int *numReports)
{
 	FILE *fp;
 	fp = fopen("exports.txt", "r");
 	
 	if (fp != NULL)
 	{
 		*numReports = 0;
 		while (fscanf(fp, " EARTHQUAKE ENTRY #%*d\n") != EOF)
 		{
 			fscanf(fp, " Date: %2s/%2s/%4s",
		 			reports[*numReports].date.monthStr,
					reports[*numReports].date.dayStr,
					reports[*numReports].date.yearStr);
				
			fscanf(fp, " Time: %2s:%2s\n",
                	reports[*numReports].time.hourStr,
                	reports[*numReports].time.minuteStr);
                
        	fscanf(fp, " Magnitude: %f\n", &reports[*numReports].magnitude);
        	fscanf(fp, " Location: %[^\n]\n", reports[*numReports].location);
        	fscanf(fp, " Details: %[^\n]\n]\n", reports[*numReports].details);
        
        	// Update numeric values
        	reports[*numReports].date.month = (reports[*numReports].date.monthStr[0] - '0') * 10 +
                                    			(reports[*numReports].date.monthStr[1] - '0');
        	reports[*numReports].date.day = (reports[*numReports].date.dayStr[0] - '0') * 10 +
                                            	(reports[*numReports].date.dayStr[1] - '0');
        	reports[*numReports].date.year = (reports[*numReports].date.yearStr[0] - '0') * 1000 +
                                            	(reports[*numReports].date.yearStr[1] - '0') * 100 +
                                             	(reports[*numReports].date.yearStr[2] - '0') * 10 +
                                             	(reports[*numReports].date.yearStr[3] - '0');

        	reports[*numReports].time.hour = (reports[*numReports].time.hourStr[0] - '0') * 10 +
                                             	(reports[*numReports].time.hourStr[1] - '0');
        	reports[*numReports].time.minute = (reports[*numReports].time.minuteStr[0] - '0') * 10 +
                                               	(reports[*numReports].time.minuteStr[1] - '0');

        	(*numReports)++;
		}
		fclose(fp);
		return 1;
	}
 	return 0;
}

void printByDate(reportType reports[], int numReports)
{
   int i;
   
   printf("\nSort by Date\n");
   printf("========================================\n");

   for(i = 0; i < numReports; i++)
   {
   	printf("\nEARTHQUAKE ENTRY #%d\n", i + 1);
        printf("Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
        printf("Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
        printf("Magnitude: %.1f\n", reports[i].magnitude);
        printf("Location: %s\n", reports[i].location);
        printf("Details: %s\n", reports[i].details);
        printf("\n========================================\n");
   }
}

void printByMagnitude(reportType reports[], int numReports)
{
   int i;
   
   printf("\nSort by Magnitude\n");
   printf("========================================\n");

   for(i = 0; i < numReports; i++)
   {
   	printf("\nEARTHQUAKE ENTRY #%d\n", i + 1);
	printf("Magnitude: %.1f\n", reports[i].magnitude);
        printf("Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
        printf("Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
        printf("Location: %s\n", reports[i].location);
        printf("Details: %s\n", reports[i].details);
        printf("\n========================================\n");
   }
}

void printByLocation(reportType reports[], int numReports)
{
   int i;
   
   printf("\nSort by Location\n");
   printf("========================================\n");
   for(i = 0; i < numReports; i++)
   {
   	printf("\nEARTHQUAKE ENTRY #%d\n", i + 1);
       printf("Location: %s\n", reports[i].location);
       printf("Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
       printf("Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
	printf("Magnitude: %.1f\n", reports[i].magnitude);
       printf("Details: %s\n", reports[i].details);
       printf("\n========================================\n");

   }
}

void printByTime(reportType reports[], int numReports)
{
   int i;

   printf("\nSort by Time\n");
   printf("========================================\n");
   for(i = 0; i < numReports; i++)
   {
   	printf("\nEARTHQUAKE ENTRY #%d\n", i + 1);
       printf("Time: %s:%s\n", reports[i].time.hourStr, reports[i].time.minuteStr);
       printf("Date: %s/%s/%s\n", reports[i].date.monthStr, reports[i].date.dayStr, reports[i].date.yearStr);
	printf("Magnitude: %.1f\n", reports[i].magnitude);
       printf("Location: %s\n", reports[i].location);
	printf("Details: %s\n", reports[i].details);
       printf("\n========================================\n");
   }

}

void sortByDate(reportType sDate[], int numReports)
{
	int i, j, min;
	reportType temp;

   	for (i = 0; i < numReports - 1; i++)
   	{
   		min = i;
   		for (j = i + 1; j < numReports; j++)
   		{
   			if (sDate[j].date.year < sDate[min].date.year)
   			{
   				min = j;
			}
			else if (sDate[j].date.year == sDate[min].date.year)
			{
				if (sDate[j].date.month < sDate[min].date.month)
				{
					min = j;
				}
				else if (sDate[j].date.month == sDate[min].date.month)
				{
					if (sDate[j].date.day < sDate[min].date.day)
					{
						min = j;
					}
				}
			}
		}
		if (min != i)
		{
			temp = sDate[i];
			sDate[i] = sDate[min];
			sDate[min] = temp;
		}
	}
	printByDate(sDate, numReports);
}

void sortByMagnitude(reportType sMag[], int numReports)
{  
	int i, j, min;
	float tempMagnitude;
	String20 tempDay;
	String20 tempMonth;
	String20 tempYear;
	String100 tempLocation;
	String20 tempHour;
	String20 tempMinutes;
	String500 tempDetails;

   for (i = 0; i < numReports - 1; i++) {
      min = i; // min is the index of the lowest element

     for (j = i + 1; j < numReports; j++)
           if (sMag[min].magnitude > sMag[j].magnitude) // Check if the numerical order is correct
             min = j;
        
            if (i != min) {
             
               tempMagnitude = sMag[i].magnitude;
               sMag[i].magnitude = sMag[min].magnitude ;
               sMag[min].magnitude = tempMagnitude;
   
               strcpy(tempDay, sMag[i].date.dayStr);
               strcpy(sMag[i].date.dayStr, sMag[min].date.dayStr);
               strcpy(sMag[min].date.dayStr, tempDay);
			
               strcpy(tempMonth, sMag[i].date.monthStr);
               strcpy(sMag[i].date.monthStr, sMag[min].date.monthStr);
               strcpy(sMag[min].date.monthStr, tempMonth);
	
               strcpy(tempYear, sMag[i].date.yearStr);
               strcpy(sMag[i].date.yearStr, sMag[min].date.yearStr);
               strcpy(sMag[min].date.yearStr, tempYear);
	
               strcpy(tempLocation, sMag[i].location);
               strcpy(sMag[i].location, sMag[min].location); 
               strcpy(sMag[min].location, tempLocation);
	
               strcpy(tempHour, sMag[i].time.hourStr);
               strcpy(sMag[i].time.hourStr, sMag[min].time.hourStr);
               strcpy(sMag[min].time.hourStr, tempHour);

               strcpy(tempMinutes, sMag[i].time.minuteStr);
               strcpy(sMag[i].time.minuteStr, sMag[min].time.minuteStr);
               strcpy(sMag[min].time.minuteStr, tempMinutes);

		strcpy(tempDetails, sMag[i].details);
               strcpy(sMag[i].details, sMag[min].details); 
               strcpy(sMag[min].details, tempDetails);
          }
      }

	  printByMagnitude(sMag, numReports);
}

void sortByLocation(reportType sLoc[], int numReports)
{
	int i, j, min;
	String100 tempLocation;

	float tempMagnitude;
	String20 tempDay;
	String20 tempMonth;
	String20 tempYear;
	String20 tempHour;
	String20 tempMinutes;
	String500 tempDetails;

   for (i = 0; i < numReports - 1; i++) {
      min = i; // min is the index of the lowest element

     for (j = i + 1; j < numReports; j++)
           if (strcmp(sLoc[min].location, sLoc[j].location) > 0) // Check if the string is alphabetically arranged
             min = j;
        
            if (i != min) {
            strcpy(tempLocation, sLoc[i].location);
            strcpy(sLoc[i].location, sLoc[min].location);
            strcpy(sLoc[min].location, tempLocation);

			tempMagnitude = sLoc[i].magnitude;
            sLoc[i].magnitude = sLoc[min].magnitude;
            sLoc[min].magnitude = tempMagnitude;
   
            strcpy(tempDay, sLoc[i].date.dayStr);
            strcpy(sLoc[i].date.dayStr, sLoc[min].date.dayStr);
            strcpy(sLoc[min].date.dayStr, tempDay);
			
            strcpy(tempMonth, sLoc[i].date.monthStr);
            strcpy(sLoc[i].date.monthStr, sLoc[min].date.monthStr);
            strcpy(sLoc[min].date.monthStr, tempMonth);
	
            strcpy(tempYear, sLoc[i].date.yearStr);
            strcpy(sLoc[i].date.yearStr, sLoc[min].date.yearStr);
            strcpy(sLoc[min].date.yearStr, tempYear);

	    strcpy(tempHour, sLoc[i].time.hourStr);
            strcpy(sLoc[i].time.hourStr, sLoc[min].time.hourStr);
            strcpy(sLoc[min].time.hourStr, tempHour);

            strcpy(tempMinutes, sLoc[i].time.minuteStr);
            strcpy(sLoc[i].time.minuteStr, sLoc[min].time.minuteStr);
            strcpy(sLoc[min].time.minuteStr, tempMinutes);

	    strcpy(tempDetails, sLoc[i].details);
            strcpy(sLoc[i].details, sLoc[min].details); 
            strcpy(sLoc[min].details, tempDetails);
            
          }
      }
  
    printByLocation(sLoc, numReports);
}


void sortByTime(reportType sTime[], int numReports)
{
	int i, j, min;
	reportType temp;

   	for (i = 0; i < numReports - 1; i++)
   	{
   		min = i;
   		for (j = i + 1; j < numReports; j++)
   		{
   			if (sTime[j].time.hour < sTime[min].time.hour)
   			{
   				min = j;
			}
			else if (sTime[j].time.hour == sTime[min].time.hour)
			{
				if (sTime[j].time.minute < sTime[min].time.minute)
				{
					min = j;
				}
			}
		}
		if (min != i)
		{
			temp = sTime[i];
			sTime[i] = sTime[min];
			sTime[min] = temp;
		}
	}
	printByTime(sTime, numReports);
} 
