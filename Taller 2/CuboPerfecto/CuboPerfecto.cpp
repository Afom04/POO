/*
4 Leer un número y decir si es cubo perfecto (eje. 153: las sumatoria de sus cifras al cubo son
iguales al número; 1^3+ 5^3+ 3^3= 153.
*/
#include <iostream>
#include <fstream>
using namespace std;
class cubo {
	private://Declaracion de atributos de la clase
		int numero;
		int suma;
	public://Declaracion de metodos de la clase
		cubo();
		~cubo();
		void entradadatos(void);
		bool validar(int);
		void proceso(void);
		int potencia(int);
		void salida(void);
		void guardar(void);
};
cubo::cubo() {//Constructor del objeto
	cout<<"./"<<endl;
	numero=0;
	suma=0;
}
cubo::~cubo() {//Destructor del objeto
}
void cubo::entradadatos() {//Metodo para recibir valores
	while(validar(numero)) {
		cout<<"Por favor ingrese el numero a comprobar "<<endl;
		cin>>numero;
	}
}
bool cubo::validar(int a) {//Metodo booleano para validar el valor ingresado
	if(a<=0) {
		return true;
	} else {
		return false;
	}
}
void cubo::proceso() {//Metodo encargado de separar las cifras y calcular la suma de las potencias
	int x=numero,ultimodigito;
	while(x>=1) {
		ultimodigito=x%10;
		x=x/10;
		suma+=potencia(ultimodigito);
	}
}
int cubo::potencia(int a) { //Metodo que calcula la potencia de la cifra recibida
	int	resultado = a,potencia=3;
	while (potencia > 1) {
		resultado = resultado * a;
		potencia--;
	}
	return resultado;
}
void cubo::salida() { //Metodo encargado de mostrar el resultado del cubo perfecto
	if(numero!=suma) {
		cout<<"El numero "<<numero<<" no es un cubo perfecto"<<endl;
	} else {
		cout<<"El numero "<<numero<<" es un cubo perfecto"<<endl;
	}
}
void cubo::guardar() {
	ofstream Guardar("Cuboperfecto.txt");
	if(numero!=suma) {
		Guardar<<"El numero "<<numero<<" no es un cubo perfecto"<<endl;
	} else {
		Guardar<<"El numero "<<numero<<" es un cubo perfecto"<<endl;
	}
}
int main() {
	cubo num1;//Creacion de objeto
	num1.entradadatos();
	num1.proceso();
	num1.salida();
	num1.guardar();
}
