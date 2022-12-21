/*
10 Hacer un programa que calcule los factoriales desde m hasta n.
*/
#include <iostream>
#include <fstream>
using namespace std;
class factorial {
	private://Declaracion de atributos de la clase
		int x;
		int y;
		int p;
		long long unsigned *fact;
	public://Declaracion de metodos de la clase
		factorial();
		~factorial();
		void entradadatos(void);
		bool validar(int,int);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
factorial::factorial() {//Constructor
	x=-1;
	y=-1;
	p=0;
	fact=new long long unsigned [x-y];
	if(fact==NULL) {
		cout<<"Error en memoria"<<endl;
	}
}
factorial::~factorial() {//Destructor
	delete fact;
}
void factorial::entradadatos() {//Metodo para entrada de datos
	while(validar(x,y)) {
		cout<<"Por favor ingrese un numero "<<endl;
		cin>>x;
		cout<<"Por favor ingrese un numero "<<endl;
		cin>>y;
	}
}
bool factorial::validar(int a,int b) {//Metodo booleano para validar el valor ingresado
	if(a<=-1 || b<=-1) {
		return true;
	} else {
		return false;
	}
}
void factorial::proceso() {//Metodo que se encarga de calcular los factoriales
	int aux;
	if(x<y) {
		aux=y;
		y=x;
		x=aux;
	}
	for(int i=0; i<x; i++) {
		fact[i]=1;
	}
	int acum=y;
	do {
		if(acum==0) {
			fact[p]=1;
		} else {
			for(int i=1; i<=acum; i++) {
				fact[p]=fact[p]*i;
			}
		}
		acum++;
		p++;
	} while(acum<=x);
}
void factorial::salida() {//Metodo para mostrar los valores del proceso
	cout<<"Los factoriales desde "<<y<<" hasta "<<x<<" son:"<<endl;
	for(int i=0; i<p; i++) {
		cout<<"["<<fact[i]<<"]"<<"  ";
	}
}
void factorial::guardar() {
	ofstream Guardar("RangoFactorial.txt");
	Guardar<<"Los factoriales desde "<<y<<" hasta "<<x<<" son:"<<endl;
	for(int i=0; i<p; i++) {
		Guardar<<"["<<fact[i]<<"]"<<"  ";
	}
}
int main() {
	factorial num1;//Creacion del objeto
	num1.entradadatos();
	num1.proceso();
	num1.salida();
	num1.guardar();
	return 0;
}
