#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h"
#include "../libs/unity.h"

#define NOMBRE_ARCHIVO "./tests/prueba.csv"
#define NOMBRE_ARCHIVO_INVALIDO "/asd/asji?-2912.tsj"
#define TIPO_FLOAT "float"

void test_abrirArchivoLecturaValido(void)
{
    printf("\t***(TEST) abrirArchivoLecturaValido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivoLectura(NOMBRE_ARCHIVO);

    //archivo exists, so no NULL expected
    TEST_ASSERT_NOT_NULL(archivo);

    cerrarArchivo(archivo);
}

void test_abrirArchivoLecturaInvalido(void)
{
    printf("\t***(TEST) abrirArchivoLecturaInvalido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivoLectura(NOMBRE_ARCHIVO_INVALIDO);

    //archivo doesnt exist, so NULL expected
    TEST_ASSERT_NULL(archivo);

    cerrarArchivo(archivo);
}

void test_recibirMetadatos(void)
{
    printf("\t***(TEST) recibirMetadatos***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;
    Metadato metadatoEntrante = NULL;
    size_t n_metadatos = 2;

    //pre-requisites
    metadatoEntrante = addMetadato(n_metadatos);
    archivo = abrirArchivoLectura(NOMBRE_ARCHIVO);

    //function to test
    metadatoEntrante = recibirMetadatos(archivo, metadatoEntrante);

    //archivo exists, so 3 lines of columna,tipo expected
    TEST_ASSERT_EQUAL_STRING("id", getColumna(metadatoEntrante, 0));
    TEST_ASSERT_EQUAL_STRING(TIPO_FLOAT, getTipo(metadatoEntrante, 0));
    TEST_ASSERT_EQUAL_STRING("edad", getColumna(metadatoEntrante, 1));
    TEST_ASSERT_EQUAL_STRING(TIPO_FLOAT, getTipo(metadatoEntrante, 1));

    //cleanup
    archivo = cerrarArchivo(archivo);
    metadatoEntrante = freeMetadato(metadatoEntrante);
}