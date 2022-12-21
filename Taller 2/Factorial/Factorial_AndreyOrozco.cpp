/*Andrey Felipe Orozco Montoya// codigo 20221678022
9 Hacer un programa que calcule el factorial de un número dado (iterativo y recursivo)
*/
#include <iostream>
#include <fstream>
using namespace std;

class factorial {
	private://Declaracion de los atributos de la clase
		int numero;
		long long unsigned factorialite;
		long long unsigned factorialrec;
	public://Declaracion de los metodos de la clase 
		factorial();
		~factorial();
		void entradadatos(void);
		bool validar(int );
		void proceso(void);
		long long unsigned recursivo(int);
		void salida(void);
		void guardar(void);
};
factorial::factorial() {//Constructor
	numero=-1;
	factorialite=1;
	factorialrec=0;
}
factorial::~factorial() {//Destructor
}
void factorial::entradadatos() {//Metodo para entrada de datos
	while(validar(numero)) {
		cout<<"Por favor ingrese un numero "<<endl;
		cin>>numero;
	}
}
bool factorial::validar(int a) {//Metodo booleano para validar el valor ingresado
	if(a<=-1) {
		return true;
	} else {
		return false;
	}
}
void factorial::proceso() {//Metodo que calcula el valor factorial de manera iterativa
	if(numero==0) {
		factorialite=1;
	} else {
		for(int i=1; i<=numero; i++) {
			factorialite=factorialite*i;
		}
	}
	factorialrec=recursivo(numero);
}
long long unsigned factorial::recursivo(int num) {//Metodo que calcula el valor factorial de manera recursiva
	if (num <= 1)
		return 1;
	return num * recursivo(num - 1); 
}
void factorial::salida(){//Metodo que muestra los valores de lo factoriales
	cout<<"El factorial iterativo de "<<numero<<" es "<<factorialite<<endl;
	cout<<"El factorial recursivo de "<<numero<<" es "<<factorialrec<<endl;
}
void factorial::guardar(){//Metodo encargado de preservar la informacion
	ofstream Guardar("Factorial.txt");
	Guardar<<"El factorial iterativo de "<<numero<<" es "<<factorialite<<endl;
	Guardar<<"El factorial recursivo de "<<numero<<" es "<<factorialrec<<endl;
}
int main(){
	factorial num1;//Creacion de objetos
	num1.entradadatos();
	num1.proceso();
	num1.salida();
	num1.guardar();
}
