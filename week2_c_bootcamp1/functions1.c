#include <stdio.h>

int sum(int a, int b) {
    return a+b;
}

int main() {
    int y = 2;
    int z = sum(5, y);

    printf("The sum of 5 and %d is %d\n", y, z);
}
