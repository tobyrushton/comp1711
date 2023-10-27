#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// open file function
FILE *open_file (char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1);
    }
    return file;
}

// Complete the main function
int main() {
    char filename [] = "FitnessData_2023.csv";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int row_count = 0;

    // counts the amount of rows in the file
    for(char c = getc(file); c != EOF; c = getc(file)){
        if (c == '\n') // Increment count if this character is newline
            row_count++;
    }

    printf("Number of records in the file: %d\n", row_count);
    fclose(file);

    // reopens file to be read
    FILE *fp = open_file(filename, "r");

    printf("Number of records in the file: %d\n", row_count);

    struct FITNESS_DATA {
        char date[11];
        char time[6];
        int steps;
    };

    struct FITNESS_DATA test[row_count];

    for(int i = 0; i < row_count; i++){
        fgets(line_buffer, buffer_size, fp);

        char date [11] = "";
        char steps [10] = "";
        char time [6] = "";

        tokeniseRecord(line_buffer, ",", date, time, steps);

        test[i].steps = atoi(steps);
        strcpy(test[i].date, date);
        strcpy(test[i].time, time);
    }

    for(int i = 0; i < 3; i++){
        printf("%s/%s/%d\n", test[i].date, test[i].time, test[i].steps);
    }

    fclose(fp);
    return 0;
}