#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"

///*Se va a la funcion modular de empezar una desafio para el jugador en una pantalla nueva */

void iniciar_Partida(char tablero[TAM][TAM], char nombre[limite], char desafio[limite], int* num_partida)
{

///Inicializa el tablero poniendo cada casilla un espacio vacio al comienzo
    Inicializar_tablero(tablero);
    int eleccion=0;


    /**se declara la variable para controlar y saber cual nivel va escoger
    el usuario en caso de precargar un desafio desde el arhivo de texto */

    int restriccion;

    system("cls");
    fflush(stdin);

    eleccion=  preguntar_usuario(nombre);

    switch (eleccion)
    {
    case 1 : ///  aqui donde hay que reemplazar la carga de tablero */
        Cargar_tablero(tablero,nombre, &restriccion, desafio);
        // Se encarga de dirigir la seleccion del desafio segun la dificultad elegido por el usuario

        break;

    case 2:
        // Se encarga de dirigir  a llevar a la pantalla donde el usuario cargara su propio tablero personalizado
        Crear_tableromanual(tablero, desafio);
        restriccion=2;
        cuadro_texto(32, 10," se ha creado el tablero personalizado\n",0);
        getch();
        break;


    default :
        printf("No ha introducido un numero correcto. Intente de nuevo");
        getch();
        break;


    }

/// funcion modular que se respondable del sistema o jugabilidad del tablero principal que se encarga de los movimientos y validarlos y ganar o perder
    sistema_movimiento(tablero,nombre, restriccion, desafio, num_partida);


}




/// pregunta el usuario si quiere cargar un desafio precargado
int preguntar_usuario(char nombre[limite])
{
    int opcion;
    char texto1[]=  "1)--> Jugar un desafio precargado?";
    char texto2[]=  "2)---> Crear un desafio personalizado";
    do
    {
        system("cls");
        fflush(stdin);
        presentacion_nombre(nombre);
        cuadro_texto(10, 15, texto1,0);
        cuadro_texto(60, 15, texto2,0);

        gotoxy(42, 20);
        printf("Escoga una opcion y presione ENTER: ");
        scanf("%i", &opcion);           // pide el numero de la opcion
        if (opcion!=1 && opcion!= 2)
        {
            traslado(35);
            printf("No ha escogido una opcion valida, intente de nuevo");
            getch();
        }
    }
    while (opcion!=1 && opcion!=2);
    return opcion;
}



