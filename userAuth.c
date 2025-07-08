#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef char input[100];

void signUp()
{
	FILE *fp;
	fp = fopen("users.txt", "a");
	input username, password; // encryptUser, encryptPW;
	
	if (fp != NULL)
	{
		printf("\033[33mSIGN UP\033[0m\n");
		printf("Enter Username: ");
		scanf("%s", username);
		printf("Enter Password: ");
		scanf("%s", password);
		
		printf("\n");
		
		fprintf(fp, "%s %s\n", username, password);
		int close = fclose(fp);
		if (close == 0)
		{
			printf("Account successfully added!\n");
		}
		else
		{
			printf("Error in adding account\n");
		}
	}
	else
	{
		printf("Error in opening users file\n");
	}
}

void logIn()
{
	FILE *fp;
	fp = fopen("users.txt", "r");
	input username, password, inputUser, inputPass;
	int found = 0;
	
	if (fp != NULL)
	{
		printf("\033[33mLOG IN\033[0m\n");
		printf("Enter Username: ");
		scanf("%s", inputUser);
		printf("Enter Password: ");
		scanf("%s", inputPass);
		
		printf("\n");
		
		while (fscanf(fp, "%s %s", username, password) != EOF)
		{
			if (strcmp(username, inputUser) == 0 && strcmp(password, inputPass) == 0)
			{
				found = 1;
			}
		}
		int close = fclose(fp);
		if (close == 0)
		{
			if (found == 1)
			{
				printf("Login successful! Welcome, %s!\n", inputUser);
			}
			else
			{	
				printf("Login failed. Incorrect username or password.\n");
			}
		}
		else
		{
			printf("Error in logging in.\n");
		}
	}
	else
	{
		printf("Error in opening users file\n");
	}
}

void forgotPassword()
{
	FILE *fp;
	fp = fopen("users.txt", "a");
	input username, password, inputUser;
	int found = 0;
	
	if (fp != NULL)
	{
		printf("\033[33mLOG IN\033[0m\n");
		printf("Enter username: ");
		scanf("%s", inputUser);
		
		while (fscanf(fp, "%s %s", username, password) != EOF)
		{
			if (strcmp(username, inputUser) == 0)
			{
				found = 1;
			}
		}
		fclose(fp);
		if (close == 0)
		{
			if (found == 1)
			{
				printf("Login successful! Welcome, %s!\n", inputUser);
			}
			else
			{	
				printf("Login failed. Incorrect username or password.\n");
			}
		}
		else
		{
			printf("Error in logging in.\n");
		}
	}
	else
	{
		printf("Error in opening users file\n");
	}
}

int main(){
	int choice;
	do
    {
        printf("User Authentication Module (Separate Program but will be added to the main when it is finalized)\n");
        printf("1. Sign Up\n");
        printf("2. Log In\n");
        printf("3. Forgot Password\n");
        printf("4. Exit\n");
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
            // forgotPassword();
            break;
        case 4:
            printf("Exiting...");
            sleep(3);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        } 
    } while (choice != 4);
	
	return 0;
}