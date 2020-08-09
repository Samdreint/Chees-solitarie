

/** esta archivo.h se encarga de hacer uso de las librerias comunes a todos los archivos .c asociados al programa y
ademas de declarar las funciones prototipo de todas los funciones que se usan en el proyecto
Tambien define unas contantes para el desarrollo del juego para mayor comodidad */
#define tamanio 50
#define Si 1
#define No 0
#define TAM 4  // define el tamanio de tablero de ajedrez a un 4x4
#define tam 18   // contante asociado a la impresion grafica de los disenos graficos de la consola
#define Tcoord 3  //define el tamaño de la cadena donde se le envia la posicion de la casilla seleccionada.
#define limite 100   // define el limite de escritura para el nombre del usuario
#include<time.h>    // accede  a la libreria para usar las funciones de registro de tiempo
#include<math.h>    // accdede a la libreria para usar las funciones matematicas disponibles
#include<stdio.h>  //  libreria que se usa para la flujo de dato de salida  y de entrada por la consola
#include<stdlib.h>//  libreria que se usa para la flujo de dato de salida  y de entrada por la consola
#include<windows.h>   // libreria que se usa para usar funciones que permiten manipular la pantalla de la consola
#include<conio.h>        // libreria grafica para uso estandar
//#include<conio2.h>    // libreria grafica actualizada que permite hacer funciones que agilizan el apartado visual como la funcion gotoxy()
#include<locale.h>      // liberia que se usa  accedder al registro y configuracion del sistema de la computadora




/// FUNCIONES PRINCIPALES DEL JUEGO  ////


// lleva a la funcion modular de empezar una desafio para el jugador en una pantalla nueva
void iniciar_Partida(char tablero[TAM][TAM], char nombre[limite], char desafio[limite], int *num_partida);
/*
    //Funcion: iniciar_Partida9();

    Parametros de entrada:
 1--> una matriz de carateres esepcificamente 4x4,  donde se crea y almacena el tablero a jugar
 2--> una cadena de caracteres donde almacena el nombre del jugador
 3-->una cadena de caracteres donde se guarda la informacion se va a guardar y extraer la informacion del desafio a jugar o crear
 4-->un entero donde indica  el numero de partida  jugada por el usuario

    Parametros de salida
 no retorna nigun valor

    Explicacion:
    Esta funcion  dirige el programa de la pantalla principal a la pantalla de menu de juego de inniciar partida nueva, mandando el tablero creado a jugar,
    el nombre introducido por el usuario , la creacion en blanco de la carta desafio y el numero de la partida

    Precondiciones y Poscondiciones:
    -->Precondiciones:  tener creado una matriz de caracteres y el nombre del usuario
    -->Post condiciones:  Modifica el tablero y la carta desafio para llenarla de informacion  y hace uso del nombre del usuario,y posteriormente en  otra funcion usar la informacion para
    guardar en un archivo de texto

 */

// Permite cargar un el tablero que  ha jugado anteriormente desde donde estaba en la sesion anterior del usuario
void Cargar_Partida(char matriz[TAM][TAM], char nombre[limite], char desafio[], int *num_partida);
/*
    //Funcion: Cargar_Partida()

    Parametros de entrada:
 1--> una matriz de carateres esepcificamente 4x4,  donde se crea y almacena el tablero a jugar y ademas modificar el tablero,segun corresponda
 2--> una cadena de caracteres donde almacena el nombre del jugador
 3-->una cadena de caracteres donde se guarda la informacion se va a guardar y extraer la informacion del desafio a jugar o crear
 4-->un entero donde indica  el numero de partida  jugada por el usuario

    Parametros de Salida:
 no retorna nigun valor

    Explicacion:
   la funcion Cargar_Partida tiene como funcion usar lainformacion del tablero jugado   traves de la matriz de carateres
     y del archivo de texto donde esta registrado la partida o juego actual y luego cargar esa informacion en el tablero
      para luego dirigirse a la funcion sistema_movimiento paa seguir jugando

    Precondiciones y Poscondiciones:
    -->Precondiciones:  tener creado una matriz de caracteres y el nombre del usuario y el la partida en estado actual de no perdida o no ganada
    -->Post condiciones:  Modifica el tablero y la carta desafio para llenarla de informacion  y hace uso del nombre del usuario,y posteriormente en  otra funcion usar la informacion para
    guardar en un archivo de texto y seguir jugando

 */

///          muestra la tabla de records
void Ver_Records(char nombre[], char tablero[TAM][TAM]);
/*
    //Funcion: Ver_Records

    Parametros de entrada:
 1--> una matriz de carateres esepcificamente 4x4,  donde se crea y almacena el tablero a jugar y ademas modificar el tablero,segun corresponda
 2--> una cadena de caracteres donde almacena el nombre del jugador

    Parametros de Salida:
 no retorna nigun valor

    Explicacion:
 Ver _Records tiene la funcion de llevarte a la modulo de pantalla donde se encarga de mostrar principalmente
 los records de las partidas ganadas pornivel y luego consultar los registros de los archivos almacenados o creados

    Precondiciones y Poscondiciones:
    -->Precondiciones: Que exista el archivo "records.txt" y los archivos:
    “records_facil.txt”  y “records_dificil.txt” , “records_entrenamiento.txt”
    -->Post condiciones:   Consulta los archivos mencionados

 */

//  funcion que muestra el menu principal del juego con las opciones principales y devuelve la opcion del usuario
int Menu(char nombre[limite]);
/*
    //Funcion: Menu

    Parametros de entrada:
 1--> un string que contiene el nombre del usuario

    Parametros de Salida:
1--> un entero, que funciona como control para evaluar las opciones del jugador

    Explicacion:
 Se llama a la funcion menu manndole el nombre del udsuario para guardar posteriormente el nombre y
escoger una opcion del menu principal  correspondiente y ademas devuelve el numero escogida para el switch
para la opcion de  jugar una partida nueva, cargar paritda guardada, ver records y salir dle juego

    Precondiciones y Poscondiciones:
    -->Precondiciones:   existencia dle nombre del usuario  ( un string que lo contenga)
    -->Post condiciones: la salida de un  numero entero

 */

