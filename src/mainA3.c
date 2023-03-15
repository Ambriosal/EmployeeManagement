#include "../include/headerA3.h"

int main()
{

    // Variable delclaration

    int choice = 0; // Menu selection choice
    printf("Hello World!\n");

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
        case 1:;

            a3Emp *newEmp = (a3Emp *)malloc(sizeof(a3Emp)); // new employee

            // Asks user for full name
            printf("Enter the first name of the employee: ");
            scanf("%s", newEmp->fname);
            printf("Enter the last name of the employee: ");
            scanf("%s", newEmp->lname);

            // Asks user for dependents
            char depend = 'y';
            int num = 0;

            newEmp->dependents = malloc(sizeof(char *) * MAX_LENGTH);
            newEmp->dependents[num] = malloc(sizeof(char) * MAX_LENGTH);

            while (depend == 'y' || depend == 'Y')
            {
                printf("Enter name of dependent #%d: ", num + 1);
                scanf("%s", newEmp->dependents[num]);

                newEmp->dependents = realloc(newEmp->dependents, sizeof(char *) * (num + 1));
                newEmp->dependents[num] = malloc(sizeof(char) * MAX_LENGTH);

                while ((getchar()) != '\n')
                    ; // fixes issue with previous fgets/scanf

                printf("Do you have anymore dependents? (y/n): ");
                scanf("%c", &depend);
                num++;
            }
            printf("You have %d dependents.\n", num);

            // Emplpyee ID
            int total = 0;
            int lnameLength = strlen(newEmp->lname);

            for (int i = 0; i < strlen(newEmp->fname); i++)
            {
                //testing
                char letter = newEmp->fname[i];
                int ascii = (int)letter;
                total = total + (int)newEmp->fname[i];

                // printf("Letter: %c, ASCII: %d\n", letter, ascii);
                // printf("ID: %d\n", total+lnameLength);
            }
            newEmp->empId = total +lnameLength;

            printf("Your computer-generated name empID is %d.\n", newEmp->empId);
            recruitEmployee(&newEmp);

            // Freeing memory
            for (int i = 0; i < num; i++)
            {
                free(newEmp->dependents[i]);
            }
            free(newEmp->dependents);
            free(newEmp);
            break;

            /*case 2:
                break;

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

    return 0;
}