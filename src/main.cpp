 #include <iostream>
#include "Tablero.h"
#include "Tablero.cpp"

using namespace std;

int main()
{


        Tablero miTablero;


        miTablero.tableroInicial(8,8);

        miTablero.setTableroInicial();
        cout<<endl;
    //miTablero.getTableroInicial();
    
    srand (time (NULL));
	Tablero unTablero;
	unTablero.llenarTablero();
	unTablero.getTablero();
	cout << endl;
	unTablero.hacerMatch();
	unTablero.getTablero();



    return 0;
}
