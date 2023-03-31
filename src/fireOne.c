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
        printf("The number selected is out of range.\n");
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

    if(current->dependents != NULL){
        for(int i = 0; i <current-> numDependents; i++){
            free(current->dependents[i]);
        }
        free(current->dependents);
    }

    a3Emp *count = *headLL;

    // Counts # of emp left
    while (count != NULL)
    {
        total++;
        count = count->nextEmployee;
    }

    // Printing # of emp
    if (total == 1)
    {
        printf("There is now 1 employee.");
    }
    else
    {
        printf("There are now %d employees.\n", total);
    }

    // Free info
    if (current != NULL){
        free(current);
    }
}