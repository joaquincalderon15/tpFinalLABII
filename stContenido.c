#include <stdlib.h>
#include <stdio.h>
#include "stContenido.h"



void intercambiar(stContenido *a, stContenido *b) {
    stContenido temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorSeleccion(stContenido arreglo[], int validos) {
    int i=0;
    int j=0;
    int indiceMinimo=0;

    // Iterar sobre todo el arreglo
    for (i = 0; i < validos - 1; i++) {
        // Encontrar el índice del elemento mínimo en el resto del arreglo
        indiceMinimo = i;
        for (j = i + 1; j < validos; j++) {
            if (arreglo[j].idContenido < arreglo[indiceMinimo].idContenido) {
                indiceMinimo = j;
            }
        }

        // Intercambiar el elemento mínimo con el elemento en la posición actual
        intercambiar(&arreglo[i], &arreglo[indiceMinimo]);
    }
}

int calcularElementosArchivoContenido (FILE* archi){
    int cantidadElementos=0;
    fseek(archi, 0, SEEK_END); //seteo cursor al final del archivo
    cantidadElementos=ftell(archi) / sizeof(stContenido);
    fseek(archi,0,SEEK_SET);

    return cantidadElementos;
}

void imprimirContenido (stContenido contenido){
    printf("********************************\n\n");
    printf("ID CONTENIDo: %-30d", contenido.idContenido);
    printf("CATEGORIA CONTENIDO: %s\n", contenido.categoria);
    printf("TITULO: %s\n\n", contenido.titulo);
    printf("DESCRIPCION: %s\n", contenido.descripcion);
    printf("LIKES: %i\n", contenido.likes);

    printf("********************************\n");

}

stContenido cargarContenido (void){
    stContenido aux;

    printf("Ingrese el id del Contenido: ");
    scanf("%i", &aux.idContenido);
    fflush(stdin);
    printf("\n");
    printf("Ingrese el titulo de la publicacion: ");
    fgets(aux.titulo, sizeof(aux.titulo), stdin);
    fflush(stdin);
    printf("\n");
    fflush(stdin);
    printf("Ingrese la descripcion de la publicacion: ");
    fgets(aux.descripcion, sizeof(aux.descripcion), stdin);
    fflush(stdin);
    printf("\n");
    printf("Ingrese la categoria de la publicacion: ");
    fgets(aux.categoria, sizeof(aux.categoria), stdin);
    fflush(stdin);
    printf("\n");
    printf("Ingrese la cantidad de likes de la publicacion: ");
    scanf("%i", &aux.likes);
    fflush(stdin);
    printf("\n");
    printf("Ingrese los puntos de la publicacion: ");
    scanf("%i", &aux.puntosPorCompartir);
    fflush(stdin);
    printf("\n");
    printf("Ingrese el estado de la publicacion (1 si esta activa o 0 de lo contrario): ");
    scanf("%i", &aux.activo);
    fflush(stdin);
    printf("\n\n");

    return aux;
}
