#include"milibreria.h"

/** f1 = fila inicial y c1= columna inicial
    f2= fila final   y c2 columna finalD
 */

/// valida el movimiento del peon
int mov_peon(char tablero[TAM][TAM], int f1, int c1,int f2,int c2, int setup)
{

    /*verificacion si la casilla destino esta en las diagonales
    superiores izquierda o derecha adyacente a la casilla origen del peon*/
    if (  (((f1-1==f2 && c1-1==c2)|| (f1-1==f2 && c1+1==c2) )&&(c1!=c2 &&f1!=f2)) &&(tablero[f2][c2]!=' ')  )
    {
        return 1;
    }

    else
    {
        if (setup==1)
        {
            printf("\t\t\tNo es valido ese movimiento para el peon.\n");
            getch();
        };

        return 0;
    }


}


/// valida el movimiento del caballo
int mov_caballo(char tablero[TAM][TAM],int f1, int c1, int f2, int c2, int setup)
{
    //verifica mov L grande
    if ( (((f1-2==f2 || f1+2==f2)&&( c1-1==c2 ||c1+1==c2 )) &&(c1!=c2 &&f1!=f2)) &&(tablero[f2][c2]!=' ')  )
    {
        return 1;
    }

    else
    {
        //verifica mov L pequeña
        if( ((( f1-1==f2 ||f1+1==f2)&&(c1-2==c2 ||c1+2==c2)) &&(c1!=c2 &&f1!=f2 )) &&(tablero[f2][c2]!=' ') )
        {

            return 1;
        }

        else
        {
            if (setup==1)
            {
                printf("\t\t\t\tNo es valido ese movimiento para el caballo\n");
                getch();
            };

            return 0;
        }
    }

}


/// valida el movimiento del alfil
int mov_alfil(char tablero[TAM][TAM], int f1, int c1, int f2, int c2, int Setup)
{


    /*   f1 = fila inicial y c1= columna inicial
    f2= fila final   y c2 columna finalD*/
    int dy= abs(f2-f1);  // calcula la distancia entre las dos filas escogidas
    int dx=abs(c2-c1); // calcula la distancia entre las columnas escogidas en alor absoluto




    ///condicion de diagonalidad : n1 ==n2
    if (((dx == dy) && ( c1!=c2 && f1!=f2) )&&(tablero[f2][c2]!=' '))
    {
        ///verifca las diagonales superiores derecha e izquerda
        if ( ( f1-dy==f2) &&(   ( c1+dx==c2)  || (c1-dx==c2)  )  )
        {
            return 1;
        }

        else
        {
            ///verifca las diagonales inferiores derecha e izquerda
            if (( f1+dy==f2) &&(   ( c1+dx==c2)  || (c1-dx==c2)  ))
            {
                return 1;
            }
            else
            {
                if (Setup==1)
                {
                    printf("\t\t\tNo es valido ese movimiento para el alfil.\n");
                    getch();
                };

                return 0;

            }
        }
    }
    else
    {
        if (Setup==1)
        {
            printf("\t\t\tNo es valido ese movimiento para el alfil.\n");
            getch();
        };
        return 0;
    }


//////////////

}



/// valida el movimiento de la torre

int mov_torre(char tablero[TAM][TAM], int f1, int c1, int f2, int c2, int setup)
{
    int validacion=1;
    int n1= f2-f1;
    int n2= c2-c1;

    if (tablero[f2][c2]!=' ')
    {
        /// Caso que se encuentre en la misma fila
        if (f1==f2 &&c1!=c2)
        {
            return 1;
        }
        else
        {
            /// Caso que se encuentre en la misma columna
            if (c1==c2 && f1!=f2)
            {
                return 1;
            }
            else
            {
                if (setup==1)
                {
                    printf("\t\t\tNo es valido ese movimiento para el Torre.\n");
                    getch();
                };

                return 0;
            }
        }
    }
    else
    {
        if (setup==1)
        {
            printf("\t\t\tNo es valido ese movimiento para el Torre o esta vacia la casilla seleccionada.\n");
            getch();
        };

        return 0;
    }

}



