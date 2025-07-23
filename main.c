#include "header.h"
#include "userAuth.h"
#include "userAuth.c"
// #include "report.c" comment out once it can be connected properly and that data in memory is saved
// #include "info.c"   same here
#include "educModel.c"

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
        printf("\n\033[33mMAIN MENU\033[0m\n");
            printf("1. Earthquake Reporting System\n");
            printf("2. Earthquake Sector Information Hub\n");
            printf("3. Educational Hub\n");
            printf("4. Logout\n");
            printf("\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            printf("\n\n");
			educationalHub();
            break;
        case 4:
            printf("Logging out...\n\n");
            sleep(3);
            break;
        default:
            printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 4);
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
