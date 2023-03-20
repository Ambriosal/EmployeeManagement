#include "../include/headerA3.h"

int lookOnId(struct employee *headLL, int whichEmpId)
{

    int index = 0;

    a3Emp *current = headLL;



    while (current != NULL)
    {
        index++;

        if (current->empId == whichEmpId)
        {
            return index;
        }

        current = current->nextEmployee;
    }

    return -1;
}
