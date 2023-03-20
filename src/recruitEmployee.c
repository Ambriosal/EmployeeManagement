#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL)
{
    a3Emp *newEmp = malloc(sizeof(a3Emp)); // new employee

    // Asks user for full name
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmp->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmp->lname);

    // Asks user for dependents
    char depend = 'y';
    int num = 0;
    a3Emp *temp = *headLL; // temp node
    newEmp->dependents = malloc(sizeof(char *) * 1);
    newEmp->dependents[num] = malloc(sizeof(char) * MAX_LENGTH);

    while (depend == 'y' || depend == 'Y')
    {
        printf("Enter name of dependent #%d: ", num + 1); // name of dependent
        scanf("%s", newEmp->dependents[num]);

        newEmp->dependents = realloc(newEmp->dependents, sizeof(char *) * (num + 2)); // resizing pointer        
        newEmp->dependents[num+1] = malloc(sizeof(char) * (MAX_LENGTH +1));

        while ((getchar()) != '\n')
            ; // fixes issue with previous fgets/scanf
        printf("Do you have any more dependents? (y/n): ");
        scanf("%c", &depend);
        num++; // next dependent

    }

    newEmp->numDependents = num;
    printf("You have %d dependent(s).\n", num);


    //-----> Employee ID
    int total = 0;
    int lnameLength = strlen(newEmp->lname);

    for (int i = 0; i < strlen(newEmp->fname); i++)
    {
        total = total + (int)newEmp->fname[i];
    }

    newEmp->empId = total + lnameLength; // empId formula

    newEmp ->nextEmployee = NULL;

    while (temp != NULL) // if temp is at first node
    {
        if (temp->empId == newEmp->empId) // checks if current empID is same as newEmp
        {
            newEmp->empId = newEmp->empId + (rand() % (999 - 1) + 1) + 1;
        }

        temp = temp->nextEmployee; // moves to next node
    }
    printf("num: %d\n\n", num);

    if (*headLL == NULL) // if there is not current head
    {
        *headLL = newEmp; // make newEmp current head of list
        return;
    }

    printf("Your computer-generated name empID is %d.\n", newEmp->empId); // print EmpId

    temp = *headLL; // Temp back to head of list
    while (temp != NULL)
    {
        if (temp->nextEmployee == NULL) // once it reaches end
        {
            temp->nextEmployee = newEmp; // newEmp add to end of list
            return; //found end
        }
        temp = temp->nextEmployee;
    }


}
