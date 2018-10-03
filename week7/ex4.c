//
// Created by Madina Gafarova on 03/10/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc/malloc.h>


void *my_realloc(void* ptr, size_t newLength) {
    if (newLength == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL){
        return malloc(newLength);
    }
    void * newPtr;
    newPtr = malloc(newLength);
    int currentLength = malloc_size(ptr);
    if (currentLength < newLength){
        newPtr = memcpy(newPtr, (int*) ptr, currentLength);
    }  else {
        newPtr = memcpy(newPtr, (int*) ptr, newLength);
    }
    free(ptr);
    return newPtr;

}
int main(){
    int N = 5;
    int *arr = malloc(N * sizeof(int));
    
    for (int i=0; i<N; i++){
        arr[i] = 0;
        printf("%d ", arr[i]);
    }
    printf("%s\n", "_______");
    
    
    int M = 8;
    arr = my_realloc(arr, M * sizeof(int));
    for (int i=0; i<M; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}

