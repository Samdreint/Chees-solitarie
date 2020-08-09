#include"milibreria.h"


///Permite cargar un el tablero que  ha jugado anteriormente desde donde estaba en la sesion anterior del usuario ////
void Cargar_Partida(char matriz[TAM][TAM], char nombre[limite], char desafio[], int *num_partida)
{

//  llama nuevamente a la funcion principal que se encarga de los movimientos y validarlos
    sistema_movimiento(matriz, nombre, 2, desafio, num_partida );


}
