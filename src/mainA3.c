#include "../include/headerA3.h"

int main(int argc, char *argv[])
{

    // Variable delclaration

    int choice = 0;       // Menu selection choice
    a3Emp *newEmp = NULL; // new employee
    a3Emp *temp = (a3Emp *)malloc(sizeof(a3Emp));
    temp->nextEmployee = NULL;
    int pos = 0;      // F3 - position of list chosen
    int SearchID = 0; // F4 - search ID
    char *FullName = malloc(sizeof(char) * (2 * MAX_LENGTH));
    int totalF6 = 0; // total F6
    int firePos = 0; // F6
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

        printf("\n");
        printf("Please select a menu option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            // newEmp = NULL;
            recruitEmployee(&newEmp); // adds new emplolyee - F1
            break;

        case 2:
            printAll(newEmp);
            break;

        case 3:

            printf("Enter a position: ");
            scanf("%d", &pos);
            printOne(newEmp, pos);

            break;

        case 4:

            printf("Enter a employeed ID: ");
            scanf("%d", &SearchID);

            int result = lookOnId(newEmp, SearchID);

            if (result != -1)
                printf("ID: %d is at pos %d.\n", SearchID, result);
            else
                printf("This employees with (ID: %d) does not exist.\n", SearchID);

            break;

        case 5:

            while ((getchar()) != '\n')
                ; // fixes issue with previous fgets/scanf
            printf("Enter the full name of the employee: ");
            fgets(FullName, 2 * MAX_LENGTH, stdin);

            int resultF5 = lookOnFullName(newEmp, FullName);

            if (result != -1)
                printf("This employee is at pos %d.\n", resultF5);
            else
                printf("This employee does not exist.\n");

            break;
        case 6:
            printf("There are %d employees.\n", countEmployees(newEmp));
            break;
            /*

                        case 7:
                            break;
*/
        case 8:
            temp = newEmp;
            while (temp != NULL)
            {
                totalF6++;
                temp = temp->nextEmployee;
            }

            printf("There are currently %d employees.\n", totalF6);

            printf("Which employee do you wish to fire — enter a value between 1 and %d: ", totalF6);
            scanf("%d", &firePos);
            fireOne(&newEmp, firePos);

            break;
            /*
                                    case 9:
                                        break;*/
        }

    } while (choice != 10);

    free(newEmp);

    return 0;
}