#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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


///ESTRUCTURA ARBOL DE CONTENIDO

typedef struct _nodoArbolContenido{
    stContenido contenido;
    struct _nodoArbolContenido* izquierda;
    struct _nodoArbolContenido* derecha;
} nodoArbolContenido;

typedef struct
{
    int idUsuario;                 // auto incremental
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int puntaje;
    int nivel;
    stContenido* listaDeFavoritos;
    int rol;                     // 1: es admin - 0: es comun
    int activo;                 // indica 1 o 0 si el usuario está activo
} stUsuario;

/*//ESTRUCTURA ARBOL DE USUARIOS
typedef struct _nodoArbolUsuario{
    stUsuario usuario;
    struct _nodoArbolUsuario* izquierda;
    struct _nodoArbolUsuario* derecha;
}nodoArbolUsuario;
*/
///LISTA SIMPLE

typedef struct _nodoSimple{
    stContenido contenidoSocial;
    struct _nodoSimple* siguiente;

} nodoSimple;

//ESTRUCTURA FAVORITOS

typedef struct
{
    int idFavorito;
    int idUsuario;
    int idContenido;
} stFavorito;

void quienesSomos(void);
void faq (void);
void subprogramaLogIn (void);
void subprogramaSignIn (void);

///////////////////ESTRUCTURA ADL///////////////////
stUsuario* inicADL (void);

///////////////////////////////////////////////////


int main (void)
{
    int opcion=0;
    FILE* pArchiUsuarios=fopen("usuarios.dat", "a+b");
    FILE* pArchiContenido=fopen("contenidos.dat", "a+b");
    FILE* pArchiFavoritos=fopen("favoritos.dat", "a+b");

    stUsuario* adlUsuarios= inicADL();
    nodoArbolContenido* arbolContenido =inicArbolContenido();


    if(pArchiUsuarios && pArchiContenido && pArchiFavoritos)
    {
        arbolContenido=deArchiToArbolContenido (arbolContenido, pArchiContenido);
        deArchiToArregloUsuarios (adlUsuarios, pArchiUsuarios);

        do
        {
            system("cls");
            printf("Bienvenido a la Red Social mas usada. \n\n\n\n\n");
            printf("%*s%s\n", 50, "", "iN-Social");
            printf("\n\n\n\n");
            printf("iN-Social! te ayuda a comunicarte y compartir con las personas que forman parte de tu vida.");
            printf("\n\n\n\n\n");
            printf("Menu de opciones: \n\n");
            printf("1) log in\n");
            printf("2) sign in\n");
            printf("3) Acerca de nosotros\n");
            printf("4) FAQ\n");
            printf("0) SALIR\n");
            printf("\n\n\n\n");

            printf("OPCION ELEGIDA:  ");


            scanf("%d", &opcion);
            fflush(stdin);
            printf("\n\n\n");
            switch (opcion)
            {
            case 1:
                subprogramaLogIn();
                break;
            case 2:
                subprogramaSignIn();
                break;
            case 3:
                quienesSomos();
                break;
            case 4:
                faq();
                break;

            default:

                if(opcion==0)
                {
                    system ("cls");
                    printf("\n\n\n\nGracias por utilizar iN-Social! Hasta pronto!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                    printf("%*s%s\n", 50, "", "version 2.0");
                    printf("\n\n\n\n\n");

                }
                break;

            }
            system("pause");

        }
        while (opcion!=0);


        fclose(pArchiContenido);
        fclose(pArchiUsuarios);
        fclose(pArchiFavoritos);
    }
    else{
        system ("cls");
        if(!pArchiContenido){
            perror("Error al abrir al cargar los contenidos.\n\n");
        }
        if(!pArchiUsuarios){
            perror("Error al cargar el usuario\n\n");
        }
        if(!pArchiFavoritos){
            perror("Error al cargar los favoritos\n\n");
        }
        exit(EXIT_FAILURE);
    }

    return 0;

}

void quienesSomos(void){
    system("cls");
    printf("\n\n\niN-Social! nace como una forma de comunicarnos en clase.\n\n");
    printf("Somos un grupo de cuatro estudiantes realizando el trabajo práctico final de Laboratorio de Programacion 2.\n");
    printf("Conformamos el grupo denominado \"Los Simuladores\"\n");
    printf("Esperamos con ansias aprobar este trabajo de la mejor manera posible y cumplir con todas las expectativas de la catedra *guinio guinio*\n\n\n\n");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Saludos Gustavo *guinio guinio*\n\n\n");

}

void faq (void){
    system("cls");
    printf("\n\n\n\nPregunten en clase, asi podemos sumarlas aca como preguntas frecuentes.\n\n\n");

}

void subprogramaLogIn (void){

}

void subprogramaSignIn (void){

}


stUsuario* inicADL (void){
    return NULL;
}

int calcularElementosEnArchivoUsuario(FILE* archi){
    int cantidadElementos=0;
    fseek(archi, 0, SEEK_END); //seteo cursor al final del archivo
    cantidadElementos=ftell(archi) / sizeof(stUsuario);
    fseek(archi,0,SEEK_SET);

    return cantidadElementos;

}
