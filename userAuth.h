#ifndef USERAUTH_H
#define USERAUTH_H

#include "header.h"

typedef char input[100];
typedef char equivalence[3];

equivalence text[71] = {"A", "a", "B", "b", "C", "c", "D", "d", "E", "e", "F", "f", "G",
		                    "g", "H", "h", "I", "i", "J", "j", "K", "k", "L", "l", "M", "m",
							"N", "n", "O", "o", "P", "p", "Q", "q", "R", "r", "S", "s", "T",
							"t", "U", "u", "V", "v", "W", "w", "X", "x", "Y", "y", "Z", "z",
							"!", "#", "$", "%", "*", "&", "+", "?", "_", "1", "2", "3", "4",
							"5", "6", "7", "8", "9", "0"}; 	


void letter_encrypt(int *index, input scrabble)
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
	case 52: strcat(scrabble, "!"); break;
	case 53: strcat(scrabble, "#"); break;
	case 54: strcat(scrabble, "$"); break;
	case 55: strcat(scrabble, "%"); break;
	case 56: strcat(scrabble, "*"); break;
	case 57: strcat(scrabble, "+"); break;
	case 58: strcat(scrabble, "?"); break;
	case 59: strcat(scrabble, "_"); break;

	// Numerical Tracking

	case 60: strcat(scrabble, "1"); break;
	case 61: strcat(scrabble, "2"); break;
	case 62: strcat(scrabble, "3"); break;
	case 63: strcat(scrabble, "4"); break;
	case 64: strcat(scrabble, "5"); break;
	case 65: strcat(scrabble, "6"); break;
	case 66: strcat(scrabble, "7"); break;
	case 67: strcat(scrabble, "8"); break;
	case 68: strcat(scrabble, "9"); break;
	case 69: strcat(scrabble, "0"); break;
   }
}


void letter_dencrypt(int *index, input scrabble)
{
   switch(*index){
    
	// UpperCase & Lower Case tracking
	case 0: strcat(scrabble, "A"); break; 
	case 1: strcat(scrabble, "a"); break; 
	case 2: strcat(scrabble, "B"); break;
	case 3: strcat(scrabble, "b"); break;
	case 4: strcat(scrabble, "C"); break;
	case 5: strcat(scrabble, "c"); break;
	case 6: strcat(scrabble, "D"); break;
	case 7: strcat(scrabble, "d"); break;
	case 8: strcat(scrabble, "E"); break;
	case 9: strcat(scrabble, "e"); break;
	case 10: strcat(scrabble,"F"); break;
	case 11: strcat(scrabble, "f"); break;
	case 12: strcat(scrabble, "G"); break;
	case 13: strcat(scrabble, "g"); break;
	case 14: strcat(scrabble, "H"); break;
	case 15: strcat(scrabble, "h"); break;
	case 16: strcat(scrabble, "I"); break;
	case 17: strcat(scrabble, "i"); break;
	case 18: strcat(scrabble, "J"); break;
	case 19: strcat(scrabble, "j"); break;
	case 20: strcat(scrabble, "K"); break;
	case 21: strcat(scrabble, "k"); break;
	case 22: strcat(scrabble, "L"); break;
	case 23: strcat(scrabble, "L"); break;
	case 24: strcat(scrabble, "M"); break;
	case 25: strcat(scrabble, "m"); break;
	case 26: strcat(scrabble, "N"); break;
	case 27: strcat(scrabble, "n"); break;
	case 28: strcat(scrabble, "O"); break;
	case 29: strcat(scrabble, "o"); break;
	case 30: strcat(scrabble, "P"); break;
	case 31: strcat(scrabble, "P"); break;
	case 32: strcat(scrabble, "Q"); break;
	case 33: strcat(scrabble, "q"); break;
	case 34: strcat(scrabble, "R"); break;
	case 35: strcat(scrabble, "r"); break;
	case 36: strcat(scrabble, "S"); break;
	case 37: strcat(scrabble, "s"); break;
	case 38: strcat(scrabble, "T"); break;
	case 39: strcat(scrabble, "t"); break;
	case 40: strcat(scrabble, "U"); break;
	case 41: strcat(scrabble, "u"); break;
	case 42: strcat(scrabble, "V"); break;
	case 43: strcat(scrabble, "v"); break;
	case 44: strcat(scrabble, "W"); break;
	case 45: strcat(scrabble, "w"); break;
	case 46: strcat(scrabble, "X"); break;
	case 47: strcat(scrabble, "x"); break;
	case 48: strcat(scrabble, "Y"); break;
	case 49: strcat(scrabble, "y"); break;
	case 50: strcat(scrabble, "Z"); break;
	case 51: strcat(scrabble, "z"); break;

	// Special Characters tracking
	case 52: strcat(scrabble, "!"); break;
	case 53: strcat(scrabble, "@"); break;
	case 54: strcat(scrabble, "#"); break;
	case 55: strcat(scrabble, "$"); break;
	case 56: strcat(scrabble, "%"); break;
	case 57: strcat(scrabble, "^"); break;
	case 58: strcat(scrabble, "&"); break;
	case 59: strcat(scrabble, "*"); break;

	// Numerical Tracking

	case 60: strcat(scrabble, "0"); break;
	case 61: strcat(scrabble, "9"); break;
	case 62: strcat(scrabble, "8"); break;
	case 63: strcat(scrabble, "7"); break;
	case 64: strcat(scrabble, "6"); break;
	case 65: strcat(scrabble, "5"); break;
	case 66: strcat(scrabble, "4"); break;
	case 67: strcat(scrabble, "3"); break;
	case 68: strcat(scrabble, "2"); break;
	case 69: strcat(scrabble, "1"); break;
   }
}






#endif