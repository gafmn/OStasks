//
// Created by Madina Gafarova on 08/11/2018.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    unsigned char buffer[20];
    int fd = open("/dev/random", O_RDWR);
    read(fd, buffer, 20);
    close(fd);

    FILE *fl = fopen("ex1.txt", "w");
    fprintf(fl, "%s", buffer);
    fclose(fl);

    return 0;
}