///  indica el final del juego y muestra una pantalla conrrespondiente a ello
void Salida(char tablero[TAM][TAM]);   // funcion que lleva a la culminacion del juego
/*
    //Funcion:  Salida

    Parametros de entrada:
 1-->  una matriz de carateres esepcificamente 4x4,  donde se crea y almacena el tablero a jugar y ademas modificar el tablero,segun corresponda


  Parametros de salida:
 1--> no retorna valor

    Explicacion:


    Precondiciones y Poscondiciones:
    -->Precondiciones:  ninguna
    -->Post condiciones:   ninguna


 */
//  es una funcion que permite imprimir el tablero de adorno de la pantalla del menu prinicipal
void dibujo_tablero();
/*
//Funcion: dibujo_tablero

Parametros de entrada:
ninguna

Parametros de Salida:
ninguna
Explicacion:
Es una funcion que permite imprimir el tablero de adorno de la pantalla del menu prinicipal

Precondiciones y Poscondiciones:
-->Precondiciones: ninguna
-->Post condiciones: Muestra el dibujo del tablero 4x4 graficamente


*/
//dibuja la linea de adorno para el contorno del tablero de adorno parte superior //
void barra_sup();
/*
    //Funcion: barra_sup

    Parametros de entrada:
Ninguno

    Parametros de Salida:

ninguno
    Explicacion:
//dibuja la linea de adorno para el contorno del tablero de adorno parte superior //

    Precondiciones y Poscondiciones:
    -->Precondiciones: ninguno
    -->Post condiciones: ninguno


 */

//dibuja la linea de adorno para el contorno del tablero de adorno parte inferior //
void barra_inf();
/*
    //Funcion: barra_inf

    Parametros de entrada:
Ninguno

    Parametros de Salida:

ninguno
    Explicacion:
//dibuja la linea de adorno para el contorno del tablero de adorno parte inferior //

    Precondiciones y Poscondiciones:
    -->Precondiciones: ninguno
    -->Post condiciones: ninguno


 */

// permite trzar las lineas que conforman el tablero de adorno de la pantalla principal
void linea_1();
/*
    //Funcion: linea_1

    Parametros de entrada:
 Ninguno

    Parametros de Salida:
Ninguno

    Explicacion:
  permite trazar las primera forma de las lineas que conforman el tablero de adorno de la pantalla principal

    Precondiciones y Poscondiciones:
    -->Precondiciones: Ningngo
    -->Post condiciones: Ningngo


 */

// permite trzar las lineas que conforman el tablero de adorno de la pantalla principal
void linea_2();
/*
    //Funcion: linea_2

    Parametros de entrada:
 Ninguno

    Parametros de Salida:
Ninguno

    Explicacion:
  permite trazar las segunda forma de lineas que conforman el tablero de adorno de la pantalla principal

    Precondiciones y Poscondiciones:
    -->Precondiciones: Ningngo
    -->Post condiciones: Ningngo


 */

// una funcion rapida que permite rapidamente hacer traladar un texto horizntalmente mas facil //
void traslado(int num);
/*
    //Funcion: traslado

    Parametros de entrada:
 1--> un numero entero (cantidad de espacios horizontales a desplazar )

    Parametros de Salida:
Ninguno

    Explicacion:

una funcion rapida que permite rapidamente hacer traladar un texto horizntalmente mas facil
cuando la siguiente intruccion se imprime un texto en pantalla. indicando el numero de espacios a correr en la pantalla antes de imprimir

    Precondiciones y Poscondiciones:
    -->Precondiciones: mandar un numero que indica
    -->Post condiciones:


 */



// muestra un display de presentacion de pantalla
void pantalla_bienvenida(char nombre[limite]);
/*
    //Funcion: pantalla_bienvenida

    Parametros de entrada:
 1--> un string donde se va almancenar el nombre dle usario durante la partida actual del usuario

    Parametros de Salida:
ninguno

    Explicacion:
 pide  el nombre del usuario cuando ejecuta al principio el juego y
  presenta una breve explicacion del juego

    Precondiciones y Poscondiciones:
    -->Precondiciones: Ninguno
    -->Post condiciones:  Ninguno


 */

/// Inicializa el tablero poniendo cada casilla un espacio vacio al comienzo
void Inicializar_tablero(char tablero[TAM][TAM]);

/*
    //Funcion: Inicializar_tablero

    Parametros de entrada:
 1--> una matriz de  caracteres  4x4 donde contiene el tablero de juego


    Parametros de Salida:
No retonrna valor

    Explicacion:
/// Inicializa el tablero poniendo cada casilla un espacio vacio ' '  al comienzo del cualqier juego antes de cargar un desafio

    Precondiciones y Poscondiciones:
    -->Precondiciones: que exista y se mande como parametro la matriz de caracteres
    -->Post condiciones:  se remplaza el tablero por espacios vacios en cada casilla inicialmente


 */

// Se encarga de dirigir la seleccion del desafio segun  la dificultad elegida por el usuario
void Cargar_tablero(char tablero[TAM][TAM], char nombre[limite], int *restriccion, char desafio[limite]);
/*
    //Funcion:  Cargar_tablero

    Parametros de entrada:
 1--> una matriz de caracteres que contiene las piezas del tablero actual cargado en ella
 2--> un string que contiene el nombre del usuario
 3--> un puntero tipo entero que representa el el valor del nivel ( representacion numerica del nivel escogido del tablero cargado )
 4--> una string que contiene o va a contener  la informacion del desafio a cargar en el tablero a partir del archivo de texto creado

    Parametros de Salida:
No retorno ningun valor

    Explicacion:
// Se encarga de dirigir la seleccion del desafio segun la dificultad elegido por el usuario
Esto lleva a otro submenu donde el usuario debe escoger la opcion de precargar un desafio de acuerdo a un nivel o personalizado por el jugador
Luego segun la opcion  y nivel escogido, ejecutara el precargado del tablero

    Precondiciones y Poscondiciones:
    -->Precondiciones:  se debe mandar el tablero matriz ya existente y con la condicion de haber mandado el tablero por la funcion Inicializar_tablero
    -->Post condiciones:  Carga la configuracion  extraido el archivo de texto partidasnuevas.txt  en el tablero a jugar o directamente del teclado


 */

