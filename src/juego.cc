
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
