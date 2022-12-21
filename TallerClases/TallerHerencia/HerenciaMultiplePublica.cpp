//Herencia multiple publica

#include <iostream>
using namespace std;

class T {
		char marca[30],procesador[20];
		int precio,especificacion;//generacion
	public:
		void entradaT();
		void procesoT();
		void salidaT();
};
void T::entradaT() {
	cout<<"Por favor ingrese la marca del dispositivo"<<endl;
	cin.getline(marca,30);
	cout<<"Por favor ingrese el procesador"<<endl;
	cin.getline(procesador,20);
	/*cout<<"Ingrese la generacion del procesador"<<endl;
	cin>>generacion;*/
	cout<<"Ingrese la espcificacion del procesador (core i#/rizen #)"<<endl;
	cin>>especificacion;
}
void T::procesoT() {
	if(especificacion==9) {

	}
	if(especificacion==7){
		
	}
	if(especificacion==5){
		
	}
	if(especificacion==3){
		
	}
}
////////////////////////////////////
class P {
		char marca[30],tipo[30];
		int resx,resy,tamano;
		int precio;
	public:
		void entradaT();
		void salidaT();
};
class Computador: public T, public P {
		char marca[30],tipo[30];
		int precio,DD;
	public:
		void entrada();
		//proceso(); //calcular cotizacion
		void salida();
}
class Computador::entrada() {

}

int main() {
	Computador PC;
	PC.entrada();
	PC.entradaT();

	return 0;
}
