#include "../include/headerA3.h"

// Prints one employee
void printOne(struct employee *headLL, int whichOne)
{

    int index = 0; // pos of employee

    a3Emp *current = headLL;

    while (current != NULL)
    { // Goes through list

        index++; // start at 1
        if (index == whichOne)
        { // When found, prints info
            printf("\tEmployee ID: %d\n", current->empId);
            printf("\tFirst name: %s\n", current->fname);
            printf("\tLast name: %s\n", current->lname);

            // Dependents
            printf("\tDependents: ");
            for (int i = 0; i < current->numDependents; i++)
            {

                printf("%s ", current->dependents[i]);
            }
            printf("\n");
            return;
        }
        current = current->nextEmployee;
    }

    if (headLL == NULL) // If list is empty
    {
        printf("There are no such employees at this moment because the list is empty.\n");
        return;
    }
}
