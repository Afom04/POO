#include <iostream>
//Herencia
using namespace std;

class persona {
		char nom[30];
		int edad;
		long int id;
	public:
		void entrada();
		void salida();
};
void persona::entrada() {
	getchar();
	cout<<"De nombre"<<endl;
	cin.getline(nom,30);
	cout<<"De edad"<<endl;
	cin>>edad;
	cout<<"De identificacion"<<endl;
	cin>>id;
}
void persona::salida() {
	cout<<"Su nombre es "<<nom <<endl;
	cout<<"Su edad "<<edad<<endl;
	cout<<"Su identificacion "<<id<<endl;
}
///
class estudiante:public persona {
		long int codE;
		float nota[6],promedio;
	public:
		void entradaE();
		void procesoE();
		void salidaE();
};
void estudiante::entradaE() {
	cout<<"Estudiante"<<endl;
	entrada();//Reclamo de herencia por segundo concepto
	cout<<"De codigo"<<endl;
	cin>>codE;
	cout<<"De Nota"<<endl;
	for(int j=0; j<6; j++) {
		cin>>nota[j];
	}
}
void estudiante::procesoE() {
	float ponderado[6]= {0.1,0.25,0.2,0.15,0.2,0.1};
	for(int i=0; i<6; i++) {
		promedio+=(nota[i]*ponderado[i]);
	}
	promedio/=6.0;
}
void estudiante::salidaE() {
	salida();
	cout<<"su codigo "<<codE<<endl;
	cout<<"Sus notas son ";
	for(int j=0; j<6; j++) {
		cout<<nota[j]<<" ";
	}
	cout<<"Su promedio es "<<promedio<<endl;
}
//
class trabajador:public persona {
		int codT,sueldo,salario;
		char cargo[40];
	public:
		void entradaT();
		void procesoT();
		float procesoO();
		//float procesoG();
		float procesoV();
		void salidaT();
};
void trabajador::entradaT() {
	cout<<"Senor trabajador"<<endl;
	entrada();
	getchar();
	cout<<"De cargo"<<endl;
	cin.getline(cargo,40);
	cout<<"De codigo"<<endl;
	cin>>codT;
	bool validar;
	while(validar) {
		cout<<"De sueldo"<<endl;
		cin>>sueldo;
		if(sueldo<1000000){
			cout<<"Cantidad invalida"<<endl;
		}else{
			validar=false;
		}
	}
}
void trabajador::procesoT() {
	float extra=0.0;
	for(int i=0; i<cargo[i]!='\0'; i++) {
		if(cargo[i]>='A' && cargo[i]<='Z') {
			cargo[i]+=32;
		}
	}

	if(cargo=="operario") {
		extra=procesoO();
	}
	if(cargo=="vendedor") {
		extra=procesoV();
	}
	/*	if(cargo=="gerente"){
			procesoG();
		}*/
	if(sueldo<=2000000) {
		salario+=117.172;
	}
	salario=sueldo-(sueldo*0.08)+extra;//El 8% corresponde al descuento de de pensión y salud (4% de salud y 4% de pensión)
}
float trabajador::procesoO() {
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
	return extra=((horas[0]*diario)*1.25)+((horas[1]*diario)*1.75)+((horas[2]*diario)*2)+((horas[3]*diario)*2.5);
}
float trabajador::procesoV() {
	float ventas=0.0;
	cout<<"Por favor ingrese la cantidad de ventas que obtuvo"<<endl;
	cin>>ventas;
	if(ventas>12000000 && ventas <=25000000) {
		cout<<"Tiene derecho a comisiones del 3%"<<endl;
		return ventas*0.03;
	}
	if(ventas>25000000) {
		cout<<"Tiene derecho a comisiones del 6%"<<endl;
		return ventas*0.06;
	}
	cout<<"No tiene derecho a comisiones"<<endl;
	return 0;
}
//void trabajador::procesoG() {

void trabajador::salidaT() {
	salida();
	getchar();
	cout<<"Cargo "<<cargo<<endl;
	cout<<"Codigo "<<codT<<endl;
	cout<<"Sueldo"<<sueldo<<endl;
}
//
int main() {

	estudiante E;
	trabajador T;

	E.entradaE();
	T.entradaT();
//T.procesoT();
	E.procesoE();
	E.salidaE();
	T.salidaT();
	return 0;
}
