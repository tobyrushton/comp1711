#include <stdio.h>

int main() {
    int temp;
    
    printf("Enter the temperature: ");
    scanf("%d", &temp);

    if(temp >= -10 && temp <= 40){
        printf("Temperature is within -10 to 40");
    }
    else {
        printf("Temperature is not within -10 to 40");
    }

    return 0;
}