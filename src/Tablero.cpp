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







