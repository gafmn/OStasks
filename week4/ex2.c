#include <stdio.h>
#include <zconf.h>

int main() {
    int i = 0;
    while(i < 3){
        fork();
        sleep(5);
        i++;
    }
    return 0;
}