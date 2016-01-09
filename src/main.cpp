 #include <iostream>
#include "Tablero.h"
#include "Tablero.cpp"

using namespace std;

int main()
{


        Tablero miTablero;
        Tablero *puntero;

        puntero = &miTablero;




        miTablero.setTableroInicial(8,8);
        (*puntero).getTableroInicial();


        (*puntero).moverseEnTablero();

        //miTablero.getTableroInicial();
        //cout<<endl;


        //miTablero.moverseEnTablero();
/*<<<<<<< HEAD


=======
    //miTablero.getTableroInicial();

   srand (time (NULL));
		Tablero unTablero;
		unTablero.llenarTablero();
		unTablero.getTablero();
		cout << endl;
		unTablero.hacerMatch(); //Puse este solo para visualizar donde se hacian los match. pero no es necesario ya.
		unTablero.getTablero();
		cout << endl;
		unTablero.matchTotal();
		unTablero.getTablero();
>>>>>>> 02168c7d3795e9171602fa3ed03524de4286426d*/



    return 0;
}
