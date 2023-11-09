#include <stdio.h>
#include <stdlib.h>

///ESTRUCTURA CONTENIDO

typedef struct {
   int idContenido; // auto incremental
   char titulo[30];
   char descripcion[300];
   char categoria[30];
   int likes;
   int puntosPorCompartir;
   int activo;                     // indica 1 o 0 si el contenido está activo
} stContenido;

///LISTA SIMPLE

typedef struct _nodoSimple{
    stContenido contenidoSocial;
    struct _nodoSimple* siguiente;

} nodoSimple;




///ESTRUCTURA MENSAJERIA

typedef struct {
   int idUsuarioEmisor;
   int idUsuarioReceptor;
   int idContenidoEnviado;
   char mensaje[300];
   int leido;                      // 1:si 0:no
} stMensajeria;

///ESTRUCTURA ARBOL DE USUARIOS

typedef struct _nodoArbolContenido{
    stContenido contenido;
    struct _nodoArbolContenido* izquierda;
    struct _nodoArbolContenido* derecha;
} nodoArbolContenido;


/////////////////////////////
nodoSimple* inicListaSimple(void);
nodoSimple* crearNodoSimple (stContenido contenidoNuevo);
nodoSimple* agregarPpioSimple (nodoSimple* lista, nodoSimple* nuevoNodo);



/////////////////////////////
nodoArbolContenido* inicArbolContenido ();
nodoArbolContenido* crearNodoArbolContenido (stContenido nuevoContenido);
int profundidadArbolContenido (nodoArbolContenido* raiz);
int subprogramaAlturaArbolContenido(nodoArbolContenido* raiz);
int esHojaContenido (nodoArbolContenido* arbol); //devuelve 1 si es hoja o 0 si no es hoja
nodoArbolContenido* eliminarNodoContenido (nodoArbolContenido* arbol, int idNodoABorrar);
nodoArbolContenido* nodoMasDerecho (nodoArbolContenido* arbol);
nodoArbolContenido* nodoMasIzquierdo(nodoArbolContenido* arbol);


nodoSimple* arbolAListaContenido (nodoArbolContenido* arbol, nodoSimple* lista);










int main()
{
    printf("Hello world!\n");
    return 0;
}

nodoSimple* inicListaSimple(void){
    return NULL;
}

nodoSimple* crearNodoSimple (stContenido contenidoNuevo){
    nodoSimple* aux = (nodoSimple*) malloc(sizeof(nodoSimple));
    aux->contenidoSocial= contenidoNuevo;
    aux->siguiente = NULL;

    return aux;
}

nodoSimple* agregarPpioSimple (nodoSimple* lista, nodoSimple* nuevoNodo){
    if(!lista){
        lista = nuevoNodo;
    }
    else {
        nuevoNodo->siguiente = lista;
        lista=nuevoNodo;
    }
    return lista;
}


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

int profundidadArbolContenido (nodoArbolContenido* raiz){
    int rta=0;
    if(!raiz){
        int profundidadIzquierda=0;
        int profundidadDerecha=0;
        profundidadIzquierda = profundidadArbolContenido(raiz->izquierda);
        profundidadDerecha = profundidadArbolContenido (raiz->derecha);
        if (profundidadIzquierda>=profundidadDerecha){
            rta=profundidadIzquierda;
        }
        else{
            rta=profundidadDerecha;
        }
    }
    return rta;
}

int subprogramaAlturaArbolContenido(nodoArbolContenido* raiz){
    if(!raiz){
        return 0;
    }
    else{
        return (profundidadArbolContenido(raiz)+1);
    }

}

void preorderArbolContenido (nodoArbolContenido* raiz){
    if(raiz){
        printf("|%d|", raiz->contenido.idContenido);
        preorderArbolContenido(raiz->izquierda);
        preorderArbolContenido(raiz->derecha);
    }

}

void inorderArbolContenido (nodoArbolContenido* raiz){
    if(raiz){
        inorderArbolContenido (raiz->izquierda);
        printf("|%d|", raiz->contenido.idContenido);
        inorderArbolContenido (raiz->derecha);

    }

}

void postorderArbolContenido (nodoArbolContenido* raiz){
    if (raiz){
        postorderArbolContenido (raiz->izquierda);
        postorderArbolContenido (raiz->derecha);
        printf("|%d|", raiz->contenido.idContenido);

    }

}

int numeroHojasArbolContenido(nodoArbolContenido* raiz){
    int rta=0;
    if(raiz){
        if(raiz->izquierda==NULL && raiz->derecha == NULL){
            rta=1;
        }
        rta+=numeroHojasArbolContenido(raiz->izquierda);
        rta+=numeroHojasArbolContenido(raiz->derecha);
    }

    return rta;

}

void eliminarArbolContenido (nodoArbolContenido* raiz){
    if(raiz){
        eliminarArbolContenido(raiz->izquierda);
        eliminarArbolContenido(raiz->derecha);
        free(raiz);
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

nodoArbolContenido* buscarNodoContenidoIterativa (nodoArbolContenido* arbol, int idBuscado){
    nodoArbolContenido* arbolAux=arbol;
    int encontrado = 0;
    if(arbol){
        while (arbolAux && encontrado==0){
            if(idBuscado==arbolAux->contenido.idContenido){
                encontrado=1;
            }
            else{
                if(idBuscado<=arbolAux->contenido.idContenido){
                    arbolAux=arbolAux->izquierda;

                }
                else{
                    arbolAux=arbolAux->derecha;
                }


            }


        }


    }
    return arbolAux;
}



nodoArbolContenido* insertarNuevoNodoContenido (nodoArbolContenido* arbol, nodoArbolContenido* nuevoNodo){
    if(!arbol){
        arbol=nuevoNodo;
    }
    else{
        if(nuevoNodo->contenido.idContenido <= arbol->contenido.idContenido){
            arbol=insertarNuevoNodoContenido(arbol->izquierda, nuevoNodo);
        }
        else {
            arbol=insertarNuevoNodoContenido(arbol->derecha, nuevoNodo);
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


nodoSimple* arbolAListaContenido (nodoArbolContenido* arbol, nodoSimple* lista){
    nodoSimple* listaDeArbol=inicListaSimple();

    if(arbol)
    {
        lista=arbolAListaContenido(arbol->derecha, lista);
        lista=agregarPpioSimple(lista, (crearNodoSimple(arbol->contenido)));
        lista=arbolAListaContenido(arbol->izquierda, lista);
    }

    return listaDeArbol;
}
