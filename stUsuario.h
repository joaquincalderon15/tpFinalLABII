#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

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
    int rol;                     // 1: es admin - 0: es comun
    int activo;                 // indica 1 o 0 si el usuario está activo
} stUsuario;


#endif // STUSUARIO_H_INCLUDED
