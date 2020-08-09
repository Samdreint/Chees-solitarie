#include"milibreria.h"


/// imprime el tablero  y las piezas que contiene el tablero en el momento actual///
void Imprimir_tablero(char tablero[TAM][TAM])
{
    int parametro= 1;
    int largo=26-parametro;
    int tras=27;
    int espacio1=parametro;
    int espacio2=parametro;
    int contador1=0;  // controla la impresion de las rayas divisoria superior
    int contador2; // controla la impresion de las rayas divisoria interna del tablero
    int contador3=0;  // controla la impresion de las rayas divisorias cruzada hacia abajo dentro dl tablero
    int contador4=0;  // controla la impresion de las rayas divisoria interna del tablero
    int contador5=4;  // esta parte del codigo controla e  imprime los indices del tablero de la filas
    for(int y=0 ; y<largo ; y++ )
    {
        if (y==0)
        {
            traslado(tras);
            printf("%c",201);   // imprime esquina superior izquerda
        }

        switch (contador1)
        {
        case 6 :
            printf("%c", 203);
            break;
        case 12:
            printf("%c", 203);
            break;
        case 18:
            printf("%c", 203);
            break;

        default:
            printf("%c", 205);
            break;
        }

        if (y==largo-1)
        {
            printf("%c ",187);   // imprime esquina superior derecha
        }
        contador1++;
    }

    printf("\n");

    for(int fila=0 ; fila<TAM ; fila++ )
    {
        traslado(tras-2);
        for(int columna=0 ; columna<TAM ; columna++ )
        {
            if (columna==0)
            {
                if (contador5>0)
                {
                    printf("%i ", contador5);  // esta parte del codigo controla e  imprime los indices del tablero de la filas
                    contador5--;
                }

                printf("%c", 186);    //// imprime la raya vertical inicial de la columna
                for(int control=0 ; control<espacio1 ; control++)
                {
                    printf(" ");
                }

            }

            printf("  %c  ", tablero[fila][columna]);    // imprime la pieza
            if (columna!=TAM-1)
            {
                printf("%c",186);   // imprime la raya vertical
            }


            if(columna==TAM-1)
            {
                for(int control=0 ; control<espacio2 ; control++)
                {
                    printf(" ");    //// imprime la raya vertical final de la columna
                }
                printf("%c", 186);
                contador2=0;

            }
        }

        printf("\n");
        contador4++;
        if (contador4==4)
        {
            break;
        }

////////////

        for(int y=0 ; y<largo ; y++ )
        {

            if (y==0)
            {
                traslado(tras);
                printf("%c",204);   // imprime las esquinas cruzadas extremas
            }
            switch (contador2)
            {
            case 6 :
                printf("%c", 206);
                break;
            case 12:
                printf("%c", 206);
                break;
            case 18:
                printf("%c", 206);
                break;

            default:
                printf("%c", 205);
                break;
            }


            if (y==largo-1)
            {
                printf("%c ",185); // imprime las esquinas cruzadas extremas
            }
            contador2++;
        }
        printf("\n");
    }

    for(int y=0 ; y<largo ; y++ )
    {
        if (y==0)
        {
            traslado(tras);
            printf("%c",200); // imprime la esquina inferior izquierda
        }
        switch (contador3)  // controla la impresion de las rayas divisorias cruzada hacia abajo dentro del tablero
        {
        case 6 :
            printf("%c", 202);
            break;
        case 12:
            printf("%c", 202);
            break;
        case 18:
            printf("%c", 202);
            break;

        default:
            printf("%c", 205);
            break;
        }
        if (y==largo-1)
        {
            printf("%c ",188); // imprime la esquina inferior derecha
        }
        contador3++;
    }

    printf("\n");

    traslado(tras+4);

/// esta parte del codigo imprime los indices del tablero de la columna
    for(char n= 'a' ; n<'e' ; n++)
    {

        printf("%c", n);
        traslado(5);
    }

}

/// una funcion rapida que permite rapidamente hacer traladar un texto horizntalmente mas facil //
void traslado(int num)
{

    for(int x=0 ; x<num ; x++ )
    {
        printf(" ");
    }
}

