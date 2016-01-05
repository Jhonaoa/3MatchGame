#include "Tablero.h"
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
using namespace std;


Tablero::Tablero()
{
    tablero[F][C];
    fila = 0;
    columna = 0;


    //ctor
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::setTableroInicial(int filas, int columnas)
{

        srand(time(NULL));


        for (int i = 0; i < filas;i++ )

    {
        for (int j = 0; j< columnas;j++)

        {
            int aleatorio = rand() % filas +1;

            tablero[i][j] = aleatorio;

        }

    }


}



void Tablero::getTableroInicial()
{
    int i,j;

    for (i = 0; i < 8; i++)
        {
            for(j = 0; j< 8; j++)
            {
                if (i == fila and j ==columna )
                {
                    matriz = &tablero[i][j];
                    cout<<"["<<*matriz<<"]";
                }else
                {
                    matriz = &tablero[i][j];
                    cout<<" "<<*matriz<<" ";
                }
            }
        cout<<endl;
        cout<<endl;
        }
}


void Tablero::moverseEnTablero()
{
    bool repeat = true;
    while(repeat)
        {


            if (kbhit())//se usa el comando kbhit() para permitir
                {       // la interacción del teclado durante la ejecución del programa
                    char ch = getch();//se usa el comando getch() para extraer qué tecla que
                        //fue usada y generar una acción mediante un switch.

                    switch (ch)
                        {
                            case 100:// moverse a la derecha 100 es la posición de la tecla "d"
                                    //en la tabla ASCCI

                                system("cls");//limpia la pantalla

                                columna += 1;//le suma uno al atributo columna e imprime
                                            //el tablero con el "seleccionador" en una posición distinta
                                Tablero::getTableroInicial();

                                if( fila ==7 and columna  == 8)//cuando llega a la posición [7][7], devuelve el seleccionador
                                                //a la primera posición [0][0]
                                    {
                                        system("cls");
                                        fila = 0;
                                        columna = 0;
                                        Tablero::getTableroInicial();
                                    }

                                if(columna == 8)//permite que al momento de llegar a última columna
                                    //de una fila distinta de 7, avance a la siguiente fila y ala primera columna
                                    {
                                        system("cls");
                                        fila += 1;
                                        columna = 0;
                                        Tablero::getTableroInicial();
                                    }

                            break;

                            case 97: //moverse a la izquierda 97 es la posición
                        //de la tecla "a" en la tabla ASCCI
                                system("cls");


                                if(fila == 0 and columna  == 0)//permite que al momento de presionar "izquierda"
                                            //estando en la primera posición de la tabla[0][0], el seleccionador vaya
                                            // al último [7][7].
                                    {
                                        system("cls");
                                        fila = 7;
                                        columna = 7;
                                        Tablero::getTableroInicial();
                                    }
                                        else if(fila != 0 and columna == 0)//permite que al momento de estar en una
                                        //fila distinta de 0 y columna = 0, alpresionar "izquierda" retroceda a la posición
                                        // [fila -1][columna = 7]

                                        {
                                            system("cls");
                                            fila -=1;
                                            columna = 7;
                                            Tablero::getTableroInicial();

                                        }
                                            else//retroceder una posición con respecto al número de columna.
                                                {
                                                    columna -= 1;
                                                    Tablero::getTableroInicial();
                                                }

                            break;

                            case 119:// moverse arriba 119 es la posición de la tecla "w"
                                //en la tabla ASCCI


                                if( fila == 0 )//permite que cuando el seleccionador está en la primera fila
                                //y se presiona "arriba" el seleccionador vaya de inmediato  la última fila
                                // pero en la misma columna
                                    {
                                        system("cls");
                                        fila = 7;
                                        Tablero::getTableroInicial();
                                    }

                                    else //permite moverse hacia arriba en el tablero, restándole 1 a
                                    //a el número de filas.
                                        {
                                            system("cls");
                                            fila -= 1;
                                            Tablero::getTableroInicial();
                                        }
                            break;

                            case 115: // moverse abajo 115 es la posición de la tecla "s"
                                //en la tabla ASCCI


                                if( fila == 7 )//permite que cuando el seleccionador se encuentre
                                //en la última fila y en cualquier columna , regrese a la primera fila
                                //en la columna en la que se encuentre.
                                    {
                                        system("cls");
                                        fila = 0;
                                        Tablero::getTableroInicial();
                                    }else//permite moverse hacia abajo sumándole 1 a filas.
                                        {
                                            system("cls");
                                            fila += 1;
                                            Tablero::getTableroInicial();
                                        }

                            break;
                        }
                    }
        //Sleep(1000);//disminuye el ritmo con el que los ciclos del bucle rotan
            }

}

/* tablero::leerTableroDesdeTexto() : a partir de una archivo, imprime una cuadrÃ­cula
 * de 8x8. */
/*void Tablero::leerTableroDesdeTexto(int *apuntador )
{
{

	
	int matriz[8][8];
	Caja matrizDeCajas[8][8];

	int *puntero =  &matriz[0][0];
	int variableSwitch = rand() % 3;
	
	switch (variableSwitch) /*Posibilidades de matriz inicial para el nivel 1 por medio de un switch
						En todas los casos posibles sea crea un IFSTREAM. pero en cada caso se accede
						a un archivo .txt diferente.*/
	{
		case 0:
		{ // caso en que numero aleatorio % 3 sea cero 
			
			ifstream nivel1 ("nivel1.txt"); //TIPO: ifstream, Nombre de Variable: Nivel1. 
											//Archivo Buscado: nivel1.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 1" ;
				cout << endl; 
				exit(1);
			}

			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
			//en un arreglo.

			{
			
				for (int j = 0 ; j < 8 ; j++)
				{
					nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.  */
				}
		
			}
		}
		break;
		
		case 1:
		{
			//caso en que numero aleatorio % 3 sea 1 
			
			ifstream nivel1 ("nivel1-2.txt");//TIPO: ifstream, Nombre de Variable: nivel1. 
											//Archivo Buscado: nivel1-2.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 2" ;
				cout << endl; 
				exit(1);
			}

			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
										//en un arreglo.

			{
				

				for (int j = 0 ; j < 8 ; j++)
				{
					nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.  */
				}
		
			}
		}
	
		break;

		case 2: 
		{//caso en que numero aleatorio % 3 sea 2:

			ifstream nivel1 ("nivel1-3.txt"); //TIPO: ifstream, Nombre de Variable: nivel1. 
											//Archivo Buscado: nivel1-3.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 3" ;
				cout << endl; 
				exit(1);
			}
		
			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
										//en un arreglo.

			{
				

				for (int j = 0 ; j < 8 ; j++)
				{
					nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.  */
				}
		
			}
		}
		break;
	}
	
