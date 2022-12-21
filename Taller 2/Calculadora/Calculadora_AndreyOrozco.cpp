/*Andrey Felipe Orozco Montoya // Cod: 20221578022
12 Realice un programa que lee dos números y realice las operaciones básicas (+, -, *, %), se debe
utilizar un menú así:
Menú principal
1. Suma
2. Resta
3. Producto
4. División
5. Salir
Se sale del programa sólo si se elige la opción 5
*/
#include <iostream>
#include <fstream>
using namespace std;
class calculadora {//Declaracion de la clase
	private://Declaracion de atributos de la clase
		double x;
		double y;
		double resultado;
	public:
		int opc;//Declaracion de atributo publico para poder repetir el menu
		calculadora();//Declaracion de metodos de la clase
		~calculadora();
		void entrada();
		void proceso();
		void salida();
		void guardar();
		void reinicio();
};
calculadora::calculadora() {//Constructor de la clase
	x=0;
	y=0;
	resultado=0.0;
	opc=0;
}
calculadora::~calculadora() {//Destructor de la clase
}
void calculadora::entrada() {//Metodo encargado de mostrar el menu y recibir que operacion se quiere hacer
	cout<<"			Menu principal"<<endl;
	cout<<"1.Suma\n";
	cout<<"2.Resta\n";
	cout<<"3.Producto\n";
	cout<<"4.Division\n";
	cout<<"5.Salir\n";
	cin>>opc;
	switch(opc) {
		case 1:
			cout<<"Ingrese el primer sumando"<<endl;
			cin>>x;
			cout<<"Ingrese el segundo sumando"<<endl;
			cin>>y;
			break;
		case 2:
			cout<<"Ingrese el minuendo de la operacion:"<<endl;
			cin>>x;
			cout<<"Ingrese el sustraendo de la operacion:"<<endl;
			cin>>y;
			break;
		case 3:
			cout<<"Ingrese el multiplicando:"<<endl;
			cin>>x;
			cout<<"Ingrese el multiplicador:"<<endl;
			cin>>y;
			break;
		case 4:
			cout<<"Ingrese el dividendo:"<<endl;
			cin>>x;
			while(y==0) {
				cout<<"Ingrese el divisor"<<endl;
				cin>>y;
				if(y==0) {
					cout<<"El divisor no puede ser 0"<<endl;
				}
			}

			break;
		case 5:
			cout<<"Gracias por usar este programa"<<endl;
			break;
		default:
			cout<<"Opcion invalida"<<endl;
	}
}

void calculadora::proceso() {//Metodo encargado de operar segun la opcion seleccionada 
	switch(opc) {
		case 1:
			resultado=x+y;
			break;
		case 2:
			resultado=x-y;
			break;
		case 3:
			resultado=x*y;
			break;
		case 4:
			resultado=x/y;
			break;
	}
}
void calculadora::salida() {//Metodo encargado de la salida de datos segun la operacion que se haya elegido
	switch(opc) {
		case 1:
			cout<<"El resultado de la operacion "<<endl;
			cout<<x<<"+"<<y<<"="<<resultado<<endl;
			break;
		case 2:
			cout<<"El resultado de la operacion "<<endl;
			cout<<x<<"-"<<y<<"="<<resultado<<endl;
			break;
		case 3:
			cout<<"El resultado de la operacion "<<endl;
			cout<<x<<"X"<<y<<"="<<resultado<<endl;
			break;
		case 4:
			cout<<"El resultado de la operacion "<<endl;
			cout<<x<<"/"<<y<<"="<<resultado<<endl;
			break;
	}
}
void calculadora::guardar() {//Metodo encargado de preservar las operaciones con la opcion que se ingreso
	ofstream Guardar("Caculadora.txt", ios::app);
	Guardar<<"			Menu principal"<<endl;
	Guardar<<"1.Suma\n";
	Guardar<<"2.Resta\n";
	Guardar<<"3.Producto\n";
	Guardar<<"4.Division\n";
	Guardar<<"5.Salir\n";
	Guardar<<"Opción seleccionada "<<opc;
	switch(opc) {
		case 1:
			Guardar<<"El resultado de la operacion "<<endl;
			Guardar<<x<<"+"<<y<<"="<<resultado<<endl;
			break;
		case 2:
			Guardar<<"El resultado de la operacion "<<endl;
			Guardar<<x<<"-"<<y<<"="<<resultado<<endl;
			break;
		case 3:
			Guardar<<"El resultado de la operacion "<<endl;
			Guardar<<x<<"X"<<y<<"="<<resultado<<endl;
			break;
		case 4:
			Guardar<<"El resultado de la operacion "<<endl;
			Guardar<<x<<"/"<<y<<"="<<resultado<<endl;
			break;
	}
}
void calculadora::reinicio() {//Metodo que reinicia las variables 
	x=0;
	y=0;
	resultado=0;
}
int main() {
	calculadora opcion;//Creacion del objeto
	while(opcion.opc!=5) {//Ciclo while para repetir la operacion hasta que se seleccione la salida
		opcion.entrada();
		opcion.proceso();//Invocacion de metodos de la clase
		opcion.salida();
		opcion.guardar();
		opcion.reinicio();
	}
}
