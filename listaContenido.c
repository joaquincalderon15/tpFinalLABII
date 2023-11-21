#include <stdio.h>
#include <stdlib.h>
#include "stContenido.h"
#include "listaContenido.h"


nodoSimple* inicListaSimple(void){
    return NULL;
}

nodoSimple* crearNodoSimple (stContenido contenidoSocial){
    nodoSimple* aux = (nodoSimple*) malloc(sizeof(nodoSimple));
    aux->contenidoSocial= contenidoSocial;
    aux->siguiente = NULL;

    return aux;
}

nodoSimple* agregarPpioSimple (nodoSimple* lista, nodoSimple* nuevoNodo)
{
    if(!lista)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista=nuevoNodo;
    }

    return lista;
}

nodoSimple* agregarNodoFinalSimple (nodoSimple* lista, nodoSimple* nuevoNodo){
    if(!lista){
        lista=nuevoNodo;
    }
    else{
        nodoSimple* ultimo = buscarUltimoNodoSimple(lista);
        ultimo->siguiente = nuevoNodo;
    }

    return lista;

}

nodoSimple* buscarUltimoNodoSimple (nodoSimple* lista){
    nodoSimple* seg = lista;
    if(seg){
        while(seg->siguiente != NULL){
            seg = seg->siguiente;
        }
    }
    return seg;
}


nodoSimple* agregarEnOrdenSimple(nodoSimple* lista, nodoSimple* nuevoNodo){
    if(!lista){
        lista=nuevoNodo;
    }
    else{
        if(nuevoNodo->contenidoSocial.idContenido<lista->contenidoSocial.idContenido){

            agregarPpioSimple(lista, nuevoNodo);

        }
        else{
            nodoSimple* ante=lista;
            nodoSimple* seg=lista->siguiente;
            while((seg) && (nuevoNodo->contenidoSocial.idContenido>seg->contenidoSocial.idContenido)){
                ante=seg;
                seg=seg->siguiente;
            }
            nuevoNodo->siguiente=seg;
            ante->siguiente=nuevoNodo;

        }



    }

    return lista;
}

nodoSimple* borrarNodoSimpleSegunidContenido (nodoSimple* lista, int idContenido){ //tres casos, que el nodo sea el primero, este en el medio o este en el ultimo nodo de la lista

    nodoSimple* seg = lista;
    nodoSimple* ante;

    if((lista)&& lista->contenidoSocial.idContenido == idContenido)  //caso que fuera el primer nodo
    {
        lista=lista->siguiente;
        free(seg);

    }
    else
    {
        while((seg)&&seg->contenidoSocial.idContenido!=idContenido)
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg)
        {
            ante->siguiente=seg->siguiente;//enlazo el anterior con el siguiente del nodo que quiero eliminar
            free(seg);
        }
    }
    return lista;

}

void mostrarNodoSimple (nodoSimple* nodito){
    imprimirContenido (nodito->contenidoSocial);
}

void recorrerYMostrarSimple (nodoSimple* lista){
    nodoSimple* seg=NULL;

    if (lista){
        while(seg){
            mostrarNodoSimple(seg);
            seg=seg->siguiente;

        }

    }
}




