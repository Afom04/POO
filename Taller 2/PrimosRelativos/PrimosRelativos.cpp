/*
11 Hacer un programa que lea dos números y diga si son primos relativos.
*/
#include <iostream>
#include <fstream>

using namespace std;

class primo {//Creacion de la clase
	private://Declaracion de atributos de la clase
		int x;
		int y;
		int cont;
	public://Declaracion de metodos de la clase
		primo();
		~primo();
		void entrada(void);
		bool validar(int,int);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
primo::primo() {//Constructor de la clase
	x=-1;
	y=-1;
	cont=0;
}
primo::~primo() {//Destructor de la clase
}
void primo::entrada() {//Metodo de entrada de datos
	while(validar(x,y)) {
		cout<<"Por favor ingrese el primer numero"<<endl;
		cin>>x;
		cout<<"Por favor ingrese el segundo numero"<<endl;
		cin>>y;
	}
}
bool primo::validar(int x, int y) {//Metodo boleeano que se encarga de validar valores positivos
	if(x<0 ||y<0) {
		return true;
	}
	return false;
}
void primo::proceso() {//Metodo encargado de sacar los divisores de los numeros brindados
	int aux;
	if(x<y) {
		aux=y;
		y=x;
		x=aux;
	}
	int lim=x/2;
	for (int i=1; i<=lim; i++) {
		if(x%i==0 && y%i==0) {
			cont++;
		}
	}
}
void primo::salida() {//Metodo encargado de mostrar los datos para ver si son primos
	if(cont==1) {
		cout<<"Los numeros "<<x<<" y "<<y<<" son primos relativos"<<endl;
	} else {
		cout<<"Los numeros "<<x<<" y "<<y<<" no son primos relativos"<<endl;
	}
}
void primo::guardar() {//Metodo que se encarga de la preseverancia de datos
	ofstream Guardar("Primos.txt");
	if(cont==1) {
		Guardar<<"Los numeros "<<x<<" y "<<y<<" son primos relativos"<<endl;
	} else {
		Guardar<<"Los numeros "<<x<<" y "<<y<<" no son primos relativos"<<endl;
	}
}

int main() {
	primo num1;//Creacion de objeto
	num1.entrada();
	num1.proceso();
	num1.salida();
	num1.guardar();
}
