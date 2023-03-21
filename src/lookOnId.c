#include "../include/headerA3.h"

// Finds employee with given ID
int lookOnId(struct employee *headLL, int whichEmpId)
{

    int index = 0; // pos of employee
    a3Emp *current = headLL;

    while (current != NULL)
    { // Traverses list

        index++;
        if (current->empId == whichEmpId)
        {
            return index; // Found position of employee
        }

        current = current->nextEmployee;
    }

    return -1; // Employee could not be found
}
