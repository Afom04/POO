/*Generar una clase "" para un circulo, otra para un rectàngulo y otra para cuadrado.
Se debe hallar el àrea y el preìmetro de cada una de ellas, y a travez de composicion hacer un
metodo que compare las areas y otro los perimetros */

#include <iostream>

using namespace std;
class cuadrado {
	private:
		float lado;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void cuadrado::entrada() {
	cout<<"Por favor ingrese el tamano de los lados del cuadrado"<<endl;
	cin>>lado;
	if(lado<1) {
		cout<<"valores invalidos"<<endl;
		entrada();
	}
}
void cuadrado::proceso(float*perimetros,float*areas) {
	perimetros[0]=lado+lado+lado+lado;
	areas[0]=lado*lado;
}
void cuadrado::salida(float*perimetros,float*areas) {
	cout<<"El area del cuadrado es "<<areas[0]<<" unidades^2"<<endl;
	cout<<"El perimetro del cuadrado es "<<perimetros[0]<<" unidades"<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////
class rectangulo {
	private:
		float base,altura;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void rectangulo::entrada() {
	cout<<endl<<"Por favor ingrese el tamano de la base del rectangulo"<<endl;
	cin>>base;
	cout<<"Por favor ingrese el tamano de la altura del rectangulo "<<endl;
	cin>>altura;
	if(base==altura || base<1 || altura<1) {
		cout<<"valores invalidos"<<endl;
		entrada();
	}
}
void rectangulo::proceso(float*perimetros,float*areas) {
	perimetros[1]=(2*altura)+(2*base);
	areas[1]=base*altura;
}
void rectangulo::salida(float*perimetros,float*areas) {
	cout<<"El area del rectangulo es "<<areas[1]<<" unidades^2"<<endl;
	cout<<"El perimetro del rectangulo es "<<perimetros[1]<<" unidades"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
class circulo {
	private:
		int radio;
	public:
		void entrada ();
		void proceso(float*,float*);
		void salida(float*,float*);
};
void circulo::entrada() {
	cout<<endl<<"Por favor ingrese el tamano del radio del circulo"<<endl;
	cin>>radio;
	if(radio<1) {
		cout<<"valores invalidos"<<endl;
		entrada();
	}
}
void circulo::proceso(float*perimetros,float*areas) {
	perimetros[2]=2*radio*(3.14159);
	areas[2]=3.14159*(radio*radio);
}
void circulo::salida(float*perimetros,float*areas) {
	cout<<"El area del circulo es "<<areas[2]<<" unidades^2"<<endl;
	cout<<"El perimetro del circulo es "<<perimetros[2]<<" unidades"<<endl;
}
//////////////////////////////////////////////////////////
class composicion {
		cuadrado cuad;
		rectangulo rec;
		circulo cir;
		float areas[3];
		float perimetros[3];
	public:
		void entrada();
		void proceso();
		void salida();
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
	for(int i=0; i<3; i++) { //Comparacion areas
		cout<<"EL area #"<<i+1<<endl;
		if(areas[2]==aux2[i]) {
			cout<<"Corresponde al circulo con "<<aux2[i]<<" u^2"<<endl;
		} else if(areas[1]==aux2[i]) {
			cout<<"Corresponde al rectangulo con "<<aux2[i]<<" u^2"<<endl;
		} else {
			cout<<"Corresponde al cuadrado con "<<aux2[i]<<" u^2"<<endl;
		}
	}
	cout<<endl;
	for(int i=0; i<3; i++) { //Comparacion areas
		cout<<"EL perimetro #"<<i+1<<endl;
		if(areas[2]==aux1[i]) {
			cout<<"Corresponde al circulo con "<<aux1[i]<<" u"<<endl;
		} else if(areas[1]==aux1[i]) {
			cout<<"Corresponde al rectangulo con "<<aux1[i]<<" u"<<endl;
		} else {
			cout<<"Corresponde al cuadrado con "<<aux1[i]<<" u"<<endl;
		}
	}
}
void composicion::salida() {
	cuad.salida(perimetros,areas);
	rec.salida(perimetros,areas);
	cir.salida(perimetros,areas);
	orden();
}
int main() {
	composicion a;
	a.entrada();
	a.proceso();
	a.salida();

	return 0;
}

