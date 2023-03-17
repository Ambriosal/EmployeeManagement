#include "../include/headerA3.h"

int lookOnFullName(struct employee *headLL, char whichName[100])
{
    a3Emp *current = headLL;
    char *FName = malloc(sizeof(char) * MAX_LENGTH);
    char *LName = malloc(sizeof(char) * MAX_LENGTH);
    int index = 0;

    sscanf(whichName, "%s %s", FName, LName);

    while (current != NULL)
    {
        index++;
        if (strcmp(current->fname, FName) == 0 && strcmp(current->lname, LName) == 0)
        {
            return index;
        }

        current = current->nextEmployee;
    }

    if (current == NULL){
        printf("There are no employees at the moment.\n");
        return 0;
    }

    return -1;
}
