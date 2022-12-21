#include <iostream>
#include <conio.h>

using namespace std;
//Prototipo de funciones que se utilizaran
void contar(char frase[50]);
void posicion(int posa[50],int pose[50],int posi[50],int poso[50],int posu[50],int a,int e,int i,int o,int u);
char llenar(char frase[50]);
//Declaración globar de variables(arreglos) que se usaran
//char frase[50];
//int posa[50],pose[50],posi[50],poso[50],posu[50];
//Funcion principal
int main() {
	char frase[50];
	llenar(frase);//Envío de el vector creado para llenarlo con espacios vacíos ' ' para que no genere un valor o caracter que rompa el programa
	cout<<"Por favor ingrese una frase"<<endl;
	cin.getline(frase,50);//Se usa el "cin.getline" para que separe cada componente en un espacio del vector
	contar(frase);//Envío del vector que contiene la frase a evaluar
}
char llenar(char frase[50]) {
	for(int c=0; c<50; c++) {//Ciclo para llenar los espacios del vector para evitar errores
		frase[c]=' ';
	}
	return frase[50];
}
void contar(char frase[50]) {//Función encargada de realizar el conteo de vocales y acomodar en los vectores las posiciones de las vocales, usando un acumulador
	int contarv=0,a=0,e=0,i=0,o=0,u=0;//Definicion de variables que funcionan como contadores de cada vocal y de el total;
	int posa[40],pose[40],posi[40],poso[40],posu[30];
	for(int p=0; p<=40; p++) {//Ciclo for que recorre el vector que contiene la frase
		if (frase[p]=='a'||frase[p]=='A') {//Condicional que se encarga de separar cada vocal, acumulandola y guardando su posición en un vector ()
			contarv++;
			posa[a]=p;
			a++;
		} else if (frase[p]=='e'||frase[p]=='E') {//Condicional que se encarga de separar cada vocal, acumulandola y guardando su posición en un vector (E)
			contarv++;
			pose[e]=p;
			e++;
		} else if (frase[p]=='i'||frase[p]=='I') {//Condicional que se encarga de separar cada vocal, acumulandola y guardando su posición en un vector (I)
			contarv++;
			posi[i]=p;
			i++;
		} else if (frase[p]=='o'||frase[p]=='O') {//Condicional que se encarga de separar cada vocal, acumulandola y guardando su posición en un vector (O)
			contarv++;
			poso[o]=p;
			o++;
		} else if (frase[p]=='u'||frase[p]=='U') {//Condicional que se encarga de separar cada vocal, acumulandola y guardando su posición en un vector (U)
			contarv++;
			posu[u]=p;
			u++;
		}
	}
	cout<<"La frase ingresada tiene un total de "<<contarv<<" vocales"<<endl;
	posicion(posa,pose,posi,poso,posu,a,e,i,o,u);//Envío del acumulado de cada vocal
	cout<<"La frase que fue ingresada es : <<"<<frase<<">>";
}
void posicion(int posa[50],int pose[50],int posi[50],int poso[50],int posu[50],int a,int e,int i, int o, int u) {//Función encargada de mostrar la posición de cada vocal y su acumulación
	if(a!=0) {//Condicional que evalua si hay una vocal especifica en la palabra por medio del acumulador
		cout<<"La frase tiene "<<a<<" vocales A"<<endl<<"En las posiciones:";
		for(int j=0; j<a; j++) {//Ciclo con el cual se recorre los vectores que guardan la posición de cada vocal
			cout<<"["<<posa[j]<<"] ";
		}
		cout<<endl;
	}
	if(e!=0) {//Condicional que evalua si hay una vocal especifica en la palabra por medio del acumulador
		cout<<"La frase tiene "<<e<<" vocales E"<<endl<<"En las posiciones:";
		for(int j=0; j<e; j++) {//Ciclo con el cual se recorre los vectores que guardan la posición de cada vocal
			cout<<"["<<pose[j]<<"] ";
		}
		cout<<endl;
	}
	if(i!=0) {//Condicional que evalua si hay una vocal especifica en la palabra por medio del acumulador
		cout<<"La frase tiene "<<i<<" vocales I"<<endl<<"En las posiciones";
		for(int j=0; j<i; j++) {//Ciclo con el cual se recorre los vectores que guardan la posición de cada vocal
			cout<<"["<<posi[j]<<"] ";
		}
		cout<<endl;
	}
	if(o!=0) {//Condicional que evalua si hay una vocal especifica en la palabra por medio del acumulador
		cout<<"La frase tiene "<<o<<" vocales O"<<endl<<"En las posiciones";
		for(int j=0; j<o; j++) {//Ciclo con el cual se recorre los vectores que guardan la posición de cada vocal
			cout<<"["<<poso[j]<<"] ";
		}
		cout<<endl;
	}

	if(u!=0) {//Condicional que evalua si hay una vocal especifica en la palabra por medio del acumulador
		cout<<"La frase tiene "<<u<<" vocales U"<<endl<<"En las posiciones";
		for(int j=0; j<u; j++) {//Ciclo con el cual se recorre los vectores que guardan la posición de cada vocal
			cout<<"["<<posu[j]<<"] ";
		}
		cout<<endl;
	}
}
