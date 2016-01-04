#include "Tablero.h"
#include <cstdlib>
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








