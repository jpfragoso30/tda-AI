#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h"
#include "../libs/unity.h"

#define NOMBRE_ARCHIVO "./tests/prueba.csv"
#define NOMBRE_ARCHIVO_INVALIDO "/asd/asji?-2912.tsj"

void test_abrirArchivoValido(void)
{
    printf("\t***(TEST) abrirArchivoValido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivo(NOMBRE_ARCHIVO);

    //archivo exists, so no NULL expected
    TEST_ASSERT_NOT_NULL(archivo);

    // to prevent anything
    archivo = cerrarArchivo(archivo);
}

void test_abrirArchivoInvalido(void)
{
    printf("\t***(TEST) abrirArchivoInvalido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivo(NOMBRE_ARCHIVO_INVALIDO);

    //archivo doesnt exist, so NULL expected
    TEST_ASSERT_NULL(archivo);

    // to prevent anything
    archivo = cerrarArchivo(archivo);
}

void test_escribirArchivo(void)
{
    printf("\t***(TEST) escribirArchivo***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;
    Metadato metadatoPrueba = NULL;
    size_t n_metadatos = 2;

    //pre-requisite
    archivo = abrirArchivo(NOMBRE_ARCHIVO);
    metadatoPrueba = addMetadato(n_metadatos);
    metadatoPrueba = setMetadato(metadatoPrueba);

    //function to test
    archivo = escribirArchivo(archivo, metadatoPrueba, n_metadatos);

    //archivo exists, so NOT NULL expected after attempting to write on it
    TEST_ASSERT_NOT_NULL(archivo);

    // cleanup
    archivo = cerrarArchivo(archivo);
    metadatoPrueba = freeMetadato(metadatoPrueba);
}

void test_cerrarArchivoValido(void)
{
    printf("\t***(TEST) cerrarArchivoValido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //pre-requisite
    archivo = abrirArchivo(NOMBRE_ARCHIVO);

    //function to test
    archivo = cerrarArchivo(archivo);

    //archivo exists, so NULL expected when closing it
    TEST_ASSERT_NULL(archivo);
}

void test_cerrarArchivoInvalido(void)
{
    printf("\t***(TEST) cerrarArchivoInvalido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //pre-requisite
    archivo = abrirArchivo(NOMBRE_ARCHIVO_INVALIDO);

    //function to test
    archivo = cerrarArchivo(archivo);

    //archivo doesnt exist, but NULL expected when trying to close it
    TEST_ASSERT_NULL(archivo);
}