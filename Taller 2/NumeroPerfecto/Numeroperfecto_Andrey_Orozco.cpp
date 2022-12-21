/*Andrey Felipe Orozco Montoya// codigo 20221678022
3. Leer un número y decir si es perfecto (eje. 6: sus divisores son: 1,2,3 y la suma es = 6. El número
es perfecto)
*/
#include <iostream>
#include <fstream>
using namespace std;

class perfecto {
	private://Declaracion de atributos de la clase
		int numero;
		int divisor;
		int *divisores;
		int cont;
	public://Declaracion de metodos de la clase
		perfecto();
		~perfecto();
		void entradadatos(void);
		bool validar(int);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
perfecto::perfecto() { //Constructor de la clase
	cout<<"./"<<endl;
	divisores=new int[numero];
	numero=0;
	divisor=0;
	cont=0;
}
perfecto::~perfecto() { //Destructor de la clase
}
void perfecto::entradadatos() { //Metodo que permite la entrada de datos y su posible validacion
	while(validar(numero)) {
		cout<<"Por favor ingrese el numero a comprobar "<<endl;
		cin>>numero;
	}
}
bool perfecto::validar(int a) { //Metodo que valida el valor de entrada
	if(a<=0) {
		return true;
	} else {
		return false;
	}
}
void perfecto::proceso() { //Metodo que saca los divisores y los acumula
	int lim=numero/2;
	for(int i=1; i<=lim; i++) {
		if(numero%i==0) {
			divisores[cont]=i;
			divisor+=i;
			cont++;
		}
	}
}
void perfecto::salida() { //Metodo encargado de mostrar si el numero ingresado es perfecto
	cout<<"El numero "<<numero<<" tiene como divisores a "<<endl;
	for(int i=0; i<cont; i++) {
		cout<<divisores[i]<<" ";
	}
	cout<<endl<<"Y la suma de estos es "<<divisor;
	if(numero!=divisor) {
		cout<<endl<<"Por lo tanto no es un numero perfecto"<<endl;
	} else {
		cout<<endl<<"Por lo tanto es un numero perfecto"<<endl;
	}
}
void perfecto::guardar() {
	ofstream Guardar("Numeroperfecto.txt");
	Guardar<<"El numero "<<numero<<" tiene como divisores a "<<endl;
	for(int i=0; i<cont; i++) {
		Guardar<<divisores[i]<<" ";
	}
	Guardar<<endl<<"Y la suma de estos es "<<divisor;
	if(numero!=divisor) {
		Guardar<<endl<<"Por lo tanto no es un numero perfecto"<<endl;
	} else {
		Guardar<<endl<<"Por lo tanto es un numero perfecto"<<endl;
	}
}
int main() {
	perfecto num;//Creacion de objeto
	num.entradadatos();
	num.proceso();
	num.salida();
	num.guardar();
}
