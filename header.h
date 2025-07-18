#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH (100)


typedef struct{
char user_name[MAX_LENGTH];
char password[MAX_LENGTH];
char encrypted_User[MAX_LENGTH];
char encrypted_Ps[MAX_LENGTH];
}info;






#endif