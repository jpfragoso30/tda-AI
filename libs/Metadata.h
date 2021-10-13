/**
* @Author: Sebastian Castaneda, Juan Pablo Fragoso, Ana Regina Morfin.
* @Date: 28 Sept 2021
* @Name Metadata.h
*/

#ifndef Metadata_h
#define Metadata_h

#include <stdio.h>
#include <stdlib.h>

typedef struct _metadato *Metadato;

typedef enum
{
    METADATA_OK,
    METADATA_NOT_INITIALIZED,
    METADATA_EMPTY,
} ERROR_CODE_METADATA;

//Constructor
Metadato addMetadato(size_t n_metadatos);

//Setter
Metadato setMetadato(Metadato emp_metadato);

//Getter
char *getColumna(Metadato metadatoIn, size_t index);
char *getTipo(Metadato metadatoIn, size_t index);
size_t getNumberMetadatos(Metadato metadatoIn);
char *getMetadato(Metadato metadatoIn, char *modo, size_t indice);

//Delete
Metadato deleteMetadato(Metadato del_metadato, char *columna);

//Free
Metadato freeMetadato(Metadato my_metadato);

//Helpers
void printTable(Metadato myTable);

#endif