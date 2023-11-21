#ifndef STCONTENIDO_H_INCLUDED
#define STCONTENIDO_H_INCLUDED

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


/*###############PROTOTIPOS FUNCIONES DE MANEJO ESTRUCTURA ST CONTENIDO#################*/

void intercambiar(stContenido *a, stContenido *b);
void ordenarPorSeleccion(stContenido arreglo[], int validos);
int calcularElementosArchivoContenido (FILE* archi);
void imprimirContenido (stContenido contenido);
stContenido cargarContenido (void);

/*####################################################################################*/

#endif // STCONTENIDO_H_INCLUDED
