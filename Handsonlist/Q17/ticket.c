#include <stdio.h>

int main() {
    FILE *file = fopen("ticket_number.txt", "w");
    if (file == NULL) {
        perror("error in file oepneing");
        return 1;
    }
    fprintf(file, "1");
    fclose(file);
    printf("Ticket number initialized to 1.\n");
    return 0;
}


/*Ticket number initialized to 1.*/

