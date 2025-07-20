#ifndef USERAUTH_H
#define USERAUTH_H
#include "header.h"

typedef char input[256];
typedef char equivalence[3];

void letter_encrypter(int *index, input scrabble)
{
   switch(*index){
    
	// UpperCase & Lower Case tracking
	case 0: strcat(scrabble, "M"); break; // Uppercase 'A'
	case 1: strcat(scrabble, "m"); break; // LowerCase 'a'
	case 2: strcat(scrabble, "S"); break;
	case 3: strcat(scrabble, "s"); break;
	case 4: strcat(scrabble, "W"); break;
	case 5: strcat(scrabble, "w"); break;
	case 6: strcat(scrabble, "U"); break;
	case 7: strcat(scrabble, "u"); break;
	case 8: strcat(scrabble, "L"); break;
	case 9: strcat(scrabble, "l"); break;
	case 10: strcat(scrabble, "R"); break;
	case 11: strcat(scrabble, "r"); break;
	case 12: strcat(scrabble, "E"); break;
	case 13: strcat(scrabble, "e"); break;
	case 14: strcat(scrabble, "Y"); break;
	case 15: strcat(scrabble, "y"); break;
	case 16: strcat(scrabble, "T"); break;
	case 17: strcat(scrabble, "t"); break;
	case 18: strcat(scrabble, "I"); break;
	case 19: strcat(scrabble, "i"); break;
	case 20: strcat(scrabble, "X"); break;
	case 21: strcat(scrabble, "x"); break;
	case 22: strcat(scrabble, "K"); break;
	case 23: strcat(scrabble, "k"); break;
	case 24: strcat(scrabble, "J"); break;
	case 25: strcat(scrabble, "j"); break;
	case 26: strcat(scrabble, "P"); break;
	case 27: strcat(scrabble, "p"); break;
	case 28: strcat(scrabble, "V"); break;
	case 29: strcat(scrabble, "v"); break;
	case 30: strcat(scrabble, "B"); break;
	case 31: strcat(scrabble, "b"); break;
	case 32: strcat(scrabble, "O"); break;
	case 33: strcat(scrabble, "o"); break;
	case 34: strcat(scrabble, "Q"); break;
	case 35: strcat(scrabble, "q"); break;
	case 36: strcat(scrabble, "C"); break;
	case 37: strcat(scrabble, "c"); break;
	case 38: strcat(scrabble, "F"); break;
	case 39: strcat(scrabble, "f"); break;
	case 40: strcat(scrabble, "Z"); break;
	case 41: strcat(scrabble, "z"); break;
	case 42: strcat(scrabble, "G"); break;
	case 43: strcat(scrabble, "g"); break;
	case 44: strcat(scrabble, "H"); break;
	case 45: strcat(scrabble, "h"); break;
	case 46: strcat(scrabble, "N"); break;
	case 47: strcat(scrabble, "n"); break;
	case 48: strcat(scrabble, "D"); break;
	case 49: strcat(scrabble, "d"); break;
	case 50: strcat(scrabble, "A"); break;
	case 51: strcat(scrabble, "a"); break;

	// Special Characters tracking
	case 52: strcat(scrabble, "_"); break;
	case 53: strcat(scrabble, "?"); break;
	case 54: strcat(scrabble, "+"); break;
	case 55: strcat(scrabble, "&"); break;
	case 56: strcat(scrabble, "."); break;
	case 57: strcat(scrabble, "%"); break;
	case 58: strcat(scrabble, "$"); break;
	case 59: strcat(scrabble, "#"); break;
	case 60: strcat(scrabble, "!"); break;
	case 61: strcat(scrabble, "*"); break;

	// Numerical Tracking
	case 62: strcat(scrabble, "0"); break;
	case 63: strcat(scrabble, "9"); break;
	case 64: strcat(scrabble, "8"); break;
	case 65: strcat(scrabble, "7"); break;
	case 66: strcat(scrabble, "6"); break;
	case 67: strcat(scrabble, "5"); break;
	case 68: strcat(scrabble, "4"); break;
	case 69: strcat(scrabble, "3"); break;
	case 70: strcat(scrabble, "2"); break;
	case 71: strcat(scrabble, "1"); break;
	default: strcat(scrabble, "\0"); break;
   }
}


 void letter_dencrypter(int *index, input scrabble)
{
   switch(*index){
    
	// UpperCase & Lower Case tracking
	case 0: strcat(scrabble, "Z"); break; // Uppercase 'A'
	case 1: strcat(scrabble, "z"); break; // LowerCase 'a'
	case 2: strcat(scrabble, "P"); break;
	case 3: strcat(scrabble, "p"); break;
	case 4: strcat(scrabble, "S"); break;
	case 5: strcat(scrabble, "s"); break;
	case 6: strcat(scrabble, "Y"); break;
	case 7: strcat(scrabble, "y"); break;
	case 8: strcat(scrabble, "G"); break;
	case 9: strcat(scrabble, "g"); break;
	case 10: strcat(scrabble, "T"); break;
	case 11: strcat(scrabble, "t"); break;
	case 12: strcat(scrabble, "V"); break;
	case 13: strcat(scrabble, "v"); break;
	case 14: strcat(scrabble, "W"); break;
	case 15: strcat(scrabble, "w"); break;
	case 16: strcat(scrabble, "J"); break;
	case 17: strcat(scrabble, "j"); break;
	case 18: strcat(scrabble, "M"); break;
	case 19: strcat(scrabble, "m"); break;
	case 20: strcat(scrabble, "L"); break;
	case 21: strcat(scrabble, "l"); break;
	case 22: strcat(scrabble, "E"); break;
	case 23: strcat(scrabble, "e"); break;
	case 24: strcat(scrabble, "A"); break;
	case 25: strcat(scrabble, "a"); break;
	case 26: strcat(scrabble, "X"); break;
	case 27: strcat(scrabble, "x"); break;
	case 28: strcat(scrabble, "Q"); break;
	case 29: strcat(scrabble, "q"); break;
	case 30: strcat(scrabble, "N"); break;
	case 31: strcat(scrabble, "n"); break;
	case 32: strcat(scrabble, "R"); break;
	case 33: strcat(scrabble, "r"); break;
	case 34: strcat(scrabble, "F"); break;
	case 35: strcat(scrabble, "f"); break;
	case 36: strcat(scrabble, "B"); break;
	case 37: strcat(scrabble, "b"); break;
	case 38: strcat(scrabble, "I"); break;
	case 39: strcat(scrabble, "i"); break;
	case 40: strcat(scrabble, "D"); break;
	case 41: strcat(scrabble, "d"); break;
	case 42: strcat(scrabble, "O"); break;
	case 43: strcat(scrabble, "o"); break;
	case 44: strcat(scrabble, "C"); break;
	case 45: strcat(scrabble, "c"); break;
	case 46: strcat(scrabble, "K"); break;
	case 47: strcat(scrabble, "k"); break;
	case 48: strcat(scrabble, "H"); break;
	case 49: strcat(scrabble, "h"); break;
	case 50: strcat(scrabble, "U"); break;
	case 51: strcat(scrabble, "u"); break;

	// Special Characters tracking
	case 52: strcat(scrabble, "_"); break;
	case 53: strcat(scrabble, "?"); break;
	case 54: strcat(scrabble, "+"); break;
	case 55: strcat(scrabble, "&"); break;
	case 56: strcat(scrabble, "."); break;
	case 57: strcat(scrabble, "%"); break;
	case 58: strcat(scrabble, "$"); break;
	case 59: strcat(scrabble, "#"); break;
	case 60: strcat(scrabble, "!"); break;
	case 61: strcat(scrabble, "*"); break;

	// Numerical Tracking
	case 62: strcat(scrabble, "0"); break;
	case 63: strcat(scrabble, "9"); break;
	case 64: strcat(scrabble, "8"); break;
	case 65: strcat(scrabble, "7"); break;
	case 66: strcat(scrabble, "6"); break;
	case 67: strcat(scrabble, "5"); break;
	case 68: strcat(scrabble, "4"); break;
	case 69: strcat(scrabble, "3"); break;
	case 70: strcat(scrabble, "2"); break;
	case 71: strcat(scrabble, "1"); break;
	default: strcat(scrabble, "\0"); break;
   }
} 




#endif