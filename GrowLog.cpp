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

const int kArrayLength = 81;

int gardenInfo(char name[]);



int main(void)
{
	int stringCheck = -1;

	char stringToParse[kArrayLength] = "";
	char blank[] = "";
	char gardenName[kArrayLength] = "";

	FILE* fp = NULL;
	FILE* ofp = NULL;

	char record[kArrayLength] = { 0 };



	// open the previously written file for reading
	fp = fopen("garden.txt", "r");
	// check for error upon opening
	if (fp == NULL)
	{
		printf("Can't open file for reading\n");
		return -4;
	}

	// get each of the lines from the file
	while ((fgets(record, sizeof record, fp) != NULL))
	{
		// do we have an error
		if (ferror(fp))
		{
			// there's an error
			printf("Error reading line from "
				"file\n");
			// try to close the file, since we're done with it
			if (fclose(fp) != 0)
			{
				// we can't even close the file
				printf("Can't close file opened "
					"for reading\n");
			}
			return -5;
		}

		strcpy(stringToParse, record);
		// display the line we got from the file
		//printf("Got: %s\n", stringToParse);


		//printf("%s", displayName);

		stringToParse[strcspn(stringToParse, "\n")] = 0;
		strcpy(gardenName, stringToParse);

		char blankString[] = "";
		if (int comparison = strcmp(stringToParse, blankString) == 0)
		{
			//printf("BLANK\n");
			continue;
		}

		if (feof(fp))
		{
			// we've reached the end of the file
			break;
		}
	}

	// close the file we are reading from 
	if (fclose(fp) != 0)
	{
		// can't close it 
		printf("Can't close file opened for "
			"reading\n");
		return -6;
	}








	printf("\t\t\tWelcome to the Grow Log!\n\n");


	stringCheck = strcmp(gardenName, blank);


	if (stringCheck == 1)
	{
		printf("\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n\t\tX Your garden: %s X\n\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n", gardenName);
	}
	//check for if string is not blank
	stringCheck = strcmp(gardenName, blank);



	if (stringCheck == 0)
	{
		printf("\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n\t\tX You have no garden Name! Choose one. X\n\n\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
		printf("\n\t\tMy garden name: ");
		fgets(gardenName, 81, stdin);
		printf("\n");

		printf("\n\t\tNow Called: %s", gardenName);


		ofp = fopen("garden.txt", "w");
		if (ofp == NULL)
		{
			printf("Can't open output file\n");
			if (fclose(ofp) != 0)
			{
				printf("Error closing input file\n");
			}
		}
		else
		{
			for (int i = 0; i < 1; i++)
			{
				fputs(gardenName, ofp);
			}
			if (fclose(ofp) != 0)
			{
				printf("Error closing input file\n");
			}



		}
		if (fclose(ofp) != 0)
		{
			// can't close it 
			printf("Can't close file opened for "
				"reading\n");
			return -6;
		}

		
	}
	//gardenInfo(gardenName);
	return 0;
}

int gardenInfo(char name[])
{
	char fileName[81] = { 0 };
	strcpy(fileName, name);
	strcat(fileName, ".txt");

	return 0;
}

















	///// UI BELOW

