#include "header.h"
#include "userAuth.h"
#include "userAuth.c"
#include "functions.c"

void printLanding()
{
    printf("\033[34mPROJECT NOAH: \033[32mEARTHQUAKE SECTOR\033[0m\n\n");
    printf("1. Sign Up\n");
    printf("2. Log In\n");
    printf("3. Forgot Password\n");
    printf("4. Exit\n");
}

void printMainMenu()
{
    reportType reports[MAX_REPORTS];
    int reportCount = 0;
    int choice;

    do
    {
        printf("\n\033[33mMAIN MENU\033[0m\n");
        printf("1. Earthquake Reporting System\n");
        printf("2. Earthquake Sector Information Hub\n");
        printf("3. Educational Hub\n");
        printf("4. Logout\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printReportLanding(reports, &reportCount);
                break;
            case 2:
                printInfoLanding(reports, &reportCount);
                break;
            case 3:
                educationalHub();
                break;
            case 4:
                printf("\n\nLogging Out\n");
                sleep(3);
        }
    } while (choice != 4);
}

void printReportLanding(reportType reports[], int *numReports)
{
	int choice;

    do {
        printf("\n\033[36mEARTHQUAKE REPORT SECTOR\033[0m\n");
        printf("1. Report an Earthquake\n");
        printf("2. Edit a Record\n");
        printf("3. Delete a Record\n");
        printf("4. Export Records\n");
        printf("5. Return to Main Menu\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addReport(reports, numReports);
                printf("\n");
                break;
            case 2:
                // editReport(reports, *numReports); TBI
                printf("\n");
                break;
            case 3:
                // deleteReport(reports, numReports); TBI
                printf("\n");
                break;
            case 4:
                exportRecords(reports, *numReports);
                printf("\n");
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                sleep(2);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);
}

void printInfoLanding(reportType reports[], int *numReports)
{
	int choice, subChoice;

    do
    {
        printf("\n\033[36mEARTHQUAKE SECTOR INFORMATION HUB\033[0m\n");
        printf("1. View All Records\n");
        printf("2. Sort Reports\n");
        printf("3. Search Reports\n");
        printf("4. Computations\n");
        printf("5. Return to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\n");
                viewRecords(reports, numReports);
                break;

            case 2:
                printf("\nSort Reports By:\n");
                printf("1. Magnitude\n");
                printf("2. Location\n");
                printf("3. Time\n\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice)
                {
                    case 1:
                        // sortByMagnitude(reports, *numReports); TBI
                        break;
                    case 2:
                        // sortByLocation(reports, *numReports); TBI
                        break;
                    case 3:
                        // sortByTime(reports, *numReports); TBI
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;

            case 3:
                printf("\nSearch Reports By:\n");
                printf("1. Date\n");
                printf("2. Magnitude\n");
                printf("3. Location\n");
                printf("4. Time\n\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice)
                {
                    case 1:
                        // searchByDate(reports, *numReports); TBI
                        break;
                    case 2:
                        // searchByMagnitude(reports, *numReports); TBI
                        break;
                    case 3:
                        // searchByLocation(reports, *numReports); TBI
                        break;
                    case 4:
                        // searchByTime(reports, *numReports); TBI
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;

            case 4:
                printf("\nComputation Options:\n");
                printf("1. Frequency Within Timeframe\n");
                printf("2. Most Frequent Location\n");
                printf("3. Month with Most Earthquakes\n");
                printf("4. Location-Magnitude Cross Table\n\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);

                switch (subChoice)
                {
                    case 1:
                        // frequencyWithinTimeframe(reports, *numReports); TBI
                        break;
                    case 2:
                        // mostFrequentLocation(reports, *numReports); TBI
                        break;
                    case 3:
                        // monthWithMostEarthquakes(reports, *numReports); TBI
                        break;
                    case 4:
                        // locationMagnitudeCrossTable(reports, *numReports); TBI
                        break;
                    default:
                        printf("Invalid choice.\n");
                }
                break;

            case 5:
                printf("Returning to Main Menu...\n");
                sleep(2);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() 
{
    int choice;
    
    printf("Welcome to...\n\n\n");
    sleep(3);
    
    do
    {
        printLanding();
        printf("\nEnter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            signUp();
            break;
        case 2:
            logIn();
            break;
        case 3:
            forgotPassword();
            break;
        case 4:
            printf("Thank you for using \033[34mPROJECT NOAH: \033[32mEARTHQUAKE SECTOR\033[0m");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        } 
    } while (choice != 4);

    return 0;
}
