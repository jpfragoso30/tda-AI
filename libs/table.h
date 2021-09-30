/**
*@author Sebastian Castaneda, Juan Pablo Fragoso, Ana Regina Morfin.
*@date 29 de sept 2021
*@name table.h
**/

#include <stdio.h>

#ifndef table_h
#define table_h

#define TABLE struct table

//structure
typedef struct _table* Table; //incomplete data type private DT

//Constructor
Vector newVector(float *elements, size_t n_elements);
Table setTable(size_t element, string title, string datatype);
Table getTable(Table table, size_t element);
Table freeTable(Table myTable);

void printTable(Table *myTable);

#endif
