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

char *getMetadato(Metadato metadatoIn, char *modo, size_t indice)
{
    if (strcmp(modo, "columna") == 0)
        return metadatoIn->columna[indice];
    else if (strcmp(modo, "tipo") == 0)
        return metadatoIn->tipo[indice];
    else
        return NULL;
};

size_t getNumberMetadatos(Metadato metadatoIn)
{
    return metadatoIn->n_metadatos;
}

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
