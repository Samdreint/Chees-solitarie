#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"


///Se encarga de dirigir la seleccion del desafio segun la dificultad elegido por el usuario////

void Cargar_tablero(char tablero[TAM][TAM], char nombre[limite], int *restriccion, char desafio[limite])
{
    /** Nota: Para ver los las partidas precargdas, dirigirse al "Modulo de registros.c" */
    int Lentren=15;   // indica el tamanio o largo de la cadena de los desafios de nivel entrenamiento
    int Lfacil=23;    // indica el tamanio o largo de la cadena de los desafios de nivel facil
    int Ldificil=27; // indica el tamanio o largo de la cadena de los desafios de nivel dificil
    int opcion=0;

/// funcion que devuelve el numero asignado a nivel escogido por el usuario para jugar y lo asigna a la variable opcion
    opcion = elegir_nivel(nombre);
    switch (opcion)  // controla la intruccion de acuerdo al numero que representa al nivel seleccionado en la funcion elegir_nivel
    {
    case 1:     /** funcion que tiene almacenado todos los desafios precargadas a este nivel entrenamiento
                y lo cargar en el tablero, escogiendo un desafio aleatorio de este nivel */

        nivel_entrenamiento(tablero,Lentren, desafio);
        *restriccion=1;
        break;
    case 2:    /** funcion que tiene almacenado todos los desafios precargadas a este nivel Facil
                y lo cargar en el tablero, escogiendo un desafio aleatorio de este nivel */

        nivel_facil(tablero, Lfacil, desafio);
        *restriccion=2;
        break;
    case 3:         /** funcion que tiene almacenado todos los desafios precargadas a este nivel Dificil
                    y lo cargar en el tablero, escogiendo un desafio aleatorio de este nivel */
        nivel_dificil(tablero,Ldificil, desafio);
        *restriccion=3;
        break;
    }
}


/// Inicializa el tablero poniendo cada casilla un espacio vacio ' '  al comienzo
void Inicializar_tablero(char tablero[TAM][TAM])
{
    int filas=TAM, columnas=TAM;
    for(int x=0 ; x<filas ; x++ )   // controla el indice de las filas
    {
        for(int y=0 ; y<columnas ; y++ )  // controla el indice de las columnas
        {
            tablero[x][y]= ' ';  //// rellena con espacios en la casilla del tablero
        }
    }

}


/// funcion que devuelve el numero asignado a nivel escogido por el usuario para jugar //
int elegir_nivel(char nombre[limite])
{
    int opcion;
    do
    {
        opcion=0;
        system("cls");
        fflush(stdin);
        presentacion_nombre(nombre);  // presenta el nombre en pantalla

        // imprime el menu
        cuadro_texto(42, 8, "(1)--> Entrenamiento  ",0);
        cuadro_texto(46, 12, "(2)-->Facil ",0);
        cuadro_texto(45, 16, "(3)--> Dificil",0);
        printf("\n");



        fflush(stdin);
        printf("\n\t\t\t\tEscoga la Opcion y presiona ENTER: ");
        scanf("%i", &opcion);  // pide el valor de opcion para la seleccion del nivel

        if (opcion<1 || opcion>3)
        {
            printf("\t\t\t\tEl numero no es valido.Intente de nuevo\a\n\t\t\t\t");
            system("pause");
        }


    }
    while (opcion<1 || opcion>3);

    return opcion;   // retorna el numero correspondiente al nivel seleccionado

}


