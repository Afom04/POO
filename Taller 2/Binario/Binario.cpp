
2 Leer una cadena e imprimir su equivalente en decimal y en binario (eje. A ? vale 65 y en binario
es 1000001 o si entra A->vale 97 y en binario 1100001).
*/
#include <iostream>//Inclusion de bibliotecas a usar
#include <fstream>
using namespace std;
class cambio {//Creacion de clase 
	private:
		char letra;//Declaracion de atributos de la clase
		int ascii;
		int *binario;
	public://Declaracion de metodos de la clase
		cambio();
		~cambio();
		void entradadatos(void);
		void proceso(void);
		void salida(void);
		void guardar(void);
};
cambio::cambio() {//Constructor de la clase
	ascii=0;
	binario= new int [8];
	if (binario==NULL) {
		cout<<"Error de memoria";
	}
}
cambio::~cambio() {//Destructor de la clase
	delete binario;
}
void cambio::entradadatos() {//Metodo encargado de recibir el caracter
	cout<<"Por favor ingrese un caracter"<<endl;
	scanf("%c", &letra);
}
void cambio::proceso() {//Metodo encargado de transformar el valor ascii del caracter a binario
	ascii=letra;
	int	n=ascii,i=0;
	while(i!=8) {
		binario[i]= n%2;
		n =n/2;
		i++;
	}
}

void cambio::salida() {//Metodo encargado de los valores luego de su transformacion
	cout<<"La caracter ingresada fue <<"<<letra<<">> y su valor ascii es "<<ascii<<endl;
	cout<<"Su valor binario es ";
	for(int i=7; i>-1; i--) {
		cout<<binario[i];
	}
}
void cambio::guardar() {//Metodo encargado de perservar los valores 
	ofstream Guardar("Binario.txt");
	Guardar<<"La caracter ingresada fue <<"<<letra<<">> y su valor ascii es "<<ascii<<endl;
	Guardar<<"Su valor binario es ";
	for(int i=7; i>-1; i--) {
		Guardar<<binario[i];
	}
}

int main() {
	cambio C;
	C.entradadatos();
	C.proceso();
	C.salida();
	C.guardar();
	return 0;
}
