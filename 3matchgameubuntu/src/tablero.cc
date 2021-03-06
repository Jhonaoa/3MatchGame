/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * 3matchgame
 * Copyright (C) JHON ALEJANDRIO OROBIO ARCE 2016 <jhonaoa@s3pc24>
 *
3matchgame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * 3matchgame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along*/


#include "tablero.h"



Tablero::Tablero()
{
    tablero = new int* [F];

	for(int i = 0; i < F;i++ )
	{
		tablero[i] = new int[C];
	}

	fila = 0;
    columna = 0;


    //ctor
}

Tablero::~Tablero()
{

}




void Tablero::getTableroInicial()
{
    int i,j;

    for (i = 0; i < 8; i++)
        {
            for(int k = 0; k< 8;k++)
            {
                cout<<"-----";
            }
            cout<<endl;


            for(j = 0; j< 8; j++)
            {


                if (i == fila and j ==columna )
                {
                    cout<<"[ "<<tablero[i][j]<<" ]";
                }else
                {

					cout<<"  "<<tablero[i][j]<<"  ";
                }
            }
        cout<<endl;
        cout<<endl;
        }


}


int Tablero::kbhit(void)
{
	struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
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
                    char ch = getchar();//se usa el comando getch() para extraer qué tecla que
                        //fue usada y generar una acción mediante un switch.

                    switch (ch)//se usa un switch case, para separar las distintas interacciones del teclado
                    // y  así lograr que solo se genere la acción que necesitamos.
                        {
                            case 100:// moverse a la derecha 100 es la posición de la tecla "d"
                                    //en la tabla ASCCI

                                system("clear");//limpia la pantalla

                                columna += 1;//le suma uno al atributo columna e imprime
                                            //el tablero con el "seleccionador" en una posición distinta
                                Tablero::getTableroInicial();

                                if( fila ==7 and columna  == 8)//cuando llega a la posición [7][7], devuelve el seleccionador
                                                //a la primera posición [0][0]
                                    {
                                        system("clear");
                                        fila = 0;
                                        columna = 0;
                                        Tablero::getTableroInicial();
                                    }

                                if(columna == 8)//permite que al momento de llegar a última columna
                                    //de una fila distinta de 7, avance a la siguiente fila y ala primera columna
                                    {
                                        system("clear");
                                        fila += 1;
                                        columna = 0;
                                        Tablero::getTableroInicial();
                                    }

                            break;

                            case 97: //moverse a la izquierda 97 es la posición
                        //de la tecla "a" en la tabla ASCCI
                                system("clear");


                                if(fila == 0 and columna  == 0)//permite que al momento de presionar "izquierda"
                                            //estando en la primera posición de la tabla[0][0], el seleccionador vaya
                                            // al último [7][7].
                                    {
                                        system("clear");
                                        fila = 7;
                                        columna = 7;
                                        Tablero::getTableroInicial();
                                    }
                                        else if(fila != 0 and columna == 0)//permite que al momento de estar en una
                                        //fila distinta de 0 y columna = 0, alpresionar "izquierda" retroceda a la posición
                                        // [fila -1][columna = 7]

                                        {
                                            system("clear");
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
                                        system("clear");
                                        fila = 7;
                                        Tablero::getTableroInicial();
                                    }

                                    else //permite moverse hacia arriba en el tablero, restándole 1 a
                                    //a el número de filas.
                                        {
                                            system("clear");
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
                                        system("clear");
                                        fila = 0;
                                        Tablero::getTableroInicial();
                                    }else//permite moverse hacia abajo sumándole 1 a filas.
                                        {
                                            system("clear");
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
                                        char ch2 = getchar();//se usa el comando getch() para extraer qué tecla
                                      //fue usada y generar una acción mediante un switch.


                                        switch(ch2)//se usa un switch case, para separar las distintas interacciones del teclado
                                                    // y  así lograr que solo se genere la acción que necesitamos.
                                            {
                                                case 100://al oprimir la "d" en el teclado se genera la acción de cambiar
                                                // la ficha inmediatamente siguiente que está a la derecha
                                                    system("clear");
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

															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");

                                                        		matriz = &tablero[fila][columna];//señala el puntero matriz a la posición a la derecha de la actual
                                                        		aCambiar2 = *matriz;//alamacena el contenido de matriz en el atributo "aCambiar2"
                                                        		*matriz = aCambiar1;//cambia el contenido del puntero matriz por el almacenado en aCambiar1
                                                        		matriz = &tablero[fila][moverColumnaD];//señala el puntero matriz a la posición que fue seleccionada

                                                        		*matriz = aCambiar2;//cambia el contenido del puntero matriz por el de aCambiar2
                                                        		Tablero::getTableroInicial();//imprime el tablero con los cambios realizados


															}else
																Tablero::matchTotal();

                                                            repetir = false;//le da el valor a la variable repetir de false, para que salga del ciclo
                                                        }
                                                    break;


                                                case 97://izquierda
                                                    system("clear");
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


															Tablero::hayMatch();


															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = *matriz;
                                                        		*matriz = aCambiar1;
                                                        		matriz = &tablero[fila][moverColumnaI];
                                                        		*matriz = aCambiar2;
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal();

															repetir = false;
                                                        }
                                                    break;

                                                case 119://arriba
                                                    system("clear");
                                                    if(fila == 0)//este condicional se usa para evitar que una ficha que
                                                    //está en el borde superior inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        Tablero::getTableroInicial();
                                                        cout<<"no se puede mover arriba"<<endl;//al oprimir la "w" en el teclado se genera la acción de cambiar
                                                            // la ficha inmediatamente siguiente que está arriba



                                                    }else
                                                        {
                                                            //el mismo procedimiento del case 100:


                                                            matriz = &tablero[moverArriba][columna];
                                                            aCambiar2 = *matriz;
                                                            *matriz = aCambiar1;
                                                            matriz = &tablero[fila][columna];
                                                            *matriz = aCambiar2;
                                                            Tablero::getTableroInicial();


															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = *matriz;
                                                        		*matriz = aCambiar1;
                                                        		matriz = &tablero[moverArriba][columna];
                                                        		*matriz = aCambiar2;
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal();

                                                            repetir = false;
                                                        }
                                                    break;

                                                case 115://abajo
                                                    system("clear");
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



															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = *matriz;
                                                        		*matriz = aCambiar1;
                                                        		matriz = &tablero[moverAbajo][columna];
                                                        		*matriz = aCambiar2;
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal();

                                                            repetir = false;
                                                        }
                                                    break;


                                    }
                                }

                        }
                    }

            }

    }
}


