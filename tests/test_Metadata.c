#include <stdio.h>
#include <stdlib.h>

#include "../libs/unity.h"

#include "../src/Metadata.c"

// #include(s) for unit testing files for each .c
#include "./test_agregarMetadatos.c"
#include "./test_guardarMetadatos.c"
#include "./test_leerMetadatos.c"
#include "./test_eliminarMetadatos.c"

void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    //agregar metadatos
    puts("//////////////////");
    RUN_TEST(test_addMetadato);
    puts("//////////////////");
    RUN_TEST(test_setMetadato);
    puts("//////////////////");

    //guardar metadatos
    RUN_TEST(test_abrirArchivoValido);
    puts("//////////////////");
    RUN_TEST(test_abrirArchivoInvalido);
    puts("//////////////////");
    RUN_TEST(test_escribirArchivo);
    puts("//////////////////");
    RUN_TEST(test_cerrarArchivoValido);
    puts("//////////////////");
    RUN_TEST(test_cerrarArchivoInvalido);
    puts("//////////////////");

    //leer metadatos
    RUN_TEST(test_abrirArchivoLecturaValido);
    puts("//////////////////");
    RUN_TEST(test_abrirArchivoLecturaInvalido);
    puts("//////////////////");
    RUN_TEST(test_recibirMetadatos);
    puts("//////////////////");

    //eliminar metadatos
    RUN_TEST(test_deleteMetadato);
    puts("//////////////////");
    RUN_TEST(test_freeMetadato);
    puts("//////////////////");

    return UNITY_END();
}