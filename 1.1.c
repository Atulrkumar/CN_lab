#include <stdio.h>

// Function to swap the contents of two variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1,num2;
    printf("Enter 1st variable\n");
    scanf("%d", &num1);
    printf("Enter 2nd variable\n");
    scanf("%d", &num2);

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);

    // Swap the contents of num1 and num2
    swap(&num1, &num2);

    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}