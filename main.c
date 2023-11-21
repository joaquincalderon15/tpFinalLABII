#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stContenido.h"
#include "listaContenido.h"
#include "arbolContenido.h"
#include "stUsuario.h"
#include "adlUsuarios.h"
#include "stFavorito.h"



void quienesSomos(void);
void faq(const char *nombreArchivo);
void subprogramaLogIn (void);
void subprogramaSignIn (void);


int main (void)
{
    int opcion=0;
    FILE* pArchiUsuarios=fopen("usuarios.dat", "a+b");
    FILE* pArchiContenido=fopen("contenidos.dat", "a+b");
    FILE* pArchiFavoritos=fopen("favoritos.dat", "a+b");

    stCelda* adl= inicADL();
    nodoArbolContenido* arbolContenido =inicArbolContenido();


    if(pArchiUsuarios && pArchiContenido && pArchiFavoritos)
    {
        arbolContenido=deArchiToArbolContenido (arbolContenido, pArchiContenido);
        deArchiToArregloUsuarios (adl, pArchiUsuarios);

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
                faq("meme.txt");
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


void subprogramaLogIn (void){

}

void subprogramaSignIn (void){

}





void faq(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        perror("Error al abrir el meme");
        exit (EXIT_FAILURE);
    }
    else{
        char linea[1000];  // Ajusta el tamaño según sea necesario

        while (fgets(linea, sizeof(linea), archivo) != NULL) {
            printf("%s", linea);
        }

        fclose(archivo);
    }

}

