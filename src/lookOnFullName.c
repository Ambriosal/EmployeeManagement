#include "../include/headerA3.h"

// Finds employee by full name
int lookOnFullName(struct employee *headLL, char whichName[100])
{
    a3Emp *current = headLL;
    char *FName = NULL;
    char *LName = NULL;
    int first = 0;
    int last = 0;

    FName = calloc(MAX_LENGTH, sizeof(char));
    LName = calloc(MAX_LENGTH, sizeof(char));
    int index = 0; // pos of employee

    sscanf(whichName, "%s %s", FName, LName); // saves first name and last name

    while (current != NULL)
    { // Traverses list

        first = strcmp(current->fname, FName);
        last = strcmp(current->lname, LName);
        index++;
        if (first == 0 && last == 0) // If found
        {
            free(FName);
            free(LName);
            return index; // Return position
        }

        current = current->nextEmployee; // next employee
    }

    // Freeing memory
    free(FName);
    free(LName);

    return -1; // Employee could not be found
}
