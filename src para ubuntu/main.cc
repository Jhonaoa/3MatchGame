/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2016 JHON ALEJANDRIO OROBIO ARCE <jhonaoa@s3pc24>
 * 
 * 3MatchGame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3MatchGame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include <iostream>
#include "tablero.h"


using namespace std;

int main()
{


        Tablero miTablero;
        Tablero *puntero;

        puntero = &miTablero;




   		(*puntero).leerTableroDesdeTexto();
        (*puntero).getTableroInicial();
		cout<<endl;

		(*puntero).moverseEnTablero();
		/*(*puntero).hacerMatch();
		cout<<endl;
		(*puntero).getTableroInicial();
		cout<<endl;


        (*puntero).moverseEnTablero();

        //miTablero.getTableroInicial();
        //cout<<endl;


        //miTablero.moverseEnTablero();
/*<<<<<<< HEAD


=======
    //miTablero.getTableroInicial();

    srand (time (NULL));
	Tablero unTablero;
	unTablero.llenarTablero();
	unTablero.getTablero();
	cout << endl;
	unTablero.hacerMatch();
	unTablero.getTablero();
>>>>>>> 02168c7d3795e9171602fa3ed03524de4286426d*/



    return 0;
}
