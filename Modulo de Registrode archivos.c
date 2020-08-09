#include"milibreria.h"


/// Esta funcion de encarga de coprobar si existe el archivo "partidasnuevas.txt"
int  Comprobar_archivo_nuevapartidas()
{
    int confirmacion;
    FILE *arch;

    if ((arch=fopen("partidasnuevas.txt", "r+t"))==NULL)
    {
        cuadro_texto(30, 6,"No se  existe el archivo partidasnuevas.txt",0);
        cuadro_texto(35, 12, "Creando partidasnuevas.txt ",0);
        getch();
        confirmacion=1;
        system("cls");

    }

    else
    {
        confirmacion=0;
    }
    fclose(arch);
    return confirmacion;


}



/// esta funcion se encarga de crear el archivo  partidasnuevas.txt" donde se almacenan los desafios precargados
void CrearArchivo_nuevapartidas()
{

    FILE *arch;
    char letra;
    if ((arch= fopen("partidasnuevas.txt", "w+t"))==NULL)
    {
        printf("No se pudo crear el archivo ''partidasnuevas.txt'");
        getch();
        exit(1);
    }

    else
    {
///creando y guardando los tableros

        /** Se crea el formato ideado de como sera el archivo , y la forma como se escribe hace
        posible extrear la informaion de cada partida precrgada por nivel. no se debe tocar*/

        fputs("CARGAS DE LOS DESAFIOS\n", arch);

        fputs("======================================\n\n", arch);


        fputs("Tableros nivel Entrenamiento\n", arch);

        fputs("======================================\n\n", arch);
//tablero para el nivel entrenamiento
        fputs("Ab4-Dc3-Ad2-Ta1 Entrenamiento\n", arch);
        fputs("Cc4-Aa3-Pb2-Tc1 Entrenamiento\n", arch);
        fputs("Da4-Tc4-Cb2-Pa1 Entrenamiento\n", arch);
        fputs("Cb4-Dd3-Cc2-Pa1 Entrenamiento\n", arch);
        fputs("Ab4-Db3-Pa2-Rc2 Entrenamiento\n", arch);
        fputs("Ta4-Pc4-Cb2-Ac1 Entrenamiento\n\n", arch);
        ;
        fputs("Tableros nivel Facil\n", arch);

        fputs("======================================\n\n", arch);

        fputs("Ac4-Ad3-Dc2-Pd2-Ca1-Tb1 Facil\n", arch);
        fputs("Tc4-Dd4-Ta3-Cc2-Pd2-Aa1 Facil\n", arch);
        fputs("Aa4-Aa2-Tc2-Cd2-Pb1-Pc1 Facil\n", arch);
        fputs("Tc4-Ta3-Pb3-Aa2-Rb2-Ac1 Facil\n", arch);
        fputs("Tc4-Ca3-Pd3-Pc2-Ca1-Tb1 Facil\n", arch);
        fputs("Cb2-Ab3-Pc3-Ad3-Pa2-Cc2 Facil\n\n", arch);



//tablero para el nivel Dificil

        fputs("Tableros nivel Dificil\n", arch);

        fputs("======================================\n\n", arch);

        fputs("Ta4-Pb3-Cc3-Ad3-Pc2-Td2-Aa1 Dificil\n", arch);
        fputs("Ac4-Ab3-Rc3-Ca2-Cb2-Pd2-Pa1 Dificil\n", arch);
        fputs("Td4-Tb3-Pc3-Aa2-Cd2-Pb1-Ac1 Dificil\n", arch);
        fputs("Tc4-Ad4-Pd3-Aa2-Cb2-Pa1-Tc1 Dificil\n", arch);
        fputs("Ad4-Td3-Ta2-Cb2-Cc2-Pa1-Pb1 Dificil\n", arch);
        fputs("Cc4-Ad4-Cb3-Pd3-Pa2-Tb2-Aa1 Dificil\n\n", arch);


        fclose(arch);
    }  // cierra el archivo
}



