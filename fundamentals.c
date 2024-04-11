#define _CRT_SECURE_NO_WARNINGS
#define BUFFER_SIZE 80 //whitebox testing
#define NUM_INPUT_SIZE 10
#include "fundamentals.h"



void clr(char* ptr)
{
	//This checks for the excess input in the buffer that the fgets didn't read
	if (strchr(ptr, '\n') == NULL)
	{
		while (getchar() != '\n')
		{
			;
		}
	}

}


//A function that count's the white space in the first elements of the string arrays
int whiteSpaceChkr(const char string[])
{
	int spceFlag = 0 , spceCtr = 0;

	while (spceFlag == 0)
	{
		if (string[spceCtr] == ' ')
		{
			spceCtr++; // To count the space in the front of the input
		}
		else
		{
			spceFlag = 1; //Exit Flag to stop counting
		}
	}

	return spceCtr;//return the value from the loop
}
void fundamentals(void)
{
	//------>> Added Variables for Counter and Flag 
	int ctr = 0, spaceFlag = 0;


	/* Version 3 */
	//>> insert here

	//Variables Declaration for Version 3
	char destination[BUFFER_SIZE];
	char source[BUFFER_SIZE];
	//Flag and Counter Variables
	int opening = 1;
	spaceFlag = 0;
	ctr = 0;

	printf("*** Start of Copying Strings Demo ***\n");

	//loop for the Program because this program will continue looking for valule
	do
	{		
		if (opening == 0)//Check if it will display if it's the programs first loop
		{									
			printf("Destination string is reset to empty\n");
		}	
		opening = 0; // To flag not to show the Reset Header
		printf("Type the source string (q - to quit):\n");
		fgets(source,BUFFER_SIZE,stdin); //Get the input from the User
		clr(source); // Clear the buffer after fetting the Input from the User so it won't overflow
		source[strlen(source) - 1] = '\0'; //setting null Terminator at the end of the string

		spaceFlag = whiteSpaceChkr(source);//Invoke the Function that check for white space character 


		//T----->> To Validate Input if it is an actual string or just empty spacess or accidentally pressing the 'Enter' key
		if ((source[0] != '\0') && (source[spaceFlag] != '\0'))
		{
				if (strcmp(source, "q") != 0) //Filter if the String Inputed is "q" character that will end the loop and exit the program
				{
					printf("\n");
					strcpy(destination, source); //Copy the Content of the String Inputed by the user and transfer it to the destination variable
					printf("New destination string is \'%s\'\n", destination);//print and display the value of the Destination variable
					printf("\n");

					//destination variables is set to empty  safe state
					for (ctr = 0;ctr < strlen(source);ctr++)
					{
						destination[ctr] = '\0'; //Setting the value of each elements by NULL
					}
				}
		}
		else
		{
			//ERROR message if the input is invalid
			printf("ERROR: Empty Character please try Again! \n\n");
		}

	} while (strcmp(source,"q") != 0);// if the user input is q it will exit this loop
	printf("*** End of Copying Strings Demo ***\n");


}