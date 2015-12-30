//============================================================================
// Name        : 3Match.cpp
// Author      : Sebastián Villegas
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Tablero.h"


int main()

{
	srand (time (NULL));
	Tablero unTablero;
	unTablero.llenarTablero();
	unTablero.getTablero();
	cout << endl;
	unTablero.hacerMatch();
	unTablero.getTablero();

}
