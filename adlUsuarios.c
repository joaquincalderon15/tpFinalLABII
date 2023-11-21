#include <stdio.h>
#include <stdlib.h>
#include "listaContenido.h"
#include "stUsuario.h"
#include "stContenido.h"
#include "adlUsuarios.h"

stCelda* inicADL (void){
    return NULL;
}


stCelda* crearArregloDeListas (int dimension)
{
    stCelda* adl=(stCelda*)malloc(sizeof(stCelda)*dimension);
    return adl;
}



int redimensionarArregloDeListas(stCelda* arregloDeListas, int dimension) //redimensiona de acuerdo a
{
    arregloDeListas = (stCelda*) realloc(arregloDeListas,(sizeof(stCelda)+10*sizeof(stCelda)));
    return (dimension+10);
}

void deArchiToArregloUsuarios(stCelda* adl, FILE* archivoUsuarios){



}



