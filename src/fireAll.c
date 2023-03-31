#include "../include/headerA3.h"

void fireAll(a3Emp **headLL)
{

    a3Emp *current = *headLL;
    a3Emp *temp = NULL;


    if(current == NULL){
        printf("There are no employees. The employee list is empty.\n");
        return;
    }

    while (current != NULL)
    {// Traverses the list
        temp = current;
        current = current->nextEmployee;

        //Freeing memory      
        for (int i = 0; i < temp->numDependents; i++)
        {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        free(temp);
    }

    printf("All fired. The employee list is now empty.\n");
    *headLL = NULL;
}
