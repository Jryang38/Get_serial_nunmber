#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../lib/serverserial.h"

int main() {
    int options;
    char server_name[100];
    char serial_number[100];
    char uuid[100];

    printf("Enter an option: \n");
    printf("0: Print to system-serial-number\n");
    printf("1: Print to baseboard-serial-number\n");
    printf("2: Print to chassis-serial-number\n");
    scanf("%d", &options);
    switch(options){
    case 0:
        if ( (get_server_name(server_name, sizeof(server_name)) == 0) && 
             (get_server_serial(serial_number, sizeof(serial_number)) == 0) &&
         (get_server_uuid(uuid, sizeof(uuid)) == 0) ) {
            printf("Server Name: %s\n", server_name);
            printf("Server Serial Number: %s\n", serial_number);
            printf("Server UUID: %s\n", uuid);
        } else {
            printf("Error getting system info.\n");
        }
        break;
    case 1:
        if (get_baseboard_name(server_name, sizeof(server_name)) == 0 && get_baseboard_serial(serial_number, sizeof(serial_number)) == 0) {
            printf("Baseboard Name: %s\n", server_name);
            printf("Baseboard Serial Number: %s\n", serial_number);
        } else {
            printf("Error getting system info.\n");
        }
        break;
     case 2:
         if (get_chassis_serial(serial_number, sizeof(serial_number)) == 0) {
             printf("Chassis Serial Number: %s\n", serial_number);
         } else {
             printf("Error getting system info.\n");
         }
        break;
    default:
        printf("Invalid option.\n");
        break;
    }

    return 0;
}

