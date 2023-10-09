#include <stdio.h>

int main() {
    char string[32];
    char reversed[32];

    printf("Enter string to be reversed: ");
    scanf("%s", string);

    for(int i = 0; i<32; i++) {
        reversed[i] = string[31-i];
    };

    printf("%s\n", reversed);

    return 0;
}