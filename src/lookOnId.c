#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){

    int index = 0;

    a3Emp*current = headLL;

    while(current != NULL)
    {
        index++;
        
        if(current->empId == whichEmpId){
            return index;
        }

        current = current->nextEmployee;

    }
    if (current == NULL){
        printf("There are no employees at the moment");
        return 0;
    }
    return -1;
}
