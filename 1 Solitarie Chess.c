#include<stdio.h>
#include"milibreria.h"

/*
Alumno Samuel Maldonado Briceno
carnet: 16-10648
prof Josue
seccion: 2
Proyecto de Ajedrez Solitarie

 */

int main()
{

    SetConsoleTitle("Chess Solitarie developed by Samuel Jose.");   //permite Poner el titulo a ventana del juego en la pantalla de la consola*/
    int num_partida=0;
    system("mode 120,41");
    /** permite ajustar el tamanio de la ventana de la consolo a un parametro determinado
       poniendo 120 bite en espacio de ventana horizontalmente y 36 en la altura de la ventana*/

    // permite cambiar  el color de fondo y la letra de la pantalla de la consola//
    system("color  F0");

/// Esta funcion de encarga de coprobar si existe el archivo "partidasnuevas.txt"
    int comprobacion= Comprobar_archivo_nuevapartidas();

    if (comprobacion==1)
    {
        /// esta funcion se encarga de crear el archivo  partidasnuevas.txt" donde se almacenanlos desafios precargados
        CrearArchivo_nuevapartidas();
    }

    char desafio[100];
    int opcion;
    int cuenta=0;
    char tablero1[TAM][TAM];
    /** se declara una matriz llamda tablero tipo char que crea el tablero de ajedrez
    nota cambiar int tablero[TAM][TAM] por char tablero[TAM][TAM]; */
    char nombre[100];       // se declara el string que va a contener  el nombre de usuario
    pantalla_bienvenida(nombre);  // muestra un display de presentacion de pantalla
    do
    {
        system("cls");   /*limpia la pantalla*/
        fflush(stdin);  /* // limpia el buffer*/

        /// se llama a la funcion menu(char nombre), para guardar posteriormente el nombre y escoger una opcion delmenu principal  correspondiente y ademas devuelve el numero escogida para el swich*/
        opcion= Menu(nombre);

        switch (opcion)    // se escoge un caso para el menu principal
        {
        case 1:
            /// lleva a la funcion modular de empezar una desafio para el jugador en una pantalla nueva */
            iniciar_Partida(tablero1, nombre, desafio, &num_partida) ;
            cuenta=1;    //Inicia la intruccion que lleva al siguente menu para escoger el nivel de dificultad y*/
            /*  precargar el tablero para jugar*/
            break;

        case 2:
        {
            if (cuenta==0)
            {
                printf("\n\nNo hay parrida cargado\n");
                system("pause");  //da freno al programa hasta que se presione uuna tecla para seguir ejecutando
            }
            else
            {
                ///  Carga una partida hecha para renaudar el juego por el actual jugador */
                Cargar_Partida(tablero1,nombre, desafio, &num_partida);
            }
            break;
        }
        case 3:  ///Muestra la Tabla de clasificacion de los jugadores que han participado*/
            Ver_Records(nombre, tablero1);
            break;
        case 4:
            break;
        default:
            printf("\tDigite un numero valido para continuar\n\t");
            system("pause");
            break;
        }
    }
    while (opcion!=4);

    Salida(tablero1); ///  indica el final del juego y muestra una pantalla conrrespondiente a ello

    return 0;
}




