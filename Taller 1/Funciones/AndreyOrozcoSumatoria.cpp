#include <iostream>
#include <conio.h>

using namespace std;
//Prototipo de funciones a usar
void ordenar(int x,int y);
void sumatoria(int x,int y);
bool validar(int x, int y);
void paridad(int impares[],int p,int pares[],int o);
//Funci�n principal
int main() {
	int x=0,y=0;//Declaracion de variables a utilizar
	while(validar( x, y)) {//Ciclo while que v�lida por medio de una funci�n que los valores sean v�lidos para trabajar
		cout<<"Por favor ingrese 2 numeros enteros positivos"<<endl;
		cin>>x;
		cin>>y;
	}
	ordenar(x,y);//Env�o de valores a la funci�n para v�lidar cual n�mero es mayor
	getch ();
	return 0;
}
bool validar(int x, int y) { //Funci�n booleana para v�lidar que el valor no sea menor a 0 o sean iguales
	if(x<0 || y<0 || x==y) {
		return true;
	} else {
		return false;
	}
}
void ordenar(int x,int y) {//Funci�n encargada de verificar cual variable es de mayor valor y reorganizarla para no alterar el c�digo
	int cambio;
	if(x<y) {//Condicional que evalua si el segundo valor ingresado es mayor que el primero, para hacer un cambio de variables y no afectar el resto del c�digo
		cambio=x;
		x=y;
		y=cambio;
	}
	sumatoria(x,y);//Env�o de variables a la funci�n para mostrar la sumatoria de la distancia entre estos y mostrar cuales de estos son pares o impares
}

void sumatoria(int x,int y) {//Funci�n encargada de acumular los valores entre X y Y, y separar por medio de vectores la paridad de estos mismos
	int lim=x-y,o=0,p=0,pares[lim],impares[lim];//Declaracion de variables para separar la paridad de valores
	int i=y,suma=0;//Declaracion de variables para realizar la sumatoria de valores intermedios
	for (i; i<=x; i++) {
		suma=suma+i;
		if(i%2==0) {//Validaci�n para separar la paridad de n�meros y guardarlos por medio de un array; usando un acumulador para mostrar la cantidad de cada tipo
			pares[o]=i;
			o++;
		} else {
			impares[p]=i;
			p++;
		}
	}
	cout<<"La sumatoria desde "<<y<<" hasta "<<x<<" es igual a "<<suma<<endl;
	paridad(impares,p,pares,o);
}
	void paridad(int impares[],int p,int pares[],int o){
		cout<<"Tiene "<<p<<" numeros impares"<<endl;
		for(int i=0; i<p; i++) {//Ciclo for que recorre el array para mostrar cuales son los valores que son impares
			cout<<"["<<impares[i]<<"] ";
		}
		cout<<endl<<"Tiene "<<o<<" numeros pares"<<endl;
		for(int j=0; j<o; j++) {//Ciclo for que recorre el array para mostrar cuales son los valores que son pares
			cout<<"["<<pares[j]<<"] ";
		}
	}


