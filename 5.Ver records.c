#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"



/** Pendiente: Completar esta seccion
Agregar la funcionalidad de leer los records guardados de un archivo y mostraro en pantalla.
nota2: anadir un registador en la funcion de jugar partida para cada ves que
inicia la partida , ver modulo de sistema de movimiento*/
void Ver_Records(char nombre[], char tablero[TAM][TAM])
{
    int opcion;
    do
    {
        system("cls");
        fflush(stdin);
        presentacion_nombre(nombre);
        //Se impprime el menu de registros
        cuadro_texto(28, 6, "            Tabla de Clasificacion                    ",0);
        cuadro_texto(35, 12, " 1--->Ver registro de nivel Entrenamiento",0);
        cuadro_texto(39, 16, "2--->Ver registro de nivel Facil",0);
        cuadro_texto(38, 20, "3--->Ver registro de nivel Dificil",0);

        gotoxy(35, 24);
        printf("Introduzca la opcion y presione Enter: ");
        scanf("%i", &opcion);
        if (opcion!=1 &&opcion!=2 &&opcion!=3)
        {
            gotoxy(35, 24);
            printf("El numero introducido es incorrecto.Intente de nuevo");
            getch();
        }
    }
    while (opcion!=1 &&opcion!=2 &&opcion!=3);

}

///Pendiente
/**
system("cls");
presentacion_nombre(nombre);

cuadro_texto(45, 6, "Haciendo registro");

printf("\n");
system("pause");
CrearArchivo_nuevapartidas(tablero);

printf("\n");
traslado(25);printf("se va a leer el archivo\n");
Leer_partidasguardadas(tablero);*/
