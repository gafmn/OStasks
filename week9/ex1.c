//
// Created by Madina Gafarova on 17/10/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct FrameTable{
    int pageNumber;
    int age;
}*frameTable;

struct PageTable{
    int frameNumber;
    bool valid;
}*pageTable;

void ageIncrease(int frames){
    int i;
    for (i = 0; i < frames; i++){
        frameTable[i].age++;
    }
}

int oldestInd(int frames){
    int oldest = 1;
    int ind;

    int i;

    for (i = 0; i < frames; i++){
        if (oldest< frameTable[i].age){
            oldest = frameTable[i].age;
            ind = i;
        }
    }
    return ind;

}

int main(){
    printf("Number of frames:\n");
    int frames;
    scanf("%d", &frames);

    frameTable = malloc(sizeof(frameTable)* frames);
    pageTable=malloc(sizeof(pageTable));

    int i;

    for (i = 0; i < frames; i++){
        frameTable[i].age = 0;
    }

    FILE *input = fopen("input.txt", "r");
    int request;
    int missCounter = 0;
    int hitCounter = 0;
    int requestCounter = 0;
    int frameTableCounter = 0;

    while (!feof(input)){
        fscanf(input, "%d", &request);
        requestCounter++;

        if(pageTable[request].valid == false){
            frameTable[frameTableCounter].pageNumber = request;
            pageTable[request].valid = true;
            pageTable[request].frameNumber = frameTableCounter;
            frameTableCounter++;
            missCounter++;
        } else{
            hitCounter++;
        }

        if (frameTableCounter == frames){
            break;
        }
    }

    while(!feof(input)){
        fscanf(input, "%d", &request);
        requestCounter++;
        ageIncrease(frames);

        if (pageTable[request].valid == false){
            int oldPage = oldestInd(frames);
            pageTable[frameTable[oldPage].pageNumber].valid = false;
            frameTable[oldPage].pageNumber = request;
            frameTable[oldPage].age = 0;
            pageTable[request].valid = true;
            pageTable[request].frameNumber = oldPage;
            missCounter++;
        }else{
            hitCounter++;
        }
    }

    printf("Miss count: %d\n", missCounter);
    printf("Hit count: %d\n", hitCounter);
    printf("Ratio %f\n",(float)hitCounter / (float)missCounter );
    fclose(input);

    free(frameTable);
    free(pageTable);
    return 0;

}