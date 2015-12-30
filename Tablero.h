/*
 * Tablero.h
 *
 *  Created on: 30/12/2015
 *      Author: Jhoan Sebastián
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "stdlib.h"
#include <cstdlib>


class Tablero {
public:
	Tablero();
	~Tablero();
	void llenarTablero ();
	void getTablero();
	void hacerMatch();


private:
	double miTablero[8][8];


};

#endif /* TABLERO_H_ */
