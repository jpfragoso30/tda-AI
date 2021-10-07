#include <stdio.h>
#include <stdlib.h>
#include "../libs/Metadata.h"
#include "../libs/unity.h"

void test_addMetadato(void)
{
  puts("Testing Reading Metadata");
  Metadato test_metadato = addMetadato(TEST_ARRAY);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, addMetadato(Metadato), strlen(TEST_ARRAY));
  deleteMetadato(test_metadato);
}

void test_setMetadato(void)
{
  puts("Testing Setting Metadata");
  Metadato test_metadato = NULL;
  size_t n_metadatos = 0;
  float contenido = 0;
  test_metadato = addMetadato(TEST_ARRAY);
  test_metadato = setMetadato(test_metadato);
  n_metadato = test_metadato->n_metadato;
  contenido = test_metadato->contenido;
  TEST_ASSERT_EQUAL(TEST_ARRAY, testVector->n_metadato);
  TEST_ASSERT_EQUAL_CHAR_ARRAY(buffer, addMetadato(Metadato), strlen(TEST_ARRAY));
}
