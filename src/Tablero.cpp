#include "Tablero.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


Tablero::Tablero()
{
    tablero[8][8];
    //ctor
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::tableroInicial(int filas, int columnas)
{

    srand(time(NULL));

    int tablero2[F][C];


    for (int i = 0; i < filas;i++ )

    {
        for (int j = 0; j< columnas;j++)

        {
            int aleatorio = rand() % filas +1;

            tablero2[i][j] = aleatorio;

            cout<<" "<< tablero2[i][j];
        }
        cout <<endl;
    }


}

void Tablero::setTableroInicial(int matriz[F][C])
{
    tablero[F][C] = matriz[F][C];
}



void Tablero::getTableroInicial()
{
    cout <<tablero[8][8];
}

/* tablero::leerTableroDesdeTexto() : a partir de una archivo, imprime una cuadrícula
 * de 8x8. */
void Tablero::leerTableroDesdeTexto()
{
	ifstream nivel1 ("nivel1.txt"); //TIPO: ifstream, Nombre de Variable: Nivel1. 
	//Archivo Buscado: nivel1.txt

	if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
	{
		cerr << "ERROR AL ABRIR ARCHIVO" ;
		cout << endl; 
		exit(1);
	}


	
	int numero[64];

	int *puntero = NULL;
	
	for (int i = 0 ; i < 64 ; i++) // Ciclo FOR para guardar cada número de la matriz
		//en un arreglo.

	{
		nivel1 >> numero[i] ; // Guarda lo que haya en el archivo  nivel1.txt en
		//la posición i del arreglo numero[]. 

	/* trataba de instanciar las cajas desde aquí, pero me tira error diciendo
	 * algo como que se intenta hacer conversión de un puntero de caja a una caja 
	 * de tipo no-escalar -btw no entendí porqué -

		 Caja caja = new Caja();

		vectorDeCajas[i] = caja;
		
	*/
		
	}

	for (int i = 0 ; i < 64 ; i++)//Ciclo FOR para imprimir las componente del arreglo
		//numero[] y formar una cuadrícula de números.
	{
		if ( i % 8 == 0 && i != 0) // si la fila es divisible por 8, se imprime un salto de línea.
			cout << endl;
		
		
		puntero  = &numero[i]; //puntero apunta a la dirección en memoria de la componente i del arreglo.
		cout << (*puntero) << " ";  // se imprime lo señalado por el puntero.

		
	}


}







