#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *server_ip = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        close(client_sock);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server: %s:%d\n", server_ip, port);

    // Message exchange
    while (1) {
        printf("Enter message (type 'close' to disconnect): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character

        // Send message to the server
        send(client_sock, buffer, strlen(buffer), 0);

        // If the client sends "close", break the loop
        if (strcmp(buffer, "close") == 0) {
            break;
        }

        // Receive message from the server
        memset(buffer, 0, BUFFER_SIZE);
        recv(client_sock, buffer, BUFFER_SIZE, 0);
        printf("Server: %s\n", buffer);
    }

    // Close socket
    close(client_sock);

    printf("Disconnected from server.\n");

    return 0;
}


