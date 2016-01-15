
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
    tablero = new Caja* [F];

	for(int i = 0; i < F;i++ )
	{
		tablero[i] = new Caja[C];
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
			

    for (i = 0; i < F; i++)  // Ciclo para recorrer y mostrar la matriz por filas.
        {
			cout<<"           "; // imprime espacios para mostrar tablero centrado

			for(int k = 0; k< F;k++) // ciclo para mostrar separacion entre cada fila.
            {
                cout<<"-----";
            }
			
            cout<<endl;// salto de linea
			cout<<"           "; // imprime espacios para mostrar tablero centrado


            for(j = 0; j< C; j++) // ciclo para imprimir las componentes de tablero[][]
            {
				

                if (i == fila and j ==columna )  // Condicional para imprimir la componente donde se encuentra el "cursor"
                {
                    cout<<"[ "<<tablero[i][j].getTipo()<<" ]";
                }else // si no está el cursor sobre la componente 
                {

					cout<<"  "<<tablero[i][j].getTipo()<<"  "; // imprimir el tipo de la CAJA
                }
            }
        cout<<endl;// 2saltos de linea
        cout<<endl;
        }


}
//http://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
/*Esta función se deriva de una galería usada en windows para el uso del teclado durante 
la ejecución del programa,dado que en linux no está presente esta galería y con la intención de 
darle un poco más de dinamismo al programa, se utilizó este método de la fuente anteriormente
especificada*/

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

