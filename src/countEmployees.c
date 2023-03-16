#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){

    a3Emp *current = headLL;
    int total = 0;

    while(current != NULL){
        total++;

        current = current->nextEmployee;

    }

    return total;
}
