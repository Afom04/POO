/*Andrey Felipe Orozco Montoya// codigo 20221678022
7 Leer una matriz y hallar la traspuesta (maneje dos matrices, una para la original y otra para la
traspuesta e imprímalas)
*/
#include <iostream>
#include <fstream>
using namespace std;
class matriz {//Declaracion de clase
	private://Declaracion de atributos de la clase
		int x,y;
		int **original;
		int **traspuesta;
	public://Declaracion de metodos de la clase
		matriz();
		~matriz();
		void entradadatos(void);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
matriz::matriz() {//Constructor
	cout<<"Ingrese la cantidad de filas"<<endl;
	cin>>x;
	cout<<"Ingrese la cantidad de columnas"<<endl;
	cin>>y;
	original=new int *[x];
	traspuesta=new int *[y];
	for(int p=0; p<x; p++) {
		original[p]=new int[y];
	}
	for(int l=0; l<y; l++) {
		traspuesta[l]=new int[x];
	}
	if(original==NULL || traspuesta==NULL) {
		cout<<"Error de memoria"<<endl;
	}
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			original[i][o]=0;
			traspuesta[o][i]=0;
		}
	}
}
matriz::~matriz() {//Destructor
}
void matriz::entradadatos() {//Metodo para la pedida de datos al usuario
	cout<<"Por favor llene la matriz "<<endl;
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			cout<<"Posicion "<<i+1<<"-"<<o+1<<"  ";cin>>original[i][o];
		}
		cout<<endl;
	}
}
void matriz::proceso() {//Metodo encargado de trasponer la matriz
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			traspuesta[i][o]=original[o][i];
		}
	}
}
void matriz::salida() {//Metodo encargado de mostrar el proceso al usuario
	cout<<"La matriz original es "<<endl;
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			cout<<"[ "<<original[i][o]<<"]";
		}
		cout<<endl;
	}
	cout<<"La matriz traspuesta es "<<endl;
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			cout<<"[ "<<traspuesta[i][o]<<"]";
		}
		cout<<endl;
	}
}
void matriz::guardar(){//Metodo encargado de preservar las matrices
	ofstream Guardar("Matriztraspuesta.txt");
		Guardar<<"La matriz original es "<<endl;
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			Guardar<<"[ "<<original[i][o]<<"]";
		}
		Guardar<<endl;
	}
	Guardar<<"La matriz traspuesta es "<<endl;
	for(int i=0; i<x; i++) {
		for(int o=0; o<y; o++) {
			Guardar<<"[ "<<traspuesta[i][o]<<"]";
		}
		Guardar<<endl;
	}
}
int main() {
	matriz m1;//Creacion del objeto
	m1.entradadatos();
	m1.proceso();
	m1.salida();
	m1.guardar();
}