//  funcion secundaria a la funcion Cargar_tablero que imprime el menu de seleccion del nivel y precargar los desafios segun correspondan
int elegir_nivel(char nombre[limite]);
/*
    //Funcion:  elegir_nivel

    Parametros de entrada:
 1--> un string que contiene el nombre del jugador


    Parametros de Salida:
 1-->retorna un entero ( valor que se usa como control para el swith de opcion de nivel de precargado por los tres niveles

    Explicacion:
//  funcion secundaria a la funcion Cargar_tablero que imprime el menu de seleccion del nivel y precargar los desafios segun correspondan
Se encarga de pedir el numero o la opcion escogida por el usuario  para  precargar un desafio  de acuerdo a la dificultad escogida

    Precondiciones y Poscondiciones:
    -->Precondiciones:    existencia del nombre del juador en cadena como parametro y pedir un numero entero positivo y comprendido entre 1 y 3
    -->Post condiciones:  devuelve el numero correspondiente al nivel


 */


// funcion que consulta todos los desafios precargadas a este nivel Entrenamiento y lo cargar en el tablero actual
void nivel_entrenamiento(char tablero[TAM][TAM], int largo_cadena, char desafio[limite]) ;
/*
    //Funcion:  nivel_entrenamiento

    Parametros de entrada:
 1--> una matriz tipo carater bidimensional 4x4, que contiene el tablero vacio
 2--> un valor entro que indica  la longitud de la cadena de la informacion que debe ser extraido del archivo
 3--> string que va a contener la informacion necesario del archivo para luego procesar la data al tablero

    Parametros de Salida:
No retorno ningun valor

    Explicacion:

        //funcion que tiene almacenado todos los desafios precargadas del nivel entrenamiento
        // y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel
          se encarga de dar un numero aleatorio entre 1 y 6 que indica
                                            la linea de texto donde se encuentra el desafio en el archivo de texto nuevaspartidas.txt, segun el nivel facil

    Precondiciones y Poscondiciones:
    -->Precondiciones:  es necesario saber la cantidad del largo de la cadena a leer, en ese caso se estima 15 letras para un desafio entrenamiento y mandar el tablero para llenar
    -->Post condiciones: Se carga el tablero con las piezas correspondientes al nivel entrenamiento y un desafio aleatorio de ese nivel


 */

// funcion que tiene almacenado todos los desafios precargadas a este nivel y lo cargar en el tablero
void nivel_facil(char tablero[TAM][TAM], int largo_cadena,char desafio[limite]);
/*
    //Funcion:   nivel_facil

     Parametros de entrada:
 1--> una matriz tipo carater bidimensional 4x4, que contiene el tablero vacio
 2--> un valor entro que indica  la longitud de la cadena de la informacion que debe ser extraido del archivo
 3--> string que va a contener la informacion necesario del archivo para luego procesar la data al tablero


     Parametros de Salida:
No retorno ningun valor

    Explicacion:

        //funcion que tiene almacenado todos los desafios precargadas del nivel entrenamiento
        // y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel
          se encarga de dar un numero aleatorio entre 7 y 13 que indica
                                            la linea de texto donde se encuentra el desafio en el archivo de texto nuevaspartidas.txt, segun el nivel facil



    Precondiciones y Poscondiciones:
    -->Precondiciones:  es necesario saber la cantidad del largo de la cadena a leer, en ese caso se estima 23 o 23 como maximo letras para un desafio facil y mandar el tablero para llenar
    -->Post condiciones: Se carga el tablero con las piezas correspondientes al nivel Facil y un desafio aleatorio de ese nivel


 */

// funcion que tiene almacenado todos los desafios precargadas a este nivel y lo cargar en el tablero
void  nivel_dificil(char tablero[TAM][TAM], int largo_cadena,char desafio[limite]);
/*
    //Funcion: nivel_dificil


     Parametros de entrada:
 1--> una matriz tipo carater bidimensional 4x4, que contiene el tablero vacio
 2--> un valor entro que indica  la longitud de la cadena de la informacion que debe ser extraido del archivo
 3--> string que va a contener la informacion necesario del archivo para luego procesar la data al tablero


     Parametros de Salida:
No retorno ningun valor

    Explicacion:

        //funcion que tiene almacenado todos los desafios precargadas del nivel entrenamiento
        // y lo cargar en el tablero, esocogiendo uno desafio aleatorio de este nivel
          se encarga de dar un numero aleatorio entre 7 y 13 que indica
                                            la linea de texto donde se encuentra el desafio en el archivo de texto nuevaspartidas.txt, segun el nivel facil



    Precondiciones y Poscondiciones:
    -->Precondiciones:  es necesario saber la cantidad del largo de la cadena a leer, en ese caso se estima 27 o 28 como maximo letras para un desafio dificil y mandar el tablero para llenar
    -->Post condiciones: Se carga el tablero con las piezas correspondientes al nivel Facil y un desafio aleatorio de ese nivel


 */

// funcion que devuelve un numero aleaotorio entre un rango de numero dado para la selecion de los desafios ///
int num_aleatorio(int rango_inf, int rango_sup);
/*
    //Funcion:  num_aleatorio

    Parametros de entrada:
 1--> un valor entrado que indica el limite inferior del rango determinado
 2--> un valor entero que indica el limite superior del rango

    Parametros de Salida:
  ---> un valor entero que indica la linea de texto a leer en el desafio del archivo dde texto nuevaspartidas.txt

    Explicacion:
/ funcion que devuelve un numero aleaotorio entre un rango de numero dado para la selecion de los desafios ///

    Precondiciones y Poscondiciones:
    -->Precondiciones:  rango_inf y rango_sup deben ser dos numeros postivas para esta funcion en particular del juego
    -->Post condiciones:  delvuelve el numero de la linea donde esta la informacion a leer el desafio


 */

