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

//Constructor
Metadato addMetadato(size_t n_metadatos);

//Setter
void setMetadato(Metadato emp_metadato);

//Delete
Metadato deleteMetadato(Metadato del_metadato);
//se necesita un free()

//Archivos
Metadato guardarMetadatos(Metadato nuevosMetadatos, size_t n_metadatos);
FILE *abrirArchivo(char *nombreArchivo);
FILE *escribirArchivo(FILE *archivo, Metadato nuevosMetadatos, size_t n_metadatos);
FILE *cerrarArchivo(FILE *archivo);

#endif