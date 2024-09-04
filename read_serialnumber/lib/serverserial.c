#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "serverserial.h"

static int get_output_c(const char *cmd, char *output, int outlen) {
    FILE *fp;
    int i = 0, n = 0;
    char out[256] = {0};

    fp = popen(cmd, "r");
    if (!fp) return -1;

    while (fgets(out, sizeof(out), fp) != NULL);

    pclose(fp);

    for (i = 0; (out[i] != '\0') && (out[i] != '\r') && (out[i] != '\n') && i < (outlen - 1); i++) {
        *(output + i) = out[i];
        n++;
    }
    *(output + n) = '\0';

    return 0;
}

int get_server_name(char *name, int name_len){
    int fd;
    ssize_t bytesRead;

    fd = open(PRODUCT_NAME_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s system-product-name", name, name_len);
    }

    bytesRead = read(fd, name, name_len - 1);

    close(fd);

    if (bytesRead > 0) {
        name[bytesRead - 1] = '\0'; 
    } else {
        printf("Cannot get system name.\n");
        return -1;
    }

    return 0;
}

int get_server_serial(char *serial, int serial_len){
    int fd;
    ssize_t bytesRead;

    fd = open(PRODUCT_SERIAL_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s system-serial-number", serial, serial_len);
    }

    bytesRead = read(fd, serial, serial_len - 1);

     close(fd);

    if (bytesRead > 0) {
        serial[bytesRead - 1] = '\0'; 
    } else {
        printf("Cannot get system serial.\n");
        return -1;
    }

    return 0;
}

int get_server_uuid(char *uuid, int uuid_len){
    int fd;
    ssize_t bytesRead;

    fd = open(PRODUCT_UUID_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s system-uuid", uuid, uuid_len);
    }

    bytesRead = read(fd, uuid, uuid_len - 1);

    close(fd);

    if (bytesRead > 0) {
        uuid[bytesRead - 1] = '\0';
    } else {
        printf("Cannot get system uuid.\n");
        return -1;
    }

    return 0;
}
int get_baseboard_name(char *name, int name_len){
    int fd;
    ssize_t bytesRead;

    fd = open(BOARD_NAME_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s baseboard-product-name", name, name_len);
    }

    bytesRead = read(fd, name, name_len - 1);

    close(fd);

    if (bytesRead > 0) {
        name[bytesRead - 1] = '\0'; 
   } else {
        printf("Cannot get board name.\n");
        return -1;
    }

    return 0;
}

int get_baseboard_serial(char *serial, int serial_len){
    int fd;
    ssize_t bytesRead;

    fd = open(BOARD_SERIAL_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s baseboard-serial-number", serial, serial_len);
    }

    bytesRead = read(fd, serial, serial_len - 1);

    close(fd);

    if (bytesRead > 0) {
        serial[bytesRead - 1] = '\0'; 
    } else {
        printf("Cannot get board serial.\n");
        return -1;
    }

    return 0;
}

int get_chassis_serial(char *serial, int serial_len){
    int fd;
    ssize_t bytesRead;

    fd = open(CHASSIS_SERIAL_FILE_PATH, O_RDONLY);

    if (fd < 0) {
        return get_output_c("dmidecode -s chassis-serial-number", serial, serial_len);
    }

    bytesRead = read(fd, serial, serial_len - 1);

    close(fd);

    if (bytesRead > 0) {
        serial[bytesRead - 1] = '\0'; 
    } else {
        printf("Cannot get chassis serial.\n");
        return -1;
    }

    return 0;
}
