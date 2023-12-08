#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Globals
FitnessData FitnessArray[1000];
int count = 0;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

int open_file(char *filename, char *method, FILE **file) {
    *file = fopen(filename, method);
    if(!*file){
        printf("Error: invalid file\n");
        return 1;
    }

    return 0;
}

void sort(){
    int swapped = 0;

    // optimised bubble sort
    do {
        swapped = 0;
        for(int i = 0; i < count - 1; i++){
            if (FitnessArray[i].steps < FitnessArray[i + 1].steps){
                FitnessData temp = FitnessArray[i];
                FitnessArray[i] = FitnessArray[i+1];
                FitnessArray[i + 1] = temp;
                swapped = 1;
            }
        }
    } while(swapped == 1);
}

int populate_array(FILE *file){
    char line[100];

    while(fgets(line, 100, file)){
        // unsure as to why 100 size is needed but it wont copy otherwise
        char date[100] = "";
        char time[5] = "";
        int steps = -1;
		tokeniseRecord(line, ',', date, time, &steps);
        if(date == "" || time == "" || steps == -1){
            printf("Error: invalid file\n");
            return 1;
        }
        strcpy(FitnessArray[count].date, date);
        strcpy(FitnessArray[count].time, time);
        FitnessArray[count].steps = steps;
        count++;
	}

    return 0;
}

void write_to_file(FILE *file){
    for(int i =0; i < count; i++){
        fprintf(file, "%s\t%s\t%d\n", FitnessArray[i].date, FitnessArray[i].time, FitnessArray[i].steps);
    }
}

int main() {
    printf("Enter filename: ");
    // FitnessData_2023.csv
    char filename[100];
    scanf("%s", filename);

    FILE *file;
    int success = open_file(filename, "r", &file);
    if(success == 1) return success;

    success = populate_array(file);
    if(success == 1) return success;
    sort();

    FILE *output;
    success = open_file(strcat(filename, ".tsv"), "w+", &output);
    if(success == 1) return success;
    write_to_file(output);

    fclose(file);
    fclose(output);

    return 0;
}