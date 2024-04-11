#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Added for isdigit function
#include <ctype.h> 

#include <limits.h>

#define BUFFER_SIZE 80

void converting(void)
{
    printf("*** Start of Converting Strings to long Demo ***\n");

    //**************Variables Initialization******************//

    char longString[BUFFER_SIZE]; // Buffer to hold input string
    long longNumber; // Variable to store converted long integer
    char* endptr; // Pointer for strtol() function

    //********************************************************//

    do {

        printf("Type the long numeric string (q - to quit):\n");

        // Read input string from user
        fgets(longString, BUFFER_SIZE, stdin);

        // Remove newline character from input, '\n' is the newline character
        longString[strcspn(longString, "\n")] = '\0';

        // Check if input is empty
        if (strlen(longString) == 0) {
            printf("Empty input. Please enter a valid string.\n");
            // Skip the rest of the loop iteration and prompt for input again
            continue; 
        }

        // Check if input is "q" to quit
        if (strcmp(longString, "q") == 0) 
        {
            // Exit the loop if input is "q"
            break;
        }

        // Check if input is a valid long integer
        int validInput = 1; // Assume input is valid
        for (int i = 0; i < strlen(longString); i++) {
            if (!isdigit(longString[i]) && longString[i] != '-' && longString[i] != '+') 
            {
                // Mark input as invalid if it contains non-digit characters
                validInput = 0;
                // Exit the loop if invalid characters are found
                break;
            }
        }

        if (!validInput) {
            printf("Invalid input. Please enter an integer value.\n");
            // Skip the rest of the loop iteration and prompt for input again
            continue;
        }

        // Convert string to long integer
        longNumber = strtol(longString, &endptr, 10);

        // Check for conversion errors
        if ((longNumber == LONG_MAX || longNumber == LONG_MIN) && errno == ERANGE) 
        {
            printf("Number is out of range for long integer. Please input a valid number.\n");
        }
        else if (*endptr != '\0') 
        {
            printf("Invalid input. Please enter an integer value.\n");
        }
        else 
        {
            printf("Converted number is %ld\n", longNumber);
        }

      // Loop indefinitely until "q" is entered
    } while (1); 

    printf("*** End of Converting Strings to long Demo ***\n\n");
}
