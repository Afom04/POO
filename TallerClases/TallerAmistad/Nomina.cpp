/*AMISTAD ENTRE CLASES [friend]*/
//Con funciones
/*
La amistad se debe declarar en todas las clases que se necesiten.
La funcion amiga no es miembro de ninguna clase.
La funcion amiga debe tener parametros obligatoriamente (OBJETOS)
*/

//Generar otro amigo que diga cual nombre es el mas largo
//cual es el menor y cual el intermedio(no usar string.h)

/*PROCESO
En el proceso realizar las operaciones para calcular el salario .
Se debe incluir otra variable para el SUELDO.
Tenga en cuenta:
	-Hora extra laboradas(diurnas,nocturnas,festivas diurnas, festivas nocturnas)
	-Auxilio de transporte
	-El sueldo del vendedor es el minimo y su comision desde de:
		-Si vende mas de 12000000 3%
		-Si vende mas de 25000000 6% sobre las ventas
	Se debe descontar salud, pension.
*/

#include <iostream>

using namespace std;

class Vendedor;
class Gerente;

class Operario {
		char nombre[40];
		int id;
		int salario,lon;
		float sueldo;
	public:
		void entrada(void);
		void proceso(void);
		void salida(void);
		friend float Promedio(Operario,Vendedor,Gerente); //Declaracion de AMISTAD por medio funciones(metodos)
		friend void contar(Operario,Vendedor,Gerente);

};