void Tablero::moverseEnTablero(Juego &game)
{
    	bool repeat = true;//variable utilizada para la ejecución del ciclo que mantiene
    	//la interacción del teclado activa
	int S = game.getTiempo () % 60 ;/*la variable S recibe el atributo tiempo de el objeto
	juego y realiza el módulo para presentar el tiempo en el reloj*/
	int M = game.getTiempo() / 60;/*la variable M recibe el atributo tiempo de la clase Juego
	y lo divide entre 60 para presentar el equivalente en segundos del tiempo*/
	bool salir = true;/*esta variable se utiliza para mantener el ciclo del reloj y el movimiento*/
	
    while(repeat)//se usa un ciclo while para mantener la interacción con el teclado
    //activa hasta que se requiera.
        {   
			
			
			while(salir)/*ciclo responsable de los cambios en el reloj y captura de los movimientos
			por medio del método kbhit y getchar */ 
			{
			
				system("clear");
			
				cout<<M<<":"<<S<<endl;//muestra los minutos y los seguundos por medio de un cout
				cout<<endl;
				
				/*lista de mensajes a mostrar durante la ejecución del programa, los requerimientos
				de los animales a liberar y l aimpresión del tablero por primera vez*/
				cout<<"   Debes liberar  estos animales para superar el nivel: "<<endl;
				cout<<endl;
				cout<<"Leones(1): "<<game.getRequerimientoTipo1 ()<<"   ";
				cout<<"Girafas(2): "<<game.getRequerimientoTipo2 ()<<"   ";
				cout<<"Hipopótamos(3): "<<game.getRequerimientoTipo3 ()<<"   ";
				cout<<"Cebras(4): "<<game.getRequerimientoTipo4 ()<<endl;
				cout<<endl;
				cout<<endl;
				
				Tablero::getTableroInicial();
			
				S--;//Reducción de la variable S, responsable de mostrar los segundos, S--, en uno por ciclo 

				if(M==0 and S== 30)
				{

					cout<<"Quedan menos de treinte segundos de juego, apúrele"<<endl;
					cout<<endl;
					
				}

				if (M== 0 and S == 0 
					or game.requerimientosCumplidos () == true)
				{
					cout<<"Has perdido!!, Loserrrrrr!!"<<endl;
					salir = false;
					repeat = false;
				}
				
				if (S == -1)
				{
					S = 59;
					M --;
				}
			
					
				sleep(1);
				

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

                                if( fila ==(F-1) and columna  == C)//cuando llega a la posición [7][7], devuelve el seleccionador
                                                //a la primera posición [0][0]
                                    {
                                        system("clear");
                                        fila = 0;
                                        columna = 0;
                                        Tablero::getTableroInicial();
                                    }

                                if(columna == C)//permite que al momento de llegar a última columna
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
                                        fila = (F-1);
                                        columna = (C-1);
                                        Tablero::getTableroInicial();
                                    }
                                        else if(fila != 0 and columna == 0)//permite que al momento de estar en una
                                        //fila distinta de 0 y columna = 0, alpresionar "izquierda" retroceda a la posición
                                        // [fila -1][columna = 7]

                                        {
                                            system("clear");
                                            fila -=1;
                                            columna = (C-1);
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
                                        fila = (F-1);
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


                                if( fila == (F-1))//permite que cuando el seleccionador se encuentre
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

							case 103:
								Tablero::guardarTableroEnArchivo(game);
								cout<<"el juego se ha guardado satisfactoriamente";
								exit(0);
								 
	
							break;

                            case 32://selccionar ficha a mover. 32 es la posición de la tecla
                            //espacio en la tabla ASSCI


                                matriz = &tablero[fila][columna];//se iguala el puntero "matriz" a la posición
                                //actual del seleccionador "[]" y se almacena el contenido en el
                                //atributo "aCambiar1"
                                aCambiar1 = (*matriz).getTipo();//almacena el conteniido del puntero matriz en el
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
                                                    if(columna == (C-1))//este condicional se usa para evitar que una ficha que
                                                    //está en el borde derecho inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover a la derecha"<<endl;//devuelve un aviso
                                                        Tablero::getTableroInicial();//devuelve el tablero otra vez

                                                    }else
                                                        {


                                                            matriz = &tablero[fila][moverColumnaD];//señala el puntero matriz a la posición a la derecha de la actual
                                                            aCambiar2 = (*matriz).getTipo();//alamacena el contenido de matriz en el atributo "aCambiar2"
                                                            (*matriz).setTipo(aCambiar1) ;//cambia el contenido del puntero matriz por el almacenado en aCambiar1
                                                            matriz = &tablero[fila][columna];//señala el puntero matriz a la posición que fue seleccionada

                                                            (*matriz).setTipo (aCambiar2);//cambia el contenido del puntero matriz por el de aCambiar2
                                                            Tablero::getTableroInicial();//imprime el tablero con los cambios realizados

															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");

                                                        		matriz = &tablero[fila][columna];//señala el puntero matriz a la posición a la derecha de la actual
                                                        		aCambiar2 = (*matriz).getTipo();//alamacena el contenido de matriz en el atributo "aCambiar2"
                                                        		(*matriz).setTipo( aCambiar1);//cambia el contenido del puntero matriz por el almacenado en aCambiar1
                                                        		matriz = &tablero[fila][moverColumnaD];//señala el puntero matriz a la posición que fue seleccionada

                                                        		(*matriz).setTipo(aCambiar2);//cambia el contenido del puntero matriz por el de aCambiar2
                                                        		Tablero::getTableroInicial();//imprime el tablero con los cambios realizados


															}else
																this->matchTotal(game);

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
                                                            aCambiar2 = (*matriz).getTipo();
                                                            (*matriz).setTipo( aCambiar1);
                                                            matriz = &tablero[fila][columna];
                                                            (*matriz).setTipo(aCambiar2);
                                                            Tablero::getTableroInicial();


															Tablero::hayMatch();


															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = (*matriz).getTipo();
                                                        		(*matriz).setTipo( aCambiar1);
                                                        		matriz = &tablero[fila][moverColumnaI];
                                                        		(*matriz).setTipo( aCambiar2);
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal(game);

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
                                                            aCambiar2 = (*matriz).getTipo();
                                                            (*matriz).setTipo( aCambiar1);
                                                            matriz = &tablero[fila][columna];
                                                            (*matriz).setTipo(aCambiar2);
                                                            Tablero::getTableroInicial();


															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = (*matriz).getTipo();
                                                        		(*matriz).setTipo(aCambiar1);
                                                        		matriz = &tablero[moverArriba][columna];
                                                        		(*matriz).setTipo( aCambiar2);
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal(game);

                                                            repetir = false;
                                                        }
                                                    break;

                                                case 115://abajo
                                                    system("clear");
                                                    if(fila == (F-1))//este condicional se usa para evitar que una ficha que
                                                    //está en el borde inferior inetnte ser intercambiada en una posición que no existe
                                                    {
                                                        cout<<"no se puede mover abajo"<<endl;//al oprimir la "s" en el teclado se genera la acción de cambiar
                                                            // la ficha inmediatamente siguiente que está abajo
                                                        Tablero::getTableroInicial();//imprime el tablero otra vez

                                                    }else
                                                        {
                                                            //el mismo procedimiento del case 100:


                                                            matriz = &tablero[moverAbajo][columna];
                                                            aCambiar2 = (*matriz).getTipo();
                                                            (*matriz).setTipo(aCambiar1);
                                                            matriz = &tablero[fila][columna];
                                                            (*matriz).setTipo(aCambiar2);
                                                            Tablero::getTableroInicial();



															Tablero::hayMatch();



															if (Tablero::hayMatch()==false)
															{
																sleep(1);
																system("clear");
                                                        		matriz = &tablero[fila][columna];
                                                        		aCambiar2 = (*matriz).getTipo();
                                                        		(*matriz).setTipo( aCambiar1);
                                                        		matriz = &tablero[moverAbajo][columna];
                                                        		(*matriz).setTipo( aCambiar2);
                                                        		Tablero::getTableroInicial();

															}else
																Tablero::matchTotal(game);

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
}



void Tablero::cargarTableroDesdeArchivo(Juego &juego)
{
	

	ifstream archivoTexto("Guardado.txt");

	if(archivoTexto.fail())
	{

		
		cerr  << "No Fue Posible Cargar Último Archivo Guardado";
		cout << endl;
	
	}

	int aux ; 
	
	archivoTexto >> aux;
	juego.setNivel(aux);

	archivoTexto >> aux; 
	juego.setTiempo(aux);
	
	archivoTexto >> aux;
	juego.setTipo1(aux);

	archivoTexto >> aux;
	juego.setTipo2(aux);

	archivoTexto >> aux;
	juego.setTipo3(aux);

	archivoTexto >> aux;
	juego.setTipo4(aux) ; 

	for (int filas = 0; filas < F ; filas++)
	{
		for(int columnas = 0 ; columnas < C ; columnas++)
		{
			archivoTexto >> aux;
			tablero[filas][columnas].setTipo(aux);	
		} 
	} 

	
}


void Tablero::leerTableroDesdeTexto(Juego &game, int lv )
{
	Juego *punteroJuego = &game;
	
	//Caja *puntero =  &tablero[0][0];
	
	int aux = 0; // DOUBLE porque maneja unidades de tiempo en milisegundos.
	//double *punteroAux = &aux;  //DOUBLE porque apunta unidades de tiempo en milisegundos.

	switch (lv) /*Posibilidades de matriz inicial para el nivel 1 por medio de un switch
						En todas los casos posibles sea crea un IFSTREAM. pero en cada caso se accede
						a un archivo .txt diferente. */
	{
		case 1:
		{ // caso en que numero aleatorio % 3 sea cero
			ifstream nivel1 ("nivel1.txt"); //TIPO: ifstream, Nombre de Variable: Nivel1.
											//Archivo Buscado: nivel1.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 1" ;
				cout << endl;
				
			}

			nivel1 >> aux; 
			(*punteroJuego).setNivel(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTiempo(aux);

			nivel1 >> aux ; 
			(*punteroJuego).setTipo1(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo2(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo3(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo4(aux);

			//nivel1 >> aux; 
			//(*punteroJuego).setTipoTortuga(aux);
			
			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
			//en un arreglo.
			{
				for (int j = 0 ; j < 8 ; j++)
				{
				
					
					nivel1 >> aux;

					tablero[i][j].setTipo(aux); /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}
			}
		}
		break;
			
		case 2:
		{
			//caso en que numero aleatorio % 3 sea 1
			ifstream nivel1 ("nivel1-2.txt");//TIPO: ifstream, Nombre de Variable: nivel1.
											//Archivo Buscado: nivel1-2.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 2" ;
				cout << endl;
				
			}

			nivel1 >> aux;
			(*punteroJuego).setNivel(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTiempo(aux);

			nivel1 >> aux ; 
			(*punteroJuego).setTipo1(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo2(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo3(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo4(aux);

			//nivel1 >> aux; 
			//(*punteroJuego).setTipoTortuga(aux);
			
			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
										//en un arreglo.
			{
				for (int j = 0 ; j < 8 ; j++)
				{
					nivel1 >> aux;

					tablero[i][j].setTipo(aux); /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}
			}
		}
		break;
			
		case 3:
		{//caso en que numero aleatorio % 3 sea 2:
			ifstream nivel1 ("nivel1-3.txt"); //TIPO: ifstream, Nombre de Variable: nivel1.
											//Archivo Buscado: nivel1-3.txt
			if (nivel1.fail() ) // Si hay error al abrir el archivo entonces imprimir mensaje de error.
			{
				cerr << "ERROR AL ABRIR ARCHIVO 3" ;
				cout << endl;
				
			}

			nivel1 >> aux;
			(*punteroJuego).setNivel(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTiempo(aux);

			nivel1 >> aux ; 
			(*punteroJuego).setTipo1(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo2(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo3(aux);

			nivel1 >> aux; 
			(*punteroJuego).setTipo4(aux);

			//nivel1 >> aux; 
			//(*punteroJuego).setTipoTortuga(aux);
			
			for (int i = 0 ; i < 8 ; i++) // Ciclo FOR para guardar cada número de la matriz
										//en un arreglo.
			{
				for (int j = 0 ; j < 8 ; j++)
				{
					nivel1 >>aux ;

					tablero[i][j].setTipo(aux); /* Guarda lo que haya en el archivo  nivel1.txt en
										la posición (i,j) de la matriz definida.*/
				}
			}
		}
		break;
		
		default :
			break;
	}
} 



void Tablero::guardarTableroEnArchivo(Juego &juego) //entra la dirección en memoria de juego
{
	 Juego *punteroJuego = &juego;

	ofstream datosGuardados ("Guardado.txt"); 

	datosGuardados <<  juego.getNivel() << "\n" ; 

	datosGuardados << (*punteroJuego).getTiempo() << "\n" ;

	datosGuardados << (*punteroJuego).getRequerimientoTipo1() << "\n" ;

	datosGuardados << (*punteroJuego).getRequerimientoTipo2() << "\n" ;

	datosGuardados << (*punteroJuego).getRequerimientoTipo3() << "\n" ;

	datosGuardados << (*punteroJuego).getRequerimientoTipo4() << "\n" ;

	//datosGuardados << (punteroJuego).getRequerimientoTortuga() << "\n" ;

	for (int i = 0; i < F; i++)
	{
		for (int j = 0 ; j < C ; j++)
		{
				
			datosGuardados << tablero[i][j].getTipo() << " ";
			
		}

		datosGuardados << "\n" ;
	}
	

}


//Matchcruz
//           0
//          000
//           0
void Tablero::matchCruz(Juego &juego) 
// Metodo de match en cruz, entra el juego para poder bajar los requerimientos del juego cada vez que se hace un match.
{
	int filas,columnas; 
	//Variables para recorrer el for. filas y columnas, que nos permiten saber a qué posición 
	//de la matriz estamos accediendo.
	
	for (filas = 1; filas < (F-1); filas++) //for externo que recorre las filas.
	// Este for va desde la posición 1 en filas (segunda fila) hasta la posición 6 (penultima fila).
	{
		for (columnas = 1; columnas < (C-1); columnas++) //for interno que recorre las columnas.
		{
			if(tablero[filas][columnas].getTipo() == tablero[filas + 1][columnas].getTipo() 
			and tablero[filas][columnas].getTipo() == tablero[filas - 1][columnas].getTipo() 
			and tablero[filas][columnas].getTipo() == tablero[filas][columnas + 1].getTipo() 
			and tablero[filas][columnas].getTipo() == tablero[filas][columnas - 1].getTipo())
//Este if comprueba si las posiciones a la izq, der, arriba, abajo, son iguales a la del lugar donde se encuentra el lugar
//donde el recorrido de la matriz se encuentra. (filas+1,filas-1,columnas++1,columnas-1).
{
	//Si llega a ocurrir que son iguales es porque hubo match y procede a cambiar el atributo "Tipo" de las cajas
	//implicadas a 0.
	
	
	juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas].getTipo());
	tablero[filas][columnas].setTipo( 0);
	//Primero se debe bajar el número de requerimientos que hacen falta para terminar el juego, de el tipo de caja 
	//que se hizo el match y después de hacer esto ya se procede a volver 0 la caja.
	
	juego.disminuirRequerimientoTodoTipo(tablero[filas + 1][columnas].getTipo());
	tablero[filas + 1][columnas].setTipo( 0);
	
	juego.disminuirRequerimientoTodoTipo(tablero[filas-1][columnas].getTipo());
	tablero[filas - 1][columnas].setTipo( 0);
	
	juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas+1].getTipo());
	tablero[filas][columnas + 1].setTipo( 0);
	
	juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas-1].getTipo());
	tablero[filas][columnas - 1].setTipo( 0);
	
	// Se hace lo mismo con las 5 cajas implicadas en la cruz.
	
				}
			}
		}
}


//MatchVertical
//    0
//    0
//    0
void Tablero::matchVertical(Juego &juego)
{
	int filas,columnas; 
	//Variables para recorrer el for. filas y columnas, que nos permiten saber a qué posición 
	//de la matriz estamos accediendo.
	for (filas = 1; filas < (F-1); filas++)//For externo que recorre las filas.
	// Empieza a recorrer desde la segunda fila hasta la penultima. (1-6)
	{
		for (columnas = 0; columnas < C; columnas++) //for interno para las columnas
		// Este si puede recorrer desde la primera columna hasta la ultima.
		{
			if(tablero[filas][columnas].getTipo() == tablero[filas + 1][columnas].getTipo() 
			and tablero[filas][columnas].getTipo() == tablero[filas - 1][columnas].getTipo())
			// En cada casilla comprueba si la fila anterior y la siguiente son iguales a la fila donde
			// se encuentra recorriendo el for.
			{
				// Si se llega a dar que hay match hay que hacer lo mismo que con el match cruz.
				// Se bajan los requerimientos del tipo de caja implicado en el match.
				// y luego se procede a cambiar los tipos de las cajas por 0.
				juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas].getTipo());
				tablero[filas][columnas].setTipo(0);
				
				juego.disminuirRequerimientoTodoTipo(tablero[filas+1][columnas].getTipo());
				tablero[filas + 1][columnas].setTipo(0);
				
				juego.disminuirRequerimientoTodoTipo(tablero[filas-1][columnas].getTipo());
				tablero[filas - 1][columnas].setTipo(0);
				
				//se hace lo mismo con las 3 cajas del match (fila,fila+1,fila-1)
				}
			
		}
		
	}
	
}

//Match horizontales
// 0 0 0

void Tablero::matchHorizontal(Juego &juego) // metodo match horizontales.
{
	int filas,columnas; 
	//Variables para recorrer el for. filas y columnas, que nos permiten saber a qué posición 
	//de la matriz estamos accediendo.	
	for (filas = 0; filas < F; filas++)//For externo que recorre las filas.
	// En este caso no hay restricción, corre desde la primera fila hasta al ultima.
	{
		for (columnas = 1; columnas < C-1; columnas++) //for interno para las columnas
		// En los match horizontales la restricción es en las columnas, recorre desde la segunda columna hasta
		// la penultima (1-6)
		{
			if(tablero[filas][columnas].getTipo() == tablero[filas][columnas + 1].getTipo() 
			and tablero[filas][columnas].getTipo() == tablero[filas][columnas - 1].getTipo())
			
			{
					juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas].getTipo());
					tablero[filas][columnas].setTipo ( 0);

					juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas-1].getTipo());
					tablero[filas][columnas - 1].setTipo ( 0);

					juego.disminuirRequerimientoTodoTipo(tablero[filas][columnas+1].getTipo());
					tablero[filas][columnas + 1].setTipo ( 0);
				}
			}
		}
}

