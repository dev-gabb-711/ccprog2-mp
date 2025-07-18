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

void viewReports(reportType reports[], int totalReports)
{
    int i;
    for (i = 0; i < totalReports; i++)
    {
        printf("Earthquake Report #%d:\n", i + 1);
        printf("Date: %s\n", reports[i].date);
        printf("Time: %s\n", reports[i].time);
        printf("Magnitude: %.1f\n", reports[i].magnitude);
        printf("Locatino: %s\n", reports[i].location);
        printf("Details: %s\n", reports[i].details);
        printf("========================================\n\n");
    }
}

int main()
{
    reportType reports[MAX_REPORT];
    int totalReports = 0;
    int choice;

    do
    {
        printf("\nEarthquake Report System\n");
        printf("1. Add Report\n");
        printf("2. View Reports\n");
        printf("3. Exit\n");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n\n");
                if (totalReports < MAX_REPORT)
                {
                    addReport(&reports[totalReports]);
                    totalReports++;
                    printf("\nReport added successfully!\n");
                }
                else if (totalReports >= MAX_REPORT)
                {
                    printf("\n");
                    printf("Maximum report limit reached!\n");
                }
                break;
            case 2:
                if (totalReports == 0)
                {
                    printf("\n");
                    printf("No reports available.\n");
                }
                else
                {
                    printf("\n");
                    viewReports(reports, totalReports);
                }
                break;
            case 3:
                printf("\n\nExiting...\n");
                sleep(3);
        }
    } while (choice != 3);
    
}