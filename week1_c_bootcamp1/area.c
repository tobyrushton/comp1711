#include <stdio.h>

int main () {
    int h, w;

    printf("Enter the height of the rectangle: ");
    scanf("%d", &h);
    printf("Enter the width of the rectangle: ");
    scanf("%d", &w);

    int area = h*w;
    printf("The area of the rectangle is %d\n", area);

    return 0;
}