//Falta por implementar.
/** lee los desafios precargadas
*/
void Leer_partidasguardadas()
{

    FILE *arch=fopen("partidasnuevas.txt","r+t");
    if (arch==NULL)
    {
        exit(1);
    }

    char caracter = fgetc(arch);
    while (!feof(arch))
    {


        printf("%c",caracter);
        caracter = fgetc(arch);


    }
    fclose(arch);
    getch();
    printf("\n");





}


///prueba


void Leer_partidasguardadasversion2(char tablero[TAM][TAM])
{
    char linea[100];
    FILE *arch=fopen("partidasnuevas.txt","r+t");
    if (arch==NULL)
    {
        printf("No se pudo leer el archivo\n");
    }
    else
    {

        fgets(linea,100,arch);
        while (!feof(arch))
        {
            traslado(25);
            printf("%s",linea);
            fgets(linea,100,arch);
        }
        fputs("\n", arch);
        fclose(arch);
        getch();


    }
    return 0;




}





void Leer_partidasguardadasversion3(char tablero[TAM][TAM])
{
    char linea[100];
    FILE *arch=fopen("partidasnuevas.txt","r+t");
    if (arch==NULL)
    {
        printf("No se pudo leer el archivo\n");
    }
    else
    {

        fscanf(arch,"%s", linea);
        while (!feof(arch))
        {
            printf("%s",linea);
            fgets(linea,28,arch);
        }
        fputs("\n", arch);
        fclose(arch);
        getch();


    }
    return 0;




}

// no implementado
void CrearArchivo_nuevapartidasprueba(char tablero[TAM][TAM])
{

    FILE *arch;
    char letra;
    if ((arch= fopen("partidasnuevas.txt", "wt"))==NULL)
    {
        printf("No se pudo crear el archivo ''partidasnuevas.txt''\a");
    }
    while( (letra= getchar())!= EOF)
    {
        fputc(letra, arch);
    }

    fclose(arch);
}



/// Funcion que se encarga de comprobar si existe el archivo "partidasguardadas.txt" en el sistema
int  Comprobar_partidas_guardadas()
{
    int confirmacion;
    FILE *arch;

    if ((arch=fopen("partidasguardadas.txt", "r+t"))==NULL)
    {

        confirmacion=1;

    }


    else
    {
        confirmacion=0;
    }
    fclose(arch);
    return confirmacion;


}

/// funcion que se encarga de crear el archivo en caso que no exista y sobreeecribe en el con la partida gaurdada actual
void CrearArchivo_partidasguardadas()
{

    FILE *arch;
    char letra;
    if ((arch= fopen("partidasguardadas.txt", "w+t"))==NULL)
    {
        traslado(25);
        printf("No se pudo crear el archivo ''partidasnuevas.txt''\a");
        getch();
    }

    else
    {
///
        fseek(arch,20, SEEK_SET);
        fputs("Partidas Guardadas\n", arch);
        fseek(arch,10, SEEK_CUR);
        fputs("======================================\n\n", arch);


    }

    fclose(arch);
}



