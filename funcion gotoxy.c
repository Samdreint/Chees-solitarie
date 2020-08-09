#include"milibreria.h"

/*
    //Funcion:

    Parametros de entrada:
 1-->
 2-->
 3-->
 4-->

    Parametros de Salida:


    Explicacion:


    Precondiciones y Poscondiciones:
    -->Precondiciones:
    -->Post condiciones:


 */

/** funcion que permite posicionar el curso de texto en la consola en un
posicion determinado de la pantalla (util en la impresion de texto)*/

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

void leer_lineas(int num, FILE *fp)
{

    int conta=num-1;
    fseek(fp, 0, SEEK_SET);
prueba:
    if (conta>0)
    {
        while (fgetc (fp) != '\n');
        conta--;
        goto prueba;
    }
}


/// funcion rapida y grafica que cree yo mismo para insertar un texto en un cuadro de texto en la pantalla
void cuadro_texto( int coordx, int coordy, char texto[], int espacio)
{
    int largo =  strlen(texto)+1;
    gotoxy(coordx,coordy);
    for(int x=0 ; x<largo; x++ )
    {
        if (x==0)
        {
            printf("%c", 201);
        }

        printf("%c", 205);

        if (x==largo-1)
        {
            printf("%c", 187);
        }

    }

    for (int x=0; x<=-espacio+1; x++ )
    {
        gotoxy(coordx, coordy+x+1);
        printf("%c", 186);
        gotoxy(coordx+largo+1, coordy+x+1);
        printf("%c", 186);

    }

    gotoxy(coordx,coordy+3-espacio);
    for(int x=0 ; x<largo; x++ )
    {
        if (x==0)
        {
            printf("%c", 200);
        }

        printf("%c", 205);

        if (x==largo-1)
        {
            printf("%c", 188);
        }
    }


    gotoxy(coordx+1, coordy+1);
    puts(texto);   /// Imprime el texto que se quiere imprimir dentro del cuadro de texto grafico
    printf("\n");

}
