#include <stdio.h>
#include <unistd.h>

void beforeEarthquake()
{
    printf("\n");
    char ch[10];
    printf("PLACEHOLDER\n\n");
    printf("Press Any Key and Enter to Return to Main Menu...");
    scanf("%s", ch);
}

void duringEarthquake()
{
    printf("\n");
    char ch[10];
    printf("PLACEHOLDER\n\n");
    printf("Press Any Key and Enter to Return to Main Menu...");
    scanf("%s", ch);
}

void afterEarthquake()
{
    printf("\n");
    char ch[10];
    printf("PLACEHOLDER\n\n");
    printf("Press Any Key and Enter to Return to Main Menu...");
    scanf("%s", ch);
}

void educationalHub()
{
    int choice;

    do {
        printf("\033[33mEARTHQUAKE SECTOR EDUCATIONAL HUB\033[0m\n");
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
                    sleep(3);
                    break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
} 

// FOR TESTING PURPOSES ONLY THIS FILE WILL BE CONNECTED TO MAIN.C FILE
int main()
{
    educationalHub();
    return 0;
}