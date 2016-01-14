/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.cc
 * Copyright (C) 2016 JHON ALEJANDRIO OROBIO ARCE <jhonaoa@s3pc24>
 * 
 * 3MatchGame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3MatchGame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PjjURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "tablero.h"
#include "caja.h"
#include <pthread.h>
#include <ctime>
#include <cstdio>



using namespace std;

int main(int argc, char * argv[])
{
	Juego game;

		
		int repetir= 1,opcion =0;
		int empezar = 0;
		int level= 0;
		
		

        Tablero miTablero;
        Tablero *puntero;
		
	
		puntero = &miTablero;

		
		system("clear");
		cout<< " MADAGASCAR 3-MATCH GAME"<<endl;
		cout<<endl;
		cout<< "1.Empezar un nuevo juego"<<endl;
		cout<<endl;
		cout<< "2.Cargar un juego existente"<<endl;
		cout<<endl;
		cout<< "3.Salir del juego"<<endl;
		cout<<endl;
		cout<<"Opcion: ";
		cin>>opcion;

	do
	{

		
			switch(opcion)
			{

				case 1:

					system("clear");
					cout<< "Instrucciones de juego:"<<endl;
					cout<<endl;
					cout<<"          Mover Arriba: W"<<endl;
					cout<<endl;
					cout<<"Mover Izquieda: A  "<< "  Mover Derecha: D"<< endl;
					cout<<endl;
					cout<<"          Mover Abajo: S"<<endl;
					cout<<endl;
					cout<< "       Escoger una ficha: SPACE"<<endl;
					cout<<endl;
					cout<<   "Guardar y salir: OPRIMA LA LETRA G"<<endl;
					cout<<endl;
					cout<<"oprime 1 cuando estés listo: ";
					cin>>empezar;
					
					
					switch(empezar)
					{   
						case 1:

							
							system("clear");
							cout<<"Escoge un nivel para empezar a jugar: "<<endl;
							cout<<endl;
							cout<<"1.Nivel 1"<<endl;
							cout<<"2.Nivel 2"<<endl;
							cout<<"3.Nivel 3"<<endl;
							cin>>level;

							(*puntero).leerTableroDesdeTexto (game, level);
							(*puntero).getTableroInicial();
							(*puntero).moverseEnTablero(game);
							system("clear");
							cout<< " MADAGASCAR 3-MATCH GAME"<<endl;
							cout<<endl;
							cout<< "1.Empezar un nuevo juego"<<endl;
							cout<<endl;
							cout<< "2.Cargar última partida guardada"<<endl;
							cout<<endl;
							cout<< "3.Salir del juego"<<endl;
							cout<<endl;
							cout<<"Opcion: ";


							cin>>opcion;
						break;


						default:

							cout<<"Debes oprimir 1 para empezar";
							
						break;

					}
				break;


				case 2:
					

					(*puntero).cargarTableroDesdeArchivo(game);
					
					(*puntero).getTableroInicial();
					(*puntero).moverseEnTablero(game);
					
					
				
				
					system("clear");
					cout<< " MADASCAR 3-MACH GAME"<<endl;
					cout<<endl;
					cout<< "1.Empezar un nuevo juego"<<endl;
					cout<<endl;
					cout<< "2.Cargar última partida guardada"<<endl;
					cout<<endl;
					cout<<"Opcion: ";
				

					cin>>opcion;
				
					
				break;

				case 3:
					system("clear");
					cout<<"saliendo...";

					repetir = 0;
					break;

				default:

					cout<<" Esa no es una opción válida, ingresa otra: ";
					cin>>opcion;
				break;
			}
		

	}while (repetir == 1);

	
	


    return 0;
}


