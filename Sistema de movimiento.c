#include"milibreria.h"


/// funcion principal el menu que se encarga de los movimientos y validarlos segun la pieza y las condiciones principales del juego

void sistema_movimiento(char tablero[TAM][TAM], char nombre[limite], int restriccion, char desafio[], int *num_partida)
{
    int conf_leyendax= 69; // parametros para posicionar el cuadro de leyenda
    int conf_leyenday= 6;  // parametros para posicionar el cuadro de leyenda
    int seguir_jugando =0;  ///condicion para seguir jugando sin saltar al menu otra vez , por comodidad
    int selecion;
    int conteo=0;
    int control=0;
    char copia[TAM][TAM];

    // inicializa un tablero de copia que sirve para tener respaldo  del tablero anterior si se quiere deshacer la jugada
    Inicializar_tablero(copia);

    do
    {


        selecion=0;
        system("cls");
        fflush(stdin);
        presentacion_nombre(nombre);
        Imprimir_tablero(tablero);   // Imprime el tablero actual

        ///PRESENTACION DEL LAS PIEZAS:
        {
            cuadro_texto(60, 5,"                             ", -6);
            gotoxy(conf_leyendax-3, conf_leyenday);
            printf("Leyenda de las piezas");
            gotoxy(conf_leyendax-5, conf_leyenday+1);
            printf("=========================");
            gotoxy(conf_leyendax, conf_leyenday+2);
            printf("Rey     =  R");
            gotoxy(conf_leyendax, conf_leyenday+3);
            printf("Reina   =  D");
            gotoxy(conf_leyendax, conf_leyenday+4);
            printf("Torre   =  T");
            gotoxy(conf_leyendax, conf_leyenday+5);
            printf("Alfil   =  A");
            gotoxy(conf_leyendax, conf_leyenday+6);
            printf("Caballo =  C");
            gotoxy(conf_leyendax, conf_leyenday+7);
            printf("Peon    =  P");
        }


        printf("\n\n\n");
        if (cuenta_piezas(tablero)==15)
        {
            /// la funcion cuentapiezas(char tablero[4][4]), comprueba si hay una sola pieza en el tablero para establece si gano
            cuadro_texto(40, 25,"Felicidades usted gano!!!\a",0 );

            getch();
            break;  // rompe el ciclo y lleva a la pantalla principal
        }

        else
        {

            if (Verifica_perdida(tablero)!=1) /// verifica constantemente si no hay posible movimientos
            {

                /** NOTA: REVISAR ESTA FUNCION, hay bugs en cuanto a falsos perdidas, cuando si se peude seguir jugando*/
                cuadro_texto(30, 25, "no hay posible movimientos.Usted ha perdido. Intente de nuevo",0);
                getch();
                break;  // rompe el ciclo y lleva nuevamente a la pantalla principal
            }

            else
            {
                if (seguir_jugando==Si) // permite seguir en la intruccion de mover pieza
                {
                    selecion= 1;
                }
                else
                {
                    selecion= menu_juego();      // funcion que imprime y hace la selecion del menu de juego
                }


                switch (selecion)   ///controla la accion que se va a tomar segun la decision del jugador
                {
                case 1 :
                    Intercambio(tablero, copia, &seguir_jugando);   /// Funcion que permite verficar el movimiento de las piezas si se cumplen las condiciones
                    gotoxy(40,30);
                    system("pause");
                    if (conteo==0)
                    {
                        conteo++;
                    }
                    break;

                /// funcion de desahacer
                case 2:
                {
                    switch (restriccion)   // swith interno que controla la restriccion de nivel de deshacer jugadas por el tipo de nivel
                    {
                    case  1:  ///nivel entrenamiento
                    {

                        if(conteo==0) // si no se ha jugado por primer vez el tablero desafio, lanza un mensaje de advertencia
                        {
                            cuadro_texto(10,24,"No se puede Desahacer las jugadas porque no se ha hecho un movimiento o ya no esta en su estado original",0);
                            getch();
                        }
                        else
                        {
                            Deshacer_jugada(tablero,nombre,copia); /// deshace la jugada N veces para el modo entrenamiento
                            conteo--;
                        }

                    }
                    break;
                    case  2:  ///nivel facil  (deshacer una sola vez)
                    {

                        switch (conteo)  /// controla las veces que se puede deshacer en nivel facil
                        {
                        case 0 :  // si no se ha jugado por primer vez el tablero desafio, lanza un mensaje de advertencia
                            cuadro_texto(20,24,"No se puede Desahacer las jugadas porque no se ha hecho un movimiento",0);

                            getch();
                            break;
                        case 1:
                            Deshacer_jugada(tablero,nombre,  copia);  // deshace la jugada solo 1 vecez para el modo entrenamiento
                            printf("\n");
                            traslado(30);
                            system("pause");
                            conteo++;
                            break;
                        default:
                            traslado(20);   // lanza el mensaje que de ya no es posible deshacer jugadas en modo facil
                            printf("Ya no se puede Desahacer las jugadas  por exceso de intentos");
                            getch();
                            break;

                        }

                    }

                    break;

                    case  3:
                        ///nivel dificil  (no deshacer ninguna vez)
                        cuadro_texto(30, 24, "En nivel Dificil no se puede desahacer jugadas",0);
                        getch();


                    }

                }



                case 3:
                    /// opcion que lleva a guardar el tablero actual en la memoria o
                    ///en el arreglo dispuesto del tablero para luego consultar mas adelante

                    if (restriccion==2 ||restriccion==3)
                    {
                        char respuesta;
                        system("cls");
                        presentacion_nombre(nombre);
                        printf("\n");
                        Imprimir_tablero(tablero);
                        cuadro_texto(40, 25, "Desea Guardar la partida? [S/N]",0); // pregunta al jugador si desea guardar la partida
                        printf("\n");
                        fflush(stdin);
                        traslado(25);
                        scanf("%c", &respuesta);
                        if (respuesta=='S' ||respuesta =='s')
                        {
                            /// Esta funcion de encarga de comprobar si existe el archivo "partidasguardadas.txt"
                            int comprobacion= Comprobar_partidas_guardadas();

                            if (comprobacion==1)
                            {
                                CrearArchivo_partidasguardadas();
                            }
                            int cont=1;
                            *(num_partida)+=cont;
                            Guardar_partidas(nombre, desafio, restriccion, num_partida );
                            cuadro_texto(40, 20, "Se ha guardado la partida",0);
                            getch();
                        }


                    }

                    break;

                }  // fin del swith ecterno que controlo si jugar o desahcer

            }  //else de condicion de perdida de juego

        }  // fin del else de verificacion de coondicion de ganaar partida o no

        ///fin de ciclo

    }
    while (selecion!=3);

}

