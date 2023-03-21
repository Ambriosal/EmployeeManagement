#include "../include/headerA3.h"

// Removes a selected employee from list
void fireOne(a3Emp **headLL, int whichOne)
{

    a3Emp *current = *headLL;
    a3Emp *prev = NULL;
    int total = 0;

    int i = 1;
    while (current != NULL && i < whichOne)
    { // Traverses list until selection employee
        prev = current;
        current = current->nextEmployee;

        i++;
    }

    // if given position is out of range
    if (current == NULL)
    {
        printf("That is out of range.\n");
        return;
    }

    // if node to remove is head node
    if (prev == NULL)
    {
        *headLL = current->nextEmployee;
    }
    else
    {
        prev->nextEmployee = current->nextEmployee;
    }

    a3Emp *count = *headLL;

    while (count != NULL)
    {
        total++;
        count = count->nextEmployee;
    }
    if (total == 1)
    {
        printf("There is now 1 employee.");
    }
    else
    {
        printf("There are now %d employees.\n", total);
    }

    free(current);
}