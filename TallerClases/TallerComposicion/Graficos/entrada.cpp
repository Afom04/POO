#include "entrada.h"

string entrada::obtenerEntrada(const std::string& instruccion, bool numero) const{
	color(color_instruccion);
	texto(posx_instruccion, posy_instruccion, instruccion);
	color(color_entrada);
	string entrada;
	for(int simbolo = tecla(); simbolo != RETURN; simbolo = tecla()){
		simbolo = filtrar_simbolo_miniwin(simbolo);
		if((simbolo == ESCAPE || simbolo == 8) && !entrada.empty()){
			borra();
			color(color_instruccion);
			texto(posx_instruccion, posy_instruccion, instruccion);
		}else if(numero && (isdigit(simbolo) || simbolo == PUNTO)){
			entrada += simbolo;
		}else if(!numero && (isalnum(simbolo) || simbolo == ESPACIO || simbolo == PUNTO)){
			entrada += simbolo;
		}
		if(simbolo != NINGUNA){
			color(color_entrada);
			texto(posx_entrada, posy_entrada, entrada);							
		}
		refresca();
		espera(20);
			
	}
	return entrada;
}
int entrada::filtrar_simbolo_miniwin(int simbolo) const{
	if(simbolo == 190 || simbolo == 188 || simbolo == 110)
		return PUNTO;
	if(simbolo >= 96 && simbolo <= 105)
		return simbolo - 48;
	return simbolo;
}
