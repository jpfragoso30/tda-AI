#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Metadata.h"
#include "./Metadata.c"

Metadato addMetadato(size_t n_metadatos)
{
    Metadato new_meta = NULL;
    new_meta = malloc(sizeof(struct _metadato));
    new_meta->columna = malloc(sizeof(char *) * n_metadatos);
    new_meta->tipo = malloc(sizeof(char *) * n_metadatos);

    //Validación
    if (!new_meta)
        return NULL;

    new_meta->n_metadatos = n_metadatos;

    return new_meta;
}

Metadato setMetadato(Metadato emp_metadato)
{
    for (size_t i = 0; i < emp_metadato->n_metadatos; i++)
    {
        emp_metadato->columna[i] = malloc(sizeof(char) * 32);
        printf("Columna: \n");
        gets(emp_metadato->columna[i]);

        emp_metadato->tipo[i] = malloc(sizeof(char) * 16);
        printf("Tipo: \n");
        gets(emp_metadato->tipo[i]);
    }

    return emp_metadato;
}

char *getColumna(Metadato metadatoIn, size_t index)
{
    return metadatoIn->columna[index];
}

char *getTipo(Metadato metadatoIn, size_t index)
{
    return metadatoIn->tipo[index];
}

size_t getNumberMetadatos(Metadato metadatoIn)
{
    return metadatoIn->n_metadatos;
}

char *getMetadato(Metadato metadatoIn, char *modo, size_t indice)
{
    if (strcmp(modo, "columna") == 0)
        return metadatoIn->columna[indice];
    else if (strcmp(modo, "tipo") == 0)
        return metadatoIn->tipo[indice];
    else
        return NULL;
}