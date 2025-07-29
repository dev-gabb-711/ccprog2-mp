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
    printf("\033[0;34mWHAT TO DO BEFORE AN EARTHQUAKE?\033[0m\n\n");
	printf("1. \e[1mCreate an Emergency Plan:\e[m Make a family emergency plan that includes meeting points, emergency contacts, and communication methods.\n\n");
	printf("2. \e[1mBuild an Emergency Kit:\e[m Prepare a kit with essentials like water, non-perishable food, flashlight, batteries, first aid supplies, medications, and important documents.\n\n");
	printf("3. \e[1mSecure Heavy Furniture and Appliances:\e[m Bolt bookshelves, cabinets, TVs, and other heavy items to walls to prevent tipping or falling.\n\n");
	printf("4. \e[1mKnow How to Turn Off Utilities:\e[m Learn how to shut off gas, water, and electricity in case of damage or leaks after the quake.\n\n");
	printf("5. \e[1mIdentify Safe Spots Indoors:\e[m Know the safest places in each room, such as under sturdy tables or against interior walls away from windows.\n\n");
	printf("6. \e[1mPractice ""Drop, Cover, and Hold On"":\e[m Regularly drill this protective action with your family to build muscle memory during an actual quake.\n\n");
	printf("7. \e[1mRetrofit Your Home:\e[m If possible, strengthen your homes structure by reinforcing foundations and cripple walls, especially in older buildings.\n\n");
	printf("8. \e[1mCheck Your Insurance Coverage:\e[m Make sure your homeowners or renters insurance includes earthquake coverage, which is usually separate.\n\n");
	printf("9. \e[1mMake Copies of Important Documents:\e[m Keep copies of IDs, insurance, deeds, and medical records in a waterproof container or cloud storage.\n\n");
	printf("10. \e[1mStay Informed:\e[m Follow local authorities or seismic agencies for early warning alerts, preparedness tips, and updates.\n\n");

    waitForEnter();
}

void duringEarthquake()
{
    printf("\n");
    printf("\033[0;31mWHAT TO DO DURING AN EARTHQUAKE!!\033[0m\n\n");
	printf("1. \e[1mDrop, Cover, and Hold On:\e[m Immediately get down on your hands and knees, take cover under sturdy furniture, and hold on until the shaking stops.\n\n");
	printf("2. \e[1mStay Indoors if You Are Inside:\e[m Do not run outside; its safer to stay inside and away from windows and exterior walls.\n\n");
	printf("3. \e[1mMove Away from Windows and Glass:\e[m Glass can shatter during an earthquake, so get away from windows, mirrors, and other breakables.\n\n");
	printf("4. \e[1mStay Clear of Heavy or Hanging Objects:\e[m Avoid being near bookshelves, cabinets, ceiling fans, and light fixtures that could fall.\n\n");
	printf("5. \e[1mUse Your Arm to Shield Your Head and Neck:\e[m If no cover is available, crouch against an interior wall and protect your head and neck with your arms.\n\n");
	printf("6. \e[1mDo Not Use Elevators:\e[m Power outages or damage may trap you; always use stairs if evacuation becomes necessary afterward.\n\n");
	printf("7. \e[1mIf You are in Bed, Stay There:\e[m Lie face down and cover your head with a pillow unless you are under a heavy light fixture or ceiling hazard.\n\n");
	printf("8. \e[1mIf You are Outside, Move to an Open Area:\e[m Stay away from buildings, power lines, streetlights, and trees that could fall or collapse.\n\n");
	printf("9. \e[1mIf You are Driving, Stop Safely:\e[m Pull over to a clear area away from overpasses, bridges, trees, and power lines, and stay inside the vehicle.\n\n");
	printf("10. \e[1mStay Calm and Focused:\e[m Panic can lead to poor decisions. Try to stay mentally aware and ready to respond as needed.\n\n");
    waitForEnter();
}