///funcion que tiene almacenado todos los desafios precargadas del nivel entrenamiento
/// y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel */
void nivel_entrenamiento(char tablero[TAM][TAM], int largo_cadena, char desafio[limite])
{
    fflush(stdin);
    int opcion;
    int cantidad_piezas=4;

    opcion = num_aleatorio(7,12);
    // los desafios del nivel entrenamiento estan entre las lineas 1 y 6 del archivo de texto partdasnuevas.txt
    /** se encarga de dar un numero aleatorio entre 1 y 6 que indica
    la linea de texto donde se encuentra el desafio del nivel seleccionado */

//scanf("%i", &opcion); // ---->>> esta intruccion era para comprobar manualmente cada desafio sin el archivo////////

    /** Nota Actualizada: Para ver los las partidas precargdas, dirigirse al "Modulo de registros.c"
    Ya que lo de abajo fue un modelo prototipo rapido sin utilizar archivos de textos. */

    Cargar_desafio(opcion,tablero,cantidad_piezas,largo_cadena, desafio);
    /**nota 1:ejemplo de cargar de un desafio desde el progrmama
    // nota2: esta fue la solucion temporal, luego se paso a escirbir la configuacion en un archivo de texto
    tablero[varible1][varible]= cad[0];    //// reemlazar por tablero[0][0]= 'T' (torre)
    // cargar_desafio(int linea, char tablero[tam[tam], int nivel, int largo_cadena);

    */  /*

    tablero[0][1]= 'A';
    tablero[1][2]= 'R';
    tablero[2][3]= 'A';
    tablero[3][0]= 'T';      */


    // cargar_desafio(int linea, char tablero[tam[tam], int nivel, int largo_cadena);
    //   Cargar_desafio(opcion,tablero,4,largo_cadena);
    /* tablero[0][2]= 'C';
     tablero[1][0]= 'A';
     tablero[2][1]=  'p';
     tablero[3][2]= 'T';      */

    // Cargar_desafio(opcion,tablero,4,largo_cadena);
    /*
    tablero[0][0]= 'R';
    tablero[0][2]= 'T';
    tablero[2][1]=  'C';
    tablero[3][0]= 'p';     */


    //   Cargar_desafio(opcion,tablero,4,largo_cadena);
    /*
    tablero[0][1]= 'C';
    tablero[1][3]= 'R';
    tablero[2][2]= 'C';
    tablero[3][0]= 'p';       */

    // Cargar_desafio(opcion,tablero,4,largo_cadena);
    /* tablero[0][1]='A';
     tablero[1][1]= 'R';
     tablero[2][0]= 'p';
     tablero[2][2]= 'K';       */

    //  Cargar_desafio(opcion,tablero,4,largo_cadena);
    /*tablero[1][0]='T';
    tablero[1][3]= 'C';
    tablero[2][1]= 'A';
    tablero[2][2]= 'C';
    tablero[3][0]= 'T';        */

}


//funcion que tiene almacenado todos los desafios precargadas del nivel facil
// y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel */
void nivel_facil(char tablero[TAM][TAM], int largo_cadena, char desafio[limite])
{
    int opcion=0;
    opcion = num_aleatorio(17,22 );  // los desafios del nivel facl  estan entre las lineas 7 y 12 dell archivo de texto partdasnuevas.txt
    int cantidad_piezas=4;
//scanf("%i", &opcion);  // ---->>> esta intruccion era para comprobar manualmente cada desafio////////
    Cargar_desafio(opcion,tablero,cantidad_piezas,largo_cadena, desafio);
    /*
    //Cargar_desafio(opcion,tablero,nivel, largo_cadena);
        switch (opcion)
        {

        // Cargar_desafio(opcion,tablero,6,largo_cadena);
        case 1:
        {
            tablero[0][2] = 'A';
            tablero[1][3] = 'A';
            tablero[2][2] = 'R';
            tablero[2][3] = 'p';
            tablero[3][0] = 'C';
            tablero[3][1] = 'T';
        }
        break;

        case 2:
        {
            ///Cargar_desafio(opcion,tablero,6,largo_cadena);

            tablero[0][2] = 'T';
            tablero[0][3] = 'D';
            tablero[1][0] = 'T';
            tablero[2][2] = 'C';
            tablero[2][3] = 'p';
            tablero[3][0] = 'A';
        }
        break;

        case 3:
        {
            //Cargar_desafio(opcion,tablero,6,largo_cadena);
            tablero[0][0] = 'A';
            tablero[2][0] = 'A';
            tablero[2][2] = 'T';
            tablero[2][3] = 'C';
            tablero[3][1] = 'p';
            tablero[3][2] = 'p';
        }
        break;
        case 4:
        {
            //  Cargar_desafio(opcion,tablero,6,largo_cadena);
            tablero[0][2] = 'T';
            tablero[1][0] = 'T';
            tablero[1][1] = 'p';
            tablero[2][0] = 'A';
            tablero[2][1] = 'K';
            tablero[3][2] = 'A';
        }
        break;
        case 5:
        {
            // Cargar_desafio(opcion,tablero,6,largo_cadena);
            tablero[0][2] = 'T';
            tablero[1][0] = 'C';
            tablero[1][3] = 'p';
            tablero[2][2] = 'p';
            tablero[3][0] = 'C';
            tablero[3][1] = 'T';
        }
        break;

        case 6:
        {
            // Cargar_desafio(opcion,tablero,6,largo_cadena);
            tablero[0][1] = 'C';
            tablero[1][1] = 'A';
            tablero[1][2] = 'p';
            tablero[1][3] = 'A';
            tablero[2][0] = 'p';
            tablero[2][2] = 'C';
        }
        break;

        } */
}





