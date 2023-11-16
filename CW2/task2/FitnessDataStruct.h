#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

void menu(){
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported \n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");
}

void populateArray(FITNESS_DATA *stepCount[], char fileName[]){
	char line[100];

	while(fgets(line, 100, fileName)){
		tokeniseRecord(line, ",", stepCount[count].date, stepCount[count].time, stepCount[count].steps);
		count++;
	}
}	

int open_file(FILE *file) {
	char fileName[100];
	// take the filename and attempt to open
    printf("Input filename: ");
    scanf("%s", fileName);

	file = fopen(fileName, "r");
	if(!file){
		printf("Error: Could not find or open the file.\n");
        return 1;
	} else {
		printf("File successfully loaded.\n");
		populateArray(stepCount, fileName);
		return 0;
	}
}

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

#endif // FITNESS_DATA_STRUCT_H
