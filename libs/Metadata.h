/**
* @Author: Sebastian Castaneda, Juan Pablo Fragoso, Ana Regina Morfin.
* @Date: 28 Sept 2021
* @Name Metadata.h
*/

#ifndef Metadata_h
#define Metadata_h

#include <stdio.h>
#include <stdlib.h>


typedef struct _metadato* Metadato;

//Constructor
Metadato addMetadato(size_t n_metadatos);
void setMetadato(Metadato emp_metadato);
Metadato deleteMetadato(Metadato del_metadato);

#endif