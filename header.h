#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LENGTH (256)

typedef char String20[21]; // For general inputs
typedef char String100[101]; // For longer text inputs
typedef char String500[501]; // For very long text inputs (like details and descriptions)

typedef struct{
char user_name[MAX_LENGTH];
char password[MAX_LENGTH];
char encrypted_User[MAX_LENGTH];
char encrypted_Ps[MAX_LENGTH];
}info;


typedef struct reportTag 
{
    String20 date;
    String20 time;
    float magnitude;
    String100 location;
    String500 details;
} reportType;



#endif