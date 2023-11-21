#ifndef ADLUSUARIOS_H_INCLUDED
#define ADLUSUARIOS_H_INCLUDED

#include "stContenido.h"
#include "stUsuario.h"
#include "listaContenido.h"

typedef struct
{
    stUsuario usuario;
    nodoSimple * listaDeContenidosFavoritos;
} stCelda;


/*###############PROTOTIPOS FUNCIONES DE MANEJO ESTRUCTURA ADL USUARIO#################*/

stCelda* inicADL (void);
stCelda* crearArregloDeListas (int dimension);
int redimensionarArregloDeListas(stCelda* arregloDeListas, int dimension);
void deArchiToArregloUsuarios(stCelda* adlUsuarios, FILE* archivoUsuarios);

/*####################################################################################*/


#endif // ADLUSUARIOS_H_INCLUDED
