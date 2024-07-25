#include <stdio.h>

int main() {
    unsigned int num =305419896;
    char byte1, byte2, byte3, byte4;

   // printf("Enter a number: ");
    //scanf("%u", &num);

    byte1 = (num & 0xFF);        
    byte2 = (num >> 8) & 0xFF;  
    byte3 = (num >> 16) & 0xFF;  
    byte4 = (num >> 24) & 0xFF;  

    printf("Byte 1: %d \n", byte1, byte1);
    printf("Byte 2: %d \n", byte2, byte2);
    printf("Byte 3: %d \n", byte3, byte3);
    printf("Byte 4: %d \n", byte4, byte4);

    return 0;
}
