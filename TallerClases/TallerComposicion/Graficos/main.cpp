/*Generar una clase "" para un circulo, otra para un rectàngulo y otra para cuadrado.
Se debe hallar el àrea y el preìmetro de cada una de ellas, y a travez de composicion hacer un
metodo que compare las areas y otro los perimetros */

#include "entrada.h"
#include <sstream>
class cuadrados {
	private:
		entrada C;
		float lado;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void cuadrados::entrada() {
	//color(BLANCO);
	C.color_instruccion=BLANCO;
	C.color_entrada=VERDE;
	C.posx_instruccion=5;
	C.posy_instruccion=15;
	C.posx_entrada=5;
	C.posy_entrada=35;
	vredimensiona(500,500);
	string aux;
	aux=C.obtenerEntrada("Por favor ingrese el tamano de los lados del cuadrado", true);
	istringstream(aux)>>lado;
	borra();
	refresca();
}
void cuadrados::proceso(float*perimetros,float*areas) {
	perimetros[0]=lado+lado+lado+lado;
	areas[0]=lado*lado;
}
void cuadrados::salida(float*perimetros,float*areas) {
	ostringstream A,P;
	A<<areas[0];
	P<<perimetros[0];
	string ar,per;
	ar=A.str();
	per=P.str();
	color(CYAN);
	vredimensiona(500,500);
	texto(5,15,"El area del cuadrado es "+ar+" unidades^2");
	texto(5,35,"El perimetro del cuadrado es "+per+" unidades");
	color(ROJO);
	rectangulo(150,150,(lado+150),(lado+150));
	refresca();
	espera(10000);
	borra();
	refresca();
}
//////////////////////////////////////////////////////////////////////////////////////////
class rectangulos {
	private:
		entrada C;
		float base,altura;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void rectangulos::entrada() {
	//color(BLANCO);
	C.color_instruccion=BLANCO;
	C.color_entrada=VERDE;
	C.posx_instruccion=5;
	C.posy_instruccion=15;
	C.posx_entrada=5;
	C.posy_entrada=35;
	vredimensiona(500,500);
	string aux,aux2;
	aux=C.obtenerEntrada("Por favor ingrese el tamano de la base del rectangulo", true);
	istringstream(aux)>>base;
	borra();
	refresca();
	aux=C.obtenerEntrada("Por favor ingrese el tamano de la altura del rectangulo", true);
	istringstream(aux2)>>altura;
	borra();
}
void rectangulos::proceso(float*perimetros,float*areas) {
	perimetros[1]=(altura+altura)+(base+base);
	areas[1]=base*altura;
}
void rectangulos::salida(float*perimetros,float*areas) {
	ostringstream A,P;
	A<<areas[1];
	P<<perimetros[1];
	string ar,per;
	ar=A.str();
	per=P.str();
	color(CYAN);
	vredimensiona(500,500);
	texto(5,15,"El area del rectangulo es "+ar+" unidades^2");
	texto(5,35,"El perimetro del rectangulo es "+per+" unidades");
	color(AMARILLO);
	rectangulo(150,150,(base+150),(altura+150));
	refresca();
	espera(10000);
	borra();
	refresca();
}
/////////////////////////////////////////////////////////////////////////////////
class circulos {
	private:
		entrada C;
		int radio;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void circulos::entrada() {
	//color(BLANCO);
	C.color_instruccion=BLANCO;
	C.color_entrada=VERDE;
	C.posx_instruccion=5;
	C.posy_instruccion=15;
	C.posx_entrada=5;
	C.posy_entrada=35;
	vredimensiona(500,500);
	string aux;
	aux=C.obtenerEntrada("Por favor ingrese el tamano del radio del circulo", true);
	istringstream(aux)>>radio;
	borra();
	refresca();
}
void circulos::proceso(float*perimetros,float*areas) {
	perimetros[2]=2*radio*(3.14159);
	areas[2]=3.14159*(radio*radio);
}
void circulos::salida(float*perimetros,float*areas) {
	ostringstream A,P;
	A<<areas[2];
	P<<perimetros[2];
	string ar,per;
	ar=A.str();
	per=P.str();
	color(CYAN);
	vredimensiona(500,500);
	texto(5,15,"El area del circulo es "+ar+" unidades^2");
	texto(5,35,"El perimetro del circulo es "+per+" unidades");
	color(MAGENTA);
	circulo(150,150,radio);
	refresca();
	espera(10000);
	borra();
	refresca();
}
//////////////////////////////////////////////////////////
class composicion {
		cuadrados cuad;
		rectangulos rec;
		circulos cir;
		float areas[3];
		float perimetros[3];
	public:
		void entrada();
		void proceso();
		void orden();
		void comparar(float*,float*);
};
void composicion::entrada() {
	cuad.entrada();
	rec.entrada();
	cir.entrada();
}
void composicion::proceso() {
	cuad.proceso(perimetros,areas);
	rec.proceso(perimetros,areas);
	cir.proceso(perimetros,areas);
}
void composicion::orden() {
	float aux[3],aux2[3], auxiliar=0.0;
	for (int i=0; i<3; i++) {
		aux[i]=perimetros[i];
		aux2[i]=areas[i];
	}
	for (int i=0; i<3; i++) {//orden de mayor a menor de los perimetros
		for(int j=0; j<3; j++) {
			if(aux[i]<aux[j]) {
				auxiliar=aux[j];
				aux[j]=aux[i];
				aux[i]=auxiliar;
			}
		}
	}
	auxiliar=0.0;
	for (int i=0; i<3; i++) {//orden de mayor a menor de los areas
		for(int j=0; j<3; j++) {
			if(aux2[i]<aux2[j]) {
				auxiliar=aux2[j];
				aux2[j]=aux2[i];
				aux2[i]=auxiliar;
			}
		}
	}
	comparar(aux,aux2);
}
void composicion::comparar(float *aux1,float* aux2) {
	cuad.salida(perimetros,areas);
	rec.salida(perimetros,areas);
	cir.salida(perimetros,areas);
	vredimensiona(500,500);
	color(CYAN);
	ostringstream Acu,Are,Aci,Pcu,Pre,Pci;
	Acu<<areas[0];
	Are<<areas[1];
	Aci<<areas[2];
	Pcu<<perimetros[0];
	Pre<<perimetros[1];
	Pci<<perimetros[2];
	string acu,are,aci,pcu,pre,pci;
	acu=Acu.str();
	are=Are.str();
	aci=Aci.str();
	pcu=Pcu.str();
	pre=Pre.str();
	pci=Pci.str();
	texto(5,10,"EL area de manera descendente");
	float pos=20;
	for(int i=0; i<3; i++) { //Comparacion areas
		if(areas[2]==aux2[i]) {
			texto(5,pos,"Corresponde al circulo con "+aci+" u^2");
		} else if(areas[1]==aux2[i]) {
			texto(5,pos,"Corresponde al rectangulo con "+are+" u^2");
		} else {
			texto(5,pos,"Corresponde al cuadrado con "+acu+" u^2");
		}
		pos+=20;
	}
	texto(5,80,"EL perimetro de manera descendente");
	for(int i=0; i<3; i++) { //Comparacion areas
	pos+=20;
		if(areas[2]==aux1[i]) {
			texto(5,pos,"Corresponde al circulo con "+pci+" u");
		} else if(areas[1]==aux1[i]) {
			texto(5,pos,"Corresponde al rectangulo con "+pre+" u");
		} else {
			texto(5,pos,"Corresponde al cuadrado con "+pcu+" u");
		}
	}
	refresca();
}

int main() {
	composicion a;
	a.entrada();
	a.proceso();
	a.orden();

	return 0;
}

