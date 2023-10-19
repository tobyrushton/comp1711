#include <stdio.h>

float volume(float r) {
    return (4/3)*3.14*r*r*r;
}

int main() {
    float r;
    printf("Enter the volume of the sphere: ");
    scanf("%f", &r);
    printf("The volume of the sphere is %f\n", volume(r));

    return 0;
}