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

Metadato *recibirMetadatos(FILE *archivo, Metadato metadatosEntrantes)
{
    size_t it = 0;
    //funcion para inicializar lista de metadatos
    do
    {
        fscanf(archivo, "%s,%s\n", metadatosEntrantes->columna[it], metadatosEntrantes->tipo[it]);
        //como el tamanio no debe ser estatico, funcion que los agrega a la lista dinamica
        it++;
    } while (feof(archivo) == 0);

    return metadatosEntrantes;
}

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