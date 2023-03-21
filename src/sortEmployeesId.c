#include "../include/headerA3.h"

// Sorts linked list based on EmpID
void sortEmployeesId(struct employee *headLL)
{
    // Using bubble sort
    int swap; // chcecks if two values were swapped
    a3Emp *current = headLL;

    // Holds members in temp variable for swapping
    int tempEmpId;
    char tempFname[MAX_LENGTH];
    char tempLname[MAX_LENGTH];
    int tempNumDepend;

    // If list is empty or only one node currently
    if (headLL == NULL || headLL->nextEmployee == NULL)
    {
        printf("There is only one employee or the employee list is empty.\n");
        return; // no sorting necessary
    }

    do
    {
        swap = 0; // resets swapping to 0
        current = headLL;
        while (current->nextEmployee != NULL) // while there is still another employee
        {

            // swap nodes if wrong EmpID order
            if (current->empId > current->nextEmployee->empId)
            { // if current Id is greater than the NEXT ID (wrong order)

                // Swapping empId
                tempEmpId = current->empId;
                current->empId = current->nextEmployee->empId;
                current->nextEmployee->empId = tempEmpId;

                // Swapping First name
                strcpy(tempFname, current->fname);
                strcpy(current->fname, current->nextEmployee->fname);
                strcpy(current->nextEmployee->fname, tempFname);

                // Swapping Last name
                strcpy(tempLname, current->lname);
                strcpy(current->lname, current->nextEmployee->lname);
                strcpy(current->nextEmployee->lname, tempLname);

                // Swapping # of dependents
                tempNumDepend = current->numDependents;
                current->numDependents = current->nextEmployee->numDependents;
                current->nextEmployee->numDependents = tempNumDepend;

                // --->Swapping dependent names

                // Allocating memory for temp variables
                char **tempDependents = malloc(sizeof(char *) * (tempNumDepend));

                for (int i = 0; i < tempNumDepend; i++)
                {
                    tempDependents[i] = malloc(sizeof(char) * MAX_LENGTH);
                }
                // swapping dependents here
                for (int i = 0; i < tempNumDepend; i++)
                {
                    char *temp = current->dependents[i];
                    current->dependents[i] = current->nextEmployee->dependents[i];
                    current->nextEmployee->dependents[i] = temp;
                }
                // Freeing memory for tempDependents
                for (int i = 0; i < tempNumDepend; i++)
                {
                    free(tempDependents[i]);
                }
                free(tempDependents);

                swap = 1; // swap successful
            }

            current = current->nextEmployee; // goes to next node
        }
    } while (swap != 0);

    printAll(headLL); // Now prints sorted list
}
