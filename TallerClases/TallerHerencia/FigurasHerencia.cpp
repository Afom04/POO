/*Generar una clase "" para un circulo, otra para un rectàngulo y otra para cuadrado.
Se debe hallar el àrea y el preìmetro de cada una de ellas, y a travez de composicion hacer un
metodo que compare las areas y otro los perimetros */
#include <iostream>
using namespace std;
class figura {
		float perimetro;
		float area;
	public:
		void setPerimetro(float p) {
			perimetro=p;
		};
		void setArea(float a) {
			area=a;
		}
		float getPerimetro() {
			return perimetro;
		}
		float getArea() {
			return area;
		}
};
class cuadrado:public figura {
		float lado;
	public:
		void entrada();
		void proceso();
		void salida();
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
	setPerimetro(lado+lado+lado+lado);
	setArea(lado*lado);
}
void cuadrado::salida() {
	cout<<"El area del cuadrado es "<<getArea()<<" unidades^2"<<endl;
	cout<<"El perimetro del cuadrado es "<<getPerimetro()<<" unidades"<<endl;
}
class rectangulo:public figura {
		float base,altura;
	public:
		void entrada ();
		void proceso();
		void salida();
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
	setPerimetro((2*altura)+(2*base));
	setArea(base*altura);
}
void rectangulo::salida() {
	cout<<"El area del rectangulo es "<<getArea()<<" unidades^2"<<endl;
	cout<<"El perimetro del rectangulo es "<<getPerimetro()<<" unidades"<<endl;
}
/////
class circulo:public figura {
		float radio;
	public:
		void entrada ();
		void proceso();
		void salida();
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
	setPerimetro(2*radio*(3.14159));
	setArea(3.14159*(radio*radio));
}
void circulo::salida() {
	cout<<"El area del circulo es "<<getArea()<<" unidades^2"<<endl;
	cout<<"El perimetro del circulo es "<<getPerimetro()<<" unidades"<<endl;
}
void ordenar(cuadrado cu,rectangulo re,circulo ci) {
	float aux[3]= {cu.getPerimetro(),re.getPerimetro(),ci.getPerimetro()},aux2[3]= {cu.getArea(),re.getArea(),ci.getArea()}, auxiliar=0.0;
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
		if(ci.getArea()==aux2[i]) {
			cout<<"Corresponde al circulo con "<<aux2[i]<<" u^2"<<endl;
		} else if(re.getArea()==aux2[i]) {
			cout<<"Corresponde al rectangulo con "<<aux2[i]<<" u^2"<<endl;
		} else {
			cout<<"Corresponde al cuadrado con "<<aux2[i]<<" u^2"<<endl;
		}
	}
	cout<<endl;
	for(int i=0; i<3; i++) { //Comparacion areas
		cout<<"EL perimetro #"<<i+1<<endl;
		if(ci.getPerimetro()==aux[i]) {
			cout<<"Corresponde al circulo con "<<aux[i]<<" u"<<endl;
		} else if(re.getPerimetro()==aux[i]) {
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
	ordenar(cuad,rec,cir);

	return 0;
}


