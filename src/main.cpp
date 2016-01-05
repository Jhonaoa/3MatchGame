 #include <iostream>
#include "Tablero.h"
#include "Tablero.cpp"

using namespace std;

int main()
{


        Tablero miTablero;


        miTablero.setTableroInicial(8,8);

        miTablero.getTableroInicial();
        cout<<endl;

        miTablero.moverseEnTablero();



    return 0;
}
