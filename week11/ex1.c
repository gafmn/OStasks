//
// Created by Madina Gafarova on 31/10/2018.
//
#include <stdio.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char* is_mapped;
    struct stat fStat;
    int fOpen;

    if (stat("ex1.txt", &fStat) < 0){
        perror("Cannot get stat of file");
        return ENOENT;
    }

    if ((fOpen = open("ex1.txt", O_RDWR)) < 0){
        perror("File cannot be opened");
        return ENOENT;
    }

    size_t fSize = (size_t)fStat.st_size;
    char* phrase = "This is a nice day";
    size_t phraseLen = strlen(phrase);
    if (fSize < phraseLen){
        fSize = phraseLen;
    }

    if((is_mapped = (char*)(long)(mmap(0, fSize, PROT_READ| PROT_WRITE, MAP_SHARED, fOpen, 0))) == MAP_FAILED){
        perror("Cannot map the file");
        return EBADF;

    }

    memset(is_mapped, ' ', fSize);
    strcpy(is_mapped, phrase);
    is_mapped[phraseLen] = ' ';
    munmap(is_mapped, fSize);

    return 0;
}