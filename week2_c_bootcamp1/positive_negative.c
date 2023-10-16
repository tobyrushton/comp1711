#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num == 0){
        printf("The number is zero\n");
    } else {
        int res = num % 2;
        if(res == 0) {
            printf("Number is even\n");
        } else {
            printf("Number is odd\n");
        }
    }
    return 0;
}