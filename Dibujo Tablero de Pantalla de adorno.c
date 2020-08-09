#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"

int Lrecuadro1=72;  // parametro del tamanio de la longitud de las lineas del tablero grafico
int blanca1= 177;// codigo ascii 177 =  ( Bloque color tramado densidad media, gráfico )
int blanca2= 219;   //codigo ascii 219 =  ( Bloque color pleno solido, carácter gráfico )
int negro1= 178;   //codigo ascii 178 =  ( Bloque color tramado densidad alta, carácter gráfico )
int negro2= 255;  // codigo ascii 255 = nbsp ( bloque de separacion o blanco - non breaking space )

//  es una funcion que permite imprimir el tablero de adorno de la pantalla del menu prinicipal
void dibujo_tablero()
{

    printf("\n");
    barra_sup();  //dibuja la linea de adorno para el contorno del tablero de adorno parte superior //

    for(int x=0 ; x<1 ; x++ )
    {
        printf("\n");
    }

    for(int x=0 ; x<2 ; x++)
    {
        linea_1();
        linea_2();
    }

    barra_inf(); //dibuja la linea de adorno para el contorno del tablero de adorno parte inferior //
    printf("\n");
}

void color (int n)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), n );
}


/// permite trazar las lineas que conforman el tablero de adorno de la pantalla principal
void linea_1()
{

    for(int filas=0 ; filas<5 ; filas++ )
    {
        traslado(18);
        printf("%c",186);   // imprime esquina superior izquerda
        for(int largo=0 ; largo<2 ; largo++ )
        {
            for(int grueso1=0 ; grueso1<tam; grueso1++ )
            {
                printf("%c",blanca2);
            }
            for(int grueso2=0 ; grueso2<tam; grueso2++)
            {
                printf("%c",negro2);
            }
        }
        printf("%c",186);
        printf("\n");
    }
}

///permite trazar las lineas que conforman el tablero de adorno de la pantalla principal
void linea_2()
{
    for(int filas=0 ; filas<5 ; filas++ )
    {
        traslado(18);
        printf("%c",186);
        for(int largo=0 ; largo<2 ; largo++ )
        {
            for(int grueso1=0 ; grueso1<tam; grueso1++ )
            {
                printf("%c",negro2);
            }
            for(int grueso2=0 ; grueso2<tam; grueso2++)
            {
                printf("%c",blanca2);
            }
        }
        printf("%c",186);
        printf("\n");
    }

}




///dibuja la linea de adorno para el contorno del tablero de adorno parte superior //
void barra_sup()
{
    traslado(18);

    for(int y=0 ; y<Lrecuadro1 ; y++ )
    {

        if (y==0)
        {
            printf("%c", 220);
        }

        printf("%c", 205);    // imprime la raya horizonta

        if (y==Lrecuadro1-1)
        {
            printf("%c", 220);
        }
    }
}

///dibuja la linea de adorno para el contorno del tablero de adorno parte inferior
void barra_inf()
{
    traslado(18);

    for(int y=0 ; y<Lrecuadro1 ; y++ )
    {

        if (y==0)
        {
            printf("%c", 223);
        }

        printf("%c", 205);    // imprime la raya horizonta

        if (y==Lrecuadro1-1)
        {
            printf("%c", 223);
        }
    }
}


