#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h"
#include "../libs/unity.h"

// #include(s) for unit testing files for each .c
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
    RUN_TEST(test_abrirArchivo, __LINE__);

    return UNITY_END();
}