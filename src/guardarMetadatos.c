#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Metadata.c"

Metadato guardarMetadatos(Metadato nuevosMetadatos, size_t n_metadatos)
{
    char *nombreArchivo = NULL;
    FILE *archivo = NULL;

    puts("Nombre del Archivo para guardar los metadatos:");
    gets(nombreArchivo);

    archivo = abrirArchivo(nombreArchivo);
    archivo = escribirArchivo(archivo, nuevosMetadatos, n_metadatos);
    archivo = cerrarArchivo(archivo);

    return nuevosMetadatos;
}

FILE *abrirArchivo(char *nombreArchivo)
{
    FILE *archivo = NULL;

    archivo = fopen(nombreArchivo, "wt");

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

FILE *escribirArchivo(FILE *archivo, Metadato nuevosMetadatos, size_t n_metadatos)
{
    for (size_t i = 0; i < n_metadatos; i++)
    {
        char *datoEntrante = NULL;
        datoEntrante = malloc((strlen(nuevosMetadatos->columna[i]) + 1 + strlen(nuevosMetadatos->tipo[i]) + 1) * 1 * sizeof(char));

        strcpy(datoEntrante, nuevosMetadatos->columna[i]);
        strcat(datoEntrante, ",");
        strcat(datoEntrante, nuevosMetadatos->tipo[i]);
        strcat(datoEntrante, "\0");

        fputs(datoEntrante, archivo);
    }

    return archivo;
}

FILE *cerrarArchivo(FILE *archivo)
{
    fclose(archivo);

    archivo = NULL;

    return archivo;
}