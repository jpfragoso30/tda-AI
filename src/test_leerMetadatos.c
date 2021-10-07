#include <stdio.h>
#include <stdlib.h>
#include "../libs/Metadata.h"
#include "../libs/unity.h"

void test_leerMetadatos(void)
{
  puts("Testing Reading Metadata Function");
  Metadato *test_metadato = NULL;
  test_metadato = leerMetadatos(INITSIZE, &archivo);
  TEST_ASSERT_NOT_NULL(test_metadato);
}
