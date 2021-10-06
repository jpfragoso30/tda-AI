/**
 * @Author Ana Regina Morfín
 * @Date 17 Aug 2021
 * @Name ComplexNumber.c
 */

//Librerías
#include <stdio.h>
#include <stdlib.h>
#include "../libs/ComplexNumber.h"

//Instancia
ComplexNumber newComplexNumber(void)
{
  ComplexNumber phasor = NULL;
  phasor = malloc(sizeof(struct _Complex_Number));
  return phasor;
}

//my_number se guarda en la parte real e imaginaria
ComplexNumber setComplexNumber(ComplexNumber phasor, float real, float imaginary)
{
  phasor->real = real;
  phasor->imaginary = imaginary;
  return phasor;
}

//Llama a getReal y getImaginary para obtener los números complejos
ComplexNumber getComplexNumberComponents(ComplexNumber phasor, float *real, float *imaginary)
{
  *real = phasor->real;
  *imaginary = phasor->imaginary;
  return phasor;
}

//Liberar memoria donde se guarda número complejo
ComplexNumber freeComplexNumber(ComplexNumber phasor)
{
  free(phasor);
  phasor = NULL;
  return phasor;
}