///funcion que tiene almacenado todos los desafios precargadas del nivel dificil
/// y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel desde el archivo */
void nivel_dificil(char tablero[TAM][TAM], int largo_cadena, char desafio[limite])
{

    int opcion;
    opcion = num_aleatorio(27,32); //// los desafios del nivel facl  estan entre las lineas 12y 17 del archivo de texto partdasnuevas.txt
    int cantidad_pieza= 4;
//scanf("%i", &opcion);  // ---->>> esta intruccion era para comprobar manualmente cada desafio////////
    Cargar_desafio(opcion,tablero,cantidad_pieza,largo_cadena, desafio);
    /*
        switch (opcion)
        {
        case 1:
        {
           //  Cargar_desafio(opcion,tablero,7,largo_cadena);
            tablero[0][0] = 'T';
            tablero[1][1] = 'p';
            tablero[1][2] = 'C';
            tablero[1][3] = 'A';
            tablero[2][2] = 'p';
            tablero[2][3] = 'T';
            tablero[3][0] = 'A';
        }
        break;

        case 2:
        {
           // Cargar_desafio(opcion,tablero,7,largo_cadena);
            tablero[0][2] = 'A';
            tablero[1][1] = 'A';
            tablero[1][2] = 'K';
            tablero[2][0] = 'C';
            tablero[2][1] = 'C';
            tablero[2][3] = 'p';
            tablero[3][0] = 'p';
        }
        break;

        case 3:
        {//Cargar_desafio(opcion,tablero,7,largo_cadena);
            tablero[0][3] = 'T';
            tablero[1][1] = 'T';
            tablero[1][2] = 'p';
            tablero[2][0] = 'A';
            tablero[2][3] = 'C';
            tablero[3][1] = 'p';
            tablero[3][2] = 'A';
        }
        break;

        case 4:
        {
            //Cargar_desafio(opcion,tablero,7,largo_cadena);
           tablero[0][2] = 'T';
            tablero[0][3] = 'A';
            tablero[1][3] = 'p';
            tablero[2][0] = 'A';
            tablero[2][1] = 'C';
            tablero[3][0] = 'p';
            tablero[3][2] = 'T';
        }
        break;
        case 5:
        {
            //Cargar_desafio(opcion,tablero,7,largo_cadena);
            tablero[0][3] = 'A';
            tablero[1][3] = 'T';
            tablero[2][0] = 'T';
            tablero[2][1] = 'C';
            tablero[2][2] = 'C';
            tablero[3][0] = 'p';
            tablero[3][1] = 'p';
        }
        break;

        case 6:
        {
            tablero[0][2] = 'C';
            tablero[0][3] = 'A';
            tablero[1][1] = 'C';
            tablero[1][3] = 'p';
            tablero[2][0] = 'p';
            tablero[2][1] = 'T';
            tablero[3][0] = 'A';
        }
        break;
        } */
}




// funcion que devuelve un numero aleaotorio entre un rango de numero dado para la selecion de los desafios ///
int num_aleatorio(int rango_inf, int rango_sup)
{

    int num;
    srand(time(NULL));
    num=  rango_inf+ rand()% ((rango_sup+1)-rango_inf);



    return num;  // devuelve el numero aleatorio
}

