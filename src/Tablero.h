#ifndef TABLERO_H
#define TABLERO_H

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
//#include<windows.h>
#include<stdio.h>
//#include<conio.h>
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

#endif // TABLERO_H