/// valida el movimiento del Reina
int mov_reina(char tablero[TAM][TAM], int f1, int c1, int f2, int c2, int setup)
{
    /* f1 = fila inicial y c1= columna inicial
        f2= fila final   y c2 columna finalD */
    int dy= abs(f2-f1);  // calcula la distancia entre las dos filas escogidas
    int dx=abs(c2-c1); // calcula la distancia entre las columnas escogidas en alor absoluto

    /* // verificacion si la casilla destino esta en las diagonales superiores e e inferior de la parte izquierda o derecha
     o sino comprueba que la casilla destino este en la misma columna o fila que la casilla origen.
     en resumen verifica los condiciones de movimientos de la torre y el alfil  al mismo tiempo. */




    /// Verifica que haya una pieza alli
    if (tablero[f2][c2]!=' ' )
    {
        /// Seccion de verificacion Horizontal y vertical
        // Caso de mov horizontal
        if ((f1==f2) && (c1!=c2))
        {
            return 1;
        }
        else
        {
            // Caso mov vertical
            if ((c1 ==c2) && (f1!= f2))
            {
                return 1;
            }
            else
            {
                /// Seccion de movimiento diagonales

                //condicion de diagonalidad : n1 ==n2
                gotoxy(0, 0);
                printf("dx: %d y dy: %d\n", dx, dy);
                getch();


                if ( (dx == dy) )
                {
                    ///verifca las diagonales superiores derecha e izquerda
                    if ( ( f1-dy==f2) &&(   ( c1+dx==c2)  || (c1-dx==c2)  )  )
                    {
                        return 1;
                    }

                    else
                    {
                        ///verifca las diagonales inferiores derecha e izquerda
                        if (( f1+dy==f2) &&(   ( c1+dx==c2)  || (c1-dx==c2)  ))
                        {
                            return 1;
                        }
                        else
                        {
                            if (setup==1)
                            {
                                printf("\t\t\tNo es valido ese movimiento para el reina.\n");
                                getch();
                            };

                            return 0;

                        }
                    }
                }
            }
        }
    }
    else
    {
        if (setup==1)
        {
            printf("\t\t\tNo es valido ese movimiento ya que la casilla selecionada esta vacia.\n");
            getch();
        };

        return 0;
    }





    ///
}

