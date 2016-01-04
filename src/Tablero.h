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

        void tableroInicial(int filas, int columnas);

        void setTableroInicial();

        void getTableroInicial();

        void moverseEnTablero();




    protected:
    private:

    int tablero[F][C];
    int fila;
    int columna;
    int *pFila;
    int *Columna;
    int *matriz;

};

#endif // TABLERO_H