///funcion que imprime y hace la selecion del menu de juego y devuelve la opcion escogida por el usuario //
int menu_juego()
{
    int opcion=0;


    cuadro_texto(18,18, "(1)-->    Jugar       ",1);
    cuadro_texto(45,18, "(2)-->   Deshacer     ",1);
    cuadro_texto(73,18, "(3)-->   Terminar     ",1);

    /* { //muestra el menu de seleccion de nivel
    for(int x=0 ;x<3 ; x++){
     if (x==0){
        traslado(8);
     }

    if (x==0){ printf("\t");}

    for(int y=0 ;y<22 ;y++ ){
         if (y==0){ ; printf("%c",201);}
         printf("%c", 205);
    if (y==21){ printf("%c " ,187);}

            }
    }
    printf("\n");



    traslado(15);
    printf(" %c",186);printf("(1)-->    Jugar       ");printf("%c ",186);
    printf("%c",186); printf("(2)-->   Deshacer     ");printf("%c ",186);
    ;printf("%c",186); printf("(3)-->   Terminar     ");printf("%c ",186);
    printf("\n");



    for(int x=0 ;x<3 ; x++){
    if (x==0){ traslado(8); printf("\t");}

    for(int y=0 ;y<22 ;y++ ){
         if (y==0){ ; printf("%c",186);}
         printf(" ");
    if (y==21){ printf("%c " ,186);}

            }
    }

    printf("\n");

    for(int x=0 ;x<3 ; x++){
    if (x==0){traslado(8); printf("\t");}

    for(int y=0 ;y<22 ;y++ ){
         if (y==0){ printf("%c",200);}
         printf("%c", 205);
    if (y==21){ printf("%c " ,188);}

            }


    }
     } */




    gotoxy(40, 22);
    printf("Escoga la Opcion y presiona ENTER: ");
    scanf("%i", &opcion);
    if (opcion<1 || opcion>3)
    {
        printf("\t\t\t\tEl numero no es valido.Intente de nuevo\a\n\t\t\t\t");
        gotoxy(45, 30);
        system("pause");
    }
    return opcion;
}


