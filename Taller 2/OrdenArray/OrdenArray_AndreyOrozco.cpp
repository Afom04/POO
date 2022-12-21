/*Andrey Felipe Orozco Montoya cod:20221578022
5 Leer un arreglo de números y ordenarlos de menor a mayor
*/
#include <iostream>
#include <fstream>
using namespace std;
class orden {//Creacion de la clase
	private://Declaracion de atributos de la clase
		int *num;
		int*dos;
		int tam,i;
	public://Declaracion de metodos de la clase
		orden();
		~orden();
		void entrada();
		void proceso();
		void salida();
		void guardar();
};
orden::orden() {//Constructor de la clase
	i=0;
	cout<<"Ingrese la cantidad de numeros"<<endl;
	cin>>tam;
	num=new int [tam];
	if(num==NULL) {
		cout<<"Error de memoria"<<endl;
	}
	dos=new int [tam];
	if(dos==NULL) {
		cout<<"error 2"<<endl;
	}
	for (i ; i<tam; i++) {
		num[i]=0;
		dos[i]=0;
	}
}
orden::~orden() {//Desctructor de la clase
	delete num;
	delete dos;
}
void orden::entrada() {//Metodo que recibe los valores del array
	for(i=0; i<tam; i++) {
		cout<<"Ingrese un dato"<<endl;
		cin>>num[i];
		dos[i]=num[i];
	}
}
void orden::proceso() {//Metodo encargado de ordenar el vector de manera ascendente
	int aux=0;
	for(i=0; i<tam; i++) {
		for(int j=i; j<tam; j++) {
			if(num[i]>num[j]) {
				aux=num[i];
				num[i]=num[j];
				num[j]=aux;
			}
		}
	}
}
void orden::salida() {//Metodo de salida de datos despues de su ordenamiento
	cout<<"Datos originales"<<endl;
	for(i=0; i<tam; i++) {
		cout<<dos[i]<<" ";
	}
	cout<<endl<<"Datos ordenados"<<endl;
	for(i=0; i<tam; i++) {
		cout<<num[i]<<" ";
	}
}
void orden::guardar() {//Metodo encargado de preservar los datos
	ofstream Guardar("Orden.txt");
	Guardar<<"Datos originales"<<endl;
	for(i=0; i<tam; i++) {
		Guardar<<dos[i]<<" ";
	}
	Guardar<<endl<<"Datos ordenados"<<endl;
	for(i=0; i<tam; i++) {
		Guardar<<num[i]<<" ";
	}
}
int main() {
	orden cambio;//Creacion del objeto
	cambio.entrada();//Invocacion de los metodos del objeto
	cambio.proceso();
	cambio.salida();
	cambio.guardar();
	return 0;
}