#include"milibreria.h"

/// pide  el nombre del usuario cuando empieza el juego
void pantalla_bienvenida(char nombre[limite])
{


    printf("\n\t\t\t\t  %c========================================%c\n",174,175);
    printf("\t\t\t\t\a  ****  BIENVENIDOS A CHESS SOLITARIE  ****\n");
    printf("\t\t\t\t  %c=========================================%c",174,175);
    gotoxy(40,6);
    printf("Descripcion de Chess Solitaire :\n");
    gotoxy(28,8);
    printf("Solitaire Chess es un rompecabezas de logica e ingenio");
    gotoxy(20,9);
    printf("inventado por el finlandes Vesa Timonen y producido por ThinkFun desde 2010");
    gotoxy(16,10);
    printf(" El juego es para un solo jugador y esta basado en las reglas del ajedrez tradicional");

    gotoxy(16,12);
    printf("El objetivo es capturar todas las piezas del tablero, de acuerdo con las cartas de desafio");
    gotoxy(19,13);
    printf("y siguiendo las reglas de movimiento, hasta que solo quede una sola pieza en el tablero");
    gotoxy(25,14);
    printf("Cada vez que se realiza un movimiento, se debe capturar o comer una pieza. ");
    gotoxy(35,20);
    printf("Introduce el nombre del jugador: ");
    gets(nombre);  // pide el nombre del usuario



    system("cls");







}

/// presenta el nombre del usuario en la sesion actual en la pantalla
void presentacion_nombre(char nombre[limite])
{

    printf("\n\t\t\t\t  %c========================================%c\n",174,175);
    printf("\t\t\t\t\a  ****  BIENVENIDOS A CHESS SOLITARIE  ****\n");
    for(int x=0 ; x<6 ; x++ )
    {
        printf("\t");
    }
    printf("**** %s ****\n", nombre);   // imprime la nombre del usuario
    printf("\t\t\t\t  %c=========================================%c\n",174,175);
}