// imprime el tablero  y las piezas que contiene el tablero en el momento actual///
void Imprimir_tablero(char tablero[TAM][TAM]);
/*
    //Funcion: Imprimir_tablero

    Parametros de entrada:
 1--> una matriz de caracteres que contiene el tablero actual con las piezas en sus respetivos casillas

    Parametros de Salida:
no retorno ningun valor

    Explicacion:
// imprime el tablero  y las piezas que contiene el tablero en el momento actual///
es decir, imprime la forma del tablero jugable y el contenido de lo que contiene de
 forma ordenada y su celda correspondiente a laimagen del tablero jugable

    Precondiciones y Poscondiciones:
    -->Precondiciones:  la existencia y mandar el parametro por referencia de la matriz del tablero que se esta juagando con laspiezas que lo contiene
    -->Post condiciones:  la actualizacion y la muestra de pantalla  del tablero con las piezas en su posicion correspondiente


 */




////FUNCIONES RELACIONADAS A LA JUBILIDAD DEL TABLERO UNA VEZ CARGADA LAS PEIZAS EN EL LA MATRIZ DE CARACTERES  ///




// funcion modular que se respondable del sistema o jugabilidad del tablero principal que se encarga de los movimientos y validarlos y ganar o perder
void sistema_movimiento(char tablero[TAM][TAM], char nombre[limite], int restriccion, char desafio[], int* num_partida);
/*
   //Funcion: sistema_movimiento

   Parametros de entrada:
1--> La matriz de caraccter 4x4
2--> un string que contiene el nombre del jugador
3--> un valor entero que representa la restriccion o control de la subfuncion Deshacerjugadas
4-->

   Parametros de Salida:
No retorno valor alguno, solo mofifica ciertos parametros por referencia al tablero y el numero de partida

   Explicacion:
// funcion modular que se respondable del sistema o jugabilidad del tablero principal que se encarga de los movimientos y validarlos y ganar o perder
Se encarga del menu principaldeljuego, entre jugar, deshacer jugada y terminar la partida. aqui adentro se anidan las subfunciones que controlan
cada modulo especifico de la jugabilidad

   Precondiciones y Poscondiciones:
   -->Precondiciones:  tener el tablero precargado con un desafio  ya traducido  y no este vacia, el nombre del usuario  y el nivel de restriccion del juego para lel deshacer jugadas
   -->Post condiciones: el display del tablero actualizado despues de cada  jugada


*/


// Funcion modular que permite verificar el movimiento de las piezas si se cumplen las condiciones
void Intercambio(char tablero[TAM][TAM], char copia[TAM][TAM], int *repetir)  ;
/*
   //Funcion:  Intercambio

   Parametros de entrada:
1--> la matriz tipo caracter 4x4 original
2-->la matriz tipo caracter 4x4 copia donde contiene el estado anterior el tablero original

   Parametros de Salida:
no devuelve un valor pero modifica el contenido del arreglo o tablero actual

   Explicacion:


   Precondiciones y Poscondiciones:
   -->Precondiciones:  el tablero de copia debe contener el contenido exacto del tablero previo a una jugada
   -->Post condiciones: el tablero actual se actualiza  a su estado anterior


*/


// Deshace la jugada anterior volviendo al posiciones del tablero anterior
void Deshacer_jugada(char tablero[TAM][TAM], char nombre[limite],char copia[TAM][TAM]);
/*
    //Funcion: Deshacer_jugada

    Parametros de entrada:
 1-->Envia coomo parametro el arreglo dimensional tipo char que contiene el tablero actual
 2-->Envia coomo parametro el arreglo dimensional tipo char que contiene el tablero de copia
 3-->Envia como parametro un string que contiene el  nombre del jugador


    Parametros de Salida:

No retorna ningun valor
    Explicacion:
//Presenta el menu de pantalla de  Deshacer la jugada anterior volviendo al posiciones del tablero anterior  y confirma si el jugador
quiere deshacer la jugada anterior

    Precondiciones y Poscondiciones:
    -->Precondiciones:  obtencion de antemano del estado anterior del tablero actual guardado en el matriz de copia
    -->Post condiciones:  se reemplaza el tablero actual por el anterior estado si la confirmacion es verdadera


 */


/// copia el contenido de un arreglo a otro
void copiar_tablero(char tablero[TAM][TAM], char copia[TAM][TAM]);
/*
    //Funcion:  copiar_tablero

    Parametros de entrada:
 1--> Manda como parametro la matriz de caracteres del tablero actual
 2--> Manda como parametro la matriz de caracteres del tablero copia o anterior


    Parametros de Salida:
No retorna ningun valor

    Explicacion:
    reemplazada el valor de cada posicion de un arreglo por el otro de forma secuencia con dos bucles que conttrolan las filas y columnas

/// copia el contenido de un arreglo a otro
    Precondiciones y Poscondiciones:
    -->Precondiciones: el tablero copia debe contener el estado anterior al tablero original
    -->Post condiciones:  el tablero acutal ahora se actualiza


 */




// funcion rapida que presenta el nombre del jugador en la pantalla
void presentacion_nombre(char nombre[limite]);
/*
    //Funcion: presentacion_nombre

    Parametros de entrada:
 1--> un string que contiene el nombre del usuario

    Parametros de Salida:
 no retorna ningun valor

    Explicacion:
presenta el nombre del usuario en la sesion actual en la pantalla en la parte superior de la pantalla

    Precondiciones y Poscondiciones:
    -->Precondiciones: existencia de la string que contenga el nombre del usuario
    -->Post condiciones:  presenta el nombre en la pantalla


 */

