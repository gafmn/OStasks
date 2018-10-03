//
// Created by Madina Gafarova on 03/10/2018.
//
#include <stdlib.h>
#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    int *arr = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++){
        arr[i] = i;
    }
    for (int i = 0; i < N ; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
