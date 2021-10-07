#include <stdio.h>
#include <stdlib.h>
#include "./Metadata.c"

void printTable(Table *myTable)
{
    for (size_t n = 0; n < mytable->elements; n++)
    {
        printf("\tData Type: %s\n\n\tValue: %s\n", myTable->datatype[n], myTable->values[n]);
    }
};