// Funcion que permite verficar el movimiento de las piezas si se cumplen las condiciones
void Intercambio(char tablero[TAM][TAM], char copia[TAM][TAM], int *repetir)
{
    int control=0;
    int fila_inicial=0, columna_inicial=0;
    int fila_final=0, columna_final=0;
    char cord_inicial[Tcoord];   // declara un arreglo donde contendra la informacion de la casilla origen
    char cord_final[Tcoord];  // declara un arreglo donde contendra la informacion de la casilla destino

    /** la funcion coordenadas se encarga de pedir la posicion de la casilla donde qiere mover la pieza y a
    donde moverla y verifica de acuerda a la pieza, el tipo de movimiento si es posible */

    control = coordenadas(tablero,cord_inicial,cord_final, &fila_inicial,&columna_inicial,&fila_final,&columna_final, repetir);

    if (control ==1)   // si control es 1,procede a mover la pieza una vez verificado los requisitos
    {

        mover_pieza(tablero,copia,  fila_inicial,columna_inicial,fila_final,columna_final);  // procesde a hacer el cambio en el tablero actual por el movimiento escogido
        *repetir=Si;
    }

}


/// pide la casilla inicial a escoger y la casila destino a mover la pieza//
int coordenadas(char tablero[TAM][TAM],char cord_inicial[Tcoord], char cord_final[Tcoord], int *fila_inicial, int *columna_inicial, int *fila_final,int *columna_final, int *repetir)
{
    int verificacion=0;
    int f1=0, c1=0, f2=0, c2=0;
    fflush(stdin);
    gotoxy(20,24 );
    printf("Introduzca las coordenadas y presione Enter: o Bien pulse '0' para anular accion\n");
    gotoxy(36,25 );printf("Ejemplo: posicion inicial: 'a1'y posicion final: 'b2'");
    gotoxy(40,26 );
    printf("Posicion Inicial: ");   // pide al usuario la posicion de la casilla donde esta la pieza a mover

    gets(cord_inicial);
//////
    if (cord_inicial[0]=='0')
    {
        *repetir= No;
        verificacion=0;

    }
    else
    {
        Verificacion_limite_del_tablero(cord_inicial, &verificacion);  /// verifica que la coordenada inicial escogida este dentro del tablero
        conversion_posicion(cord_inicial, fila_inicial, columna_inicial);    /// envia la posicion origen en lo transforma en los indices de la matriz coorrespondiente
        f1 = *fila_inicial;      //  guarda el subindice de la fila inicial de la casilla donde esta la peza originalmente
        c1 = *columna_inicial;   //  guarda el subindice de la columna inicial de la casilla donde esta la peza originalmente
        verificacion_casillavacia(tablero, f1, c1, &verificacion);  /// Se verifica que en esta casilla escogida no este vacia y contenga una pieza
        if (verificacion==1)
        {
            gotoxy(40,27 );
            printf("Posicion final:   ");   /// pide al usuario la posicion de la casilla a donde quiero mover finalmente la peiza escogida
            gets(cord_final);

            if (cord_final[0]=='0')
            {
                *repetir= No;
                verificacion=0;

            }
            else
            {
                Verificacion_limite_del_tablero(cord_final, &verificacion);  /// verifica que la coordenada final escogida este dentro del tablero
                conversion_posicion(cord_final, fila_final,columna_final);   /// envia la posicion destino en lo transforma en los indices de la matriz coorrespondiente
                f2 = *fila_final;    //  guarda el subindice de la fila final de la casilla donde se quiere mover la pieza como destino
                c2 = *columna_final;  //  guarda el subindice de la columna final de la casilla donde se quiere mover la pieza como destino
                Verificacion_movpieza(tablero,f1, c1, f2, c2, &verificacion );    /// verifica el tipo de pieza seleccionada para poder redirigir a la funcion especifica que valide el movimiento de la pieza

                if (verificacion==1)
                {
                    verificacion_casillavacia(tablero, f2, c2, &verificacion);   /// verificacion si la casilla selecionada esta vacia
                }

            }

        }

    }

////

    return verificacion;  /// devuelve la confimacion, donde si es 1 es posible mover y 0 si no es posible
}


