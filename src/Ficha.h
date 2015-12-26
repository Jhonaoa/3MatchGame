 /*
 * Clase: Ficha
 * 
 * Responsabilidad: Representar una ficha en un juego de hacer coincidir fichas similares.
 * Las fichas cuentan con :
 *			Un número asociado al puntaje dado al hacer coincidir la ficha con otras 2 similares como mínimo.
 *			Un número que indica qué animal representa la ficha o si representa una ficha vacía.
 *			Un estado liberado, que indica si el animal representado se encuentra liberado o no.
 * Adicionalmente las fichas pueden: 
 *			Generar un puntaje en el juego.
 *			Modificar el animal al que representan.
 *			Modificar el puntaje que pueden generar en el juego.
 *			
 */

#ifndef _FICHA_H_
#define _FICHA_H_

class Ficha 
{
public:
	enum Animal {Vacio , Koala, Mico, Pez, Rana}; //Posibles animales a representar por una ficha.
	
	Ficha( int numero); // el número es aleatorio y  determina qué animal representa.
	~Ficha();
	Animal getAnimal() ; 

	void setLiberado(); 
	void setNumeroPuntaje(double aumentaPuntaje); //para el 4match 
	void setNumeroAnimal(int nuevo ); /* se debe almacenar el valor anterior, para poderlo
												asignar a la ficha de la fila superior. en este caso por Referencia.
												(base para reasignar fichas después del match)*/
	 
	
	
protected:

private:
	
	int numeroAnimal; // Cada número del 0 a cinco está asociado con un animal, 
					  //excepto el 0, que representa un vacío.

	int numeroPuntaje; //Valor de puntos obtenidos al liberar esta ficha.
	bool liberado;
	Animal miAnimal;
	

};

#endif // _FICHA_H_

