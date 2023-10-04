/*
 * Implement your solution in thi file
 *
 */

#include <stdio.h> //Import input and output module
#include <stdlib.h> // Import library module
#include <string.h> //Import strings modules manipulate stringd

#define MAX_LINE_LENGTH 1024

// Function to read a single line from a file and return it as a dynamically allocated string.
char* readString(FILE* file) {
    char* line = NULL;
    char buffer[MAX_LINE_LENGTH];
    size_t len = 0;

    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        len = strlen(buffer);

        // Remove the newline character at the end of the line, if present.
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Allocate memory for the line and copy it.
        line = (char*)malloc(len + 1);
        if (line != NULL) {
            strcpy(line, buffer);
        }
    }

    return line;
}

//Mystery explode function 
char** mysteryExplode(const char* str, char delimiter, int* count) {
    if (str == NULL || count == NULL) {
        return NULL;
    }

    // Count the number of substrings (delimiter occurrences + 1).
    *count = 1;
    const char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr == delimiter) {
            (*count)++;
        }
        ptr++;
    }
}