void Operario::entrada() {
	cout<<"Senor operario"<<endl;
	cout<<"De nombre "<<endl;
	cin.getline(nombre,40);
	cout<<"De identificador"<<endl;
	cin>>id;
	bool validar=true;
	do{
		cout<<"De su salario"<<endl	;
		cin>>salario;
		if(salario<1000000) {
			cout<<"salario invalido"<<endl;
		} else {
			validar=false;
		}
	}while(validar==true); 
}
void Operario::proceso() {
	lon=0;
	sueldo=salario-salario*0.08;//Descuento de pension y salud
	if(salario<=2000000) {
		sueldo+=117.172;
	}
	while(nombre!='\0') {
		lon+=1;
	}
	int horas[4];
	float diario=sueldo/240,extra=0;
	bool validar;
	while(validar) {
		cout<<"Ingrese el total de horas extras diurnas"<<endl;
		cin>>horas[0];
		cout<<"Ingrese el total de horas extras nocturnas"<<endl;
		cin>>horas[1];
		cout<<"Ingrese el total de horas festivas diurnas"<<endl;
		cin>>horas[2];
		cout<<"Ingrese el total de horas festivas nocturnas"<<endl;
		cin>>horas[3];
		if(horas[0]+horas[1]+horas[2]+horas[3]>=0 && horas[0]+horas[1]+horas[2]+horas[3]<=48) {
			validar=false;
		}
	}
	sueldo=(horas[0]*diario)*1.25+(horas[1]*diario)*1.75+(horas[2]*diario)*2+(horas[3]*diario)*2.5+salario;
}
void Operario::salida() {
	cout<<"OPERARIO"<<endl;
	cout<<"Nombre "<<nombre<<endl;
	cout<<"Identificacion "<<id<<endl;
	cout<<"Salario "<<salario<<endl;
	cout<<"Sueldo"<<sueldo<<endl;
	cout<<"Longitud de nombre"<<lon<<endl;
}
////////////////////////////////////////////////////////////////
class Vendedor {
		char nombre[40];
		int id;
		int salario,lon,ventas;
		float sueldo;
	public:
		void entrada(void);
		void proceso(void);
		void salida(void);
		friend float Promedio(Operario,Vendedor,Gerente);
		friend void contar(Operario,Vendedor,Gerente);
};
void Vendedor::entrada() {
	getchar();
	cout<<"Senor vendedor"<<endl;
	cout<<"De nombre "<<endl;
	cin.getline(nombre,40);
	cout<<"De identificador"<<endl;
	cin>>id;
	cout<<"De su cantidad de ventas "<<endl	;
	cin>>ventas;
}
void Vendedor::proceso() {
	lon=0;
	sueldo=salario=1000000;
	sueldo-=sueldo*0.08;//Descuento de pension y salud
	if(salario<=2000000) {
		sueldo+=117.172;
	}
	while(nombre!='\0') {
		lon+=1;
	}
	if(ventas>12000000 && ventas <=25000000) {
		cout<<"Tiene derecho a comisiones del 3%"<<endl;
		sueldo+=ventas*0.03;
	}
	if(ventas>25000000) {
		cout<<"Tiene derecho a comisiones del 6%"<<endl;
		sueldo+=ventas*0.06;
	}
}
void Vendedor::salida() {
	cout<<"VENDEDOR"<<endl;
	cout<<"Nombre "<<nombre<<endl;
	cout<<"Identificacion "<<id<<endl;
	cout<<"Salario "<<salario<<endl;
	cout<<"Sueldo"<<sueldo<<endl;
	cout<<"Longitud de nombre"<<lon<<endl;
}
////////////////////////////////////////////////////////////
class Gerente {
		char nombre[40];
		int id;
		int salario,lon;
		float sueldo;
	public:
		void entrada(void);
		void proceso(void);
		void salida(void);
		friend float Promedio(Operario,Vendedor,Gerente);
		friend void contar(Operario,Vendedor,Gerente);
};
void Gerente::entrada() {
	getchar();
	cout<<"Senor gerente"<<endl;
	cout<<"De nombre "<<endl;
	cin.getline(nombre,40);
	cout<<"De identificador"<<endl;
	cin>>id;
	bool validar=true;
	do{
		cout<<"De su salario"<<endl	;
		cin>>salario;
		if(salario<3000000) {
			cout<<"salario invalido"<<endl;
		} else {
			validar=false;
		}
	}while(validar==true); 
}
void Gerente::proceso() {
	sueldo-=salario*0.08;//Descuento de pension y salud
	lon=0;
	while(nombre!='\0') {
		lon+=1;
	}
}
void Gerente::salida() {
	cout<<"GERENTE"<<endl;
	cout<<"Nombre "<<nombre<<endl;
	cout<<"Identificacion "<<id<<endl;
	cout<<"Salario "<<salario<<endl;
	cout<<"Sueldo"<<sueldo<<endl;
	cout<<"Longitud de nombre"<<lon<<endl;
}
////////////////////////////////////////////////////////////
float Promedio(Operario obj1,Vendedor obj2,Gerente obj3) {
	float prom=0.0;
	prom=(obj1.salario+obj2.salario+obj3.salario)/3.0;
	return prom;
}
void contar(Operario Op,Vendedor Ven,Gerente Ger) {
	int aux=0,orden[3]= {Op.lon,Ven.lon,Ger.lon};
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if(orden[i]>orden[j]) {
				aux=orden[i];
				orden[i]=orden[j];
				orden[j]=aux;
			}
		}
	}
	cout<<"El orden de los nombres ordenados de mayor a menor"<<endl;
	for(int i=0; i<3; i++) {
		if(orden[i]==Op.lon) {
			cout<<Op.nombre<<endl;
		}
		if(orden[i]==Ven.lon) {
			cout<<Ven.nombre<<endl;
		}
		if(orden[i]==Ger.lon) {
			cout<<Ger.nombre<<endl;
		}
	}
}
////////////////////////////////////////////////////////////
int main() {

	Operario O;
	Vendedor V;
	Gerente G;

	O.entrada();
	O.proceso();
	V.entrada();
	V.proceso();
	G.entrada();
	G.proceso();
	O.salida();
	V.salida();
	G.salida();

	float prom=Promedio(O,V,G);

	cout<<"El promedio de salario es "<<prom<<endl;
	contar(O,V,G);
	return 0;
}
