#include <stdio.h>
#include <stdlib.h>
#include "./Metadata.c"

void printTable(Metadato myTable)
{
    for (size_t n = 0; n < getNumberMetadatos(myTable); n++)
    {
        printf("\tColumna: %s\n\n\tTipo: %s\n", getMetadato(myTable, "columna", n), getMetadato(myTable, "tipo", n));
    }
};
