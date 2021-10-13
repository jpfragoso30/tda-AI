#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/Archivos.h"
#include "../libs/Metadata.h"

struct _metadato
{
    char **columna;
    char **tipo;
    size_t n_metadatos;
    float *contenido;
};

FILE *abrirArchivo(char *nombreArchivo, char *modo)
{
    FILE *archivo = NULL;

    archivo = fopen(nombreArchivo, modo);

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
    char *input;
    char *parsedInput;

    input = malloc(sizeof(char) * BUFSIZ);
    parsedInput = malloc(sizeof(char) * BUFSIZ);

    for (size_t it = 0; it < metadatosEntrantes->n_metadatos; it++)
    {
        fgets(input, BUFSIZ, archivo);

        metadatosEntrantes->columna[it] = malloc(sizeof(char) * BUFSIZ);
        parsedInput = strtok(input, delimiter);
        strcpy(metadatosEntrantes->columna[it], parsedInput);
        strcat(metadatosEntrantes->columna[it], "\0");

        metadatosEntrantes->tipo[it] = malloc(sizeof(char) * BUFSIZ);
        parsedInput = strtok(NULL, delimiter);
        strcpy(metadatosEntrantes->tipo[it], parsedInput);
        (metadatosEntrantes->tipo[it])[strlen(metadatosEntrantes->tipo[it]) - 1] = '\0';
    };

    return metadatosEntrantes;
}

FILE *escribirArchivo(FILE *archivo, Metadato nuevosMetadatos, size_t n_metadatos)
{
    for (size_t i = 0; i < n_metadatos; i++)
    {
        fprintf(archivo, "%s,%s\n", nuevosMetadatos->columna[i], nuevosMetadatos->tipo[i]);
    }

    return archivo;
}

FILE *cerrarArchivo(FILE *archivo)
{
    fclose(archivo);

    archivo = NULL;

    return archivo;
}

Metadato leerMetadatos(Metadato nuevosMetadatos, FILE *archivo)
{
    char *nombreArchivo = NULL;

    puts("Nombre del Archivo para leer los metadatos:");
    gets(nombreArchivo);

    archivo = abrirArchivo(nombreArchivo, ARCHIVO_LECTURA);
    nuevosMetadatos = recibirMetadatos(archivo, nuevosMetadatos);
    archivo = cerrarArchivo(archivo);

    return nuevosMetadatos;
}

Metadato guardarMetadatos(Metadato nuevosMetadatos, size_t n_metadatos)
{
    char *nombreArchivo = NULL;
    FILE *archivo = NULL;

    puts("Nombre del Archivo para guardar los metadatos:");
    gets(nombreArchivo);

    archivo = abrirArchivo(nombreArchivo, ARCHIVO_ESCRITURA);
    archivo = escribirArchivo(archivo, nuevosMetadatos, n_metadatos);
    archivo = cerrarArchivo(archivo);

    return nuevosMetadatos;
}