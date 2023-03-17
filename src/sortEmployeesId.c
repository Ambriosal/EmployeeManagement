#include "../include/headerA3.h"

void sortEmployeesId(struct employee *headLL)
{
    // Using bubble sort
    int swap; // chcecks if two values were swapped
    a3Emp *current = headLL;

    int num = 0;

    // Holds members in temp variable for swaaping
    int tempEmpId;
    char tempFname[MAX_LENGTH];
    char tempLname[MAX_LENGTH];
    int tempNumDepend;
    char **tempDependents = calloc(MAX_LENGTH, sizeof(char *));
    tempDependents[0] = malloc(sizeof(char) * MAX_LENGTH);

    // If list is empty or only one node currently
    if (headLL == NULL || headLL->nextEmployee == NULL)
    {
        printf("There is only one employee or the employee list is empty.\n");
        return; // no sorting necessary
    }

    a3Emp *prev = NULL; // rememebers previous node
    a3Emp *next = NULL; // remembers next node

    do
    {
        swap = 0; // resets swapping to 0
        current = headLL;
        prev = NULL;                          // reset prev to NULL
        while (current->nextEmployee != NULL) // while there is still another employee
        {

            // swap nodes if wrong EmpID order
            if (current->empId > current->nextEmployee->empId)
            { // if current Id is greater than the NEXT ID (wrong order)

                // Swapping empId
                tempEmpId = current->empId;
                current->empId = current->nextEmployee->empId;
                current->nextEmployee->empId = tempEmpId;

                printf("Afer EmpId %d\n", num);

                // Swapping First name
                strcpy(tempFname, current->fname);
                strcpy(current->fname, current->nextEmployee->fname);
                strcpy(current->nextEmployee->fname, tempFname);

                printf("Afer Fname %d\n", num);

                // Swapping Last name
                strcpy(tempLname, current->lname);
                strcpy(current->lname, current->nextEmployee->lname);
                strcpy(current->nextEmployee->lname, tempLname);

                printf("Afer LName %d\n", num);

                // Swapping # of dependents
                tempNumDepend = current->numDependents;
                current->numDependents = current->nextEmployee->numDependents;
                current->nextEmployee->numDependents = tempNumDepend;

                printf("Afer #Dep %d\n", num);

                // swapping Dependents
                for (int i = 0; i < MAX_LENGTH; i++) // temps for dependents
                {
                    tempDependents[i] = current->dependents[i];
                    current->dependents[i] = current->nextEmployee->dependents[i];
                    current->nextEmployee->dependents[i] = tempDependents[i];
                }

                tempDependents = realloc(tempDependents, sizeof(char *) * (MAX_LENGTH + 1));
                tempDependents[MAX_LENGTH] = malloc(sizeof(char) * MAX_LENGTH);

                printf("Afer Depd %d\n", num);

                // swapping nodes
                next = current->nextEmployee;
                current->nextEmployee = next->nextEmployee;
                next->nextEmployee = current;

                printf("Afer Node %d\n", num);

                if (prev == NULL) // there is no prev node
                {
                    headLL = next; // goes to next node
                }
                else
                { // prev node is now the next node
                    prev->nextEmployee = next;
                }

                // current node moves to next
                current = next;
                swap = 1; // swap successful

                printf("Updating next node. %d\n", num);
            }
            prev = current;
            current = current->nextEmployee; // goes to next node
            printf("Here??, %d\n", num);
            num++;
        }
        printf("After again.%d\n", num);

    } while (swap == 1);

    printf("Out of the swap funciton.\n");
    // Printing sorted list

    int index = 0;

    current = headLL;
    printf("After sorting EmpIDs, the employees are as followed:\n");
    while (current != NULL)
    { // traverse through the list
        printf("Employee #%d:\n", index + 1);

        printf("Employee Id: %d\n", current->empId);
        printf("First name: %s\n", current->fname);
        printf("Last name: %s \n", current->lname);

        // Dependents
        printf("Dependents[%d]: ", current->numDependents);

        int i = 0;
        while (current->dependents[i] != NULL)
        {
            printf("%s ", current->dependents[i]);
            i++;
        }

        printf("\n");
        printf("\n");
        index++;
        current = current->nextEmployee;
    }
}
