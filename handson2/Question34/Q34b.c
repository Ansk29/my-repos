Name : 32.c
Author : Anshul Kakirde
Description: 34. Write a program to create a concurrent server.

b. use pthread_create
Date:  2024.
============================================================================
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

void* handle_client(void* arg) {
    int client_fd = *(int*)arg;
    char buffer[1024];
    read(client_fd, buffer, 1024);
    printf("Message from client: %s\n", buffer);
    close(client_fd);
    return NULL;
}

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address = { .sin_family = AF_INET, .sin_port = htons(8080), .sin_addr.s_addr = INADDR_ANY };
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_fd);
        pthread_detach(thread);
    }

    close(server_fd);
    return 0;
}

/*Message from client: Hello, Server
*/
