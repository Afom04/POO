/*Andrey Felipe Orozco Montoya// codigo 20221678022
Leer una cadena (arreglo char)y pasarla a minúsculas/mayúsculas según corresponda (eje. Hola
Mundo: ? hOLA mUNDO). Abstenerse de usar las funciones de string.h ‘A’ ‘a’
*/
#include <iostream>
#include <fstream>
using namespace std;

class letras {
	private://Declaracion de atributos de la clase
		char frase[50],frase2[50];
	public://Declaracion de metodos de la clase
		letras();//Constructor
		~letras();//Destructor
		void entradadatos(void);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
letras::letras() {//Constructor que inicializa los atributos
	cout<<"./"<<endl;
	for (int i=0; i<50; i++) {
		frase[i]=' ';
		frase[i]=' ';
	}
}
letras::~letras() { //Destructor
}
void letras::entradadatos() {//Metodo que pide la informacion al usuario
	cout<<"Por favor ingrese una frase: "<<endl;
	cin.getline(frase,50);

}
void letras::proceso() {//Metodo encargado de hacer el cambio de mayusculas a minusculas por medio del codigo ascii
	for (int o=0; frase[o]!='\0'; o++) {
		frase2[o]=frase[o];
	}
	for(int i=0; frase[i]!='\0'; i++) {
		if (frase[i]>=65 && frase[i]<=90) {
			frase[i]=frase[i]+32;
		} else if(frase[i]>=97 && frase[i]<=122) {
			frase[i]=frase[i]-32;

		}
	}
}
void letras::salida() {//Metodo que imprime en pantalla la frase alterada
	cout<<"Se ha realizado el cambio en la frase << "<<frase2<<" >>"<<endl;
	cout<<"a << "<<frase<<" >>"<<endl;
}
void letras::guardar(){
	ofstream Guardar("CambioCaracter.txt");
	Guardar<<"Se ha realizado el cambio en la frase << "<<frase2<<" >>"<<endl;
	Guardar<<"a << "<<frase<<" >>"<<endl;
}
int main() {
	letras cambio;//Creacion del objeto
	cambio.entradadatos();
	cambio.proceso();
	cambio.salida();
	cambio.guardar();
}
