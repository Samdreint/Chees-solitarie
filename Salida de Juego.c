#include"milibreria.h"

/// funcion que lleva a la culminacion del juego
void Salida(char tablero[TAM][TAM])
{
    system("cls");

    printf("\n\t\t\t\t<=========================================>\n");


    printf("\t\t\t\t\t\aGRACIAS POR JUGAR, VUELVA PRONTO!!!\n");
    printf("\t\t\t\t<=========================================>");


    //cuadro(20, 5, 60, 25);



    gotoxy(36,12);

    system("pause");

}

void cuadro(int x1, int y1, int x2, int y2)
{
    int i;
    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("%c", 205) ; //linea horizontal superior
        gotoxy(i,y2);
        printf("%c", 205) ; //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("%c", 186) ; //linea vertical izquierda
        gotoxy(x2,i);
        printf("%c", 186) ; //linea vertical derecha
    }

    gotoxy(x1,y1);
    printf("%c", 201); //Esquinas del cuadro
    gotoxy(x1,y2);
    printf("%c",200 );
    gotoxy(x2,y1);
    printf("%c", 187);
    gotoxy(x2,y2);
    printf("%c", 188);
}
