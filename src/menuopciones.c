#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Incluir archivos .c y .h

void Menu (void);

int main (void)
{
  //Declaraciones
  int option;
  system("clear");
  do
  {
    //Desplegar Menú
    Menu();
    //Selección de opción
    scanf ("%d", &option);
    switch(option)
    {
      case 1:
      //Imprimir
      printf("Imprimir\n");
      break;
      case 2:
      //Modificar tabla, incluye agregar y eliminar metadato
      printf("Modificar\n");
      break;
      case 3:
      //Guardar tabla
      printf("Guardar\n");
      break;
    }
  }while (option != 4);
  return 0;
}

void Menu (void)
{
  printf("Select option:\n");
  printf("1.Print table\n2.Modify table\n3.Save table\n4.Exit\n");
}
