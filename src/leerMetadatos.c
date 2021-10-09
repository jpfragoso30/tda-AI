#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Metadata.c"

FILE *abrirArchivoLectura(char *nombreArchivo)
{
    FILE *archivo = NULL;

    archivo = fopen(nombreArchivo, "rt");

    if (archivo != NULL)
    {
        return archivo;
    }
    else
    {
        fputs("File not found\n", stdout);
        return NULL;
    }
}

Metadato recibirMetadatos(FILE *archivo, Metadato metadatosEntrantes)
{
    char delimiter[2] = ",";
    char input[50];
    char *parsedInput;

    for (size_t it = 0; it < metadatosEntrantes->n_metadatos; it++)
    {
        metadatosEntrantes->columna[it] = malloc(sizeof(char) * 32);
        metadatosEntrantes->tipo[it] = malloc(sizeof(char) * 16);

        fgets(input, 50, archivo);

        parsedInput = strtok(input, delimiter);
        metadatosEntrantes->columna[it] = parsedInput;
        strcat(metadatosEntrantes->columna[it], "\0");
        parsedInput = strtok(NULL, delimiter);
        metadatosEntrantes->tipo[it] = parsedInput;
        strcat(metadatosEntrantes->tipo[it], "\0");
        parsedInput = strtok(NULL, delimiter);
    };

    return metadatosEntrantes;
}

//Wrapper para implementacion
Metadato leerMetadatos(Metadato nuevosMetadatos, FILE *archivo)
{
    char *nombreArchivo = NULL;

    puts("Nombre del Archivo para leer los metadatos:");
    gets(nombreArchivo);

    archivo = abrirArchivoLectura(nombreArchivo);
    nuevosMetadatos = recibirMetadatos(archivo, nuevosMetadatos);
    archivo = cerrarArchivo(archivo);

    return nuevosMetadatos;
}