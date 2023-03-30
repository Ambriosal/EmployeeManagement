#include "../include/headerA3.h"

// Counts total employees in linked list
int countEmployees(a3Emp *headLL)
{

    a3Emp *current = headLL;
    int total = 0; // # of employees

    if (current == NULL)
    {
        return 0;
    }

    while (current != NULL)
    { // Traverses list

        total++;                         // increments
        current = current->nextEmployee; // next employee
    }

    return total;
}
