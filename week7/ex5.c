//
// Created by Madina Gafarova on 03/10/2018.
//

#include <stdio.h>
int main() {
    char **s; // array of pointers
    char *foo = "Hello World";
    s = &foo;
    printf("s is %s\n", *s);
    s[0] = foo;
    printf("s[0] is %s\n",s[0]);
    return(0);
}