// funcion que imprime y hace la selecion del menu de juego
int menu_juego();
/*
    //Funcion:

    Parametros de entrada:
 1--> no tiene parametros

    Parametros de Salida:
Retora un valor de confimracion en un numero entero

    Explicacion:
/ funcion que imprime y hace la selecion del menu de juego y devuelve la opcion escogida por el usuario //
da a escoger entre las opciones de Jugar, Deshacer y Terminar la partida, devolviendo un numero que correspondea la opcion escogida

    Precondiciones y Poscondiciones:
    -->Precondiciones:  tablero todavia sea jugable y que no tenga estado de perdida o ganada
    -->Post condiciones:   devuelve un numero de confirmacion que dirge a una swith que ejecutara una funcion especifica


 */

//// Verificacion si la casilla seleccionada esta dentro del tablero
void Verificacion_limite_del_tablero(char coordenadas[Tcoord], int *confirmacion);
/*
    //Funcion:  Verificacion_limite_del_tablero

    Parametros de entrada:
 1--> Tiene como parametro la posicion e la casilla en forma de cadena de tamanio 3
 2--> manda como parametro un puntero tipo entero que controla la verificacion secuencial de movimiento posible


    Parametros de Salida:
No retorna ningun valor

    Explicacion:
 Verificacion si la casilla seleccionada esta dentro de las casillas del tablero
 // verifica si la contenida de la cadena esta completa y concuerda con el rango aceptado de valores
// de la columna este entre (a y d) y la fila este entre el rango de (1 y 4)

    Precondiciones y Poscondiciones:
    -->Precondiciones:  la cadena debe contener solo 3 letras, la primero repsenta la peiza, 2da la fila y 3 la columna en ese orden
    -->Post condiciones:  modifica el valor con confirmacion secuencial a ver si es posible el movimiento


 */

// Se verifica que en esta casilla escogida no este vacia y contenga una pieza
void verificacion_casillavacia(char tablero[TAM][TAM], int fila, int columna, int *confirmacion);
/*
    //Funcion: verificacion_casillavacia

    Parametros de entrada:
 1-->manda la matriz de caracteres de 4x4 y su informacion
 2--> un  entero que indica el indice de la fila escogida
 3--> un  entero que indica el indice de la columna escogida

    Parametros de Salida:
no Retorno ningun valor  pero mofifica el parametro de confirmacion secunencial de movimiento

    Explicacion:
 con la informacion traducida del indice de la fila y columna especifica, se accede a la posicion del arreglo y se comprueba que el valor de esa casilla no esta vacia
 o no contenga el caracter ' '

    Precondiciones y Poscondiciones:
    -->Precondiciones: tener la informacion del indice y columna para accder al vaor almacenado en el
    -->Post condiciones:  mofidifca el valor de confirmacion secuencial de movimiento, 1 si hay una pieza y 0 si esta vacia


 */




// verifica el tipo de pieza seleccionada para poder redirigir a la funcion especifica que valide el tipo de movimiento
void Verificacion_movpieza(char tablero[TAM][TAM],int fila_inicial, int columna_inicial, int fila_final, int columna_final, int *confirmacion);
/*
    //Funcion: Verificacion_movpieza

    Parametros de entrada:
 1-->  la matriz de tipo char que contiene las peizas del tablero
 2--> variable tipo entera que indica la fila inicial de la casilla origen
 3--> variable tipo entera que indica la columna inicial de la casilla origen
 4--> variable tipo entera que indica la fila final de la casilla destino
 5--> variable tipo entera que indica la columna  de la casilla  destino



    Parametros de Salida:
no retorna ningun valor

    Explicacion:
 compara la dos posiciones pedidas por el jugador   y de acuerdo al tipo de pieza que contenga,
 verifica el tipo de pieza y si la posicion final concuerda con un movimento valida para la pieza, en caso valida,  manda un valor de confirmacion secuencial
 para que se pueda ejecutar el movimiento

    Precondiciones y Poscondiciones:
    -->Precondiciones:  obtener las dos posiciones a comparar y el tipo de piez aque contiene  la casilla origen
    -->Post condiciones:  si el movimiento es posible es asignado a confirmacion el valor 1 y 0 si no posible


 */



/// la funcion coordenadas se encarga de pedir la posicion de la casilla donde qiere mover la pieza y a donde moverla y verifica de acuerda a la pieza, el tipo de movimiento si es posible
int coordenadas(char tablero[TAM][TAM],char cord_inicial[Tcoord], char cord_final[Tcoord], int* fila_inicial, int *columna_inicial, int *fila_final,int *columna_final, int *repetir);
/*
   //Funcion:

   Parametros de entrada:
1--> manda el arreglo de caracteres donde se tiene las pieazas del tablero
2--> un string que va almacenar  la cordenada inicial de la pieza
3-->un string que va almacenar  la cordenada final de la pieza
4--> manda como parametro un puntero tipo entero para el indice de la fila inicial
5--> manda como parametro un puntero tipo entero para el indice de la columna inicial
6--> manda como parametro un puntero tipo entero para el indice de la fila fila o destino
7--> manda como parametro un puntero tipo entero para el indice de la columna  final o destino

   Parametros de Salida:
devuelve un numero entero como c
   Explicacion:
/// pide la casilla inicial a escoger y la casila destino a mover la pieza y verifica mas a fondo en la subfuncion interna si es valida o no,
y luego deuvelve el valor de 1 como confirmacion de intercambio de peizas o 0 si no es posible

   Precondiciones y Poscondiciones:
   -->Precondiciones: existencia y declaracion de los indices de la sfilas y columna de  las casillas y la cadenas donde se va almacena la informacion
   -->Post condiciones: retorna 1 si es verdadero y 0 si es falso


*/




