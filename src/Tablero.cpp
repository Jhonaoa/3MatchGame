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

void Tablero::llenarTablero()// Lo creé para poner generar un tablero aleatorio de prueba.
{

	int filas, columnas;
	double *puntero;


	for (filas = 0; filas < 8; filas++)
	{
		for (columnas = 0; columnas < 8; columnas++)
		{
			puntero = &miTablero[filas][columnas];
			*puntero = 1 + rand() % 4;
		}

	}
}


void Tablero::getTablero() //Imprime el tablero.
{
	int filas, columnas;
	for (filas = 0; filas < 8; filas++)
		{
			for (columnas = 0; columnas < 8; columnas++)
			{
				cout << miTablero[filas][columnas] << " " ;
			}

			cout << endl;
		}
}

void Tablero::hacerMatch() //3match
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	double *puntero;

	for (filas = 0; filas < 8; filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < 8; columnas++) //for interno para las columnas
		{
			puntero = &miTablero[filas][columnas];//En cada iteración, amarro el puntero a la posición por la que vayan las variables filas, columnas.

			//Primero el programa comprueba si hay alguna cruz.
			//           0
			//          000
			//           0
			if(*puntero == miTablero[filas + 1][columnas] and *puntero == miTablero[filas - 1][columnas] and
			*puntero == miTablero[filas][columnas + 1] and *puntero == miTablero[filas][columnas - 1])
			//Este if comprueba si las posiciones a la izq, der, arriba, abajo, son iguales a la del lugar donde se encuentra el puntero.
			{
				if (columnas == 0 or columnas == 7) // Algunas veces los match horizontales causaban problemas, ya que al hacer columna +1 en
					// la ultima columna o hacer columna - 1 en la primera columna hacia que saltara de fila, así que tomamos los casos en los que
					// columnas es 0 (primera columna) o columnas es 7 (ultima columna).
				{
					if (miTablero[filas][columnas + 1] != miTablero[filas + 1] [0] and miTablero[filas][columnas - 1] != miTablero[filas - 1] [7])
						// Comprueba que el valor en la ultima columna no sea igual al primero de la siguiente fila
						// o que el valor en la primera columna no sea igual al ultimo de la fila anterior.
						// Si no pasa esto debe hacer el match.
					{
						//Muevo el puntero y cambio a 0 las casillas correspondientes.
						*puntero = 0;
						puntero = &miTablero[filas][columnas - 1];
						*puntero = 0;
						puntero = &miTablero[filas][columnas + 1];
						*puntero = 0;
						puntero = &miTablero[filas + 1][columnas];
						*puntero = 0;
						puntero = &miTablero[filas - 1][columnas];
						*puntero = 0;
					}
				}
				else //Si no está en la columna final o en la columna inicial, es porque es un match normal.
				{
					*puntero = 0;
					puntero = &miTablero[filas][columnas - 1];
					*puntero = 0;
					puntero = &miTablero[filas][columnas + 1];
					*puntero = 0;
					puntero = &miTablero[filas + 1][columnas];
					*puntero = 0;
					puntero = &miTablero[filas - 1][columnas];
					*puntero = 0;
				}

				}

			//Ahora el programa hace los match verticales
			if(*puntero == miTablero[filas + 1][columnas] and *puntero == miTablero[filas - 1][columnas])
			{
				*puntero = 0;
				puntero = &miTablero[filas + 1][columnas];
				*puntero = 0;
				puntero = &miTablero[filas - 1][columnas];
				*puntero = 0;
			}

			// Y por ultimo los match horizontales, aquí se hace lo mismo que en el de la cruz para solucionar el problema de el columna +1 y columna - 1.
			if(*puntero == miTablero[filas][columnas + 1] and *puntero == miTablero[filas][columnas - 1])
			{
				if (columnas == 0 or columnas == 7)
				{
					if (miTablero[filas][columnas + 1] != miTablero[filas + 1] [0] and miTablero[filas][columnas - 1] != miTablero[filas - 1] [7])
					{
						*puntero = 0;
						puntero = &miTablero[filas][columnas - 1];
						*puntero = 0;
						puntero = &miTablero[filas][columnas + 1];
						*puntero = 0;
					}
				}
				else
				{
					*puntero = 0;
					puntero = &miTablero[filas][columnas - 1];
					*puntero = 0;
					puntero = &miTablero[filas][columnas + 1];
					*puntero = 0;
				}
			}
		}
		}
}







