#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stContenido.h"
#include "arbolContenido.h"

nodoArbolContenido* inicArbolContenido (){
    return NULL;

}

nodoArbolContenido* crearNodoArbolContenido (stContenido nuevoContenido){
    nodoArbolContenido* aux = (nodoArbolContenido*) malloc(sizeof(nodoArbolContenido));

    aux->contenido=nuevoContenido;
    aux->derecha=NULL;
    aux->izquierda=NULL;

    return aux;
}

nodoArbolContenido* deArchiToArbolContenido (nodoArbolContenido* arbol, FILE* archi){
    int cantidadElementos=0;
    int i=0;
    stContenido* arregloAux=NULL;

    if(archi){
        cantidadElementos=calcularElementosArchivoContenido(archi);
        arregloAux=(stContenido*)malloc(sizeof(stContenido)*cantidadElementos);
        while(!feof(archi) && i<cantidadElementos){
            fread(arregloAux+i,sizeof(stContenido), 1, archi);
            i++;
        }

        ordenarPorSeleccion(arregloAux, cantidadElementos);
        arbol=deArregloBalanceadoToArbol(arbol, arregloAux, 0, cantidadElementos-1);
        free(arregloAux);
    }
    return arbol;
}

void imprimirPreorderArbolContenido (nodoArbolContenido* raiz){
    if(raiz){
        imprimirContenido(raiz->contenido);
        imprimirPreorderArbolContenido(raiz->izquierda);
        imprimirPreorderArbolContenido(raiz->derecha);
    }

}

void imprimirInorderArbolContenido (nodoArbolContenido* raiz){
    if(raiz){
        imprimirInorderArbolContenido (raiz->izquierda);
        imprimirContenido(raiz->contenido);
        imprimirInorderArbolContenido (raiz->derecha);

    }

}

void imprimirPostorderArbolContenido (nodoArbolContenido* raiz){
    if (raiz){
        imprimirPostorderArbolContenido (raiz->izquierda);
        imprimirPostorderArbolContenido (raiz->derecha);
        imprimirContenido(raiz->contenido);
    }
}

int contarNodos(nodoArbolContenido* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
    }
}

nodoArbolContenido* buscarNodoArbolContenido (nodoArbolContenido* arbol, int idBuscado){
    nodoArbolContenido* nodoBuscado=NULL;
    if(arbol){
        if(idBuscado==arbol->contenido.idContenido){
            nodoBuscado=arbol;
        }
        else{
            if(idBuscado<=arbol->contenido.idContenido){
                nodoBuscado=buscarNodoArbolContenido(arbol->izquierda, idBuscado);
            }
            else{
                nodoBuscado=buscarNodoArbolContenido(arbol->derecha, idBuscado);
            }
        }

    }

    return nodoBuscado;
}

nodoArbolContenido* insertarNuevoNodoContenido (nodoArbolContenido* arbol, nodoArbolContenido* nuevoNodo){
    if(!arbol){
        arbol=nuevoNodo;
    }
    else{
        if(nuevoNodo->contenido.idContenido <= arbol->contenido.idContenido){
            arbol->izquierda=insertarNuevoNodoContenido(arbol->izquierda, nuevoNodo);
        }
        else {
            arbol->derecha=insertarNuevoNodoContenido(arbol->derecha, nuevoNodo);
        }
    }

    return arbol;
}

nodoArbolContenido* eliminarNodoContenido (nodoArbolContenido* arbol, int idNodoABorrar){
    nodoArbolContenido* aux=NULL;

    if(arbol){
        if(arbol->contenido.idContenido == idNodoABorrar){
            if(esHojaContenido(arbol)){
                free(arbol);
                arbol=NULL;
            }
            else{
                if(arbol->izquierda){
                    aux=nodoMasDerecho(arbol->izquierda);
                    arbol->contenido=aux->contenido;
                    arbol->izquierda=eliminarNodoContenido(arbol->izquierda, aux->contenido.idContenido);
                }
                else{
                    if(idNodoABorrar>arbol->contenido.idContenido){
                        arbol->derecha=eliminarNodoContenido(arbol->derecha, idNodoABorrar);
                    }
                    else{
                        arbol->izquierda=eliminarNodoContenido(arbol->izquierda, idNodoABorrar);
                    }

                }
            }
        }
    }
    else{


    }

    return arbol;

}

int esHojaContenido (nodoArbolContenido* arbol){ //devuelve 1 si es hoja o 0 si no es hoja
    int rta=0;

    if(!(arbol->derecha)&&!(arbol->izquierda))
        rta=1;

    return rta;
}

nodoArbolContenido* nodoMasDerecho (nodoArbolContenido* arbol){
    nodoArbolContenido* rta =arbol;
    if(rta && (rta->derecha)==NULL){
    }
    else{
        rta=nodoMasDerecho(arbol->derecha);

    }
    return rta;

}

nodoArbolContenido* nodoMasIzquierdo(nodoArbolContenido* arbol){
    nodoArbolContenido* rta =arbol;
    if(rta && (rta->izquierda)==NULL){
    }
    else{
        rta=nodoMasDerecho(arbol->izquierda);

    }
    return rta;

}

nodoArbolContenido* deArregloBalanceadoToArbol (nodoArbolContenido* raiz, stContenido* arregloContenido, int posInicio, int posFinal){

    if(posFinal > posInicio){
        int medio = esMedio(posInicio+posFinal);
        raiz=insertarNuevoNodoContenido(raiz,crearNodoArbolContenido(arregloContenido[medio]));
        raiz=deArregloBalanceadoToArbol(raiz,arregloContenido,posInicio,medio-1);
        raiz=deArregloBalanceadoToArbol(raiz,arregloContenido,medio+1,posFinal);


    }

    return raiz;
}

int esMedio(int validos){
    return round(validos/2);


}


nodoArbolContenido* crearNuevoContenido (nodoArbolContenido* raiz){
    stContenido aux;

    aux= cargarContenido();
    raiz=insertarNuevoNodoContenido(raiz, crearNodoArbolContenido(aux));


    return raiz;
}

void guardarArbolContenidoEnArchivo (nodoArbolContenido* raiz, const char* nombreArchivo ){
    FILE* archi = fopen(nombreArchivo, "ab");

    if (archi){
        guardarInorderContenido(raiz,archi);
        fclose(archi);
    }


}

void guardarInorderContenido (nodoArbolContenido* raiz, FILE* archi){
    if (raiz){
        guardarInorderContenido(raiz->izquierda, archi);
        fwrite(&(raiz->contenido),sizeof(stContenido),1,archi);
        guardarInorderContenido(raiz->derecha,archi);
    }
}