/// valida el movimiento del rey
int mov_rey(char tablero[TAM][TAM], int f1, int c1, int f2, int c2, int setup)
{



    if ( (tablero[f2][c2]!=' '))
    {
        if ((f1-1==f2)&&(c1==c2)) // caso A
        {
            return 1;
        }
        else
        {
            if ((f1-1==f2)&&(c1+1==c2)) //Caso B
            {
                return 1;
            }
            else
            {
                if ((f1==f2)&&(c1+1==c2))//caso C
                {
                    return 1;
                }
                else
                {
                    if ((f1+1==f2)&&(c1+1==c2) )//CASO D
                    {
                        return 1;
                    }
                    else
                    {
                        if ((f1+1==f2)&&(c1==c2)) // Caso E
                        {
                            return 1;
                        }
                        else
                        {
                            if ((f1+1==f2)&&(c1-1==c2)) // Caso F
                            {
                                return 1;
                            }
                            else
                            {
                                if ((f1==f2)&&(c1-1==c2))// Caso G
                                {
                                    return 1;
                                }
                                else
                                {
                                    if ((f1-1==f2)&&(c1-1==c2)) //Caso H
                                    {
                                        return 1;
                                    }
                                    else
                                    {

                                        if (setup==1)
                                        {
                                            printf("\tNo es valido el movimiento para el rey\n");
                                            getch();
                                        };

                                        return 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
    else
    {
        if (setup==1)
        {
            printf("\tla casilla seleccionada esta vacia y/0 no es valido el movimiento\n");
            getch();
        };

        return 0;
    }






}



///Revisa el estado del tablero para comprobar si hay mov posibles y si no, se pierde la partida
int Verifica_perdida(char tablero[TAM][TAM])
{

    int contador=0;
    int confirmacion=0;
    for(int fila=0 ; fila<TAM ; fila++ )
    {

        for(int columna=0 ; columna<TAM ; columna++ )
        {
            Verificacion_posiblemovimientos(tablero, fila,columna, &confirmacion);

            /*if ( confirmacion!=0)
            {
                return 1;
            }*/
        }
    }
    ///nota
    // gotoxy(45, 42);
    //  system("pause");

    if (confirmacion==1 || confirmacion!=0)
    {
        return 1;
    }
    else
    {
        ///marca de tiempo
        gotoxy(45,30);
        printf("Ha salido un %d de perder", confirmacion);
        gotoxy(45,31);
        system("pause");

//
        return 0;
    }


}

/**
////////////////////////////
///**Parte dle codigo que se verificar  si hay movimiento posible al momento de jugar */
///////////////////////////*/
///NOTA: Hay bugs en cuanto a perder cuando realmente si hay posibles mov. pendiente arreglar
/**funcion que identifica el tipo de movimiento que hay una casilla seleccionada
y posteriormente analizar los posibles movimientso de acuerda al tipo de pieza */

void Verificacion_posiblemovimientos(char tablero[TAM][TAM], int fila_inicial,int columna_inicial,  int *confirmacion1)
{
    int aux=0;
    switch (tablero[fila_inicial][columna_inicial])
    {
    case 'P':

        *confirmacion1+= posible_mov_peon(tablero, fila_inicial, columna_inicial);
        //marca de tiempo
        // gotoxy(0,35);
        // printf("\a%d es numero de mov disponibles para el peon\n",posible_mov_peon( tablero, fila_inicial,columna_inicial) );
        break;
    /// verifica los posible mov del "Peon"

    case 'C':

        *confirmacion1+= posible_mov_caballo( tablero, fila_inicial,columna_inicial);
        //marca de tiempo
        // gotoxy(0, 36);
        // printf("\a%d es numero de mov disponibles para el caballo\n",posible_mov_caballo( tablero, fila_inicial,columna_inicial) );

        break; /// verifica los posible mov del "caballo"

    case 'A':
        *confirmacion1+= posible_mov_alfil( tablero, fila_inicial,columna_inicial);
        //marca de tiempo
        // gotoxy(0, 37);
        //printf("\a%d es numero de mov disponibles para el alfil\n",posible_mov_alfil( tablero, fila_inicial,columna_inicial) );;
        break; /// verifica los posible mov del "ALfil"

    case 'T':
    {
        *confirmacion1+= posible_mov_torre(  tablero, fila_inicial,columna_inicial);
        //marca de tiempo
        // gotoxy(0, 38);
        // printf("\a%d es numero de mov disponibles para el torre\n",posible_mov_torre( tablero, fila_inicial,columna_inicial));
        break; /// verifica los posible mov del "Torre"
    }

    case 'D':
        *confirmacion1+= posible_mov_reina( tablero, fila_inicial,columna_inicial);
        //marca de tiempo
        //gotoxy(0, 39);
        // printf("\a\%d es numero de mov disponibles para el reina\n",posible_mov_reina( tablero, fila_inicial,columna_inicial) );

        break; /// verifica los posible mov del "reina"

    case 'R':
        *confirmacion1+= posible_mov_rey( tablero, fila_inicial,columna_inicial);
        //marca de tiempo
        // gotoxy(0, 40);
        // printf("\a%d es numero de mov disponibles para el rey\n",posible_mov_rey( tablero, fila_inicial,columna_inicial), *confirmacion1 );
        break;
    /// verifica los posible mov del "Rey"

    case ' ':
        break;




        /** Si da confirmacion con valor =0, entonces significa que o hya posible movs y se pierde y se manda
        ese dato a una funcion que indica que se perdio.
        De lo contrario valor 1 indica que sigue el juego y hay hay movimientos disponibles*/

    }
}


///verifica si hay posible movimientos si hay un peon en el tablero
/** Revisa desde la posicion que se encuentra e indica si hay piezas posibles a capturar segun si tipo de movimiento*/
int posible_mov_peon(char tablero[TAM][TAM], int f1, int c1)
{
    int confirmacion =0;
    for(int f2=0 ; f2<TAM ; f2++)
    {
        for(int c2=0; c2<TAM; c2++ )
        {

            confirmacion+= mov_peon(tablero, f1, c1, f2, c2, 0);
        }
    }
    return confirmacion;

}


/// verifica si hay posible movimientos si hay un caballo en el tablero  //
/** Revisa desde la posicion que se encuentra e indica si hay
piezas posibles a capturar segun si tipo de movimiento*/
int posible_mov_caballo(char tablero[TAM][TAM], int f1, int c1)
{

    int confirmacion =0;
    for(int f2=0 ; f2<TAM ; f2++)
    {
        for(int c2=0; c2<TAM; c2++ )
        {

            confirmacion+= mov_caballo(tablero, f1, c1, f2, c2, 0);
        }
    }
    return confirmacion;
}


///verifica si hay posible movimientos si hay un alfil en el tablero  //
/** Revisa desde la posicion que se encuentra e indica si hay
 piezas posibles a capturar segun si tipo de movimiento*/
int posible_mov_alfil(char tablero[TAM][TAM], int f1, int c1)
{
    int confirmacion =0;
    for(int f2=0 ; f2<TAM ; f2++ )
    {
        for(int c2=0 ; c2<TAM ; c2++ )
        {
            confirmacion+= mov_alfil(tablero, f1, c1, f2, c2, 0);
        }
    }
    return confirmacion;
}




/// verifica si hay posible movimientos si hay un torre en el tablero  //
/** Revisa desde la posicion que se encuentra e indica si hay piezas posibles a capturar segun si tipo de movimiento*/
int posible_mov_torre(char tablero[TAM][TAM],  int f1, int c1)
{
    int confirmacion =0;
    for(int f2=0 ; f2<TAM ; f2++ )
    {
        for(int c2=0 ; c2<TAM ; c2++ )
        {

            int registro=0;
            confirmacion +=mov_torre(tablero,f1,c1, f2, c2, 0);
            registro= mov_torre(tablero, f1, c1, f2, c2, 0);

            /// nota de tiempo
            //  gotoxy(1, 45);
            // printf("confirmacion en este momennto en el torre es: %d y posicion es (f1,c1)=(%d, %d) y (f2, c2)=(%d, %d) ",registro, f1, c1, f2, c2);
            //  system("pause");
        }
    }
    return confirmacion;
}



/// verifica si hay posible movimientos si hay un reina en el tablero  //
/** Revisa desde la posicion que se encuentra e indica si hay piezas
posibles a capturar segun si tipo de movimiento*/
int posible_mov_reina(char tablero[TAM][TAM], int f1, int c1)
{
    int confirmacion =0;
    for(int f2=0 ; f2<TAM ; f2++ )
    {
        for(int c2=0 ; c2<TAM ; c2++ )
        {
            confirmacion+= mov_reina(tablero,f1, c1, f2, c2, 0 );
        }
    }
    return confirmacion;
}


/// verifica si hay posible movimientos si hay un rey en el tablero  //
/** Revisa desde la posicion que se encuentra e indica si hay piezas
posibles a capturar segun si tipo de movimiento*/
int posible_mov_rey(char tablero[TAM][TAM], int f1, int c1)
{
    int confirmacion =0;

    for(int f2=0 ; f2<TAM ; f2++ )
    {
        for(int c2=0 ; c2<TAM ; c2++ )
        {
            int registro=0;
            confirmacion+= mov_rey(tablero, f1, c1, f2, c2, 0);
            registro= mov_rey(tablero, f1, c1, f2, c2, 0);

            /// nota de tiempo
            // gotoxy(1, 45);
            //  printf("confirmacion en este momennto en el rey es: %d y posicion es (f1,c1)=(%d, %d) y (f2, c2)=(%d, %d) ",registro, f1, c1, f2, c2);
            //  system("pause");


        }
    }
    return confirmacion ;
}



