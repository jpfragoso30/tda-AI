#include <stdio.h>
#include <stdlib.h>

#include "../libs/Metadata.h" 

struct _metadato
{
    char **columna;
    char **tipo;
    size_t n_metadatos;
    float *contenido;
};

Metadato addMetadato(size_t n_metadatos){
    Metadato new_meta = NULL;
    new_meta = malloc(sizeof(struct _metadato)); 

    //Validación
    if(!new_meta) return NULL;

    new_meta->contenido = calloc(n_metadatos,sizeof(float));
    new_meta->n_metadatos = n_metadatos;

    return new_meta;
}

void setMetadato(Metadato emp_metadato){
    for(size_t i = 0; i < emp_metadato->n_metadatos; i++){
        printf("Add: \n");
        scanf("%f", &emp_metadato->conenido[i]);
    }
}

Metadato deleteMetadato(Metadato del_metadato){
    free(del_metadato);
    del_metadato = NULL;
    return del_metadato;
}

