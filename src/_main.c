#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Metadata.c"

int main(void)
{
    //Declaraciones
    int option, option2;
    Metadato tablaMetadatos = NULL;

    system("clear");
    do
    {
        //Desplegar Menú
        Menu1();
        //Selección de opción
        scanf("%d", &option);
        printf("\e[1;1H\e[2J");
        switch (option)
        {
        case 1:
            //Imprimir
            printTable(tablaMetadatos);
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
                    scanf("%d", &option2);
                    printf("\e[1;1H\e[2J");
                    switch (option2)
                    {
                        size_t elements;
                        char *columna;

                    case 1:
                        //Add function
                        scanf("Elements: %zd", &elements);
                        addMetadato(elements);
                        setMetadato(tablaMetadatos);
                        break;
                    case 2:
                        //Delete function
                        gets(columna);
                        tablaMetadatos = deleteMetadato(tablaMetadatos, columna);
                        break;
                    }
                } while (option2 != 3);
            }
            break;
        case 3:
            //Guardar tabla
            guardarMetadatos(tablaMetadatos, getNumberMetadatos(tablaMetadatos));
            break;
        }
    } while (option != 4);
    printf("\n\nGoodbye!\n\n");
    return 0;
}