/**nota: no esta implementado, añadir
Se debe pedir al usuario un formato estandarizado para introdcur piezas, guiandose de tal manera que la
la funcion leer partida, pueda extraerlo, crear un archivo aparte "Partida personalizada " y de ese archivo leer la patida a mostrar en pantalla
de la misma manera que los desafios precargados */
///Funcion que se encarga de pedir al usuario el tablero personalizado
void Crear_tableromanual(char tablero[TAM][TAM], char desafio[limite])
{



    char cadena_aux[4];  // Va almacenar por parte segamentada la informacion de cada pieza y su posicion

    char pieza;
    int fila,columna;
    int cantidad_piezas=4;
    int respuesta;
    FILE *arch;

    if ((arch=fopen("partidasnuevas.txt", "a+t"))==NULL)
    {
        traslado(25) ;
        printf("No se pudo crear Registrar el tablero, intento de nuevo");
    }

    else
    {

        system("cls");
        fflush(stdin);
        traslado(25);
        printf("Ingrese las posiciones de las las piezas de su tablero personalizado\n");
        traslado(25);
        printf("Ejemplo de escritura:\n");
        traslado(25);
        printf("Ta4-Pc4-Cb2-Ac1 Facil:\n");
        traslado(25);
        printf("Esta notacion indica que una Torre esta ubicada en la posicion a4\n");
        traslado(25);
        printf("un peon en c4, un Caballo en b2 y un Alfil en c1\n\n");

        traslado(25);
        printf("Introduzca el numero de piezas: ");
        scanf("%i", &cantidad_piezas);   // pie el numero de piezas, con esta se tiene un paametro del tamanio de la cadena a registar

        char informacion[(cantidad_piezas*4)-1];  // se crea la cadena que leere al informacion por teclado
        /*
        for(int x=0 ;x<cantidad_piezas ;x++ ){


           menu_pieza(cadena_aux);
           strcat(cadena, cadena_aux);


           if (x=!cantidad_piezas-1){
               strcat(cadena, "-");
           }

        } */


        traslado(25);
        printf("Introduzca la configuracion del tablero de tal manera como el ejemplo\n");
        traslado(25);
        scanf("%s", informacion);
        //printf("prueba de captura:\n");
// puts(informacion);


        getch();

        /*  if ( strlen(cad)!= 15 && strlen(cad)!= 23  &&strlen(cad)!= 27 ){
              printf("El numero de piezas en el tablero es erroneo\nDebe poner al menos 4 piezas en el tablero y maximo 7  piezas en el tablero\n");
              system("pause");
              respuesta= 0;
         }
         else{
             respuesta=1;
         }

         } while (respuesta); */


        fputs(informacion, arch);  // graba la cadena obtenida en el archivo de texto "nuevaspartidas.txt"
        fputs("  Tablero personalizado\n", arch); // graba la cadena obtenida en el archivo de texto "nuevaspartidas.txt"


        fclose(arch);  // cierra el archivo "nuevaspartidas.txt"

/// esta funcion se encarga de desglozar la informacion de la cadena en las piezas y la posicion correspondiente al tablero
        separar_piezas(tablero,informacion,strlen(informacion),4);

        strcpy(desafio, informacion);
        getch();

    }

}


///Funcion para el usario poner la pieza en el tablero y la posicion
void menu_pieza(char cadena_aux[])
{
    char pieza_aux[3];
    int opcion=0;

    do
    {
        fflush(stdin);

        traslado(25);
        printf("  (1)-->Peon\n  ");
        traslado(25);
        printf("(2)--> Caballo\n  ");
        traslado(25);
        printf("(3)--> Alfil\n  ");
        traslado(25);
        printf("(4)-->Torre\n  ");
        traslado(25);
        printf("(5)--> Dama/Reina\n  ");
        traslado(25);
        printf("(6)-->Rey\n\n ");
        traslado(25);
        printf("Introduzca la opcion para el tipo de pieza: ");
        scanf("%i", &opcion );
        switch (opcion)
        {
        case 1:
            cadena_aux[0]='P';
            break;
        case 2:
            cadena_aux[0]='C';
            break;
        case 3:
            cadena_aux[0]='A';
            break;
        case 4:
            cadena_aux[0]='T';
            break;
        case 5:
            cadena_aux[0]='D';
            break;
        case 6:
            cadena_aux[0]='R';
            break;
        default:
            traslado(25);
            printf("No ha introducido una opcion valida.Intente de nueva\n\n");
            break;
        }
    }
    while (opcion!=1 &&opcion!=2 &&opcion!=3 &&opcion!=4 &&opcion!=5 &&opcion!=6 );



    traslado(20);
    printf("Introduzca la posicion donde quiere colocar la casilla: (recuerde escribir en minuscula)\n");
    traslado(10);
    printf("Recuerde que la letra representa la columna (va desde a hasta d) y el numero indica la fila (desde el 1 hasta el 4)\n");
    traslado(25);
    printf("Ejemplo: a1, c4, b2,etc\n");
    traslado(25);
    printf("Introduzca la posicion: ");
    scanf("%s", pieza_aux);
    strcat(cadena_aux, pieza_aux);
    printf("\nPrueba: %s\n", cadena_aux);
    system("pause");





}


