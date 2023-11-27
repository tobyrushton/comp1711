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

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

// Globals prototypes
FILE *file;
FITNESS_DATA stepCount[1000];
int count;

void menu(){
    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");
}

void populateArray(){
	char line[100];

	while(fgets(line, 100, file)){
		char steps[5];
		tokeniseRecord(line, ",", 	stepCount[count].date, stepCount[count].time, steps);
		stepCount[count].steps = atoi(steps);
		count++;
	}
}	

int open_file() {
	char fileName[100];
	// take the filename and attempt to open
    printf("Input filename: ");
    scanf("%s", fileName);

	// clears the stdin
	while ( getchar() != '\n' );

	file = fopen(fileName, "r");
	if(!file){
		printf("Error: Could not find or open the file.\n");
        return 1;
	} else {
		printf("File successfully loaded.\n");
		populateArray();
		return 0;
	}
}

FITNESS_DATA find_lowest(){
	FITNESS_DATA lowest = stepCount[0];

	for(int i =1; i<count; i++)
		if(stepCount[i].steps < lowest.steps)
			lowest = stepCount[i];
	
	return lowest;
}

FITNESS_DATA find_highest(){
	FITNESS_DATA highest = stepCount[0];

	for(int i = 1; i < count; i++)
		if(stepCount[i].steps > highest.steps)
			highest = stepCount[i];

	return highest;
}

int find_mean(){
	int total = 0;

	for(int i = 0; i < count; i++)
		total += stepCount[i].steps;

	return total / count;
}

void longest_continuous(FITNESS_DATA *streak){

	// longest and current streak
	int longest = 0, current = 0;
	// count object of start and end of current
	FITNESS_DATA currentStart = stepCount[0], currentEnd = stepCount[0];

	for(int i =0; i < count; i++){
		if(stepCount[i].steps > 500){
			if(current == 0)
				currentStart = stepCount[i];
			currentEnd = stepCount[i];
			current++;
		} else {
			if(current > longest){
				streak[0] = currentStart;
				streak[1] = currentEnd;
				longest = current;
			}
			current = 0;
		}
	}
}

#endif // FITNESS_DATA_STRUCT_H
