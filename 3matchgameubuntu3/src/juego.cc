/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * juego.cc
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
 */

#include "juego.h"

//Constructor:
Juego::Juego()
{
	requerimientoTipo1 = 100;
	requerimientoTipo2 = 100;  //Cada uno de los 4 requerimientos se inicializa
	requerimientoTipo3 = 100;   // Con un valor no nulo.
	requerimientoTipo4 = 100;
}

// Destructor.
Juego::~Juego()
{
}


/* void Juego::setTipo1(int) : Iguala el atributo requerimientoTipo1 al valor de entrada como argumuneto */
void Juego::setTipo1(int requerido)
{
	requerimientoTipo1 = requerido; 
}

/* void Juego::setTipo2(int) : Iguala el atributo requerimientoTipo2 al valor de entrada como argumuneto */
void Juego::setTipo2(int requerido)
{
	requerimientoTipo2 = requerido;
}

/* void Juego::setTipo3(int) : Iguala el atributo requerimientoTipo3 al valor de entrada como argumuneto */
void Juego::setTipo3(int requerido)
{
	requerimientoTipo3 = requerido;
}

/* void Juego::setTipo4(int) : Iguala el atributo requerimientoTipo4 al valor de entrada como argumuneto */
void Juego::setTipo4(int requerido) 
{
	requerimientoTipo4 = requerido;
}
/* void Juego::disminuirRequerimientoTipo1(): Disminuye en una unidad el valor del atributo
 * requerimientoTipo1 */
 
 void Juego::setNivel(int lv)
{
	nivel = lv;
}

void Juego::disminuirRequerimientoTipo1()
{
	requerimientoTipo1--;
}

/* void Juego::disminuirRequerimientoTipo2(): Disminuye en una unidad el valor del atributo
 * requerimientoTipo2 */
void Juego::disminuirRequerimientoTipo2()
{
	requerimientoTipo2--;
}

/* void Juego::disminuirRequerimientoTipo3(): Disminuye en una unidad el valor del atributo
 * requerimientoTipo3 */
void Juego::disminuirRequerimientoTipo3()
{ 
	requerimientoTipo3--;
}

/* void Juego::disminuirrequerimientoTipo4(): Disminuye en una unidad el valor del atributo
 * requerimientoTipo4 */
void Juego::disminuirRequerimientoTipo4()
{
	requerimientoTipo4--;
}

/* void Juego::disminuirRequerimientoTodoTipo(int) Disminuye en una unidad el valor de alguno de 
los 4 requerimientos, de acuerdo a lo que se indique en el valor que entra como argumento. */
void Juego::disminuirRequerimientoTodoTipo(int tipo)
{
	switch (tipo)/*Por medio de la instrucción switch se verifica cuál de los requermientos debe 
		 * disminuirse, y se llama al método correspondiente al caso. */
	{
		case 1: 
	
		Juego::disminuirRequerimientoTipo1();
	
		break;
		
		case 2: 
	
			Juego::disminuirRequerimientoTipo2();
	
		break; 

		case 3: 
	
			Juego::disminuirRequerimientoTipo3();
	
		break; 

		case 4: 
	
			Juego::disminuirRequerimientoTipo4(); 
	
		break; 
	}
		
}

int Juego::getRequerimientoTipo1()
{
	return requerimientoTipo1;
}

int Juego::getRequerimientoTipo2()
{
	return requerimientoTipo2;
}

int Juego::getRequerimientoTipo3()
{
	return requerimientoTipo3;
}

int Juego::getRequerimientoTipo4()
{
	return requerimientoTipo4;
}

int Juego::getNivel()
{
	return nivel;

}

























