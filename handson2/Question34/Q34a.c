Name : 32.c
Author : Anshul Kakirde
Description: 34. Write a program to create a concurrent server.
a. use fork

Date:  21 sept 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = { .sin_family = AF_INET, .sin_port = htons(8080), .sin_addr.s_addr = INADDR_ANY };
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (fork() == 0) {
            char buffer[1024];
            read(client_fd, buffer, 1024);
            printf("Message from client: %s\n", buffer);
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }
    close(server_fd);
    return 0;
}
/*Message from client: Hello, Server


*/
