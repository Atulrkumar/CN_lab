/*1. Write a C program to swap the content of 2 variables entered through the
command line using function and pointer.*/
#include <stdio.h>
#include <stdlib.h>

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <value1> <value2>\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Before swapping content :\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    swapValues(&num1, &num2);

    printf("After swapping content :\n");
    printf("num1 = %d\n", num1);
    printf("num2 = %d\n", num2);

    return 0;
}