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
        
        void llenarTablero ();
        void getTablero();
        void hacerMatch();




    protected:
    private:

<<<<<<< HEAD
        int tablero[F][C];
        int fila;
        int columna;
        int *pFila;
        int *Columna;
        int *matriz;
=======
    int tablero[F][C];
    int fila;
    int columna;
    int *pFila;
    int *Columna;
    int *matriz;
    double miTablero[8][8];
>>>>>>> 02168c7d3795e9171602fa3ed03524de4286426d

};

#endif // TABLERO_H
