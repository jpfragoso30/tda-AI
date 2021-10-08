#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h"
#include "../libs/unity.h"
#include "./test_agregarMetadatos.c"

// #include(s) for unit testing files for each .c

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
    RUN_TEST(test_addMetadato);
    //RUN_TEST(test_setMetadato);
    //RUN_TEST(test_deleteMetadato);
    RUN_TEST(test_freeMetadato);

    return UNITY_END();
}