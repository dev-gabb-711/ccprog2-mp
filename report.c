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

void viewReports(reportType reports[], int reportCount)
{
    int i;
    printf("========================================\n\n");
    for (i = 0; i < reportCount; i++)
    {
        printf("Earthquake Report #%d:\n", i + 1);
        printf("Date: %s\n", reports[i].date);
        printf("Time: %s\n", reports[i].time);
        printf("Magnitude: %.1f\n", reports[i].magnitude);
        printf("Locatino: %s\n", reports[i].location);
        printf("Details: %s\n", reports[i].details);
        printf("\n========================================\n\n");
    }
}

void exportEntries(reportType reports[], int reportCount)
{
	String20 filename;
	FILE *fp;
	int i;
	
	if (reportCount == 0)
	{
		printf("No data to export.\n\n");
	}
	else
	{
		printf("Enter filename to export data into: ");
		scanf("%20s", filename);
		printf("\n");
		
		fp = fopen(filename, "w");
		if (fp != NULL)
		{
			for (i = 0; i < reportCount; i++)
			{
				fprintf(fp, "EARTHQUAKE ENTRY #%d\n", i + 1);
				fprintf(fp, "Date: %s\n", reports[i].date);
				fprintf(fp, "Time: %s\n", reports[i].time);
				fprintf(fp, "Magnitude: %.2f\n", reports[i].magnitude);
				fprintf(fp, "Location: %s\n", reports[i].location);
				fprintf(fp, "Details: %s\n", reports[i].details);
				fprintf(fp, "\n");
			}
			int close = fclose(fp);
			if (close == 0)
			{
				printf("Data exported successfully to %s!\n", filename);
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
        printf("2. View Reports\n");
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
                if (reportCount == 0)
                {
                    printf("\n");
                    printf("No reports available.\n");
                }
                else
                {
                    printf("\n");
                    viewReports(reports, reportCount);
                }
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
