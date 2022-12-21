#include <iostream>
#include <math.h>
using namespace std;

class base {//Clase base que tiene los valores del vector raiz
		int n,t,*raiz;
	public:
		~base();
		int getRaiz(int);
		int getT();
		void leer();
		void ver();
};
base::~base() {
	delete raiz;
}
void base::leer() {
		cout<<"Por favor ingrese un numero entero"<<endl;
		cin>>n;
	t=pow(2,n)-1;
	raiz=new int[t];
	if(raiz==NULL) {
		cout<<"Error en asignacion de memoria dinamica"<<endl;
	}
	fflush(stdin);
	/*cout<<"Por favor llene el vector padre con "<<t<<" valores"<<endl;
	  cin>>raiz[i];*/
	for(int i=0; i<t; i++) {
		raiz[i]=i+1;
	}
}
void base::ver() {//Metodo encargado de mostrar los valores del vector raiz
	cout<<"Vector padre contiene"<<endl;
	for(int i=0; i<t; i++) {
		cout<<raiz[i]<<" ";
	}
	cout<<endl;
}
int base::getRaiz(int tem) {//Getter para obtener el vector raiz en una posicion especifica
	return raiz[tem];
}
int base::getT() {//Getter para obtener el tamano del vector padre
	return t;
}
///////////////////////////////////////////////
class Izq:virtual public base {//Clase que es la rama izquierda que hereda del padre(con herencia virtual para poder obtener los valores del padre)
		int *raizIzq,tamano;
	public:
		~Izq();
		void asignarIzq();
		void buscarIzq();
		void verIzq();
};

Izq::~Izq() {//Destructor de la clase para la liberacion de memoria dinamica
	delete raizIzq;
}
void Izq::asignarIzq() {//Metodo encargado de asignar en el vector hijo(calculando posiciones del padre) segun el arbol
	tamano=(getT()-1)/2;
	raizIzq=new int [tamano];
	for (int i=0; i<tamano; i++) {
		raizIzq[i]=0;
	}
	int nivel=1,acum=0,aux=1;
	for(int i=0; i<tamano; i++) {
		raizIzq[i]=getRaiz(aux+acum);//Carga del vector izquierda
		acum++;
		if(acum==nivel) {//Validacion que mira si el acumulador es igual al tamano del nivel
			nivel*=2;//Aumento del nivel al cuadrado
			acum=0;//Reinicio del acumulador que suma
			aux=(aux*2)+1;//Indica el valor del primer elemento del piso
		}
	}
}
void Izq::verIzq() {//Metodo encargado de recorrer el vector izquierdo y muestra sus componentes
	cout<<"Vector guardado en la rama izquierda"<<endl;
	for(int i=0; i<tamano; i++) {
		cout<<"[ "<<raizIzq[i]<<" ] ";
	}
	cout<<endl;
}
void Izq::buscarIzq() {//Metodo encargado de buscar un valor especifico en el vector izquierdo
	int cont=0,a=0;
	cout<<"Ingrese el valor a buscar"<<endl;
	cin>>a;
	fflush(stdin);
	cout<<"Buscando valores de la rama izquierda"<<endl;
	for(int i=0; i<tamano; i++) { //Ciclo que recorre el vector en posiciones
		if(raizIzq[i]==a) {
			cout<<"Elemento encontrado en la posicion "<<i+1<<" del vector"<<endl;
		} else {
			cont++;//Contador que aumenta en caso de no hallar el elemento
		}
	}
	if(cont==tamano) {//Validacion que mira si el vector se recorrio completo y no se encontro el elemento
		cout<<"Elemento no encontrado en la rama izquierda"<<endl;
	}
	cout<<endl;
}
/////////////////////////////////////////
class Der:virtual public base {//Clase que hereda la derecha del arbol (con class virtual para poder heredar el valor del vector padre)
		int *raizDer,tamano;
	public:
		~Der();
		void verDer();
		void asignarDer();
		void buscarDer();
};

Der::~Der() {//Destructor de la clase encargado de liberar la memoria dinamica
	delete raizDer;
}

void Der::asignarDer() {//Metodo encargado de asignar al vector derecho (heredando del padre)
	int nivel=1,acum=0,aux=2;
	tamano=(getT()-1)/2;
	raizDer=new int [tamano];
	for (int i=0; i<tamano; i++) {
		raizDer[i]=0;
	}
	for(int i=0; i<tamano; i++) {
		raizDer[i]=getRaiz(aux+acum);//Carga del vector derecho
		acum++;
		if(acum==nivel) {//Validacion que mira si el acumulador es igual al espacio que hay por pisos del arbol
			nivel*=2;//El piso se eleva en 2, en los espacios que contiene
			acum=0;//Reinicio del acumulador que suma
			aux=(aux*2)+1;//Variable que obtiene el primer elemento del nivel
		}
	}
}
void Der::buscarDer() {//Metodo encargado de buscar un valor especifico en el arreglo derecho
	int cont=0,a=0;
	cout<<"Ingrese el valor a buscar"<<endl;
	cin>>a;
	fflush(stdin);
	cout<<"Buscando valores de la rama derecha"<<endl;
	for(int i=0; i<tamano; i++) {//Ciclo que recorre el vector derecho
		if(raizDer[i]==a) {//Validacion que mira si el elemento pertenece al vector
			cout<<"Elemento encontrado en la posicion "<<i+1<<" del vector"<<endl;
		} else {
			cont++;//Contador para ver si el elemento no esta en el vector
		}
	}
	if(cont==tamano) {//Validacion que mira si el contador es igual al tamano del vector
		cout<<"Elemento no encontrado en la rama derecha"<<endl;
	}
	cout<<endl;
}
void Der::verDer() {//Metodo encargado de mostrar los elementos del vector derecho
	cout<<"El vector de la rama derecha guarda"<<endl;
	for(int i=0; i<tamano; i++) {
		cout<<"[ "<<raizDer[i]<<" ] ";
	}
	cout<<endl;
}
//
class arbol:public Izq,public Der {//Clase que maneja el arbol (base,izquierda,derecha) por medio de la herencia de los ultimos
	public:
		void menu();
};
void arbol::menu() {//Metodo que muestra un menu para elegir las opciones del arbol
	int opcion=0;
	cout<<"1. Para ver el contenido de la raiz"<<endl;
	cout<<"2. Para ver la rama izquierda"<<endl;
	cout<<"3. Para buscar en la rama izquierda"<<endl;
	cout<<"4. Para ver la rama derecha"<<endl;
	cout<<"5. Para buscar en la rama derecha"<<endl;
	cout<<"6. Para salir"<<endl;
	cin>>opcion;
	fflush(stdin);
	switch (opcion) {
		case 1:
			ver();
			break;
		case 2:
			verIzq();
			break;
		case 3:
			buscarIzq();
			break;
		case 4:
			verDer();
			break;
		case 5:
			buscarDer();
			break;
		case 6:
			cout<<"Gracias por usar el programa"<<endl;
			exit(0);
		default:
			cout<<"Opcion invalida"<<endl;
			break;
	}
	menu();
}
int main() {
	arbol b;//Declaracion del objeto de tipo arbol(hereda: izquierda,derecha(Estos heredan la base))
	b.leer();
	b.asignarIzq();
	b.asignarDer();
	b.ver();
	b.verIzq();
	b.verDer();
	return 0;
}
