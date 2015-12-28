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








