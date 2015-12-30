/*
 * Tablero.cc
 *
 *  Created on: 30/12/2015
 *      Author: Jhoan Sebastián
 */

#include "Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero()
{
	// TODO Auto-generated constructor stub

}

Tablero::~Tablero()
{
	// TODO Auto-generated destructor stub
}

void Tablero::llenarTablero()
{

	int filas, columnas; // las variables para el for
	double *puntero; //Declaro el puntero que va a recorrer todas las posiciones de la matriz.
	puntero = miTablero[0]; // La verdad, no sé muy bien si esto es necesario, pero según entiendo, primero a la dirección del puntero
	// se le asigna la dirección de la matriz, tiene que ser solo con una llave [], ya que el espacio de memoria miTablero[0] es el
	// mismo de miTablero[0][0]

	for (filas = 0; filas < 8; filas++)
	{
		for (columnas = 0; columnas < 8; columnas++)
		{
			puntero = &miTablero[filas][columnas]; // Se amarra el puntero al espacio de el tablero que necesitamos.
			*puntero = 1 + rand() % 4; // y al poner el * le asignamos el valor a ese espacio de memoria en donde fue amarrado
			// el puntero.
		}

	}
}


void Tablero::getTablero() // Este slo es mostrar cada posición del tablero.
{
	int filas, columnas;
	for (filas = 0; filas < 8; filas++)
		{
			for (columnas = 0; columnas < 8; columnas++)
			{
				cout << miTablero[filas][columnas] << " " ;
			}

			cout << endl;
		}
}

void Tablero::hacerMatch()
{
	int filas,columnas;
	double *puntero; // de nuevo el puntero
	puntero = miTablero[0]; // De nuevo se le asigna la dirección de memoria.
	for (filas = 0; filas < 8; filas++)
		{
			for (columnas = 0; columnas < 8; columnas++)
			{
				puntero = &miTablero[filas][columnas];// Amarro el puntero a la posición de la matriz
				// El if compara el valor donde se encuentra el puntero con el valor de arriba y el de abajo. 
				if(*puntero == miTablero[filas + 1][columnas] and *puntero == miTablero[filas - 1][columnas])
				{
					*puntero = 0; // Si esto sucede el lugar donde está el puntero toma el valor de 0
					puntero = &miTablero[filas + 1][columnas]; //Muevo el puntero arriba
					*puntero = 0; // cambio a 0
					puntero = &miTablero[filas - 1][columnas]; // Muevo el puntero abajo
					*puntero = 0; //cambio a 0
				}
				if(*puntero == miTablero[filas][columnas + 1] and *puntero == miTablero[filas][columnas - 1]) 
				// ahora comparo con los lados derecha e izquierda
				{
					if (miTablero[filas][columnas + 1] != miTablero[filas + 1] [0] and miTablero[filas][columnas - 1] != miTablero[filas - 1] [7]) 
					//este if es necesario para que el programa no hiciera combinaciones saltando de linea, ya que si se hace columna +1 en la 
					// ultima columna se comparaba con el primer valor de la fila siguiente y si se hacia columna -1 en la primera columna, 
					// Se comparaba con el ultimo valor de la fila anterior.
					{
					*puntero = 0;
					puntero = &miTablero[filas][columnas - 1];
					*puntero = 0;
					puntero = &miTablero[filas][columnas + 1];
					*puntero = 0;
					}
				}


			}

		}

}
