#include "../include/headerA3.h"

// Sorts linked list based on EmpID
void sortEmployeesId(struct employee *headLL)
{
    // Using bubble sort
    int swap; // checks if two values were swapped
    a3Emp *current = headLL;

    // Holds members in temp variable for swapping
    int tempEmpId;
    char tempFname[MAX_LENGTH];
    char tempLname[MAX_LENGTH];
    int tempNumDepend;

    // If list is empty or only one node currently
    if (headLL == NULL || headLL->nextEmployee == NULL)
    {
        printf("Cannot sort list.\n");
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
                    char **temp = current->dependents;
                    current->dependents = current->nextEmployee->dependents;
                    current->nextEmployee->dependents = temp;

                swap = 1; // swap successful
            }

            current = current->nextEmployee; // goes to next node
        }
    } while (swap != 0);

    printAll(headLL); // Now prints sorted list
}
