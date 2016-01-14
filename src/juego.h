
 

/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * juego.h
 * Copyright (C) 2016 Jhon Alejandro Orobio <alejo@alejo-OEM>
 *
 * 3matchgameubuntu is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3matchgameubuntu is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 	 /*
	 Clase: Juego: 
	 Responsabilidad: mostrar las caracteristica que componen un juego. un juego contará con
		 un nivel
		 4 tipos de requerimientos para completar el nivel.
		 un tiempo, que en caso de terminarse, finalizará el nivel.
	Además se puede disminuir en una unidad la cantidad de cada uno de estos requerimientos
	y se les puede asignar un valor inicial.

	Colaboración: Ninguna.
 */

#ifndef _JUEGO_H_
#define _JUEGO_H_

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <time.h>

 
using namespace std;
class Juego
{
public: 
	Juego();
	~Juego();
	void setTipo1(int requerido); //Estos determinan qué tantos requerimientos hay que 
	void setTipo2(int requerido); // cumplir por nivel para finalizarlo.
	void setTipo3(int requerido); // La cantidad mencionada entra como argumento.
	void setTipo4(int requerido);
	void setNivel(int lv);
	void disminuirRequerimientoTodoTipo(int tipo); 
	void disminuirRequerimientoTipo1(); // Cada uno de estos cuatro
	void disminuirRequerimientoTipo2(); // reducen en una unidad, los requerimientos
	void disminuirRequerimientoTipo3(); // de algún tipo, para terminar el nivel.
	void disminuirRequerimientoTipo4();
	void reloj();
	int getNivel();
	int getTiempo();
	void setTiempo(int segundos);
	int getRequerimientoTipo1();
	int getRequerimientoTipo2();
	int getRequerimientoTipo3();
	int getRequerimientoTipo4();
	bool requerimientosCumplidos ();
	
	

	

protected:

private:
	int requerimientoTipo1;
	int requerimientoTipo2;
	int requerimientoTipo3;
	int requerimientoTipo4;
	int nivel; 
	int tiempo; 
	
};
#endif // _JUEGO_H_
