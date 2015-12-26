 /*
 * Clase: Liberados
 * 
 * Responsabilidad: Representar y contabilizar los animales de cada tipo que deben 
 * ser liberados en el juego para cumplir con el nivel planteado.
 * Se cuenta :
 *			Una cantidad de animales de cada tipo que faltan por ser liberados.
 * y además se puede: 
 *			Disminuir en una unidad la cantidad de animales de cualquier tipo que resten por liberar
 *			Retornar si ya se ha cumplido con el mínimo de animales liberados de cada tipo o no
 * 
 * Colaboración: nose
 */

#ifndef _LIBERADOS_H_
#define _LIBERADOS_H_

class Liberados
{
public:
	Liberados();
	~Liberados(); 
	void setAnimal1Liberado(); //Decrementa en uno la cantidad de animales tipo 1 que deben ser liberados
	void setAnimal2Liberado(); //Decrementa en uno la cantidad de animales tipo 2 que deben ser liberados
	void setAnimal3Liberado(); //Decrementa en uno la cantidad de animales tipo 3 que deben ser liberados
	void setAnimal4Liberado(); //Decrementa en uno la cantidad de animales tipo 4 que deben ser liberados

	bool cumplidoAnimal1();
	bool cumplidoAnimal2(); 
	bool cumplidoAnimal3();
	bool cumplidoAnimal4();
	
	

protected:

private:
	int animal1PorLiberar;
	int animal2PorLiberar;
	int animal3PorLiberar;
	int animal4PorLiberar;
	

};

#endif // _LIBERADOS_H_

