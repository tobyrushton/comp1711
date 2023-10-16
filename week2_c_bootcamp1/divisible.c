#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num % 4 == 0 && num % 5 == 0){
        printf("The number is divisible by both 4 and 5\n");
    }
    else {
        printf("The number is not divisible by 4 and 5\n");
    }

    return 0;
}