#include <stdio.h>

int lets_get_serious(){
    return 0;
}

int main(){
    printf("\n\n Even functions have adress. \n\n");
    printf("The adress of main function = %p\n\n", (void*)main);
    printf("The adress of lets_get_serious function = %p\n\n", (void*)lets_get_serious);
}