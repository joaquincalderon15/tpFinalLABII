#ifndef LISTACONTENIDO_H_INCLUDED
#define LISTACONTENIDO_H_INCLUDED

#include "stContenido.h"

///ESTRUCTURA LISTA CONTENIDO

typedef struct _nodoSimple{
    stContenido contenidoSocial;
    struct _nodoSimple* siguiente;

} nodoSimple;





/*###############PROTOTIPOS FUNCIONES DE MANEJO LISTA CONTENIDO#################*/

nodoSimple* inicListaSimple(void);
nodoSimple* crearNodoSimple (stContenido contenidoSocial);
nodoSimple* agregarPpioSimple (nodoSimple* lista, nodoSimple* nuevoNodo);
nodoSimple* agregarNodoFinalSimple (nodoSimple* lista, nodoSimple* nuevoNodo);
nodoSimple* buscarUltimoNodoSimple (nodoSimple* lista);
nodoSimple* agregarEnOrdenSimple(nodoSimple* lista, nodoSimple* nuevoNodo);
nodoSimple* borrarNodoSimpleSegunidContenido (nodoSimple* lista, int idContenido); //tres casos, que el nodo sea el primero, este en el medio o este en el ultimo nodo de la lista
void mostrarNodoSimple (nodoSimple* nodito);
void recorrerYMostrarSimple (nodoSimple* lista);


/*#############################################################################*/


#endif // LISTACONTENIDO_H_INCLUDED
