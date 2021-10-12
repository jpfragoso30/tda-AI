#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libs/unity.h"

#include "../libs/Metadata.h"

#define EXPSIZE 5
#define COLUMNA "TestColumna"
#define TIPO "TestTipo"
#define ELIMINARCOLUMNA "TestEliminarColumna"

void setUp(void)
{
}

void tearDown(void)
{
}

//unit tests functions
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
//

int main(void)
{
    UNITY_BEGIN();

    puts("//////////////////");
    RUN_TEST(test_addMetadato);
    puts("//////////////////");
    RUN_TEST(test_setMetadato);
    puts("//////////////////");
    RUN_TEST(test_deleteMetadato);
    puts("//////////////////");
    RUN_TEST(test_freeMetadato);
    puts("//////////////////");

    return UNITY_END();
}