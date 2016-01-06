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
                        int aleatorio = rand() % 5 +1;

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
    while(repeat)//se usa un ciclo while para mantener la interacción con el teclad
    //activa hasta que se requiera.
        {


            if (kbhit())//se usa el comando kbhit() para permitir
                {   // la interacción del teclado durante la ejecución del programa
                    char ch = getch();//se usa el comando getch() para extraer qué tecla que
                        //fue usada y generar una acción mediante un switch.

                    switch (ch)//se usa un switch case, para separar las distintas interacciones del teclado
                    // y  así lograr que solo se genere la acción que necesitamos.
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

                            case 32://selccionar ficha a mover. 32 es la posición de la tecla
                            //espacio en la tabla ASSCI


                                matriz = &tablero[fila][columna];//se iguala el puntero "matriz" a la posición
                                //actual del seleccionador "[]" y se almacena el contenido en el
                                //atributo "aCambiar1"
                                aCambiar1 = *matriz;//almacena el conteniido del puntero matriz en el
                                //atributo aCambiar1

                                //declaración de variables auxiliares

                                 bool repetir = true;
                                 int moverColumnaD = columna + 1;
                                 int moverColumnaI = columna - 1;
                                 int moverArriba = fila -1 ;
                                 int moverAbajo = fila + 1 ;



                                 while(repetir)//se usa un ciclo while para mantener la interacción con el teclado
                                        //activa hasta que se requiera.
                                 {

                                    if (kbhit())//se usa el comando kbhit() para permitir
                                    // la interacción del teclado durante la ejecución del programa
                                    {
                                        char ch2 = getch();//se usa el comando getch() para extraer qué tecla
                                        //fue usada y generar una acción mediante un switch.


                                        switch(ch2)//se usa un switch case, para separar las distintas interacciones del teclado
                                                    // y  así lograr que solo se genere la acción que necesitamos.
                                            {
                                                case 100://al oprimir la "d" en el teclado se genera la acción de cambiar
                                                // la ficha inmediatamente siguiente que está a la derecha
                                                    system("cls");
                                                    if(columna == 7)//este condicional se usa para evitar que una ficha que
                                                    //está en el borde derecho inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover a la derecha"<<endl;//devuelve un aviso
                                                        Tablero::getTableroInicial();//devuelve el tablero otra vez

                                                    }else
                                                        {


                                                            matriz = &tablero[fila][moverColumnaD];//señala el puntero matriz a la posición a la derecha de la actual
                                                            aCambiar2 = *matriz;//alamacena el contenido de matriz en el atributo "aCambiar2"
                                                            *matriz = aCambiar1;//cambia el contenido del puntero matriz por el almacenado en aCambiar1
                                                            matriz = &tablero[fila][columna];//señala el puntero matriz a la posición que fue seleccionada

                                                            *matriz = aCambiar2;//cambia el contenido del puntero matriz por el de aCambiar2
                                                            Tablero::getTableroInicial();//imprime el tablero con los cambios realizados

                                                            repetir = false;//le da el valor a la variable repetir de false, para que salga del ciclo
                                                        }
                                                    break;


                                                case 97://izquierda
                                                    system("cls");
                                                    if(columna == 0)//este condicional se usa para evitar que una ficha que
                                                    //está en el borde izquierdo inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover a la izquierda"<<endl;//al oprimir la "a" en el teclado se genera la acción de cambiar
                                                            // la ficha inmediatamente siguiente que está a la izquierda
                                                        Tablero::getTableroInicial();//imprime el tablero otra vez

                                                    }else
                                                        {

                                                            //el mismo procedimiento del case 100:


                                                            matriz = &tablero[fila][moverColumnaI];
                                                            aCambiar2 = *matriz;
                                                            *matriz = aCambiar1;
                                                            matriz = &tablero[fila][columna];
                                                            *matriz = aCambiar2;
                                                            Tablero::getTableroInicial();

                                                            repetir = false;
                                                        }
                                                    break;

                                                case 119://arriba
                                                    system("cls");
                                                    if(fila == 0)//este condicional se usa para evitar que una ficha que
                                                    //está en el borde superior inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover arriba"<<endl;//al oprimir la "w" en el teclado se genera la acción de cambiar
                                                            // la ficha inmediatamente siguiente que está arriba
                                                        Tablero::getTableroInicial();

                                                    }else
                                                        {
                                                            //el mismo procedimiento del case 100:


                                                            matriz = &tablero[moverArriba][columna];
                                                            aCambiar2 = *matriz;
                                                            *matriz = aCambiar1;
                                                            matriz = &tablero[fila][columna];
                                                            *matriz = aCambiar2;
                                                            Tablero::getTableroInicial();

                                                            repetir = false;
                                                        }
                                                    break;

                                                case 115://abajo
                                                    system("cls");
                                                    if(fila == 7)//este condicional se usa para evitar que una ficha que
                                                    //está en el borde inferior inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover abajo"<<endl;//al oprimir la "s" en el teclado se genera la acción de cambiar
                                                            // la ficha inmediatamente siguiente que está abajo
                                                        Tablero::getTableroInicial();//imprime el tablero otra vez

                                                    }else
                                                        {
                                                            //el mismo procedimiento del case 100:


                                                            matriz = &tablero[moverAbajo][columna];
                                                            aCambiar2 = *matriz;
                                                            *matriz = aCambiar1;
                                                            matriz = &tablero[fila][columna];
                                                            *matriz = aCambiar2;
                                                            Tablero::getTableroInicial();

                                                            repetir = false;
                                                        }
                                                    break;


                                    }
                                }

                        }
                    }
        //Sleep(1000);//disminuye el ritmo con el que los ciclos del bucle rotan
            }

    }
}
/* tablero::leerTableroDesdeTexto() : a partir de una archivo, imprime una cuadrÃ­cula
 * de 8x8. */
/*void Tablero::leerTableroDesdeTexto(int *apuntador )
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

		/*for (int j = 0 ; j < 8 ; j++)
		{
			nivel1 >> matriz[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.
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







