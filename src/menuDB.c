#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/menuopciones.c"

//Incluir archivos .c y .h

void MenuDB (void);

//Falta conectar este con el menu principal
int main (void)
{
  //Declaraciones
  int option;
  system("clear");
  do
  {
    //Print menu options regarding DB
    MenuDB();
    //Option selection
    scanf ("%d", &option);
    switch(option)
    {
      case 1:
      //Add function
      printf("Add\n");
      break;
      case 2:
      //Delete function
      printf("Delete\n");
      break;
    }
  }while (option != 3);
  return 0;
}

void MenuDB (void)
{
  printf("Select option:\n");
  printf("1.Add metadata\n2.Delete metadata\n43.Exit\n");
}
