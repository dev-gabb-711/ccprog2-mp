#include <stdio.h>
#include <string.h>

typedef char String20[21];
typedef char String100[101];
typedef char String500[501];

typedef struct reportTag
{
    String20 date;
    String20 time;
    float magnitude;
    String100 location;
    String500 details;
} reportType;

int importRecords(reportType reports[], int *numReports)
{
    FILE *fp;
    fp = fopen("exports.txt", "r");

    if (fp != NULL)
    {
        *numReports = 0;

        while (fscanf(fp, " EARTHQUAKE ENTRY #%*d\n") != EOF)
        {
            fscanf(fp, " Date: %20s\n", reports[*numReports].date);
            fscanf(fp, " Time: %20s\n", reports[*numReports].time);
            fscanf(fp, " Magnitude: %f\n", &reports[*numReports].magnitude);
            fscanf(fp, " Location: %[^\n]\n", reports[*numReports].location);
            fscanf(fp, " Details: %[^\n]\n", reports[*numReports].details);
            (*numReports)++;
        }
        fclose(fp);
        return 1;
    }
    else
    {
        return 0;
    }
}

void viewRecords(reportType reports[], int *numReports)
{
    int i;
    if (*numReports == 0)
    {
        importRecords(reports, numReports);
    }

    if (*numReports > 0)
    {
        printf("========================================\n\n");
        for (i = 0; i < *numReports; i++)
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
    else
    {
        printf("No records available.\n");
    }
}

int main()
{
    reportType reports[100];
    int numReports = 0;

    viewRecords(reports, &numReports);
}