#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Metadata.h"
#include "./Metadata.c"

Metadato addMetadato(size_t n_metadatos)
{
    Metadato new_meta = NULL;
    new_meta = malloc(sizeof(struct _metadato));

    //Validación
    if (!new_meta)
        return NULL;

    new_meta->n_metadatos = n_metadatos;

    return new_meta;
}

void setMetadato(Metadato emp_metadato)
{
    for (size_t i = 0; i < emp_metadato->n_metadatos; i++)
    {

        printf("Columna: \n");
        scanf("%s", emp_metadato->columna[i]);

        printf("Tipo: \n");
        scanf("%s", emp_metadato->tipo[i]);
    }
}

char *getColumna(Metadato metadatoIn, size_t index){
    return metadatoIn->columna[index];
}

char *getTipo(Metadato metadatoIn, size_t index){
    return metadatoIn->tipo[index];
}

size_t getNumberMetadatos(Metadato metadatoIn)
{
    return metadatoIn->n_metadatos;
}