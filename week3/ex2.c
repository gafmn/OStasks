//
// Created by Madina Gafarova on 29/08/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int array[], int n){
    int i, j;
    for (i = 0 ; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]){
                 swap(& array[j], &array[j + 1]);
            }
        }
    }
}

void print_result(int array[], int n){
    int i;

    for (i = 0; i < n - 1; i++ ){
        printf("%d\n", array[i]);
    }
}
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr, n);
    printf("Sorted array: \n");
    print_result(arr, n);
    return 0;
}

