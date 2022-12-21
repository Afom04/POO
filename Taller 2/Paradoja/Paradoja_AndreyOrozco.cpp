/*Andrey Felipe Orozco Montoya // Cod: 20221578022
8 Hacer un programa en C++ que calcule la paradoja del cumpleaños.
*/
#include <iostream>
#include <fstream>

using namespace std;

class paradoja {//Declaracion de clase
	private://Declaracion de atributos de la clase
		int cant;
		long double prb,fail;
	public://Declaracion de metodos de la clase
		paradoja();
		~paradoja();
		void entrada(void);
		bool validar(int);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
paradoja::paradoja() {//Constructor de la clase
	cant=0;
	prb=1;
	fail=prb;
}
paradoja::~paradoja() {//Destructor de la clase
}
void paradoja::entrada() {//Metodo que permite la entrada de datos
	while(validar(cant)) {
		cout<<"Por favor ingrese el total de personas en el grupo"<<endl;
		cin>>cant;
	}
}
bool paradoja::validar(int a) {//Metodo que valida que la menos haya una persona en el grupo
	if(a<2) {
		return true;
	}
	return false;
}
void paradoja::proceso() {//Metodo encargado de calcular el porcentaje de acierto como de falla
	for(int i=0; i<cant; i++) {
		prb=prb*(365-i)/365;
		fail=prb;
	}
	prb=100*(1-prb);
}
void paradoja::salida() {//Metodo que muestra el proceso obtenido
	cout<<"La probabilidad de que en un grupo de "<<cant<<" de personas, dos cumplan anios el mismo dia es de "<<prb<<"%"<<endl;
	cout<<"Por lo cual no cumplen el mismo dia "<<fail*100<<"%"<<endl;
}
void paradoja::guardar() {//Metodo encargado de preservar el resultado
	ofstream Guardar("Paradoja.txt");
	Guardar<<"La probabilidad de que en un grupo de "<<cant<<" de personas, dos cumplan años el mismo dia es de "<<prb<<"%"<<endl;
	Guardar<<"Por lo cual no cumplen el mismo dia "<<fail*100<<"%"<<endl;
}
int main() {
	paradoja grupo;
	grupo.entrada();
	grupo.proceso();
	grupo.salida();
	grupo.guardar();
}