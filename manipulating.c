//The code now includes the clear_input_buffer() function, which is called when the last character in the buffer is not a newline. his situation occurs when the user input exceeds the buffer size, leaving the buffer without enough space to store the newline character that fgets typically appends. 
//A new function, is_only_whitespace(), was added to check if the user-entered substring is composed solely of whitespace characters. This check is performed after removing the newline character and before searching for the substring in the main string.

#define _CRT_SECURE_NO_WARNINGS
#include "manipulating.h"
// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // discard characters until newline or EOF
}

// Check if the string consists only of whitespace
int is_only_whitespace(const char* str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return 0; // Found a non-whitespace character
        }
        str++;
    }
    return 1; // String consists only of whitespace
}


void manipulating(void) {
    // Display start message for the string searching demo
    printf("*** Start of Searching Strings Demo ***\n");

    // Define buffer arrays for the main string and the substring
    char haystack[BUFFER_SIZE];
    char needle[BUFFER_SIZE];

    // Pointer for storing the start of the substring within the main string
    char* occurrence = NULL;

    // Start a loop to get input from the user
    do {
        // Prompt the user to enter the main string or 'q' to quit
        printf("Type the string (q - to quit):\n");
        // Read the main string from the user input
        if (!fgets(haystack, BUFFER_SIZE, stdin)) {
            // If reading fails, clear the input buffer to avoid issues on the next read
            clear_input_buffer();
            continue; // Start the loop over, skipping the rest of this iteration
        }

        // Check if the last character before the null terminator is not a newline character
        if (haystack[strlen(haystack) - 1] != '\n') {
            // The input exceeded the buffer size and was truncated, warn the user
            clear_input_buffer(); // Clear the remaining characters from the input buffer
            printf("Input exceeded buffer size. Please try again with shorter input.\n");
            continue; // Start the loop over, prompting for a new string
        }

        // Remove the trailing newline character from the input
        haystack[strcspn(haystack, "\n")] = '\0';

        // If the user entered 'q', exit the loop
        if (strcmp(haystack, "q") == 0) break;

        // Prompt the user to enter the substring
        printf("Type the substring:\n");
        // Read the substring from the user input
        if (!fgets(needle, BUFFER_SIZE, stdin)) {
            // If reading fails, clear the input buffer to avoid issues on the next read
            clear_input_buffer();
            continue; // Start the loop over, skipping the rest of this iteration
        }

        // Check if the last character before the null terminator is not a newline character
        if (needle[strlen(needle) - 1] != '\n') {
            // The input exceeded the buffer size and was truncated, warn the user
            clear_input_buffer(); // Clear the remaining characters from the input buffer
            printf("Input exceeded buffer size. Please try again with shorter input.\n");
            continue; // Start the loop over, prompting for a new substring
        }

        // Remove the trailing newline character from the input
        needle[strcspn(needle, "\n")] = '\0';

        // Ensure the substring is not empty or composed only of whitespace
        if (strlen(needle) == 0 || is_only_whitespace(needle)) {
            // Inform the user that an empty or whitespace-only substring is not valid
            printf("Searching for an empty or whitespace-only substring is not allowed. Please enter a valid substring.\n");
            continue; // Start the loop over, asking for a valid substring
        }

        // Search for the substring within the main string
        occurrence = strstr(haystack, needle);
        if (occurrence) {
            // If found, report the position of the substring within the main string
            printf("\"%s\" found at %ld position\n", needle, (long)(occurrence - haystack));
        }
        else {
            // If not found, inform the user that the substring was not found
            printf("Not found\n");
        }

        // Continue the loop indefinitely until 'q' is entered
    } while (1);

    // Display closing message for the string searching demo
    printf("*** End of Searching Strings Demo ***\n\n");
}
