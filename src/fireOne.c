#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){

    a3Emp *current = (a3Emp*)malloc(sizeof(a3Emp));

    int index= 0;

    if(*headLL == NULL || whichOne < 1){
        return;
    }

    // if (whichOne == 1){
    //     *headLL = headLL->nextEmployee;
    //     return;
    // }
    while( current != NULL && index < whichOne){
        *headLL = current;
        current = current->nextEmployee;
        index++;
    }

    while(current != NULL)
    {
        index++;
        current = current->nextEmployee;
    }


    if (current == NULL){
        return;
    }

    printf("Currently there are %d employees.", index);

}