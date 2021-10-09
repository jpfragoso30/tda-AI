#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Metadata.c"

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
        fprintf(archivo, "%s,%s\n", nuevosMetadatos->columna[i], nuevosMetadatos->tipo[i]);
        printf("Iteracion %zd: %s,%s\n", i, nuevosMetadatos->columna[i], nuevosMetadatos->tipo[i]);
    }

    return archivo;
}

FILE *cerrarArchivo(FILE *archivo)
{
    fclose(archivo);

    archivo = NULL;

    return archivo;
}

//Wrapper para implementacion
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