#include "../include/headerA3.h"

// Prints all info in current linked list
void printAll(struct employee *headLL)
{

    int index = 0; // pos of employee
    int total = 0; // total amount of employees

    a3Emp *current = headLL;

    while (current != NULL)
    { // traverse through the list
        printf("Employee #%d:\n", index + 1);

        printf("\tEmployee Id: %d\n", current->empId);
        printf("\tFirst name: %s\n", current->fname);
        printf("\tLast name: %s \n", current->lname);
        // Dependents
        printf("\tDependents[%d]: ", current->numDependents);

        for (int i = 0; i < current->numDependents; i++)
        {
            printf("%s ", current->dependents[i]);
        }

        printf("\n");
        printf("\n");
        index++;
        total++;
        current = current->nextEmployee;
    }

    if (index == 1)
    {
        printf("Currently, there is one employee.\n");
    }
    else
    {
        printf("Currently, there are %d employees. \n", total);
    }

    if (headLL == NULL)
    {
        printf("There are no employees because the list is empty.\n");
        return;
    }
}
