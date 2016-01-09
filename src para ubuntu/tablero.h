/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * 3matchgame
 * Copyright (C) JHON ALEJANDRIO OROBIO ARCE 2016 <jhonaoa@s3pc24>
 * 
3matchgame is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3matchgame is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TABLERO_H_
#define _TABLERO_H_

#define F 8
#define C 8



class Tablero
{
    public:

        Tablero();
        ~Tablero();

        void setTableroInicial(int filas, int columnas);

        void getTableroInicial();

        void moverseEnTablero();

        void leerMatrizDesdeArchivo (int *apuntador );

        void leerTableroDesdeTexto( );

		int kbhit(void);



        void llenarTablero ();
        void getTablero();
        void hacerMatch();




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

#endif // _TABLERO_H_
