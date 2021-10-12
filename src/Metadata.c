#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Metadata.h"

struct _metadato
{
    char **columna;
    char **tipo;
    size_t n_metadatos;
    float *contenido;
};

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
        emp_metadato->columna[i] = malloc(sizeof(char) * BUFSIZ);
        printf("Columna: \n");
        fgets(emp_metadato->columna[i], sizeof(emp_metadato->columna[i]), stdin);
        strcat(emp_metadato->columna[i], "\0");

        emp_metadato->tipo[i] = malloc(sizeof(char) * BUFSIZ);
        printf("Tipo: \n");
        fgets(emp_metadato->tipo[i], sizeof(emp_metadato->tipo[i]), stdin);
        strcat(emp_metadato->tipo[i], "\0");
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

void printTable(Metadato myTable)
{
    for (size_t n = 0; n < getNumberMetadatos(myTable); n++)
    {
        printf("\tColumna: %s\tTipo: %s\n", getColumna(myTable, n), getTipo(myTable, n));
    }
};

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