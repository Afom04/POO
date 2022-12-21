/*Generar una clase "" para un circulo, otra para un rectàngulo y otra para cuadrado.
Se debe hallar el àrea y el preìmetro de cada una de ellas, y a travez de composicion hacer un
metodo que compare las areas y otro los perimetros */

#include <iostream>
class rectangulo;
class circulo;
using namespace std;
class cuadrado {
		float lado;
		float perimetro,area;
	public:
		void entrada ();
		void proceso();
		void salida();
		friend void orden(cuadrado,rectangulo,circulo);
};
void cuadrado::entrada() {
	cout<<"Por favor ingrese el tamano de los lados del cuadrado"<<endl;
	cin>>lado;
	if(lado<1) {
		cout<<"valores invalidos"<<endl;
		entrada();
	}
}
void cuadrado::proceso() {
	perimetro=lado+lado+lado+lado;
	area=lado*lado;
}
void cuadrado::salida() {
	cout<<"El area del cuadrado es "<<area<<" unidades^2"<<endl;
	cout<<"El perimetro del cuadrado es "<<perimetro<<" unidades"<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////
class rectangulo {
		float area,perimetro;
		float base,altura;
	public:
		void entrada ();
		void proceso();
		void salida();
		friend void comparar(cuadrado,rectangulo,circulo);
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
void rectangulo::proceso() {
	perimetro=(2*altura)+(2*base);
	area=base*altura;
}
void rectangulo::salida() {
	cout<<"El area del rectangulo es "<<area<<" unidades^2"<<endl;
	cout<<"El perimetro del rectangulo es "<<perimetro<<" unidades"<<endl;
}
/////////////////////////////////////////////////////////////////////////////////
class circulo {
		int radio;
		float perimetro,area;
	public:
		void entrada ();
		void proceso();
		void salida();
		friend void orden(cuadrado,rectangulo,circulo);
};
void circulo::entrada() {
	cout<<endl<<"Por favor ingrese el tamano del radio del circulo"<<endl;
	cin>>radio;
	if(radio<1) {
		cout<<"valores invalidos"<<endl;
		entrada();
	}
}
void circulo::proceso() {
	perimetro=2*radio*(3.14159);
	area=3.14159*(radio*radio);
}
void circulo::salida() {
	cout<<"El area del circulo es "<<area<<" unidades^2"<<endl;
	cout<<"El perimetro del circulo es "<<perimetro<<" unidades"<<endl;
}

void orden(cuadrado cu,rectangulo re,circulo ci) {
	float aux[3]= {cu.perimetro,re.perimetro,ci.perimetro},aux2[3]= {cu.area,re.area,ci.area}, auxiliar=0.0;
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
		for(int i=0; i<3; i++) { //Comparacion areas
		cout<<"EL area #"<<i+1<<endl;
		if(ci.area==aux2[i]) {
			cout<<"Corresponde al circulo con "<<aux2[i]<<" u^2"<<endl;
		} else if(re.area==aux2[i]) {
			cout<<"Corresponde al rectangulo con "<<aux2[i]<<" u^2"<<endl;
		} else {
			cout<<"Corresponde al cuadrado con "<<aux2[i]<<" u^2"<<endl;
		}
	}
	cout<<endl;
	for(int i=0; i<3; i++) { //Comparacion areas
		cout<<"EL perimetro #"<<i+1<<endl;
		if(ci.perimetro==aux[i]) {
			cout<<"Corresponde al circulo con "<<aux[i]<<" u"<<endl;
		} else if(re.perimetro==aux[i]) {
			cout<<"Corresponde al rectangulo con "<<aux[i]<<" u"<<endl;
		} else {
			cout<<"Corresponde al cuadrado con "<<aux[i]<<" u"<<endl;
		}
	}
}


int main() {
	cuadrado cuad;
	rectangulo rec;
	circulo cir;
	cuad.entrada();
	rec.entrada();
	cir.entrada();
	cuad.proceso();
	rec.proceso();
	cir.proceso();
	cuad.salida();
	rec.salida();
	cir.salida();
	orden(cuad,rec,cir);
	return 0;
}