void afterEarthquake()
{
    printf("\n");
    printf("\033[0;33mWHAT TO DO AFTER AN EARTHQUAKE?\033[0m\n\n");
	printf("1. \e[1mCheck Yourself and Others for Injuries:\e[m Administer first aid if necessary and seek medical help for serious injuries.\n\n");
	printf("2. \e[1mBe Ready for Aftershocks:\e[m Move carefully and stay alert, as aftershocks can follow the main quake and cause further damage.\n\n");
	printf("3. \e[1mInspect Your Home for Hazards:\e[m Check for structural damage, gas leaks, fires, water line breaks, and electrical issues.\n\n");
	printf("4. \e[1mTurn Off Utilities if Needed:\e[m Shut off gas, electricity, or water if you suspect leaks or damage to avoid further risk.\n\n");
	printf("5. \e[1mListen to Authorities for Updates:\e[m Use a battery-powered radio or phone to get emergency broadcasts and follow instructions.\n\n");
	printf("6. \e[1mAvoid Using the Phone Unnecessarily:\e[m Keep phone lines clear for emergency communications.\n\n");
	printf("7. \e[1mEvacuate if Your Home is Unsafe:\e[m Leave the building if its structurally compromised and go to an open, safe area or emergency shelter.\n\n");
	printf("8. \e[1mStay Away from Damaged Areas:\e[m Do not re-enter buildings until authorities declare them safe; avoid roads unless necessary.\n\n");
	printf("9. \e[1mHelp Neighbors if You Can:\e[m Assist those who are injured, elderly, or disabled, especially if emergency services are delayed.\n\n");
	printf("10. \e[1mDocument Damage for Insurance:\e[m Take photos of structural damage and property loss to help with insurance claims later.\n\n"); 
    waitForEnter();
}

