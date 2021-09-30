#include <stdio.h>
#include <stdlib.h>

// #include "../libs/metadatos.h" typedef que va a ser Metadatos

// Suponiendo que Metadatos tiene la forma:
struct _metadatos
{
    char **columna;
    char **tipo;
    size_t n_metadatos;
};

Metadatos guardarMetadatos(Metadatos nuevosMetadatos, size_t n_metadatos)
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

    archivo = fopen(nombreArchivo, 'wt');

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

FILE *escribirArchivo(FILE *archivo, Metadatos nuevosMetadatos, size_t n_metadatos)
{
    for (int i = 0; i < n_metadatos; i++)
    {
        char *datoEntrante = NULL;
        datoEntrante = malloc((strlen(nuevosMetadatos->columna[i]) + 1 + strlen(nuevosMetadatos->tipo[i]) + 1) * 1(typeof(char *)));

        datoEntrante = strcat(nuevosMetadatos->columna[i], ',');
        datoEntrante = strcat(datoEntrante, nuevosMetadatos->tipo[i]);
        datoEntrante = strcat(datoEntrante, '\n');

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