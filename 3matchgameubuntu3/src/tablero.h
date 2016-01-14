/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * 3matchgame
 * Copyright (C) JHON ALEJANDRIO OROBIO ARCE 2016 <jhonaoa@s3pc24>
 * 
3matchgame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3matchgame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TABLERO_H_
#define _TABLERO_H_

#define F 8
#define C 8
#include "caja.h"
#include"juego.h"
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include<stdio.h>

using namespace std;

class Tablero
{
    public:

        Tablero();
        ~Tablero();

        void setTableroInicial();

        void getTableroInicial();

        void moverseEnTablero(Juego &game);

       bool operator == (Caja cajaSiguiente);

        void leerTableroDesdeTexto(Juego &game);

		int kbhit(void);

		void matchCruz(Juego &juego);

		void matchVertical(Juego &juego);

		void matchHorizontal(Juego &juego);

		void hacerMatch(Juego &juego );

		bool ceroAbajo();

		void bajarMatriz();

		void guardarTableroEnArchivo(Juego &juego) ;
		
		void llenarPrimeraColumna();

		bool hayCero();

		void rellenarMatriz();

		bool hayMatch();

		void matchTotal(Juego &game);

		

		




        void llenarTablero ();
        void getTablero();
        



    protected:
    private:


        Caja **tablero;
	
        int fila;
        int columna;
        int aCambiar1;
        int aCambiar2;
        Caja *matriz;
		



        


};

#endif // _TABLERO_H_
