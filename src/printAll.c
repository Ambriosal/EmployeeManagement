#include "../include/headerA3.h"

// Prints all info in current linked list
void printAll(struct employee *headLL)
{

    int index = 0;
    a3Emp *current = (a3Emp *)malloc(sizeof(a3Emp));
    current->nextEmployee = NULL;

    current = headLL; // moves current to head of list

    while (current != NULL)
    { // traverse through the list
        printf("Employee #%d:\n", index+1);

        printf("Employee Id: %d\n", current->empId);
        printf("First name: %s\n", current->fname);
        printf("Last name: %s \n", current->lname);
        // Dependents
    
        printf("Dependents[%d]: ", current->numDependents);
        int  i= 0;
        while (current->dependents[i] != NULL){

            printf("%s, ", current->dependents[i]);

          i++;      
        }

        printf("\n");
        printf("\n");
        index++;
        current = current->nextEmployee;
    }

    if (headLL == NULL)
    {
        printf("There are no employees at this moment.\n");
        return;
    }
}
