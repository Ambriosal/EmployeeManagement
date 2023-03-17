#include "../include/headerA3.h"

void printOne(struct employee *headLL, int whichOne)
{

    int index = 0;

    a3Emp *current = headLL;

    while (current != NULL)
    {
        index++;
        if (index == whichOne)
        {
            printf("Employee ID: %d\n", current->empId);
            printf("First name: %s\n", current->fname);
            printf("Last name: %s\n", current->lname);

            //Dependents
            printf("Dependents: ");
            int  i= 0;
            while (current->dependents[i] != NULL)
            {

                printf("%s ", current->dependents[i]);

            i++;      
            }
            printf("\n");
            return;
        }
        current = current->nextEmployee;
    }

        if (headLL == NULL)
    {
        printf("There are no such employees at this moment.\n");
        return;
    }
}
