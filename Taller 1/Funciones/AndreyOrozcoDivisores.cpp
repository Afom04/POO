#include <iostream>
#include <conio.h>

using namespace std;
//Prototipo de funciones a usar
void divisores(int a,int b);
void evaluar(int cont1,int cont2,int a, int b);
bool validar(int c, int d);
//Funcion principal
int main() {
	//Declaracion de variables a utilizar
	int x=0,y=0;
	bool validacion=true;
	//Ciclo para while para validar el ingreso de datos
	while(validar(x,y)) {
		cout<<"Por favor ingrese 2 numeros enteros"<<endl;
		cin>>x;
		cin>>y;
	}
	divisores(x,y);//Env�o de valores a la funci�n para sacar sus divisores y ver cual tiene mayor cantidad
	getch();
	return 0;
}

bool validar(int c, int d) { //Funci�n booleana para v�lidar que el valor no sea menor a 1
	if(c<=0 || d<=0) {
		return true;
	} else {
		return false;
	}
}

void divisores(int a,int b) {//Funci�n de tipo Void que muestra los divisores y acumula la cantidad de estos para v�lidarlos
	int contadorA=0, contadorB=0;;
	cout<<"El numero "<<a<<" tiene estos divisores:"<<endl;
	for(int i=1; i<=a; i++) {
		if(a%i==0) {
			cout<<"["<<i<<"] ";
			contadorA ++;
		}
	}
	
	cout<<endl<<"El numero "<<b<<" tiene estos divisores:"<<endl;
	for(int o=1; o<=b; o++) {
		if(b%o==0) {
			cout<<"["<<o<<"] ";
			contadorB ++;
		}
	}
	evaluar(contadorA,contadorB,a,b);//Env�o de los contadores para evaluar cu�l tiene mayor cantidad de divisores
}

void evaluar(int cont1,int cont2,int a,int b) {//Funci�n void que compara la cantidad de de divisores de cada numero
	if(cont1>cont2) {
		cout<<endl<<"El numero "<<a<<" tiene mayor cantidad de divisores";
	} else {
		if(cont2>cont1) {
			cout<<endl<<"El numero "<<b<<" tiene mayor cantidad de divisores";
		} else {
			if(cont1==cont2) {
				cout<<endl<<"El numero "<<a<<" tiene la misma cantidad de divisores que el numero "<<b<<endl;
			}
		}
	}
}
