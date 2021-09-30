#include <stdio.h>
#include <stdlib.h>
#include "../libs/vector.h"

void printTable(Table *myTable)
{
    for (size_t n = 0; n < mytable->elements; n++)
    {
        printf("\tTitle: %s\n\n\tValue: %s\n", myTable->title[n], myTable->datatype[n]);
    }
};
