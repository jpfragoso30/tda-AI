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
Metadato setMetadato(Metadato emp_metadato);

//Getter
char *getMetadato(Metadato metadatoIn, char *modo, size_t indice);
size_t getNumberMetadatos(Metadato metadatoIn);

//Delete
Metadato deleteMetadato(Metadato del_metadato, char *columna);

//Free
Metadato freeMetadato(Metadato my_metadato);

//Archivos
Metadato guardarMetadatos(Metadato nuevosMetadatos, size_t n_metadatos);
Metadato leerMetadatos(Metadato nuevosMetadatos, FILE *archivo);
FILE *abrirArchivo(char *nombreArchivo);
FILE *abrirArchivoLectura(char *nombreArchivo);
FILE *escribirArchivo(FILE *archivo, Metadato nuevosMetadatos, size_t n_metadatos);
Metadato recibirMetadatos(FILE *archivo, Metadato metadatosEntrantes);
FILE *cerrarArchivo(FILE *archivo);

//Imprimir
void printTable(Metadato myTable);
void Menu1();
void Menu2();

#endif