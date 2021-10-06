
#include <stdio.h>
#include <stdlib.h>


#include "../libs/ComplexNumber.h"
#include "../libs/unity.h"

#define REAL 0.02
#define IMAGINARY 0.1
#define DELTA 0.00005

void setUp(void){

}

void tearDown(void){

}


void test_ComplexNumberInit(void){
    puts("Testing Complex Number Init function");
    ComplexNumber test_number = NULL;
    test_number = newComplexNumber();
    TEST_ASSERT_NOT_NULL(test_number);
    freeComplexNumber(test_number);

}


void test_ComplexNumberSet(void){
    puts("Testing Complex Number Set Function");
    ComplexNumber test_number = NULL;
    float real=0, imaginary=0;
    test_number = newComplexNumber();

    test_number = setComplexNumber(test_number, REAL, IMAGINARY);

    // TEST CODE
    real = test_number->real;
    imaginary = test_number->imaginary;

    // TEST CODE
    TEST_ASSERT_FLOAT_WITHIN(DELTA, REAL, real);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, IMAGINARY, imaginary);
    freeComplexNumber(test_number);

}


void test_ComplexNumberGet(void){
    puts("Testing Complex Number Get Function");
    ComplexNumber test_number = newComplexNumber();
    float real=0, imaginary=0;

    test_number->real = REAL;
    test_number->imaginary = IMAGINARY;

    getComplexNumberComponents(test_number, &real, &imaginary);

    TEST_ASSERT_FLOAT_WITHIN(DELTA, REAL, real);
    TEST_ASSERT_FLOAT_WITHIN(DELTA, IMAGINARY, imaginary);
    freeComplexNumber(test_number);
}

void test_ComplexNumberFree(void){
    puts("Testing Complex Number Get Function");
    ComplexNumber test_number = newComplexNumber();

    test_number = freeComplexNumber(test_number);

    TEST_ASSERT_NULL(test_number);
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_ComplexNumberInit, __LINE__);
    RUN_TEST(test_ComplexNumberSet, __LINE__);
    RUN_TEST(test_ComplexNumberGet, __LINE__);
    RUN_TEST(test_ComplexNumberFree, __LINE__);
    return UNITY_END();
}