/// envia la posicion origen en lo transforma en los indices de la matriz coorrespondiente
void conversion_posicion(char cord_posicion[Tcoord],  int *pos_fila, int *pos_columna);
/*
    //Funcion: conversion_posicion

    Parametros de entrada:
 1-->Tiene como parametro una cadena que contiene la informacion de la poscicion de la casilla escogida en forma de texto
 2-->  un apuntador tipo entero que apunta al valor del indice de la fila escogida
 2-->  un apuntador tipo entero que apunta al valor del indice de la columna escogida


    Parametros de Salida:
No tiene retorno pero mofifica y asigna el valor correspondiente a la fila y columna

    Explicacion:
// permite convertir la posicion escrita en caracteres en los numeros que indican los indices y la posicion correcta en la matriz del tablero


    Precondiciones y Poscondiciones:
    -->Precondiciones:  la informacion contenida en la cadena debe tener solo 2 letras, la primera indica la columna y la 2da la fila
    -->Post condiciones: se traduce la informacion de cadena de texto a infomracion en forma de indices de acuerda a como se trabaja los arreglos


 */






// procede a hacer el cambio en el tablero actual por el movimiento escogido
void mover_pieza(char tablero[TAM][TAM], char copia[TAM][TAM],  int fila_inicial, int columna_inicial, int fila_final, int columna_final) ;
/*
    //Funcion: mover_pieza

    Parametros de entrada:
 1-->manda como parametro el tablero o matriz de caracteres actual y el tablero de copia anterior
 2--> manda como parametros en forma par, el indice de la fila o columna origen
 2--> manda como parametros en forma par, el indice de la fila o columna destino


    Parametros de Salida:

    no retorna nada pero hace la modificacion respectiva al tablero actual

    Explicacion:

// permite el intercambio de la pieza escogida a la casilla destino y reemplaza la casilla anteior por un vacio.

    Precondiciones y Poscondiciones:
    -->Precondiciones:  la existencia de las dos matrices y el tablero copia debe tener el estado anterior del tablero original
    -->Post condiciones:  el tablero actual se actualiza a su estado anterior y procede a jugar nuevamente


 */


//////SECCION DE VALIDACION DE MOVIMIENTO DE LA PIEZAS

// valida el movimiento del peon
int mov_peon(char tablero[TAM][TAM], int x1, int y1,int x2,int y2, int setup);
/*
    //Funcion : mov_peon

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible
    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    del peon, comprobando las casilla destino sea un casilla adyecente superior diagonal a la casilla origen



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */

// valida el movimiento del caballo
int mov_caballo(char tablero[TAM][TAM], int x1, int y1,int x2,int y2, int setup);
/*
    //Funcion : mov_caballo

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible
    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    del caballo, donde la distancia entre las fila origen  y fila destino sea 1 o 2, mietras que la distancia entre la columna origen y destino sea a la ves
    dos casillas alejada de la columa orinal, es decir, recorra un patron de L en las 8 posibles configuraciones



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */


// valida el movimiento del  alfil
int mov_alfil(char tablero[TAM][TAM], int x1, int y1,int x2,int y2, int Setup);
/*
    //Funcion : mov_alfil

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible
    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    del alfil, comprobando las casilla destino esta en la misma diagonal que la casilla origen



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */


// valida el movimiento de la torre
int mov_torre( char tablero[TAM][TAM], int x1, int y1, int x2, int y2, int setup);
/*
    //Funcion : mov_torre

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible
    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    de la torre, comprobando las casilla destino esta en la misma fila o columna que la casila origen



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */


int mov_reina(char tablero[TAM][TAM], int x1, int y1,int x2,int y2, int setup);  // valida el movimiento de la reina
/*
    //Funcion : mov_reina

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

    retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible

    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    de la reina  comprobando las casilla destino esta en la misma diagonal y misma fila o columna que la casilla origen



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */

// valida el movimiento del rey
int mov_rey(char tablero[TAM][TAM], int x1, int y1,int x2,int y2, int setup);
/*
    //Funcion : mov_reina

    Parametros de entrada:
 1--> dos pares de parametros que indica el indice de la fila y columna inicial
 2--> dos pares de parametros que indica el indice de la fila y columna final


    Parametros de Salida:

    retorno el valor de confirmacion tipo entero : 1 s es posible el movimiento y 0 si no es posible

    Explicacion:
    Compara las dos opciones de acuerdo al tipo de movimiento especifica de la pieza
    de la rey,   comprobando las casilla destino esta en la misma diagonal y misma fila o columna que la casilla origen pero solo na casilla adyacente



    Precondiciones y Poscondiciones:
    -->Precondiciones:  el correcto valor de los indices de las flas y columnas esten dentro del tablero
    -->Post condiciones:  devuelve una confirmacion en forma de 1 si es cierto o 0si es falso


 */


//=========================================================







// esta funcion cuenta las casillas vacias en en tablero  en el momento actual
int cuenta_piezas(char tablero[TAM][TAM]);
/*
    //Funcion:

    Parametros de entrada:
 1--> el tablero de matriz de caracteres  4x4

    Parametros de Salida:
---> devuelve un entero que indica la cantidad de  casillas vacias hay en el tablero

    Explicacion:

esta funcion realiza un escaneo completo de todas las casillas de la matriz en busca del caracter ' ' o
espacio vacio, y va anotando la cantidad de veces qe sale,
de esta manera, se puede comprobar si se gana o no con la logica de que si un tablero tiene 16 casilla,
la condicion de ganar partidas ue solo debe haber una pieza y por consecuente debe haber  15 espacios y no 16 en total y luego devuelve un numero de confirmacion

    Precondiciones y Poscondiciones:
    -->Precondiciones: el tablero este bien definido y precargado con la spiezas en el arreglo
    -->Post condiciones:  muestra un mensaje al jugador qu egano la partida


 */

