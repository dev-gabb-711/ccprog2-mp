// #include "header.h"    Uncomment this line when finished
// #include "report.h"    Uncomment this line when finished

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_REPORT 100

typedef char String20[21]; // For general inputs
typedef char String100[101]; // For longer text inputs
typedef char String500[501]; // For very long text inputs (like details and descriptions)

typedef struct reportTag 
{
    String20 date;
    String20 time;
    float magnitude;
    String100 location;
    String500 details;
} reportType;

void addReport(reportType *reports)
{
    printf("Report an Earthquake\n");
    printf("========================================\n");
    sleep(1);
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%20s", reports->date);
    printf("Enter time (HHMM): ");
    scanf("%20s", reports->time);
    printf("Enter magnitude: ");
    scanf("%f", &reports->magnitude);
    printf("Enter location: ");
    scanf(" %[^\n]", reports->location);
    printf("Enter details: ");
    scanf(" %[^\n]", reports->details);
}

void exportEntries(reportType reports[], int reportCount)
{
	FILE *fp, *reportCounter;
	int i, lastEntry = 0;

    reportCounter = fopen("reportCounter.txt", "r");
    if (reportCounter != NULL)
    {
        fscanf(reportCounter, "%d", &lastEntry);
        fclose(reportCounter);
    }
	
	if (reportCount == 0)
	{
		printf("No data to export.\n\n");
	}
	else
	{
		fp = fopen("exports.txt", "a");
		if (fp != NULL)
		{
			for (i = 0; i < reportCount; i++)
			{
				fprintf(fp, "EARTHQUAKE ENTRY #%d\n", lastEntry + i+ 1);
				fprintf(fp, "Date: %s\n", reports[i].date);
				fprintf(fp, "Time: %s\n", reports[i].time);
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

            reportCounter = fopen("reportCounter.txt", "w");
            if (reportCounter != NULL)
            {
                fprintf(reportCounter, "%d", lastEntry + reportCount);
                fclose(reportCounter);
            }
		}
		else
		{
			printf("Unsuccessful export of data.\n");
		}
	}
}

int main()
{
    reportType reports[MAX_REPORT];
    int reportCount = 0;
    int choice;

    do
    {
        printf("\nEarthquake Report System\n");
        printf("1. Add Report\n");
        printf("2. TBI\n"); // TO BE IMPLEMENTED SEGMENTS
        printf("3. Export Data\n");
        printf("4. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n\n");
                if (reportCount < MAX_REPORT)
                {
                    addReport(&reports[reportCount]);
                    reportCount++;
                    printf("\nReport added successfully!\n");
                }
                else if (reportCount >= MAX_REPORT)
                {
                    printf("\n");
                    printf("Maximum report limit reached!\n");
                }
                break;
            case 2:
                break;
            case 3:
                printf("\n");
                exportEntries(reports, reportCount);
                break;
            case 4:
                printf("\n\nExiting...\n");
                sleep(3);
        }
    } while (choice != 4);
    
}
