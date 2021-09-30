#include <stdio.h>
#include <stdlib.h>
#include "../libs/table.h"

struct _table
{
  string *datatype;
  string *values;
  size_t elements;
};

static size_t tableMemory(Table check)
{
  if(check)return;
}

Table newTable(string *title, string *datatype, size_t elements)
{
  Table my_table = NULL;

  my_table = malloc(sizeof(struct _table)); //quiero la estructura completa
  if(!my_table)return NULL;

  my_table->title = calloc(elements, sizeof(string));
  my_table->datatype = calloc(elements, sizeof(string));
  my_table->n_elements;

  return my_table;
}

Table setTable(size_t element, string title, string datatype)
{

}

Table getTable(Table table, size_t element)
{

}

Table freeTable(Table myTable)
{

}
