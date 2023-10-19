#include <stdio.h>

float circleArea (float r) {
    return r*r*3.14;
}

int main() {
    float r;
    printf("Input the radius of the circle: ");
    scanf("%f", &r);
    printf("The area of the circe is %f\n", circleArea(r));

    return 0;
}