// funcion rapida y grafica que cree yo mismo para insertar un texto en un cuadro de texto en la pantalla
void cuadro_texto( int coordx, int coordy, char texto[], int espacio);
/*
    //Funcion: cuadro_texto

    Parametros de entrada:
 1-->  un numero entero, indica posicion horizontal en la pantalla donde se colocara el cuadro de texto
 2--> un numero entero, indica posicion vertical en la pantalla  donde se colocara el cuadro de texto
 3-->  un string donde contendra el texto a insertar en el cuadro
 4-->

    Parametros de Salida:
 No retorna ningun valor

    Explicacion:

// funcion rapida y grafica que cree yo mismo para insertar un texto en un cuadro de texto en la pantalla, indicando la posicion de la
pantalla de la consola donde posicionar el cuadro de texto grafico y e insertar un texto directo o un string como parametro como ultimo argumento

    Precondiciones y Poscondiciones:
    -->Precondiciones: enviar las coordenadas x y y de la pantalla donde posicionar el cuadro  en forma de valores enteros
    -->Post condiciones:  se muestra en pantalla en el lugar indicado, el cuadro de texto insertado graficamente


 */

// pregunta el usuario si quiere cargar un desafio precargado  y devuelve un numero
int preguntar_usuario(char nombre[limite]);
/*
    //Funcion: preguntar_usuario

    Parametros de entrada:
 1--> un string que contiene el noombre del usuario

    Parametros de Salida:
 devuelve un numero entero

    Explicacion:
// pregunta el usuario si quiere cargar un desafio precargado  y devuelve un numero entre 1 y 2
1 indica precargar un desafio desde un archivo de texto
2 indica precargar un  desafio manualmente

    Precondiciones y Poscondiciones:
    -->Precondiciones: mandar el nombre como cadena a la funcion como parametro
    -->Post condiciones: devuelve el numero de la opcion escogida por el usuario


 */

/// funcion que permite posicionar el curso de texto en la consola en un posicion determinado de la pantalla (util en la impresion de texto)
void gotoxy(int x,int y);
/*
    //Funcion:

    Parametros de entrada:
 1--> un valor entero que indica la posicion horizontal a donde se dirigira el cursor de texto
 2--> un valor entero que indica la posicion vertical a donde se dirigira el cursor de texto


    Parametros de Salida:
No retorno ningun valor

    Explicacion:
/// funcion que permite posicionar el curso de texto en la consola
en un posicion determinado de la pantalla (util en la impresion de texto)

    Precondiciones y Poscondiciones:
    -->Precondiciones:  mandar la coordenadas en par, en forma de enteros
    -->Post condiciones:  El cursor de texto se dirige a la posicion determinado


 */
// nuevas funciones agregadas para archivos

void leer_lineas(int num, FILE *fp);

// Es una funcion modular que se encarga de dirigir  a llevar a la pantalla donde el usuario cargara su propio tablero personalizado
void Crear_tableromanual(char tablero[TAM][TAM], char desafio[limite]);
/*
    //Funcion: Crear_tableromanual

    Parametros de entrada:
 1--> una matriz de tipo caracter donde se encuentra el tablero donde se dispone cargar el desafio
 2--> un string donde se va almacenar el desafio personalizado por el usuario

    Parametros de Salida:

No retorna ningun valor

    Explicacion:
// Se encarga de dirigir  a llevar a la pantalla donde el usuario cargara su propio tablero personalizado, mando el tablero
jugar ya vacio y a continuacion se almacena en el tablero las peizas

    Precondiciones y Poscondiciones:
    -->Precondiciones:   Tener el tablero inicializado con la funcion  Inicializar_tablero y mandar tambien la cadena donde se va a almacenar la informacion del tablero a jugar
    -->Post condiciones: Se carga el tablero listo para jugar y dirige a la funcion modular de sistema_movimiento qque controla la funcionalidad de jugabilidad de tablero


 */




/// FUNCIONES ASOCIADOS AL MANEJO DE ARCHIVOS Y EXTRACCION Y CONVERSION DE INFORMACION ///////////


/// Esta funcion de encarga de comprobar si existe el archivo "partidasnuevas.txt"
int  Comprobar_archivo_nuevapartidas();
/*
    //Funcion:  Comprobar_archivo_nuevapartidas

    Parametros de entrada:
 No contiene parametros

    Parametros de Salida:
devuleve un entero como valor de confirmacion

    Explicacion:
 //
 /// Esta funcion de encarga de comprobar si existe el archivo "partidasnuevas.txt" para prodecer si crearlo o no en el sistema

    Precondiciones y Poscondiciones:
    -->Precondiciones:  Comprobar si existe  o no al archivo "partidasnuevas.txt".
    -->Post condiciones:  retorna la confirmacion


 */



/// esta funcion se encarga de crear el archivo  partidasnuevas.txt" donde se almacenan los desafios precargados
void CrearArchivo_nuevapartidas();
/*
    //Funcion: CrearArchivo_nuevapartidas

    Parametros de entrada:
 No contiene parametros

    Parametros de Salida:
No retorno ningun valor

    Explicacion:
 //
 /// Esta funcion de encarga de crear  el archivo "partidasnuevas.txt" para prodecer mas adelante  a manipular los datos
 se almacenan alli

    Precondiciones y Poscondiciones:
    -->Precondiciones:  el puntero File *p no sea Null, ya que no podra crear el archivo por algun error
    -->Post condiciones: se crear el archivo de texto  "partidasnuevas.txt"


 */

void CrearArchivo_partidasguardadas();
void Guardar_partidas( char nombre[limite], char desafio[], int nivel, int num_partida);


void Leer_partidasguardadas();
void Leer_partidasguardadasversion2(char tablero[TAM][TAM]);
void Leer_partidasguardadasversion3(char tablero[TAM][TAM]);
void CrearArchivo_nuevapartidasprueba(char tablero[TAM][TAM]);

/// Extaccion dl teclado del desafio personalizado////

