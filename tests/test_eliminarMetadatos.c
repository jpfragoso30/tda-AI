#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/unity.h"

#include "../libs/Metadata.h"

#define ELIMINARCOLUMNA "TestEliminarColumna"

void test_deleteMetadato(void)
{
    printf("\t***(TEST) deleteMetadato***\n\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = setMetadato(myMeta);
    myMeta = deleteMetadato(myMeta, ELIMINARCOLUMNA);
    TEST_ASSERT_EQUAL_STRING("\0", getColumna(myMeta, 0));
    TEST_ASSERT_EQUAL_STRING("\0", getTipo(myMeta, 0));
    myMeta = freeMetadato(myMeta);
}

void test_freeMetadato(void)
{
    printf("\t***(TEST) freeMetadato***\n\n");
    Metadato myMeta = NULL;
    myMeta = addMetadato(1);
    myMeta = freeMetadato(myMeta);
    TEST_ASSERT_NULL(myMeta);
}