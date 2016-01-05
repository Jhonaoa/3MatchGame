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

        void leerMatrizDesdeArchivo (int *apuntador );

        void leerTableroDesdeTexto(int *apuntador );

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
