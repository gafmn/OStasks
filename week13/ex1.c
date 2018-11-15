#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1024
#define TESTSIZE 100


int n;
int m;
int* existing;
int* available;
int** current_allocation;
int** request;


void input_error() {
    fprintf(stderr, "Input file parsing error");
    exit(1);
}


void read_input(const char* filename) {
    FILE *fp;
    char str[MAXCHAR];
    char* token;
    char separators[] = " ";
    int* test_array;
    int** test_matrix;
    int i;
    int j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Couldn't open the file %s", filename);
        exit(1);
    }

    // Get first line of the input file
    if (fgets(str, MAXCHAR, fp) == NULL) input_error();

    test_array = malloc(TESTSIZE * sizeof(int));

    // Get all numbers from this line
    token = strtok(str, separators);
    for (i = 0; token != NULL; i++) {
        sscanf(token, "%d", &test_array[i]);
        token = strtok(NULL, separators);
    }

    // Set number of resources
    n = i;

    // Allocate memory for vectors
    existing = malloc(n * sizeof(int));
    available = malloc(n * sizeof(int));

    // Copy first line integers to existence vector
    memcpy(test_array, existing, n * sizeof(int));

    // Pass empty line and then read availability vector
    fgets(str, MAXCHAR, fp);
    if (fgets(str, MAXCHAR, fp) == NULL) input_error();

    token = strtok(str, separators);
    for (i = 0; token != NULL; i++) {
        sscanf(token, "%d", &available[i]);
        token = strtok(NULL, separators);
    }

    // Pass empty line and read current allocation matrix
    fgets(str, MAXCHAR, fp);

    test_matrix = (int**)malloc(TESTSIZE * sizeof(int*));

    i = 0;
    do {
        if (fgets(str, MAXCHAR, fp) == NULL) input_error();

        test_matrix[i] = (int*)malloc(n * sizeof(int));

        token = strtok(str, separators);
        for (j = 0; token != NULL; j++) {
            sscanf(token, "%d", &test_matrix[i][j]);
            token = strtok(NULL, separators);
        }

        i++;
    } while (str[0] != '\n');

    // Set number of programs
    m = i - 1;

    // Copy test matrix to request matrix
    current_allocation = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < n; i++) {
        current_allocation[i] = (int*)malloc(n * sizeof(int));
        memcpy(test_matrix[i], current_allocation[i], n * sizeof(int));
    }

    request = (int**)malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) {
        request[i] = (int*)malloc(n * sizeof(int));
    }

    // Read request matrix
    for (i = 0; i < m; i++) {
        if (fgets(str, MAXCHAR, fp) == NULL) input_error();

        token = strtok(str, separators);
        for (j = 0; token != NULL; j++) {
            sscanf(token, "%d", &request[i][j]);
            token = strtok(NULL, separators);
        }
    }

    fclose(fp);
}


int main() {
    read_input("input_dl.txt");

    return 0;
}