/// Verificacion si la casilla seleccionada esta dentro de las casillas del tablero */
void Verificacion_limite_del_tablero(char coordenadas[Tcoord], int *x)
{

    /** verifica si la contenida de la cadena esta completa y concuerda con el rango aceptado de valores
    // de la columna este entre (a y d) y la fila este entre el rango de (1 y 4)*/

    if (coordenadas[0]!='a' &&coordenadas[0]!='b' &&coordenadas[0]!='c' &&coordenadas[0]!='d'&&coordenadas[1]!='1' &&coordenadas[1]!='2' &&coordenadas[1]!='3' &&coordenadas[1]!='4')
    {
        gotoxy(35, 28);
        printf("La casilla selecionada esta fuera del tablero. Intenta de nuevo\n");



    }
    else
    {
        *x= 1;
    }


}



///permite el intercambio de la pieza escogida a la casilla destino y reemplaza la casilla anteior por un vacio ' '  */
void mover_pieza(char tablero[TAM][TAM], char copia[TAM][TAM],  int fila_inicial, int columna_inicial, int fila_final, int columna_final)
{

    copiar_tablero(tablero, copia);
    tablero[fila_final][columna_final] = tablero[fila_inicial][columna_inicial];
    tablero[fila_inicial][columna_inicial]= ' ';


}

/** permite convertir la posicion escrita del arreglo de caracteres pedido por el usuario
 caracteres en los numeros que indican los indices y la posicion correcta en la matriz del tablero */
void conversion_posicion(char cord_posicion[Tcoord],  int *pos_fila, int *pos_columna)
{

    switch (cord_posicion[1])
    {
    case '1':
        *pos_fila= 3;
        break;
    case '2':
        *pos_fila= 2;
        break;
    case '3':
        *pos_fila= 1;
        break;
    case '4':
        *pos_fila= 0;
        break;
    }

    switch (cord_posicion[0])
    {
    case 'a':
        *pos_columna= 0;
        break;
    case 'b':
        *pos_columna= 1;
        break;
    case 'c':
        *pos_columna= 2;
        break;
    case 'd':
        *pos_columna= 3;
        break;
    }

}

