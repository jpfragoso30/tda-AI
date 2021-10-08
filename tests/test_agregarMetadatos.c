#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/unity.h"

#include "../libs/Metadata.h"

#define EXPSIZE 5
#define COLUMNA "TestColumna"
#define TIPO "TestTipo"
#define ELIMINARCOLUMNA "TestEliminarColumna"
#define ELIMINARTIPO "TestEliminarTipo"

void test_addMetadato(void)
{
    printf("Test addMetadato\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(EXPSIZE);
    TEST_ASSERT_NOT_NULL(myMeta);
    myMeta = freeMetadato(myMeta);
}

void test_setMetadato(void)
{
    printf("Test setMetadato\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = setMetadato(myMeta);
    TEST_ASSERT_EQUAL_STRING(COLUMNA, getColumna(myMeta,0));
    TEST_ASSERT_EQUAL_STRING(TIPO, getTipo(myMeta,0));
    myMeta = freeMetadato(myMeta);
}

void test_deleteMetadato(void)
{
    printf("Test deleteMetadato\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = setMetadato(myMeta);
    myMeta = deleteMetadato(myMeta, ELIMINARCOLUMNA);
    TEST_ASSERT_EQUAL_STRING("\0", getColumna(myMeta,0));
    TEST_ASSERT_EQUAL_STRING("\0", getTipo(myMeta,0));
    myMeta = freeMetadato(myMeta);
}

void test_freeMetadato(void)
{
    printf("Test freeMetadato\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = freeMetadato(myMeta);
    TEST_ASSERT_NULL(myMeta);
}
