#ifndef TABLERO_H
#define TABLERO_H
#define F 8
#define C 8


class Tablero
{
    public:
        Tablero();
        ~Tablero();

        void tableroInicial(int filas, int columnas);

        void setTableroInicial(int matriz[F][C]);

        void getTableroInicial();
        
        void leerMatrizDesdeArchivo (int *apuntador );


    protected:
    private:

    int tablero[F][C];
};

#endif // TABLERO_H
