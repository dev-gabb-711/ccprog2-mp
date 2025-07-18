#include "header.h"
#include "userAuth.h"

void encryptUser(info *data)
{   
	input temp = "";
	input encrypted ="";
	int i = 0; 
	int j = 0;
	int found = 0;

	equivalence text[71] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G",
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", "1", "2", "3", "4",
							"5", "6", "7", "8", "9", "0"}; 	

	int length = strlen(data->user_name);

	int dupe = 71;

	while(j < length && i < dupe)
	{
      temp[j] = data->user_name[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_encrypt(lIndex, encrypted);
         
        j++;
		i = 0;
		found = 1;

	   }

       else if(temp[j] != text[i][0])
      {
        i++;
        found = 0;
	  }

	  if(j == length && found == 1)
	  {
        strcat(encrypted, "\0");

		strcpy(data->encrypted_User, encrypted);
	  }

	  }

}


void encryptPS(info *data)
{   
	input temp = "";
	input encrypted ="";
	int i = 0; 
	int j = 0;
	int found = 0;
	equivalence text[71] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G",
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", "1", "2", "3", "4",
							"5", "6", "7", "8", "9", "0"}; 	



	int length = strlen(data->password);

	int dupe = 71;

	while(j < length && i < dupe)
	{
      temp[j] = data->password[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_encrypt(lIndex, encrypted);
         
        j++;
		i = 0;
		found = 1;

	   }

       else if(temp[j] != text[i][0])
      {
        i++;
        found = 0;
	  }

	  if(j == length && found == 1)
	  {
        strcat(encrypted, "\0");

		strcpy(data->encrypted_Ps, encrypted);
	  }

	  }

}


void dencryptData()
{
    // Assign a value for letter
    

	// fprintf(fp, "%s\n", personal.encrypted_Ps);




}

void signUp()
{
	FILE *fp;
	info personal;
	
	fp = fopen("users.txt", "a");
	
	if (fp != NULL)
	{
	  printf("\033[33mSIGN UP\033[0m\n");
	  printf("Enter Username: "); 
	  scanf("%s", personal.user_name);
	  printf("Enter Password: ");
	  scanf("%s", personal.password);
	  
	  encryptUser(&personal); // Encrypts the User Name
	  encryptPS(&personal); // Encrypts the User Password

	  fprintf(fp, "%s  ", personal.encrypted_User);
	  fprintf(fp, "%s\n", personal.encrypted_Ps);
		
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

void logIn()  // Required to use the encrypted string
{
	/*
	    TO DO

        Choose an Approach
	    1. Scan the printed string and make it to an encrypted form
		2. De-encrypt the scanned info from the .txt file
	*/

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

void forgotPassword() // Required to use the encrypted string
{

	/*
	    TO DO
		
		Choose an approach:
	    1.a. Scan the printed string and make it to an encrypted form
		1.b. De-encrypt the scanned info from the .txt file

		2. Append/Overwrite the previous data stored (Depends on intepretation)

		3. Allow strcmp() for if the encrypted & entered password are the same
		   it will inform the user that they can login with the entered password.
	*/


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