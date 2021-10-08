#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/Metadata.h"
#include "../libs/unity.h"

#define EXPSIZE 5
#define COLUMNA "TestColumna"
#define TIPO "TestTipo"
#define ELIMINARCOLUMNA "TestEliminarColumna"
#define ELIMINARTIPO "TestEliminarTipo"

void test_addMetadato(void){
    printf("Test addMetadato\n");
    Metadata myMeta = NULL;
    myMeta = addMetadato(SIZE);
    TEST_ASSERT_NOT_NULL(myMeta);
    freeMetadato(myMeta);
}

void test_setMetadato(void){
    printf("Test setMetadato\n");
    Metadata myMeta = NULL;
    myMeta = addMetadato(1);
    setMetadato(myMeta);
    TEST_ASSERT_EQUAL_STRING(COLUMNA, myMeta->columna[0]);
    TEST_ASSERT_EQUAL_STRING(TIPO, myMeta->tipo[0]);
    freeMetadato(myMeta);
}

void test_deleteMetadato(void){
    printf("Test deleteMetadato\n");
    Metadata myMeta = NULL;
    myMeta = addMetadato(1);
    setMetadato(myMeta);
    myMeta = deleteMetadato(myMeta,ELIMINARCOLUMNA);
    TEST_ASSERT_EQUAL_STRING('\0', myMeta->columna[0]);
    TEST_ASSERT_EQUAL_STRING('\0', myMeta->tipo[0]);
    freeMetadato(myMeta);
}

void test_freeMetadato(void){
    printf("Test freeMetadato\n");
    Metadata myMeta = NULL;
    myMeta = addMetadato(1);
    freeMetadato(myMeta);
    TEST_ASSERT_NULL(myMeta);
}
