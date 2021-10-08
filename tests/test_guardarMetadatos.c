#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h"
#include "../libs/unity.h"

#define NOMBRE_ARCHIVO "prueba.txt"

void test_abrirArchivo(void)
{
    puts("Testing Abrir Archivo Prueba");

    //initialize testing variable
    FILE *archivo = NULL;

    //function to test
    archivo = abrirArchivo(NOMBRE_ARCHIVO);

    //archivo exists, so no NULL expected
    TEST_ASSERT_NOT_NULL(archivo);

    // to prevent anything
    fclose(archivo);
}