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

	int filas, columnas;
	double *puntero;
	puntero = miTablero[0];

	for (filas = 0; filas < 8; filas++)
	{
		for (columnas = 0; columnas < 8; columnas++)
		{
			puntero = &miTablero[filas][columnas];
			*puntero = 1 + rand() % 4;
		}

	}
}


void Tablero::getTablero()
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
	double *puntero;
	puntero = miTablero[0];
	for (filas = 0; filas < 8; filas++)
		{
			for (columnas = 0; columnas < 8; columnas++)
			{
				puntero = &miTablero[filas][columnas];
				if(*puntero == miTablero[filas + 1][columnas] and *puntero == miTablero[filas - 1][columnas])
				{
					*puntero = 0;
					puntero = &miTablero[filas + 1][columnas];
					*puntero = 0;
					puntero = &miTablero[filas - 1][columnas];
					*puntero = 0;
				}
				if(*puntero == miTablero[filas][columnas + 1] and *puntero == miTablero[filas][columnas - 1])
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
