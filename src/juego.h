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
	void disminuirRequerimientoTodoTipo(int tipo); 
	void disminuirRequerimientoTipo1(); // Cada uno de estos cuatro
	void disminuirRequerimientoTipo2(); // reducen en una unidad, los requerimientos
	void disminuirRequerimientoTipo3(); // de algún tipo, para terminar el nivel.
	void disminuirRequerimientoTipo4();

	int getNivel();
	int getRequerimientoTipo1();
	int getRequerimientoTipo2();
	int getRequerimientoTipo3();
	int getRequerimientoTipo4();
	

	

protected:

private:
	int requerimientoTipo1;
	int requerimientoTipo2;
	int requerimientoTipo3;
	int requerimientoTipo4;
	int nivel ; 
	// TIEMPO: NO SÉ DE QUÉ TIPO DEFINIRLO.
	
};

#endif // _JUEGO_H_
