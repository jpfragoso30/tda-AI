#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/unity.h"

#include "../libs/Metadata.h"

#define EXPSIZE 5
#define COLUMNA "TestColumna"
#define TIPO "TestTipo"

void test_addMetadato(void)
{
    printf("\t***(TEST) addMetadato***\n\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(EXPSIZE);
    TEST_ASSERT_NOT_NULL(myMeta);
    myMeta = freeMetadato(myMeta);
}

void test_setMetadato(void)
{
    printf("\t***(TEST) setMetadato***\n\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = setMetadato(myMeta);
    TEST_ASSERT_EQUAL_STRING(COLUMNA, getColumna(myMeta, 0));
    TEST_ASSERT_EQUAL_STRING(TIPO, getTipo(myMeta, 0));
    myMeta = freeMetadato(myMeta);
}
