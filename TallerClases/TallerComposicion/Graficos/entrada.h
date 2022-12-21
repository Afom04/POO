#ifndef ENTRADA_H
#define ENTRADA_H

#include "miniwin.h"
#include <string>
#include <iostream>
using namespace std;
using namespace miniwin;

class entrada{		
	public:
	float posx_instruccion, posy_instruccion;
	int color_instruccion;
	float posx_entrada, posy_entrada;
	int color_entrada;
	
	string obtenerEntrada(const string &instruccion, bool numero = false) const;
	
	private:
		int filtrar_simbolo_miniwin(int simbolo) const;
		
		enum{
			PUNTO = 46
		};
};
#endif
