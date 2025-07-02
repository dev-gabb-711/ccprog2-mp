#include <stdio.h>
#include <unistd.h>

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
    int choice;

    do
    {
        printf("\033[33mMAIN MENU\033[0m\n");
        printf("Username: SampleUser\n\n");
            printf("1. Earthquake Reporting System\n");
            printf("2. Earthquake Sector Information Hub\n");
            printf("3. Educational Hub\n");
            printf("4. Logout\n");
            printf("\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Earthquake Reporting System functionality to be implemented.\n");
            break;
        case 2:
            printf("Earthquake Sector Information Hub functionality to be implemented.\n");
            break;
        case 3:
            printf("Educational Hub functionality to be implemented.\n");
            break;
        case 4:
            printf("Logging out...\n");
            sleep(3);
            system("cls"); // Clear the console for better visibility
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void signUp()
{
    printf("Sign Up functionality to be implemented.\n");
}

void logIn()
{
    printf("Log In functionality to be implemented.\n");
    printf("Please enter your username and password.\n\n");
    // Here you would typically collect user input and validate it.
    // For now, we will just simulate a successful login.
    printf("Login successful!\n");

    sleep(3);

    system("cls"); // Clear the console for better visibility

    printMainMenu();
}

void forgotPassword()
{
    printf("Forgot Password functionality to be implemented.\n");
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
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        } 
    } while (choice != 4);

    return 0;
}