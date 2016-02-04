
#include "ficha.h"

/* Constructor Ficha: el parámetro numero se genera de manera aleatoria
 al construir una ficha. */

Ficha::Ficha( int numero) 
{
	numeroAnimal = numero; 
	liberado = false ;
	
}

//Destructor
Ficha::~Ficha()
{
}


/*Ficha::setLiberado(): cuando se hace un match, cambia a TRUE estado de liberado
de la ficha */

void Ficha::setLiberado()
{
	liberado = true;
}

/* setNumeroPuntaje(double aumentaPuntaje): Incrementa en puntaje de la ficha al liberar
el animal, tras hacer un 4Match contiguo. */
void Ficha::setNumeroPuntaje(double aumentaPuntaje)
{
	numeroPuntaje += aumentaPuntaje; //Se puede manejar por parámetro o puede ser un cantidad fija.
}


/* setNumeroAnimal(int nuevo) : modifica el atributo número animal, igualándolo a 
una atributo ingresado como parámetro. */

void Ficha::setNumeroAnimal(int nuevo)
{
	numeroAnimal = nuevo; /* el número animal debe guardarse, para poder asignarlo 
	 * a las fichas de arriba al hacer el match */
}

