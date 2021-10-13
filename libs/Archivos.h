/**
* @Author: Sebastian Castaneda, Juan Pablo Fragoso, Ana Regina Morfin.
* @Date: 28 Sept 2021
* @Name Archivos.h
*/

#ifndef Archivos_h
#define Archivos_h

#include <stdio.h>
#include <stdlib.h>

#include "./Metadata.h"

#define ARCHIVO_LECTURA "rt"
#define ARCHIVO_ESCRITURA "wt"

//File has a type

typedef enum
{
    FILE_OK,
    FILE_NOT_FOUND,
    FILE_EMPTY,
} ERROR_CODE_ARCHIVOS;

//Constructor
FILE *abrirArchivo(char *nombreArchivo, char *modo);

//Getter
Metadato recibirMetadatos(FILE *archivo, Metadato metadatosEntrantes);

//Setter
FILE *escribirArchivo(FILE *archivo, Metadato nuevosMetadatos, size_t n_metadatos);

//Delete
FILE *cerrarArchivo(FILE *archivo);

//Helpers
Metadato guardarMetadatos(Metadato nuevosMetadatos, size_t n_metadatos);
Metadato leerMetadatos(Metadato nuevosMetadatos, FILE *archivo);

#endif