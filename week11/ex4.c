//
// Created by Madina Gafarova on 01/11/2018.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    char* src;
    char* dest;
    int fileIn;
    int fileOut;

    struct stat bufferStat;
    fileIn = open("ex1.txt", O_RDONLY);
    fstat(fileIn, &bufferStat);
    src = mmap(NULL, bufferStat.st_size, PROT_READ, MAP_PRIVATE, fileIn, 0);
    fileOut = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(fileOut, bufferStat.st_size);
    dest = mmap(NULL, bufferStat.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fileOut, 0);

    memcpy(dest, src, bufferStat.st_size);
    munmap(src, bufferStat.st_size);
    munmap(dest, bufferStat.st_size);
    close(fileIn);
    close(fileOut);
    
    return 0;
}