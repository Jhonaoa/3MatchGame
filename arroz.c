#include <iostream>
#include "Tablero.h"
#include "Tablero.cpp"

using namespace std;

int main()
{

    cout<<"mi plataforma es: "<< 8*sizeof(int)<<" bytes"<<endl;
    Tablero miTablero;
    miTablero.tableroInicial(8,8);

    //miTablero.setTableroInicial(& tablero2[F][C]);
    cout<<endl;
    miTablero.getTableroInicial();

    return 0;
}
