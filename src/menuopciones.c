#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Incluir archivos .c y .h

void Menu1 ();
void Menu2 ();

int main (void)
{
  //Declaraciones
  int option, option2;
  system("clear");
  do
  {
    //Desplegar Menú
    Menu1();
    //Selección de opción
    scanf ("%d", &option);
    printf("\e[1;1H\e[2J");
    switch(option)
    {
      case 1:
      //Imprimir
      printf("Insert printing function here\n");
      break;
      case 2:
      //Modificar tabla, incluye agregar y eliminar metadato
      {
        system("clear");
        do
        {
          //Print menu options regarding DB
          Menu2();
          //Option selection
          scanf ("%d", &option2);
          printf("\e[1;1H\e[2J");
          switch(option2)
          {
            case 1:
            //Add function
            printf("Insert Add function here\n");
            break;
            case 2:
            //Delete function
            printf("Insert Delete function here\n");
            break;
          }
        }while (option2 != 3);
      }
      break;
      case 3:
      //Guardar tabla
      printf("Insert Save function here\n");
      break;
    }
  }while (option != 4);
  printf("\n\nGoodbye!\n\n");
  return 0;
}

void Menu1 ()
{
  printf("MAIN MENU\n");
  printf("--------------------------\n");
  printf("Select option:\n");
  printf("--------------------------\n");
  printf("1.Print table\n2.Modify table\n3.Save table\n4.Exit\n");
  printf("--------------------------\n\n");
}

void Menu2 ()
{
  printf("MODIFY\n");
  printf("--------------------------\n");
  printf("Select option:\n");
  printf("--------------------------\n");
  printf("1.Add metadata\n2.Delete metadata\n3.Back to main menu\n");
  printf("--------------------------\n\n");
}
