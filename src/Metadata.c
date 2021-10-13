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

static ERROR_CODE_METADATA IsInitialized(Metadato metadatoSospechoso)
{
    if (metadatoSospechoso == NULL && sizeof(metadatoSospechoso) == 8)
    {
        fprintf(stderr, "METADATA NOT INITIALIZED (%d) IN %s: LINE %d\n", METADATA_NOT_INITIALIZED, __FILE__, __LINE__);
        return METADATA_NOT_INITIALIZED;
    }
    else
        return METADATA_OK;
}

static ERROR_CODE_METADATA IsEmpty(Metadato metadatoSospechoso)
{
    if ((IsInitialized(metadatoSospechoso) == METADATA_NOT_INITIALIZED && metadatoSospechoso->n_metadatos == 0) || (sizeof(metadatoSospechoso->columna) == 0 && sizeof(metadatoSospechoso->tipo) == 0))
    {
        fprintf(stderr, "METADATA EMPTY (%d) IN %s: LINE %d\n", METADATA_EMPTY, __FILE__, __LINE__);
        return METADATA_EMPTY;
    }
    else
        return METADATA_OK;
}

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
    if (IsInitialized(emp_metadato) != METADATA_NOT_INITIALIZED)
    {
        for (size_t i = 0; i < emp_metadato->n_metadatos; i++)
        {
            emp_metadato->columna[i] = malloc(sizeof(char) * BUFSIZ);
            printf("Columna: \n");
            gets(emp_metadato->columna[i]);
            strcat(emp_metadato->columna[i], "\0");

            emp_metadato->tipo[i] = malloc(sizeof(char) * BUFSIZ);
            printf("Tipo: \n");
            gets(emp_metadato->tipo[i]);
            strcat(emp_metadato->tipo[i], "\0");
        }
    }
    else
    {
        return NULL;
    }

    return emp_metadato;
}

char *getColumna(Metadato metadatoIn, size_t index)
{
    if (IsInitialized(metadatoIn) != METADATA_NOT_INITIALIZED && IsEmpty(metadatoIn) != METADATA_EMPTY)
        return metadatoIn->columna[index];
    else
        return "\0";
}

char *getTipo(Metadato metadatoIn, size_t index)
{
    if (IsInitialized(metadatoIn) != METADATA_NOT_INITIALIZED && IsEmpty(metadatoIn) != METADATA_EMPTY)
        return metadatoIn->tipo[index];
    else
        return "\0";
}

size_t getNumberMetadatos(Metadato metadatoIn)
{
    if (IsInitialized(metadatoIn) != METADATA_NOT_INITIALIZED && IsEmpty(metadatoIn) != METADATA_EMPTY)
        return metadatoIn->n_metadatos;
    else
        return 0;
}

void printTable(Metadato myTable)
{
    if (IsInitialized(myTable) != METADATA_NOT_INITIALIZED && IsEmpty(myTable) != METADATA_EMPTY)
    {
        for (size_t n = 0; n < getNumberMetadatos(myTable); n++)
        {
            printf("\tColumna: %s\tTipo: %s\n", getColumna(myTable, n), getTipo(myTable, n));
        }
    }
    else
        printf("Metadatos no ha sido inicializado o no tiene elementos.\n");
};

Metadato deleteMetadato(Metadato del_metadato, char *columna)
{
    if (IsInitialized(del_metadato) == METADATA_NOT_INITIALIZED && IsEmpty(del_metadato) == METADATA_EMPTY)
    {
        printf("Metadato no inicializado o vacio\n");
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
    if (IsInitialized(my_metadato))
    {
        for (size_t it = 0; it < my_metadato->n_metadatos; it++)
        {
            free(my_metadato->columna[it]);
            free(my_metadato->tipo[it]);
        }
        free(my_metadato);
    }
    my_metadato = NULL;

    return my_metadato;
}