/// Se encarga de extarer el desafio de una linea de texto expecifica y configurar el tablero
void Cargar_desafio(int linea_desafio, char tablero [TAM][TAM],int cantidad_piezas, int largo_cadena, char desafio[limite]);
/*
    //Funcion:  Cargar_desafio

    Parametros de entrada:
 1--> numero entero, indica la linea en que se encuentra el desafio especifico
 2-->manda el tablero o matriz tipo char, donde se a cargar la configuracion del tablero
 3-->indica la cantidad de piezas que va a contener el desafio
 4-->largo_cadena indica  el largo dela cadena que contiene el desafio
 5--> es la cadena donde esta almacena el desafio a extraer del archivo

    Parametros de Salida:

no retorna nigun valor
    Explicacion:

    Esta funcion modular se encarga de extraer la liena que contiene el desafio especifico y
    luego se encarga de desglozar la infomracion de forma ordenada para asignarla
    al tabelro actual

    Precondiciones y Poscondiciones:
    -->Precondiciones:  obneer la linea donde se encuentra el desafio y el largo de la cadena donde va a contener el desafio a una cadena  desde al archivo de texto
    -->Post condiciones: Se carga correctamente la configuracion del tablero


 */

//// funcion de converion de la cadena que contiene el tipo de pieza, la fila y columna donde se encuentra//
void conversion_posicion_archivos(char caden_aux[tamanio],  int *pos_fila, int *pos_columna, char *pieza);
/*
    //Funcion: conversion_posicion_archivos

    Parametros de entrada:
 1-->un string que contiene tres caracteres
 2--> un puntero tipo ntero que indica que el valor del inidce de la fila de la pieza
 3--> un puntero tipo ntero que indica que el valor del inidce de la columna de la pieza
 4--> un puntero tipo caracter que indica el tipo d epeiza que hay en que informacion


    Parametros de Salida:
no retorno ningun valor pero modifica el valor de que debe extraerse de la fila, columna y la pieza

    Explicacion:

analiza las posiciones de las cadena, donde
cad[0] ---> representa la pieza
cad[ 1]---> indica la columna
cad[ 2]---> indica la fila

esa se asigna de esta manera a las variables tipos punteros por separadas

    Precondiciones y Poscondiciones:
    -->Precondiciones: la cadena debe contener 3 caracteres
    -->Post condiciones:  se extrae la informacion necesaria para la conversion al tablero


 */
void Llenar_tablero(char tablero[TAM][TAM], int fila, int columna, char pieza);

void extraer_desafio(char cadena_principal[], int linea_desafio, int largo_cadena );


/// esta funcion se encarga de desglozar la informacion de la cadena en las piezas y la posicion correspondiente al tablero
void separar_piezas(char tablero[TAM][TAM], char desafio[],  int largo_cadena, int cantidad_piezas);
/*
    //Funcion:

    Parametros de entrada:
 1-->Manda como parametro  el tablero tipo char de matriz que contiene las peizas
 2--> un string que indica que la cadena que contiene la informacion a desglozar para el tablero
 3--> un valor entero que indica el largo de la cadena a extraer o revisar
 4-->un  valor entero  que indica la cantida de ppiezas a generar en el tablero

    Parametros de Salida:

No retorno ningun valor

    Explicacion:

Analiza  la cadena que contiene la informacion del desafio por ejemplo:
Ta4-Pc4-Cb2-Ac1 en informacion desglozada en :
tablero[ 0][0] = 'T'
tablero[ 0][2] = 'P'
tablero[ 2][2] = 'C'
tablero[ 3][0] = 'A'


    Precondiciones y Poscondiciones:
    -->Precondiciones: la cadena debe estar definida con un tamanio correcta de acuerda a la cantidad de piezas
    -->Post condiciones:  Asigna la informacion correspondiente al tablero actual


 */
void lineas(int num_lineadesafio);

void menu_pieza(char cadena_aux[]); /// forma diferente de pedir la info



////// Funciones Asociadas al estado y Verificacion de estado de perdida

/// verifica el estado de perdida del jugador al verifcar si hay movimentos posibles
int Verifica_perdida(char tablero[TAM][TAM]);
/*
    //Funcion: Verifica_perdida

    Parametros de entrada:
 1--> Manda como parametro el tablero, es decir, la matriz de caracter


    Parametros de Salida:
retorna un entero como forma de confirmacion si se cumple la condicion de perdida de perdida

    Explicacion:

    Va comprobando cada casilla del tablero y si encuentra una casilla no vacia, identifica el tipo de pieza y analiza los posibles movimientos
    de acuerdo el tipo de pieza.
    Va comprobando cad auno, si almenos hay una pieza que tenga disponible un movimiento, entonces devuelve un numero de confirmacion paa seguir jugando, sino se ha perdido al partida

    Precondiciones y Poscondiciones:
    -->Precondiciones:  que no haya estado de partida ganada o el tablero este vacio
    -->Post condiciones:   verifica si hay posible moviemtnos


 */

void Verificacion_posiblemovimientos(char tablero[TAM][TAM], int fila_inicial,int columna_inicial,  int *confirmacion);  // revisa cada una de las piezas que hay actualmente en el tablero
int posible_mov_peon(char tablero[TAM][TAM], int f1, int c1);   /// verificacion todos los posibles movimientos de los peones que hay en el tablero
int posible_mov_caballo(char tablero[TAM][TAM], int f1, int c1);/// verificacion todos los posibles movimientos de los caballos que hay en el tablero
int posible_mov_torre(char tablero[TAM][TAM],  int f1, int c1); /// verificacion todos los posibles movimientos de los caballos que hay en el tablero
int posible_mov_alfil(char tablero[TAM][TAM], int f1, int c1);/// verificacion todos los posibles movimientos de los caballos que hay en el tablero
int posible_mov_reina(char tablero[TAM][TAM], int f1, int c1); /// verificacion todos los posibles movimientos de los caballos que hay en el tablero
int posible_mov_rey(char tablero[TAM][TAM], int f1, int c1); /// verificacion todos los posibles movimientos de los caballos que hay en el tablero


FILE *fd_records;  ///archivo para el records.text
FILE *fd_newplay;   ///archivo para el nuevapartida.text
FILE *fd_savegame;   /// archivo para partidaguardadas.text

