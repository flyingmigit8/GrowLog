/* PROGRAMMER : Caleb Cullen
* FIRST VERSION : 2022-03-31
* DESCRIPTION : This is an experimental grow log.
* 
* 1. User opens grow log: greeted with UI. -> Fast selection to add note (automatically appends to text file with time and date)
*
*/
// more error checking

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#pragma warning(disable: 4996)
#define FALSE 1
#define TRUE 0

int main(void)
{
	char blank[] = "";
	char gardenName[81] = "";



	printf("\t\t\tWelcome to the Grow Log!\n\n");

	if (bool stringCheck = strcmp(gardenName, blank) == 1);
	{
		printf("\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n\t\tX You have no garden Name! Choose one. X\n\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("My garden name: ");
		fgets(gardenName, 81, stdin);
		printf("\n");

		printf("Now Called: %s", gardenName);
	}
}