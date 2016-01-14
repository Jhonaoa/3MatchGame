/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * proyecto1
 * Copyright (C) DANIEL FELIPE BUENO GARCIA 2016 <danielfbg@s4pc6>
 * 
proyecto1 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * proyecto1 is distributed in the hope that it will be useful, but
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

	void setTipo(int valor);
	int getTipo();

protected:

private:

	int tipo;
	

};

#endif // _CAJA_H_
