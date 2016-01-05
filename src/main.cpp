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
<<<<<<< HEAD

        miTablero.moverseEnTablero();
=======
    //miTablero.getTableroInicial();
    
    srand (time (NULL));
	Tablero unTablero;
	unTablero.llenarTablero();
	unTablero.getTablero();
	cout << endl;
	unTablero.hacerMatch();
	unTablero.getTablero();
>>>>>>> 02168c7d3795e9171602fa3ed03524de4286426d



    return 0;
}
