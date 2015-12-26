
#include "liberados.h"

Liberados::Liberados()
{
	animal1PorLiberar = 10; //se asigna la cantidad que hay que liberar para que el usuario cumpla con el req. del nivel.
	animal2PorLiberar = 10; //se asigna la cantidad que hay que liberar para que el usuario cumpla con el req. del nivel.
	animal3PorLiberar = 10; //se asigna la cantidad que hay que liberar para que el usuario cumpla con el req. del nivel.
	animal4PorLiberar = 10; //se asigna la cantidad que hay que liberar para que el usuario cumpla con el req. del nivel.
}



Liberados::~Liberados()
{
}


 /* Liberados::serAnimal1Liberado(): Disminuye en uno el valor del atributo animal1Porliberar .
*/
void Liberados::setAnimal1Liberado()
{
	animal1PorLiberar--;
}
 /* Liberados::serAnimal2Liberado(): Disminuye en uno el valor del atributo animal2Porliberar .
*/
void Liberados::setAnimal2Liberado()
{
	animal2PorLiberar--;
}

 /* Liberados::serAnimal3Liberado(): Disminuye en uno el valor del atributo animal3Porliberar .
*/
void Liberados::setAnimal3Liberado()
{
	animal3PorLiberar--;
}
 /* Liberados::serAnimal4Liberado(): Disminuye en uno el valor del atributo animal4Porliberar .
*/
void Liberados::setAnimal4Liberado()
{
	animal4PorLiberar--;
}


/*Liberados::cumplidoAnimal1():  Retorna True cuando el valor del atributo animal1porLiberar 
es menor a 0, es decir cuando no es requerido liberar más animales de este tipo. Si no se cumple
la condición, se retorna False. */

bool Liberados::cumplidoAnimal1()
{
	if(animal1PorLiberar <= 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Liberados::cumplidoAnimal2():  Retorna True cuando el valor del atributo animal2porLiberar 
es menor a 0, es decir cuando no es requerido liberar más animales de este tipo. Si no se cumple
la condición, se retorna False. */
bool Liberados::cumplidoAnimal2()

{
	if (animal2PorLiberar <= 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/*Liberados::cumplidoAnimal3():  Retorna True cuando el valor del atributo animal3porLiberar 
es menor a 0, es decir cuando no es requerido liberar más animales de este tipo. Si no se cumple
la condición, se retorna False. */
bool Liberados::cumplidoAnimal3()
{
	if(animal3PorLiberar <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*Liberados::cumplidoAnimal4():  Retorna True cuando el valor del atributo animal4porLiberar 
es menor a 0, es decir cuando no es requerido liberar más animales de este tipo. Si no se cumple
la condición, se retorna False. */
bool Liberados::cumplidoAnimal4()
{
	if(animal4PorLiberar <= 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}