/// verifica el tipo de pieza seleccionada para poder redirigir a la funcion especifica que valide el tipo de movimiento
void Verificacion_movpieza(char tablero[TAM][TAM], int fila_inicial, int columna_inicial, int fila_final, int columna_final, int *confirmacion)
{

    switch (tablero[fila_inicial][columna_inicial])
    {
    case 'P': ///PEON
        // recibe el dato de pieza "peon" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion=  mov_peon(tablero, fila_inicial, columna_inicial,fila_final,columna_final, 1);
        break;
    case 'C': ///caballo
        // recibe el dato de pieza "peon" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion= mov_caballo(tablero, fila_inicial,columna_inicial, fila_final,columna_final, 1);
        break;
    case 'A': ///Alfil
        // recibe el dato de pieza "alfil" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion= mov_alfil(tablero, fila_inicial,columna_inicial, fila_final,columna_final, 1);
        break;
    case 'T': ///TORRE
        // recibe el dato de pieza "torre" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion= mov_torre( tablero, fila_inicial,columna_inicial,fila_final,columna_final, 1);
        break;
    case 'D': ///DAMA O REINA
        // recibe el dato de pieza "dama" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion= mov_reina(tablero, fila_inicial,columna_inicial,fila_final,columna_final,1);
        break;
    case 'R': ///Rey
        // recibe el dato de pieza "rey" y compara el mov indicado con los validos por el tipo de pieza
        *confirmacion= mov_rey(tablero, fila_inicial,columna_inicial,fila_final,columna_final, 1);
        break;
    }


}

/// verificacion si la casilla selecionada esta vacia para comprobar el requisito de captura obligatoria de una pieza
void verificacion_casillavacia(char tablero[TAM][TAM], int fila, int columna, int *confirmacion)
{

    if (tablero[fila][columna] != ' ')
    {
        *confirmacion=  1;
    }
    else
    {
        *confirmacion = 0;
        printf("\t\t\aLa casilla seleccionada debe contener una pieza para mover o capturar una pieza\n");
    }



}


///Presenta el menu de pantalla de  Deshacer la jugada anterior volviendo al posiciones del tablero anterior  //
void Deshacer_jugada(char tablero[TAM][TAM], char nombre[limite],char copia[TAM][TAM])
{
    char opcion;
    int repite=0;
    do
    {
        fflush(stdin);
        system("cls");
        presentacion_nombre(nombre);   // presenta el nombre del jugador
        cuadro_texto(45, 6, "Deshacer Jugada\n\n",0);
        Imprimir_tablero(tablero);              //imprime el tablero actual
        printf("\n\n\n");
        traslado(25);
        printf("Estas seguro de deshacer la jugada anterior?  [S/N] : ");
        scanf("%c", &opcion);               // pide confirmacion del usuario

        switch (opcion)
        {
        case 's' :
        case 'S':
            copiar_tablero(copia, tablero);  /// realiza la accion de reemplazar todo el contenido del tablero actual por la copia
            repite=1;
            break;
        case 'n':
        case 'N':
            traslado(25);
            printf("Regresando al menu anterior\n");
            repite=1;
            getch();
            break;

        default:
            traslado(25);
            printf("No ha digitado la tecla correcta. Intente de nuevo");
            getch();
        }

    }
    while (repite==0);
}



/// copia el contenido de un arreglo a otro de un tablero a otro temporal para luego usarlo en la funcion deshacer
void copiar_tablero(char tablero[TAM][TAM], char copia[TAM][TAM])
{
    int filas=TAM, columnas=TAM;
    for(int x=0 ; x<filas ; x++ )
    {
        for(int y=0 ; y<columnas ; y++ )
        {
            copia[x][y] = tablero[x][y];  //// copia el contenido
        }
    }
}

/// esta funcion cuenta las casillas vacias en en tablero  en el momento actual para saber si ganaste la partida
int cuenta_piezas(char tablero[TAM][TAM])
{
    int contador=0;
    int filas=TAM, columnas=TAM;
    for(int x=0 ; x<filas ; x++ )
    {
        for(int y=0 ; y<columnas ; y++ )
        {
            if (tablero[x][y]==' ')  // va iterando en cada casilla y comprobando el contenido de esta si hay un casilla vacia
            {
                contador++;  // agrega +1 al contador
            }

        }
    }
    return contador;  //devuelve el valor de numero de veces de casillas contadas vacias
}





