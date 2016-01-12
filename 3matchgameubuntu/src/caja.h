/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * caja.h
 * Copyright (C) 2016 Jhon Alejandro Orobio <alejo@alejo-OEM>
 *
 * 3matchgameubuntu is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 3matchgameubuntu is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _CAJA_H_
#define _CAJA_H_

class Caja
{
public:
	Caja();
	~Caja();

	void setValor(int a);
	int getValor();

protected:

private:
	int valor;
	bool estado;

};

#endif // _CAJA_H_

