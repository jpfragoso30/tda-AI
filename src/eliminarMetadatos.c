#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Metadata.h"
#include "./Metadata.c"

Metadato deleteMetadato(Metadato del_metadato, char *columna)
{
    if (!del_metadato)
    {
        printf("Metadato vacío \n");
        return del_metadato;
    }

    for (size_t i = 0; i < del_metadato->n_metadatos; i++)
    {

        if (strcmp(del_metadato->columna[i], columna) == 0)
        {
            strcpy(del_metadato->columna[i], "\0");
            strcpy(del_metadato->tipo[i], "\0");

            return del_metadato;
        }
    }

    printf("Columna no encontrada\n");

    return del_metadato;
}

Metadato freeMetadato(Metadato my_metadato)
{
    free(my_metadato);
    my_metadato = NULL;

    return my_metadato;
}