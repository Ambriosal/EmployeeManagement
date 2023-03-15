#include "../include/headerA3.h"

int main(int argc, char *argv[])
{

    // Variable delclaration

    int choice = 0; // Menu selection choice
    a3Emp *newEmp = NULL; // new employee
    a3Emp *temp = (a3Emp*)malloc(sizeof(a3Emp));
    temp->nextEmployee = NULL;


    printf("Hello World!\n");

    loadEmpData(&newEmp, argv[1]);

    do
    {
        // Menu selection
        printf("\n");
        printf("1. Add a new employee.\n");
        printf("2. Print data of all employees.\n");
        printf("3. Print data of the nth employee\n");
        printf("4. Search for employee based on empId\n");
        printf("5. Search for employee based on full name\n");
        printf("6. Count the total number of employees\n");
        printf("7. Sort the employees based on their empId\n");
        printf("8. Remove the nth employee in the current LL\n");
        printf("9. Remove all employees in the current LL\n");
        printf("10. Exit\n");

        printf("Please select a menu option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            // newEmp = NULL;
            recruitEmployee(&newEmp); //adds new employee - F1
            break;

        case 2://i waana go my room and? better enviro
            //newEmp = (a3Emp *)malloc(sizeof(a3Emp)); 
            printAll(newEmp);
                break;
/*
            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

             case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;*/
        }

    } while (choice != 10);

    free(newEmp);

    return 0;
}