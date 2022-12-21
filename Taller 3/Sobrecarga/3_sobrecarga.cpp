/*2 Modelar dos arreglos dinámicos (int, float) siguiendo las siguientes reglas:*/
#include <iostream>

using namespace std;

class sobrecarga {
	public:
		sobrecarga(float*,int*,int,int);
		void entrada(float*,int*);
		void entrada(int*,int*);
		void eliminar(float*,int*);
		void eliminar(int*,int*);
		void mostrar(float*,int*);
		void mostrar(int*,int *);
		int menu();
};

sobrecarga::sobrecarga(float *flotantes,int *enteros,int tamanoF,int tamanoI) {//Constructor de la clase usado para inicializar los vectores
	for(int i=0; i<tamanoF; i++) {
		flotantes[i]=0.0;
	}
	for(int i=0; i<tamanoI; i++) {
		enteros[i]=0;
	}
}
int sobrecarga::menu() {
	int opcion=0;
	cout<<"------------------MENU--------------------"<<endl;
	cout<<"1. Insertar"<<endl;
	cout<<"2. Eliminar"<<endl;
	cout<<"3. Imprimir"<<endl;
	cout<<"4. Salir"<<endl;
	cout<<"Por favor ingrese una opción"<<endl;
	cin>>opcion;
	if(opcion<1 || opcion>4) {
		cout<<"Opcion invalida"<<endl;
	}
	return opcion;
}
void sobrecarga::entrada(int*enteros,int *ocupacion) {
	int valor=0;
	cout<<"Por favor ingrese el valor del vector"<<endl;
	cin>>valor;
	enteros[*ocupacion]=valor;
	*ocupacion=*ocupacion+1;
	//cout<<*ocupacion;
	system("pause");
	system("cls");
}

void sobrecarga::entrada(float*flotantes,int *ocupacion) {
	float valor=0.0;
	cout<<"Por favor ingrese el valor del vector"<<endl;
	cin>>valor;
	flotantes[*ocupacion]=valor;
	*ocupacion=*ocupacion+1;
//	cout<<*ocupacion;
	system("pause");
	system("cls");
}
void sobrecarga::eliminar(float*flotantes,int *ocupacion) {
	flotantes[*ocupacion]=0.0;
	*ocupacion=*ocupacion-1;
	//cout<<*ocupacion;
	system("pause");
	system("cls");
}
void sobrecarga::eliminar(int*enteros,int *ocupacion) {
	enteros[*ocupacion]=0;
	*ocupacion=*ocupacion-1;
	cout<<*ocupacion;
	system("pause");
	system("cls");
}
void sobrecarga::mostrar(float*flotantes,int*ocupacion) {
	cout<<"ARREGLO FLOTANTE"<<endl;
	for(int i=0; i<*ocupacion; i++) {
		cout<<flotantes[i]<<"  ";
	}
	cout<<*ocupacion;
	system("pause");
	system("cls");
}
void sobrecarga::mostrar(int*enteros,int*ocupacion) {
	cout<<"ARREGLO ENTEROS"<<endl;
	for(int i=0; i<*ocupacion; i++) {
		cout<<enteros[i]<< "  ";
	}
//	cout<<*ocupacion;
	system("pause");
	system("cls");
}
int main() {
	int *enteros;
	float *flotantes;
	int tamanoF=0,tamanoI=0;
	while(tamanoF==0 || tamanoI==0) {
		cout<<"Por favor ingrese el tamano del vector entero"<<endl;
		cin>>tamanoI;
		cout<<"Por favor ingrese el tamano del vector flotante"<<endl;
		cin>>tamanoF;
	}
//Asignacion de memoria dinamica de los vectores
	enteros=new int[tamanoI];
	flotantes=new float[tamanoF];
	if(flotantes==NULL || enteros==NULL) {
		cout<<"Error en asignacion dinamica de memoria"<<endl;
		return 42;
	}
	sobrecarga a(flotantes,enteros,tamanoF,tamanoI);
	/*		cout<<"ARREGLO FLOTANTES "<<endl;
		for(int i=0; i<tamanoF; i++) {
			cout<< flotantes[i]<<"   --- ";
		}
		cout<<endl;
			cout<<"ARREGLO enteros"<<endl;
		for(int i=0; i<tamanoI; i++) {
			cout<<enteros[i]<< "   --- ";
		}
		cout<<endl;*/
	//int estadoI=1,estadoF=1;
	int ocupacionI=0,ocupacionF=0;
	int opcion=0;
	int interno=0;
	while(opcion!=4) {
		opcion=a.menu();
		switch(opcion) {
			case 1://Agregar
				do {
					cout<<"1 Si desea ingresar en flotantes ,2 para enteros"<<endl;
					cin>>interno;
					if(interno==1) {
						if(ocupacionF!=tamanoF) {
							a.entrada(flotantes,&ocupacionF);
						} else {
							cout<<"El vector se encuentra lleno."<<endl;
						}
					} else if(interno==2) {
						if(ocupacionI!=tamanoI) {
							a.entrada(enteros,&ocupacionI);
						} else {
							cout<<"El vector se encuentra lleno."<<endl;
						}
					}
				} while(interno!=1 && interno!=2);
				break;
			case 2://ELiminar
				do {
					cout<<"1 Si desea eliminar en flotantes ,2 para enteros"<<endl;
					cin>>interno;
					if(interno==1) {
						if(ocupacionF!=0) {
							a.eliminar(flotantes,&ocupacionF);
						} else {
							cout<<"El vector se encuentra vacio, no se podra eliminar nada."<<endl;
						}
					}
					if(interno==2) {
						if(ocupacionI!=0) {
							a.eliminar(enteros,&ocupacionI);
						} else {
							cout<<"El vector se encuentra vacio, no se podra eliminar nada."<<endl;
						}
					}
				} while(interno!=1 && interno!=2);
				break;
			case 3://Imprimir
				do {
					cout<<"1 Si desea visualizar flotantes ,2 para enteros"<<endl;
					cin>>interno;
					if(interno==1) {
						if(ocupacionF!=0) {
							a.mostrar(flotantes,&ocupacionF);
						} else {
							cout<<"El vector se encuentra vacio, no se podra visualizar nada."<<endl;
						}
					}
					if(interno==2) {
						if(ocupacionI!=0) {
							a.mostrar(enteros,&ocupacionI);
						} else {
							cout<<"El vector se encuentra vacio, no se podra visualizar nada."<<endl;
						}
					}
				} while(interno!=1 && interno!=2);
				break;
		}
	}
	cout<<"Gracias por usar el programa."<<endl;
	delete enteros;
	delete flotantes;
	return 0;

}

