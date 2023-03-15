#include "../include/headerA3.h"


void recruitEmployee (struct employee ** headLL){

a3Emp* recruit = (a3Emp*)malloc(sizeof(a3Emp));
    recruit->nextEmployee = NULL;
    
    if (*headLL == NULL) {
        *headLL = recruit;
        return;
    }
    
    a3Emp* last = *headLL;

    while (last->nextEmployee != NULL) {
        last = last->nextEmployee;
    }
    
    last->nextEmployee = recruit;
}
