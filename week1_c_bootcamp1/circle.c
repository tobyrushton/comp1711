#include <stdio.h>

int main() {
    int r;
    float pi = 3.14, a;

    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    a = r*r*pi;

    printf("The are of the circle is %f\n", a);

    return 0;
}