void Tablero::hacerMatch(Juego &juego )
{
	system("clear");
	Tablero::getTableroInicial();
	sleep(1);
	matchCruz(juego );

	matchHorizontal(juego );

	matchVertical(juego );
	sleep(0.8);
	system("clear");
	Tablero::getTableroInicial();

}


bool Tablero::ceroAbajo()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.

	for (filas = 0; filas < (F-1); filas++)//For externo que recorre las filas.
	{
		for (columnas = 0; columnas < C; columnas++) //for interno para las columnas
		{
			if(tablero[filas][columnas].getTipo() > 0 
			   and tablero[filas + 1][columnas].getTipo() == 0)
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
		for (filas = 0; filas < (F-1); filas++)//For externo que recorre las filas
		{
			for (columnas = 0; columnas < C; columnas++) //for interno para las columna
			{
				if(tablero[filas + 1][columnas].getTipo() == 0)
				{

					tablero[filas + 1][columnas].setTipo(tablero[filas][columnas].getTipo());

					tablero[filas][columnas].setTipo(0);

				}
			}
		}
		sleep(1);
		system("clear");
		Tablero::getTableroInicial();
	}
}

void Tablero::llenarPrimeraColumna()
{
	int columnas;
	for (columnas = 0; columnas < C; columnas++)
	{
		if(tablero[0][columnas].getTipo() == 0)
			tablero[0][columnas].setTipo(1 + rand() % 4);
	}
}

bool Tablero::hayCero()
{
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y columna del tablero está el puntero en algún momento.
	for (filas = 0; filas < F; filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < C; columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas].getTipo() == 0)
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
	int filas,columnas; //Variables para recorrer el for, necesario para saber en qué fila y 
	//columna del tablero está el puntero en algún momento.
	for (filas = 1; filas < (F-1); filas++)//For externo que recorre las filas.
		{
		for (columnas = 0; columnas < C; columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas].getTipo() == tablero[filas + 1][columnas].getTipo() 
			   and tablero[filas][columnas].getTipo() == tablero[filas - 1][columnas].getTipo())
			return true;
			}
		}

	for (filas = 0; filas < F; filas++)//For externo que recorre las filas.
		{
		for (columnas = 1; columnas < (C-1); columnas++) //for interno para las columnas
			{
			if(tablero[filas][columnas].getTipo() == tablero[filas][columnas + 1].getTipo() 
			   and tablero[filas][columnas].getTipo() == tablero[filas][columnas - 1].getTipo())
				return true;
			}
		}
	return false;
}

void Tablero::matchTotal(Juego &game)
{
	while (hayMatch())
	{
		hacerMatch(game);
		
		rellenarMatriz();


	}

}