void educationalHub()
{
	system("clear || cls");
    int choice;

    do {
        printf("\033[36mEARTHQUAKE SECTOR EDUCATIONAL HUB\033[0m\n");
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
            case 1: beforeEarthquake(); 
                    break;
            case 2: duringEarthquake(); 
                    break;
            case 3: afterEarthquake(); 
                    break;
            case 4: printf("Returning to Main Menu...\n");
                    sleep(2);
					system("clear || cls");
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

void editReport(reportType reports[], int *numReports)
{
	int index, choice;
	
	printf("\nEdit Report\n");
	viewRecords(reports, numReports);
	printf("Enter the report number to edit (1 to %d): ", *numReports);
	scanf("%d", &index);
	index--;

	if (index >= 0 && index < *numReports)
	{
		printf("\nWhich field would you like to edit?\n");
		printf("1. Date\n");
		printf("2. Time\n");
		printf("3. Magnitude\n");
		printf("4. Location\n");
		printf("5. Details\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: 
				reports[index].date = getDate();
				break;
			case 2:
				reports[index].time = getTime();
				break;
			case 3:
				printf("Enter Magnitude: ");
				scanf("%f", &reports[index].magnitude);
				break;
			case 4:
				printf("Enter Location: ");
				scanf(" %[^\n]", reports[index].location);
				break;
			case 5:
				printf("Enter Details: ");
				scanf(" %[^\n]", reports[index].details);
				break;
			default:
				printf("Invalid choice. No changes made.\n");
		}
	}
	printf("\nDetails successfully changed.\n\n");
}

void deleteReport(reportType reports[], int *numReports)
{
	int i, index;

	printf("\nDelete Report\n");
	viewRecords(reports, numReports);

	printf("Enter the report number to delete (1 to %d): ", *numReports);
	scanf("%d", &index);
	index--;

	if (index >= 0 && index < *numReports)
	{
		for (i = index; i < *numReports - 1; i++)
		{
			reports[i] = reports[i + 1];
		}
		(*numReports)--;
		printf("Report #%d deleted successfully.\n", index + 1);
	}
	else
	{
		printf("Invalid report number.\n");
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
        printf("No records available.\n\n");
    }
}

int importRecords(reportType reports[], int *numReports)
{
 	FILE *fp;
 	fp = fopen("exports.txt", "r");
 	
 	if (fp != NULL)
 	{
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
   printf("\n");
}

void printByMagnitude(reportType reports[], int numReports)
{
   int i;
   
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
   printf("\n");
}

void printByLocation(reportType reports[], int numReports)
{
   int i;
   
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
   printf("\n");
}

void printByTime(reportType reports[], int numReports)
{
   int i;

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
   printf("\n");
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
}

void sortByMagnitude(reportType sMag[], int numReports)
{  
	int i, j, min;
    reportType temp;

   for (i = 0; i < numReports - 1; i++) {
      min = i; // min is the index of the lowest element

     for (j = i + 1; j < numReports; j++)
           if (sMag[min].magnitude > sMag[j].magnitude) // Check if the numerical order is correct
             min = j;

            if (i != min) {
             temp = sMag[i];
             sMag[i] = sMag[min];
             sMag[min] = temp;
          }
      }
}

void sortByLocation(reportType sLoc[], int numReports)
{
	int i, j, min;
	reportType temp;

   for (i = 0; i < numReports - 1; i++) {
      min = i; // min is the index of the lowest element

     for (j = i + 1; j < numReports; j++)
           if (strcmp(sLoc[min].location, sLoc[j].location) > 0) // Check if the string is alphabetically arranged
             min = j;
        
            if (i != min) {
            temp = sLoc[i];
            sLoc[i] = sLoc[min];
            sLoc[min] = temp;
          }
      }
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
} 

void searchByDate(reportType sDate[], int numReports)
{
	sortByDate(sDate, numReports);

	int i, j = 0, count = 0;
	reportType dateIndex[numReports]; // Stores the indexes of the dates of the searched

	dateType search = getDate(); // Get the date to search for

	for (i = 0; i < numReports; i++)
	{
		if (sDate[i].date.year == search.year && 
			sDate[i].date.month == search.month && 
			sDate[i].date.day == search.day)
		{
			dateIndex[j] = sDate[i]; // Store the found date
			count++;
			j++;
		}
	}

	if (j == 0)
	{
		printf("No records found for the date %s/%s/%s.\n\n", search.monthStr, search.dayStr, search.yearStr);
	}
	else
	{
		printByDate(dateIndex, count); // Print the found dates
	}
}

void searchByMagnitude(reportType sMag[], int numReports)
{
	sortByMagnitude(sMag, numReports);

	int i, j = 0, count = 0;
	reportType magIndex[numReports]; // Stores the indexes of the magnitudes of the searched

	float search;
	printf("Enter Magnitude: ");
	scanf("%f", &search); // Get the magnitude to search for

	for (i = 0; i < numReports; i++)
	{
		if (sMag[i].magnitude == search)
		{
			magIndex[j] = sMag[i]; // Store the found magnitude
			count++;
			j++;
		}
	}

	if (j == 0)
	{
		printf("No records found for the magnitude %.1f.\n\n", search);
	}
	else
	{
		printByMagnitude(magIndex, count); // Print the found magnitudes
	}
}

void searchByLocation(reportType sLoc[], int numReports)
{
	sortByLocation(sLoc, numReports);

	int i, j = 0, count = 0;
	reportType locIndex[numReports]; // Stores the indexes of the locations of the searched

	String100 search;
	printf("Enter Location: ");
	scanf(" %[^\n]", search); // Get the location to search for

	for (i = 0; i < numReports; i++)
	{
		if (strcmp(sLoc[i].location, search) == 0)
		{
			locIndex[j] = sLoc[i]; // Store the found location
			count++;
			j++;
		}
	}

	if (j == 0)
	{
		printf("No records found for the location %s.\n\n", search);
	}
	else
	{
		printByLocation(locIndex, count); // Print the found locations
	}
}

void searchByTime(reportType sTime[], int numReports)
{
	sortByTime(sTime, numReports);

	int i, j = 0, count = 0;
	reportType timeIndex[numReports]; // Stores the indexes of the times of the searched

	timeType search = getTime(); // Get the time to search for

	for (i = 0; i < numReports; i++)
	{
		if (sTime[i].time.hour == search.hour && 
			sTime[i].time.minute == search.minute)
		{
			timeIndex[j] = sTime[i]; // Store the found time
			count++;
			j++;
		}
	}

	if (j == 0)
	{
		printf("No records found for the time %s:%s.\n\n", search.hourStr, search.minuteStr);
	}
	else
	{
		printByTime(timeIndex, count); // Print the found times
	}
}

int compareDate(dateType d1, dateType d2)
{
	if (d1.year != d2.year)
	{
		return d1.year - d2.year;
	}
	if (d1.month != d2.month)
	{
		return d1.month - d2.month;
	}
	return d1.day - d2.day;
}

int frequencyInDateFrame(reportType reports[], int *numReports)
{
	sortByDate(reports, *numReports);

	int i, j = 0, count = 0;
	dateType startDate, endDate;
	reportType temp[*numReports];

	printf("\nGet Frequency Within Time Frame\n");
	printf("========================================\n");

	printf("Start Date\n");
	startDate = getDate();
	printf("End Date\n");
	endDate = getDate();

	for (i = 0; i < *numReports; i++)
	{
		if ((compareDate(reports[i].date, startDate) >= 0) &&
			(compareDate(reports[i].date, endDate) <= 0))
		{
			count++;
			temp[j]	= reports[i];
			j++;
		}
	}
	if (count == 0)
	{
		printf("No reports found within the specified time frame.\n\n");
	}
	else
	{
		viewRecords(temp, &count);
	}

	return count;
}

void mostFrequentLocation(reportType reports[], int *numReports)
{
	String100 locations[MAX_REPORTS];
	int frequency[MAX_REPORTS];
	int i, j, locationCount = 0;

	for (i = 0; i < *numReports; i++)
	{
		int found = 0;
		for (j = 0; j < locationCount; j++)
		{
			if (strcmp(reports[i].location, locations[j]) == 0)
			{
				frequency[j]++;
				found = 1;
			}
		}

		if (!found)
		{
			strcpy(locations[locationCount], reports[i].location);
			frequency[locationCount] = 1;
			locationCount++;
		}
	}

	int maxFreq = 0;
	char mostFreqLoc[100];

	for (i = 0; i < locationCount; i++)
	{
		if (frequency[i] > maxFreq)
		{
			maxFreq = frequency[i];
			strcpy(mostFreqLoc, locations[i]);
		}
	}

	if (locationCount > 0)
	{
		printf("\nMost Frequent Location: %s\n", mostFreqLoc);
		printf("Frequency: %d\n\n", maxFreq);
	}
	else
	{
		printf("\nNo data to compute most frequent location.\n\n");
	}
}

void monthWithMostEarthquakes(reportType reports[], int *numReports)
{
	char months[12][3] = {
        "01", "02", "03", "04", "05", "06",
        "07", "08", "09", "10", "11", "12"
    };

    char monthNames[12][11] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
	
	int monthCount[12] = {0};
	int i, j;

	for (i = 0; i < *numReports; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (reports[i].date.monthStr[0] == months[j][0] &&
				reports[i].date.monthStr[1] == months[j][1])
			{
				monthCount[j]++;
			}
		}
	}

	int max = 0, maxIndex = -1;
	
	for (i = 0; i < 12; i++)
	{
		if (monthCount[i] > max)
		{
			max = monthCount[i];
			maxIndex = i;
		}
	}

	if (maxIndex != -1)
	{
		printf("\nMonth with Most Earthquakes: %s\n", monthNames[maxIndex]);
		printf("Number of Earthquakes: %d\n\n", max);
	}
	else
	{
		printf("\nNo data to compute month with most earthquakes.\n\n");
	}
}

void locationMagnitudeCrossTable(reportType reports[], int *numReports)
{
	char locations[MAX_REPORTS][100];
	int magnitudes[MAX_REPORTS]; // Rounded down for easier comparison
	int matrix[100][100] = {0};

	int locationCount = 0, magnitudeCount = 0;
	int i, j, k;

	for (i = 0; i < *numReports; i++)
    {
        int locIndex = -1, magIndex = -1;
        int roundedMag = (int)(reports[i].magnitude);

        for (j = 0; j < locationCount; j++)
        {
            if (strcmp(reports[i].location, locations[j]) == 0)
            {
                locIndex = j;
            }
        }

        if (locIndex == -1)
		{
			strcpy(locations[locationCount], reports[i].location);
			locIndex = locationCount;
			locationCount++;
		}

		for (j = 0; j < magnitudeCount; j++)
		{
			if (magnitudes[j] == roundedMag)
			{
				magIndex = j;
			}
		}

		if (magIndex == -1)
		{
			magnitudes[magnitudeCount] = roundedMag;
			magIndex = magnitudeCount;
			magnitudeCount++;
		}

		matrix[locIndex][magIndex]++;
	}

	for (i = 0; i < magnitudeCount - 1; i++)
	{
		for (j = i + 1; j < magnitudeCount; j++)
		{
			if (magnitudes[i] > magnitudes[j])
			{
				int temp = magnitudes[i];
				magnitudes[i] = magnitudes[j];
				magnitudes[j] = temp;

				for (k = 0; k < locationCount; k++)
				{
					int tempVal = matrix[k][i];
					matrix[k][i] = matrix[k][j];
					matrix[k][j] = tempVal;
				}
			}
		}
	}

	// Determine max location width
	int maxLocWidth = 0;

	for (i = 0; i < locationCount; i++)
	{
		int len = strlen(locations[i]);
		if (len > maxLocWidth)
		{
			maxLocWidth = len;
		}
	}
	maxLocWidth += 2; // Add padding for better formatting

	printf("\nLocation-Magnitude Cross Table:\n\n");

	// Header row
    printf("Location");
	for (i = 8; i < maxLocWidth; i++)
	{
		printf(" ");
	}

    for (j = 0; j < magnitudeCount; j++)
    {
        printf("%5d", magnitudes[j]);
    }
    printf("\n");

    // Separator line
    for (i = 0; i < maxLocWidth + 5 * magnitudeCount; i++)
    {
        printf("-");
    }
    printf("\n");

    // Data rows
    for (i = 0; i < locationCount; i++)
    {
        printf("%s", locations[i]);
		int spaceCount = maxLocWidth - strlen(locations[i]);

		for (j = 0; j < spaceCount; j++)
		{
			printf(" ");
		}

        for (j = 0; j < magnitudeCount; j++)
        {
            printf("%5d", matrix[i][j]);
        }
        printf("\n");
    }

	if (locationCount == 0 || magnitudeCount == 0)
	{
		printf("No data to display in the cross table.\n");
	}
    printf("\n");
}
