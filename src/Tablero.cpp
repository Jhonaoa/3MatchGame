#include "Tablero.h"
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <iostream>
#include<windows.h>
using namespace std;


Tablero::Tablero()
{
    tablero[F][C];
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

    matriz = &tablero2[0][0];

}

void Tablero::setTableroInicial()
{
    for (int i = 0; i < 8; i++)
        {
            cout <<*matriz <<endl;
            matriz++;
        }
}


/*void Tablero::moverseEnTablero()
{
    bool repeat = true;
    while(repeat)
    {


         if (kbhit())//se usa el comando kbhit() para permitir la interacción
        {            // la interacción del teclado durante la ejecución del programa
            char ch = getch();//se usa el comando getch() para extraer qué tecla
            switch (ch)         //fue usada y generar una acción mediante un switch.
            {
                case 27:// 27 es la posición de la tecla esc en la tabla ASCCI
                    repeat = false;
                    break;
                case 32: // 32 es la posición de la tecla space en la tabla ASCCI
                    //fotos = 0;
                    break;
            }
        }
        Sleep(1000);//disminuye el ritmo con el que los ciclos del bucle rotan
    }

}*/

/* tablero::leerTableroDesdeTexto() : a partir de una archivo, imprime una cuadrÃ­cula
 * de 8x8. */
void Tablero::leerTableroDesdeTexto(int *apuntador )
{
		ifstream nivel1 ("nivel1.txt"); //TIPO: ifstream, Nombre de Variable: Nivel1. 
	//Archivo Buscado: nivel1.txt

	if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
	{
		cerr << "ERROR AL ABRIR ARCHIVO" ;
		cout << endl; 
		exit(1);
	}


	
	

	int matriz[8][8];

	int *puntero =  &matriz[0][0];

	
	
	for (int i = 0 ; i < 64 ; i++) // Ciclo FOR para guardar cada número de la matriz
		//en un arreglo.

	{
		//nivel1 >> numero[i] ; 

	/* trataba de instanciar las cajas desde aquí, pero me tira error diciendo
	 * algo como que se intenta hacer conversión de un puntero de caja a una caja 
	 * de tipo no-escalar -btw no entendí porqué -

		 Caja caja = new Caja();

		vectorDeCajas[i] = caja;
		
	*/

		for (int j = 0 ; j < 8 ; j++)
		{
			nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.  */
		}
		
	}

	for (int i = 0 ; i < 8 ; i++)//Ciclo FOR para imprimir las componente del arreglo
		//numero[] y formar una cuadrícula de números.
	{
		if ( i % 8 == 0 && i != 0) // si la fila es divisible por 8, se imprime un salto de línea.
			cout << endl;
		
		for (int j = 0; j < 8 ; j++)
		{
			puntero[i][j]  = &matriz[i][j]; //puntero apunta a la dirección en memoria de la componente (i.j) de la matriz.
			cout << (*puntero) << " ";  // se imprime lo señalado por el puntero.

		}
	}



}







