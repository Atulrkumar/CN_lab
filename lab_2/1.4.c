/*4. Write a C Program to enter a number and store the number across the
following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and
print the same.
struct pkt {
char ch1;
char ch2[2];
char ch3;
};*/


#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int num;
    struct pkt packet;

    printf("Enter a number (0-255): ");
    scanf("%d", &num);

    packet.ch1 = (num & 0xF0) >> 4;
    packet.ch2[0] = (num & 0x0F);
    packet.ch2[1] = '\0';
    packet.ch3 = (num & 0x0F);

    printf("Content of ch1: %d\n", packet.ch1);
    printf("Content of ch2[0]: %d\n", packet.ch2[0]);
    printf("Content of ch2[1]: %d\n", packet.ch2[1]);
    printf("Content of ch3: %d\n", packet.ch3);

    int aggregated_num = (packet.ch1 << 4) | (packet.ch2[0] & 0x0F);

    printf("Aggregated number: %d\n", aggregated_num);

    return 0;
}