void Tablero::leerTableroDesdeTexto()

{


	//int matriz[8][8];
	//Caja matrizDeCajas[8][8];
	srand(time(NULL));

	int *puntero =  &tablero[0][0];
	int variableSwitch = rand() % 3;

	switch (variableSwitch) /*Posibilidades de matriz inicial para el nivel 1 por medio de un switch
						En todas los casos posibles sea crea un IFSTREAM. pero en cada caso se accede
						a un archivo .txt diferente. */
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
					nivel1 >> tablero[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}

			}
		}
		break;

		case 1:
		{
			//caso en que numero aleatorio % 3 sea 1

			ifstream nivel1 ("nivel1.txt");//TIPO: ifstream, Nombre de Variable: nivel1.
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
					nivel1 >> tablero[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}

			}
		}

		break;

		case 2:
		{//caso en que numero aleatorio % 3 sea 2:

			ifstream nivel1 ("nivel1.txt"); //TIPO: ifstream, Nombre de Variable: nivel1.
											//Archivo Buscado: nivel1-3.txt*/
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
					nivel1 >> tablero[i][j]; /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}

			}
		}
		break;
	}



//Primero el programa comprueba si hay alguna cruz.
			//           0
			//          000
			//           0
void Tablero::matchCruz()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 1; filas < 7; filas++)//For externo que recorre las filas.
		{
		for (columnas = 1; columnas < 7; columnas++) //for interno para las columnas
			{
				if(tablero[filas][columnas] == tablero[filas + 1][columnas] and tablero[filas][columnas] == tablero[filas - 1][columnas] and
					tablero[filas][columnas] == tablero[filas][columnas + 1] and tablero[filas][columnas] == tablero[filas][columnas - 1])
					//Este if comprueba si las posiciones a la izq, der, arriba, abajo, son iguales a la del lugar donde se encuentra el puntero.
				{
					tablero[filas][columnas] = 0;
					tablero[filas + 1][columnas] = 0;
					tablero[filas - 1][columnas] = 0;
					tablero[filas][columnas + 1] = 0;
					tablero[filas][columnas - 1] = 0;
				}
			}
		}
}

