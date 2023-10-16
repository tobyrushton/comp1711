#include <stdio.h>

int main() {
    int mark;

    printf("Enter the students marks: ");
    scanf("%d", &mark);

    if(mark >= 70) {
        printf("Distinction has been achieved\n");
    }
    else if(mark >=50){
        printf("Student has passed\n");
    } else {
        printf("Student has failed\n");
    }

    return 0;
}