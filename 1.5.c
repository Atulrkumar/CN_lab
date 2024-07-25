/*5. Write a C program to check whether the Host machine is in Little Endian or
Big Endian. Enter a number, print the content of each byte location and
Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.*/
#include <stdio.h>

union {
    unsigned int num;
    unsigned char bytes[4];
} endianTest;

void checkEndianness() {
    endianTest.num = 0x1;
    if (endianTest.bytes[0] == 1) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }
}

void printBytes(void *ptr, size_t size) {
    unsigned char *bytePtr = (unsigned char*)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("Byte %zu: 0x%02x\n", i, bytePtr[i]);
    }
}

void convertEndianness(unsigned int *num) {
    unsigned char *bytes = (unsigned char*)num;
    size_t start = 0;
    size_t end = sizeof(unsigned int) - 1;
    unsigned char temp;

    while (start < end) {
        temp = bytes[start];
        bytes[start] = bytes[end];
        bytes[end] = temp;
        start++;
        end--;
    }
}

int main() {
    unsigned int num;

    checkEndianness();

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Original number in memory:\n");
    printBytes(&num, sizeof(num));

    convertEndianness(&num);

    printf("Converted number in memory:\n");
    printBytes(&num, sizeof(num));

    printf("Converted number: %u\n", num);

    return 0;
}
