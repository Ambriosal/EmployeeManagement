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
            printf("\tEmployee ID: %d\n", current->empId);
            printf("\tFirst name: %s\n", current->fname);
            printf("\tLast name: %s\n", current->lname);

            //Dependents
            printf("\tDependents: ");
            for(int i = 0; i < current->numDependents; i++)
            {

                printf("%s ", current->dependents[i]);
 
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