//Match verticales
void Tablero::matchVertical()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 1; filas < 7; filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < 8; columnas++) //for interno para las columnas
			{
				if(tablero[filas][columnas] == tablero[filas + 1][columnas] and tablero[filas][columnas] == tablero[filas - 1][columnas])
				{
					tablero[filas][columnas] = 0;
					tablero[filas + 1][columnas] = 0;
					tablero[filas - 1][columnas] = 0;
				}
			}
		}
}

//Match horizontales
void Tablero::matchHorizontal()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 0; filas < 8; filas++)//For externo que recorre las filas.
		{
		for (columnas = 1; columnas < 7; columnas++) //for interno para las columnas
			{
				if(tablero[filas][columnas] == tablero[filas][columnas + 1] and tablero[filas][columnas] == tablero[filas][columnas - 1])
				{
					tablero[filas][columnas] = 0;

					tablero[filas][columnas - 1] = 0;

					tablero[filas][columnas + 1] = 0;
				}
			}
		}
}

void Tablero::hacerMatch()
{
	system("clear");
	Tablero::getTableroInicial();
	sleep(1);
	matchCruz();

	matchHorizontal();

	matchVertical();
	sleep(0.8);
	system("clear");
	Tablero::getTableroInicial();

}


bool Tablero::ceroAbajo()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.

	for (filas = 0; filas < 7; filas++)//For externo que recorre las filas.
	{
		for (columnas = 0; columnas < 8; columnas++) //for interno para las columnas
		{
			if(tablero[filas][columnas] > 0 and tablero[filas + 1][columnas] == 0)
			   {
				   return true;
			   }
		}
	}
	return false;
}



void Tablero::bajarMatriz()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	while (ceroAbajo())
	{
		for (filas = 0; filas < 7; filas++)//For externo que recorre las filas
		{
			for (columnas = 0; columnas < 8; columnas++) //for interno para las columna
			{
				if(tablero[filas + 1][columnas] == 0)
				{

					tablero[filas + 1][columnas] = tablero[filas][columnas];

					tablero[filas][columnas] = 0;

				}
			}
		}
		sleep(1);
		system("clear");
		Tablero::getTableroInicial();}
}

void Tablero::llenarPrimeraColumna()
{
	int columnas;
	for (columnas = 0; columnas < 8; columnas++)
	{
		if(tablero[0][columnas] == 0)
			tablero[0][columnas] = 1 + rand() % 4;
	}
}

bool Tablero::hayCero()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 0; filas < 7; filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < 8; columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas] == 0)
				   {
					   return true;
				   }
			}
		}
	return false;
}

void Tablero::rellenarMatriz()
{
	while (hayCero())
	{

		bajarMatriz();
		sleep(1);
		system("clear");
		Tablero::getTableroInicial();

		system("clear");
		llenarPrimeraColumna();
		Tablero::getTableroInicial();



	}
}

bool Tablero::hayMatch()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 1; filas < 7; filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < 8; columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas] == tablero[filas + 1][columnas] and tablero[filas][columnas] == tablero[filas - 1][columnas])
			return true;
			}
		}

	for (filas = 0; filas < 8; filas++)//For externo que recorre las filas.
		{
		for (columnas = 1; columnas < 7; columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas] == tablero[filas][columnas + 1] and tablero[filas][columnas] == tablero[filas][columnas - 1])
				return true;
			}
		}
	return false;
}

void Tablero::matchTotal()
{
	while (hayMatch())
	{
		hacerMatch();
		//sleep(0.8);
		rellenarMatriz();


	}

}



