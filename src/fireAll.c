#include "../include/headerA3.h"

void fireAll(a3Emp **headLL)
{

    a3Emp *current = *headLL;
    a3Emp *temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->nextEmployee;
        free(temp);
    }

    *headLL = NULL;
}
