#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FILE *file;
FITNESS_DATA stepCount[1000];
int count = 0;


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
   while(1) {
        char option;
        menu();
        option = getchar();
        while (getchar() != '\n');

        switch(option){
            case 'a':
            case 'A': {
                int success = open_file();
                if(success == 1) return success;
                break;
            }
            case 'b':
            case 'B':
                printf("Total records: %d\n", count);
                break;
            case 'c':
            case 'C':{
                FITNESS_DATA lowest = find_lowest();
                printf("Fewest steps: %s %s\n", lowest.date, lowest.time);
                break;
            }
            case 'd':
            case 'D':{ 
                FITNESS_DATA highest = find_highest();
                printf("Largest steps: %s %s\n", highest.date, highest.time);
                break;
            }
            case 'e':
            case 'E':{
                int mean = find_mean();
                printf("Mean step count: %d\n", mean);
                break;
            }
            case 'f':
            case 'F':{ 
                FITNESS_DATA streak[2];
                longest_continuous(streak);
                printf("Longest period start: %s %s\n", streak[0].date, streak[0].time);
                printf("Longest period end: %s %s\n", streak[1].date, streak[1].time);
                break;
            }
            case 'q':
            case 'Q':
                // exit loop
                return 0;
                break;
            default:
                // if unregistered input
                printf("Invalid choice. Try again\n");
                break;
        }
    }

    return 0;
}
