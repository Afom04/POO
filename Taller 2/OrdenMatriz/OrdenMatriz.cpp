/*
6 Leer una matriz de números y ordenarla de mayor a menor
*/
#include <iostream>
#include <fstream>

using namespace std;
class orden {//Declaracion de la clase
	private://Declaracion de atributos de la clase
		int **original;
		int **copia;
		int fila;
		int columna;
	public://Declaracion de metodos de la clase
		orden(void);
		~orden(void);
		void entrada(void);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
orden::orden() {//Constructor de la clase
	cout<<"Ingrese la cantidad de filas de la matriz"<<endl;
	cin>>fila;
	cout<<"Ingrese la cantidad de columnas de la matriz"<<endl;
	cin>>columna;
	original=new int*[fila];
	copia=new int*[fila];
	for(int i=0; i<columna; i++) {
		original[i]=new int[columna];
		copia[i]=new int[columna];
	}
	if(original==NULL || copia==NULL) {
		cout<<"Error de memoria"<<endl;
	}
	for(int p=0; p<fila; p++) {
		for(int l=0; l<columna; l++) {
			original[p][l]=0;
			copia[p][l]=0;
		}
	}
}
orden::~orden() {//Destructor de la clase
	delete original;
	delete copia;
}
void orden::entrada() {//Metodo encargado de recibir los componentes de la matriz
	cout<<"Por favor llene la matriz a ordenar"<<endl;
	for(int i=0; i<fila; i++) {
		for(int o=0; o<columna; o++) {
			cout<<"Posicion "<<i+1<<"-"<<o+1<<" ";
			cin>>original[i][o];
			copia[i][o]=original[i][o];
		}
	}
}
void orden::proceso() {//Metodo encargado de ordenar la matriz por el metodo de la burbuja
	int aux;
	for(int i=0; i<fila; i++) {
		for(int o=0; o<columna; o++) {
			for(int p=0; p<fila; p++) {
				for(int l=0; l<columna; l++) {
					if(copia[i][o]>copia[p][l]) {
						aux=copia[i][o];
						copia[i][o]=copia[p][l];
						copia[p][l]=aux;
					}
				}
			}
		}
	}
}
void orden::salida() {//Metodo encargado de mostrar al usuario la matriz ordenada
	cout<<"Matriz original"<<endl;
	for(int i=0; i<fila; i++) {
		for(int o=0; o<columna; o++) {
			cout<<"[ "<<original[i][o]<<" ]";
		}
		cout<<endl;
	}
	cout<<"Matriz ordenada"<<endl;
	for(int p=0; p<fila; p++) {
		for(int l=0; l<columna; l++) {
			cout<<"[ "<<copia[p][l]<<" ]";
		}
		cout<<endl;
	}
}
void orden::guardar() {//Metodo encargado para la preservacion de datos
	ofstream Guardar("Ordenmatriz.txt");
	Guardar<<"Matriz original"<<endl;
	for(int i=0; i<fila; i++) {
		for(int o=0; o<columna; o++) {
			Guardar<<"[ "<<original[i][o]<<" ]";
		}
		Guardar<<endl;
	}
	Guardar<<"Matriz ordenada"<<endl;
	for(int p=0; p<fila; p++) {
		for(int l=0; l<columna; l++) {
			Guardar<<"[ "<<copia[p][l]<<" ]";
		}
		Guardar<<endl;
	}
}
int main() {
	orden matriz;//Creacion del objeto
	matriz.entrada();//Invocacion de metodos
	matriz.proceso();
	matriz.salida();
	matriz.guardar();
}
