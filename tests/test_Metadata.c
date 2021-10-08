#include <stdio.h>
#include <stdlib.h>

#include "../libs/unity.h"

#include "../src/Metadata.c"

// #include(s) for unit testing files for each .c
#include "./test_agregarMetadatos.c"
#include "./test_guardarMetadatos.c"

void setUp(void)
{
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    // RUN_TEST(functions..., __LINE__);

    //agregar metadatos
    RUN_TEST(test_addMetadato);
    RUN_TEST(test_setMetadato);
    RUN_TEST(test_deleteMetadato);
    RUN_TEST(test_freeMetadato);

    //guardar metadatos
    RUN_TEST(test_abrirArchivoValido);
    RUN_TEST(test_abrirArchivoInvalido);

    RUN_TEST(test_escribirArchivo);

    RUN_TEST(test_cerrarArchivoValido);
    RUN_TEST(test_cerrarArchivoInvalido);

    return UNITY_END();
}