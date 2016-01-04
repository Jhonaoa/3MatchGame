/*
 * Tablero.h
 *
 *  Created on: 30/12/2015
 *      Author: Jhoan Sebastián
 * Como les digo, luego veo como hacerlo entre clases, quería entenderlo primero.
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "stdlib.h"
#include <cstdlib>


class Tablero {
public:
	Tablero();
	~Tablero();
	void llenarTablero (); // Este metodo lo cree para llenar el tablero con números aleatorios.
	void getTablero(); // Para mostrar el tablero completo.
	void hacerMatch(); //Ya el metodo del match


private:
	double miTablero[8][8]; //Defino la matriz aqui.


};

#endif /* TABLERO_H_ */
