#include "header.h"
#include "userAuth.h"

void encryptUser(info *data)
{   
	input temp = "";
	input encrypted = "";
	int i = 0; 
	int j = 0;
	int found = 0;

	equivalence text[73] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G",
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", ".", "1", "2", "3",
							"4", "5", "6", "7", "8", "9", "0"}; 	

	int length = strlen(data->user_name);

	int dupe = sizeof(text) / sizeof(text[0]);

	while(j < length && i < dupe)
	{
      temp[j] = data->user_name[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_encrypter(lIndex, encrypted);
         
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

    equivalence text[73] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G", 
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", ".", "1", "2", "3",
							"4", "5", "6", "7", "8", "9", "0"}; 

	int length = strlen(data->password);

	int dupe = sizeof(text) / sizeof(text[0]);

	printf("%d\n", dupe);

	while(j < length && i < dupe)
	{
      temp[j] = data->password[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_encrypter(lIndex, encrypted);
         
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
		strcpy(data->encrypted_Ps, encrypted);
	  }

	  }

}


void dencryptUser(info *data)
{
	input temp = "";
	input dencrypted ="";
	int i = 0; 
	int j = 0;
	int found = 0;
	equivalence text[73] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G", 
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", ".", "1", "2", "3",
							"4", "5", "6", "7", "8", "9", "0"}; 		



	int length = strlen(data->encrypted_User);

	int dupe = sizeof(text) / sizeof(text[0]);

	while(j < length && i < dupe)
	{
      temp[j] = data->encrypted_User[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_dencrypter(lIndex, dencrypted);
         
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
		strcpy(data->user_name, dencrypted);
	  }

	  }
}  

void dencryptPS(info *data)
{
	input temp = "";
	input dencrypted ="";
	int i = 0; 
	int j = 0;
	int found = 0;
	equivalence text[73] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G", 
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", ".", "1", "2", "3",
							"4", "5", "6", "7", "8", "9", "0"}; 



	int length = strlen(data->encrypted_Ps);

	int dupe = sizeof(text) / sizeof(text[0]);

	while(j < length && i < dupe)
	{
      temp[j] = data->encrypted_Ps[j];

	  if(temp[j] == text[i][0])
	  {
         int *lIndex = &i;
   
	    letter_dencrypter(lIndex, dencrypted);
         
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
		strcpy(data->password, dencrypted);
	  }

	}




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
	FILE *fp;
	fp = fopen("users.txt", "r");
	input username, password, inputUser, inputPass;
	info login;
	int found = 0;
	
	if (fp != NULL)
	{
		printf("\033[33mLOG IN\033[0m\n");
		printf("Enter Username: ");
		scanf("%s", username);
		printf("Enter Password: ");
		scanf("%s", password);
		
		printf("\n");
		
		while (fscanf(fp, "%s %s", login.encrypted_User , login.encrypted_Ps) != EOF)
		{
             dencryptUser(&login); // Dencrypt the string output of user
			 dencryptPS(&login); // Dencrypt the string output of password

			 strcpy(inputUser, login.user_name);
			 strcpy(inputPass, login.password);

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
	FILE *fp;
	fp = fopen("users.txt", "r");
	input username, password, inputUser,inputPassword, newPs;
	info fPassword;
	int found = 0;
	int close = 1;
	
	if (fp != NULL)
	{
		printf("\033[33mFORGET PASSWORD\033[0m\n");
		printf("Enter username: ");
		scanf("%s", inputUser);
		
		while (fscanf(fp, "%s %s", fPassword.encrypted_User, fPassword.encrypted_Ps) != EOF)
		{
            dencryptUser(&fPassword); // Dencrypt the string output of user
			dencryptPS(&fPassword); // Dencrypt the string output of password

			 strcpy(username, fPassword.user_name);
			 strcpy(password, fPassword.password);

			if (strcmp(username, inputUser) == 0)
			{			
				printf("Enter your original password: ");
				scanf("%s", inputPassword);

				if(strcmp(password, inputPassword) == 0)
				 {
                   printf("The password you entered is the same\n");
				   found = 1;
				 }
                 else
				 {
				   fclose(fp);

				   fp = fopen("users.txt", "a");

				   printf("The password is incorrect\n");
			       printf("Enter your new password: ");
				   scanf("%s", newPs);

				   strcpy(fPassword.password, newPs);

				   encryptUser(&fPassword);
				   encryptPS(&fPassword);

                   fprintf(fp, "%s  ", fPassword.encrypted_User);  // Encrypts the string output of user
				   fprintf(fp, "%s\n", fPassword.encrypted_Ps);    // Encrypts the string output of password

				   found = 1;

				   fclose(fp);
				   printf("Password successfully changed.\n");
                     
				}
			} 
				   
		}
		
		close = fclose(fp);
		if (close == 0)
		{
			if (found == 1)
			{
				printf("Login successful! Welcome, %s!\n", inputUser);
			}
			else
			{	
				printf("Login failed. Incorrect username.\n");
			}
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
            forgotPassword();
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