/// convierte la cadena auxliar extraida en informacion para el tablero //
void conversion_posicion_archivos(char caden_aux[tamanio],  int *pos_fila, int *pos_columna, char *pieza)
{
    /**
     Traduce la informacion contenida en la cadena extraida y separa entres partes
     primera letra: tipo de pieza
     2da letra: columna
     2da letra: Fila
     ej: "Ca1"
     C = caballo
     a= columna a del tablero
     1= fila 1 del tablero */

    switch (caden_aux[2])
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

    switch (caden_aux[1])
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
    *pieza =  caden_aux[0];


}


//sin implementar, falta agregar
void Llenar_tablero(char tablero[TAM][TAM], int fila, int columna, char pieza)
{









}


/// Se encarga de extarer el desafio de una linea de texto expecifica y configurar el tablero
void Cargar_desafio(int linea_desafio, char tablero [TAM][TAM],int cantidad_piezas, int largo_cadena, char desafio[limite])
{



// paso1 : extrar desafio predeterminado desde el archivo de texto "nuevaspartidas.txt"///

    extraer_desafio(desafio, linea_desafio,largo_cadena);



//  paso 2: separar la data extraida de la linea del archivo y almacenarla en una cadena auxiliar y luego analizar cada informacion//
    separar_piezas(tablero,desafio,largo_cadena,cantidad_piezas);





}



/// extrae el dato necesario de una desafio predeterminado//
void extraer_desafio(char cadena_principal[], int linea_desafio, int largo_cadena )
{

    /** Nota: Hay que ver como puedo dirigirme a
    una linea exacta del archivo */
    FILE *arch;
    int conta;
    char cad_basura[100];
    if ((arch=fopen("partidasnuevas.txt", "rt"))==NULL)
    {
        printf("No se puedo leer el  desafio\n");
    }

    else
    {
        {
            conta=linea_desafio-1;
            fseek(arch, 0, SEEK_SET);
prueba:
            if (conta>0)
            {
                while (fgetc (arch) != '\n');
                conta--;
                goto prueba;
            }

            fscanf(arch, "%s", cadena_principal);
            //fgets(cadena_principal, largo_cadena+1, arch);




        }

    }

    fclose(arch);
}


/**
 Traduce la informacion contenida en la cadena extraida y separa entres partes
 primera letra: tipo de pieza
 2da letra: columna
 2da letra: Fila
 ej: "Ca1"
 C = caballo
 a= columna a del tablero
 1= fila 1 del tablero */
void separar_piezas(char tablero[TAM][TAM], char cadena[],  int largo_cadena, int cantidad_piezas)
{
    int fila, columna;
    char pieza;
    char caden_aux[4];
    char *p_cadena;
    getch();
    for(int x=0 ;  x<largo_cadena ; x+=4)
    {

        caden_aux[0]= cadena[x];
        caden_aux[1]=cadena[x+1];
        caden_aux[2]= cadena[x+2];


        //// funcion de converion de la cadena que contiene el tipo de pieza, la fila y columna donde se encuentra//
        conversion_posicion_archivos(caden_aux, &fila, &columna, &pieza );

        ///carga la informacion traducida ahora en el tablero
        tablero[fila][columna]= pieza;
    }

}

///Nota: falta implementar
//funcion que se encarga de grabar la partida del jugador en el archivo de texto de "records.txt"

void Guardar_partidas( char nombre[limite], char desafio[], int nivel, int num_partida)
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    char tipo_nivel[50];
    switch (nivel)
    {
    case 2:
        strcpy(tipo_nivel, "Facil");
        break;

    case 3:
        strcpy(tipo_nivel, "Dificil");

    default:
        strcpy(tipo_nivel, "Personalizado");
        break;
    }

    FILE *arch;

    if((arch= fopen("partidasguardadas.txt", "a+t"))==NULL )
    {
        printf("No se pudo guardar la partida. intente luego.");
        getch();
    }

    else
    {



        traslado(25);
        printf( "Partida: %i %s,%s,%s, %s\n", num_partida, nombre, output, tipo_nivel,  desafio);
        fprintf(arch, "Partida:  %i ,%s, %s,%s,%s\n", num_partida, nombre, output, tipo_nivel,  desafio);

        ;

    }

    fclose(arch);

}

