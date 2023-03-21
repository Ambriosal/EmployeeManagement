#include "../include/headerA3.h"

int main(int argc, char *argv[])
{

    // Variable declaration

    int choice = 0;       // Menu selection choice
    a3Emp *newEmp = NULL; // new employee
    a3Emp *temp = newEmp;
    int pos = 0;      // F3 - position of list chosen
    int SearchID = 0; // F4 - search ID
    char *FullName = malloc(sizeof(char) * (2 * MAX_LENGTH));
    int totalF6 = 0; // total F6
    int resultF5 = 0;
    int firePos = 0; // F8
    char fire = 'n'; // F9 - fire choice
    int count = 0;   // counting
    printf("Hello World!\n");

    loadEmpData(&newEmp, argv[1]); // Uses helper function with input file

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
        printf("Please select a menu option: "); //user selects choice
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            recruitEmployee(&newEmp); // adds new employee - F1
            break;

        case 2:

            printAll(newEmp); //Prints current employees - F2
            break;

        case 3:

            printf("Enter a position: ");
            scanf("%d", &pos);
            printOne(newEmp, pos); //Finds employee at current pos - F3

            break;

        case 4:

            printf("Enter a employeed ID: ");
            scanf("%d", &SearchID);

            int result = lookOnId(newEmp, SearchID);

            if (result != -1)
                printf("ID: %d is at position #%d.\n", SearchID, result); // Emp. found
            else if (result == -1)
                printf("This employee with (ID: %d) does not exist.\n", SearchID);

            break;

        case 5:

            while ((getchar()) != '\n')
                ; // fixes issue with previous fgets/scanf
            printf("Enter the full name of the employee: ");
            fgets(FullName, 2 * MAX_LENGTH, stdin);

            resultF5 = lookOnFullName(newEmp, FullName);

            if (resultF5 != -1)
                printf("This employee is at position #%d.\n", resultF5); // Emp found.
            else if (resultF5 == -1)
                printf("This employee does not exist.\n");

            break;
        case 6:

            count = countEmployees(newEmp); //Counts # of employees - F6

            if (count == 1)
            {
                printf("There is one employee.");
            }
            else
            {
                printf("There are %d employees.\n", countEmployees(newEmp));
            }
            printf("\n");

            break;

        case 7:

            sortEmployeesId(newEmp); //Shows sorted list - F7
            break;

        case 8:

            temp = newEmp;
            while (temp != NULL) // checks how many employees
            {
                totalF6++;
                temp = temp->nextEmployee;
            }
            if (totalF6 == 0) // if linked list is empty
            {
                printf("Currently, there are no employees.\n");
                break;
            }
            else if (totalF6 == 1) // if one
            {
                printf("There is currently 1 employee.\n");
            }
            else
            {
                printf("There are currently %d employees.\n", totalF6);
            }

            printf("Which employee do you wish to fire — enter a value between 1 and %d: ", totalF6);
            scanf("%d", &firePos);
            fireOne(&newEmp, firePos); //removes selected employee - F8

            totalF6 = 0; // reset employee count
            printf("\n");

            break;

        case 9:

            while ((getchar()) != '\n')
                ; // fixes issue with previous fgets/scanf
            printf("Are you sure you want to fire everyone? (y/n): ");
            scanf("%c", &fire);
            if (fire == 'y')
            {
                fireAll(&newEmp); // removes all employees - F9
                printf("All fired. Linked list is now empty.\n");
            }

            break;
        }

    } while (choice != 10); //Exits menu 

    //Freeing memory
    while (newEmp != NULL)
    {
        temp = newEmp;
        newEmp = newEmp->nextEmployee;

        for (int i = 0; i < temp->numDependents; i++)
        {
            free(temp->dependents[i]);
        }
        free(temp->dependents);
        // free dependents
        free(temp);
    }

    newEmp = NULL;
    free(FullName);

    return 0;
}