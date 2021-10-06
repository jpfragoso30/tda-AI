/**
 * @Author Cesarin Anggelidis
 * @Date 17 Aug 2021
 * @Name ComplexNumber.h
 * @Copyright TDA Otoño 2021
 */

// SOLID Convention

#ifndef ComplexNumber_h
#define ComplexNumber_h
// Bibliotecas Standard
#include <stdio.h>

// User Libraries


// Data Types

struct _Complex_Number{
    float real; // 32 bits
    float imaginary; // 32 bit
};

// Wrapper
typedef struct _Complex_Number* ComplexNumber;
typedef enum{
    _FALSE,
    _TRUE
}_bool;

// Interfaces

// Generator/Constructors


ComplexNumber newComplexNumber(void);


ComplexNumber setComplexNumber(ComplexNumber phasor, float real, float imaginary);


ComplexNumber getComplexNumberComponents(ComplexNumber phasor, float *real, float *imaginary);


ComplexNumber freeComplexNumber(ComplexNumber phasor);

#endif
