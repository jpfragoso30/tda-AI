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

void freeMetadato(Metadato my_metadato)
{
    free(my_metadato);
    my_metadato = NULL;
}
