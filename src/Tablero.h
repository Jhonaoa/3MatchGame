#ifndef TABLERO_H
#define TABLERO_H
#define F 8
#define C 8
#include<windows.h>


class Tablero
{
    public:

        Tablero();
        ~Tablero();

        void setTableroInicial(int filas, int columnas);

        void getTableroInicial();

        void moverseEnTablero();

        void leerMatrizDesdeArchivo (int *apuntador );

        void leerTableroDesdeTexto(int *apuntador );



        void llenarTablero ();
        void getTablero();
        void hacerMatch();
        void bajarMatriz();
	bool ceroAbajo ();




    protected:
    private:


        int tablero[F][C];
        int fila;
        int columna;
        int aCambiar1;
        int aCambiar2;
        int *matriz;



        double miTablero[8][8];


};

#endif // TABLERO_H
