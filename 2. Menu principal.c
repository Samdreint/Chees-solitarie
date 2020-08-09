#include <stdio.h>
#include <stdlib.h>
#include"milibreria.h"

///  funcion que muestra el menu principal del juego con las opciones principales y devuelve la opcion del usuario //

int Menu(char nombre[limite])
{

    int opcion=0;
    presentacion_nombre(nombre);      // funcion rapida que presenta el nombre del jugador en la pantalla

    dibujo_tablero();   /// imprime en pantalla una imagen detallada de un tablero 4x4 como adorno del menu grafico

    //muestra el menu principal //

    /* esta parte del codigo controlo la impresion de los rectangulos y las opciones a mostrar*/
    {
        for(int x=0 ; x<4 ; x++)
        {
            if (x==0)
            {
                printf("\t");
            }

            for(int y=0 ; y<22 ; y++ )
            {
                if (y==0)
                {
                    printf("%c",201);   // imprime la esquina superior izquierda
                }
                printf("%c", 205);    // imprime la raya horizontal
                if (y==21)
                {
                    printf("%c ",187);   // imprime la esquina superior derecha
                }
            }
        }
        printf("\n");

// imprime en pantalla las opciones

        printf("\t%c",186);
        printf("(1)--> Partida nueva  ");
        printf("%c ",186);
        printf("%c",186);
        printf("(2)--> Cargar Partida ");
        printf("%c ",186);
        printf("%c",186);
        printf("(3)--> Mostrar Records");
        printf("%c ",186);
        printf("%c",186);
        printf("(4)--> Salir del Juego");
        printf("%c",186);
        printf("\n");


        {
            // SE e imprime los recuadros graficos de las opciones
            for(int x=0 ; x<4 ; x++)
            {
                if (x==0)
                {
                    printf("\t");
                }

                for(int y=0 ; y<22 ; y++ )
                {
                    if (y==0)
                    {
                        printf("%c",186);
                    }
                    printf(" ");
                    if (y==21)
                    {
                        printf("%c ",186);
                    }
                }
            }
            printf("\n");

            for(int x=0 ; x<4 ; x++)
            {
                if (x==0)
                {
                    printf("\t");
                }

                for(int y=0 ; y<22 ; y++ )
                {
                    if (y==0)
                    {
                        printf("%c",200);
                    }
                    printf("%c", 205);
                    if (y==21)
                    {
                        printf("%c ",188);
                    }
                }
            }
        }

    }


    printf("\n\t\t\t\t\tEscoga la Opcion y presiona ENTER: ");
    scanf("%i", &opcion);  // se pide la opcion a escoger al usuario
    fflush(stdin);

    /** se pide al usuario el numero
    de la opcion para luego devolver un valor al archivo fuente Solitarie cheess
    especicifamente en la variable local opcion del main*/


    return opcion;  /// devuelve la opcion escogida por el usuario

}



