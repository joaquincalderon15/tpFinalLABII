#include <stdio.h>
#include <stdlib.h>
#include "stUsuario.h"

int calcularElementosEnArchivoUsuario(FILE* archi){
    int cantidadElementos=0;
    fseek(archi, 0, SEEK_END); //seteo cursor al final del archivo
    cantidadElementos=ftell(archi) / sizeof(stUsuario);
    fseek(archi,0,SEEK_SET);

    return cantidadElementos;

}
