#include "../include/headerA3.h"

void fireAll(a3Emp **headLL)
{

    a3Emp *current = *headLL;
    a3Emp *temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->nextEmployee;
        for (int i = 0; i < temp->numDependents; i++)
        {

            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free(temp);
    }

    *headLL = NULL;
}
