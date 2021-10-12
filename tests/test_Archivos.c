#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/unity.h"

#include "../libs/Metadata.h"
#include "../libs/Archivos.h"

#define NOMBRE_ARCHIVO "./tests/prueba.csv"
#define NOMBRE_ARCHIVO_INVALIDO "/asd/asji?-2912.tsj"

void setUp(void)
{
}

void tearDown(void)
{
}

//unit tests functions
void test_abrirArchivoValido(void)
{
    printf("\t***(TEST) abrirArchivoValido***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivo(NOMBRE_ARCHIVO, ARCHIVO_LECTURA);

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
    archivo = abrirArchivo(NOMBRE_ARCHIVO_INVALIDO, ARCHIVO_LECTURA);

    //archivo doesnt exist, so NULL expected
    TEST_ASSERT_NULL(archivo);

    // to prevent anything
    archivo = cerrarArchivo(archivo);
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
    archivo = abrirArchivo(NOMBRE_ARCHIVO, ARCHIVO_LECTURA);

    //function to test
    metadatoEntrante = recibirMetadatos(archivo, metadatoEntrante);

    //archivo exists, so lines of columna,tipo expected
    TEST_ASSERT_EQUAL_STRING("id", getColumna(metadatoEntrante, 0));
    TEST_ASSERT_EQUAL_STRING("float", getTipo(metadatoEntrante, 0));
    TEST_ASSERT_EQUAL_STRING("edad", getColumna(metadatoEntrante, 1));
    TEST_ASSERT_EQUAL_STRING("float", getTipo(metadatoEntrante, 1));

    //cleanup
    archivo = cerrarArchivo(archivo);
    metadatoEntrante = freeMetadato(metadatoEntrante);
}

void test_escribirArchivo(void)
{
    printf("\t***(TEST) escribirArchivo***\n\n");

    //initialize testing variable
    FILE *archivo = NULL;
    Metadato metadatoPrueba = NULL;
    size_t n_metadatos = 2;

    //pre-requisite
    archivo = abrirArchivo(NOMBRE_ARCHIVO, ARCHIVO_ESCRITURA);
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
    archivo = abrirArchivo(NOMBRE_ARCHIVO, ARCHIVO_LECTURA);

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
    archivo = abrirArchivo(NOMBRE_ARCHIVO_INVALIDO, ARCHIVO_LECTURA);

    //function to test
    archivo = cerrarArchivo(archivo);

    //archivo doesnt exist, but NULL expected when trying to close it
    TEST_ASSERT_NULL(archivo);
}
//

int main(void)
{
    UNITY_BEGIN();

    puts("//////////////////");
    RUN_TEST(test_abrirArchivoValido);
    puts("//////////////////");
    RUN_TEST(test_abrirArchivoInvalido);
    puts("//////////////////");
    RUN_TEST(test_escribirArchivo);
    puts("//////////////////");
    RUN_TEST(test_recibirMetadatos);
    puts("//////////////////");
    RUN_TEST(test_cerrarArchivoValido);
    puts("//////////////////");
    RUN_TEST(test_cerrarArchivoInvalido);
    puts("//////////////////");

    return UNITY_END();
}