/*
	for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
		//en un arreglo.

	{
		//nivel1 >> numero[i] ; 

	/* trataba de instanciar las cajas desde aquí, pero me tira error diciendo
	 * algo como que se intenta hacer conversión de un puntero de caja a una caja 
	 * de tipo no-escalar -btw no entendí porqué - 

		 Caja caja = new Caja();

		vectorDeCajas[i] = caja;
		
	

		for (int j = 0 ; j < 8 ; j++)
		{
			nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.  
		}
		
	}
*/
			
	for (int i = 0 ; i < 8 ; i++)//Ciclo FOR para imprimir las componente del arreglo
		//numero[] y formar una cuadrícula de números.
	{
		
		
		for (int j = 0; j < 8 ; j++)
		{
			puntero  = &matriz[i][j]; //puntero apunta a la dirección en memoria de la componente (i.j) de la matriz.

			//Caja caja = new Caja();
			//matrizDeCajas[i][j] = caja ;
			cout << (*puntero) << " ";  // se imprime lo señalado por el puntero.

		}

		cout << endl;
	}


}



} */

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

void Tablero::bajarMatriz()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.

	double *puntero;

	for (filas = 7; filas >= 0; filas--)
	{
		for (columnas = 0; columnas < 8; columnas++)
		{
			puntero = &miTablero[filas][columnas];//En cada iteración, amarro el puntero a la posición por la que vayan las variables filas, columnas.
			if (*puntero == 0)
			{
				int contador = 0;
				for (int j = 0; j >= 0; j--)
		{
					contador++;
					
		}
				for (int i = filas; i > 0; i--)
				{
					
					puntero = &miTablero[i][columnas];
					*puntero = miTablero[i-1][columnas];

				}

			}
		}
	}
}






