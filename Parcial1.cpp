/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class cadena {
	private:
		char *original,*copia;
		int palabra,vocales,a,e,i,o,u,longitud,x;
	public:
		cadena();
		~cadena();
		void entrada(void);
		void proceso(void);
		void salida(void);
};
cadena::cadena() {
	cout<<"Ingrese el tamano del arreglo"<<endl;
	cin>>x;
	original=new char[x];
	copia=new char[x];
	if(original==NULL || copia==NULL) {
		cout<<"Error en asignar memoria"<<endl;
	}
	palabra=vocales=a=e=i=o=u=longitud=0;
}
cadena::~cadena() {
	delete original;
	delete copia;
}
void cadena::entrada() {
	cout<<"Por favor ingrese la frase a procesar"<<endl;
	//cin>>original;
	cin.getline(original,x);
}
void cadena::proceso() {
	for(int l=0; original[l]!='\0'; l++) {
		copia[l]=original[l];

		if(original[l]>='A' && original[l]<='Z') {
			original[l]+=32;
		}
		if(original[l]>='a' && original[l]<='z') {
			original[l]-=32;
		}
		if(original[l]=='U' || original[l]=='u') {
			u++;
			vocales++;
		}
		if(original[l]=='O' || original[l]=='o') {
			o++;
			vocales++;
		}
		if(original[l]=='I' || original[l]=='i') {
			i++;
			vocales++;
		}
		if(original[l]=='E' || original[l]=='e') {
			e++;
			vocales++;
		}
		if(original[l]=='A' || original[l]=='a') {
			a++;
			vocales++;
		}
		if(original[l]==' ') {
			palabra++;
		}
		longitud++;
	}
	palabra++;
}
void cadena::salida() {
	cout<<"La frase ingresada es "<<copia<<endl;
	cout<<"La frase alterada es "<<original<<endl;
	cout<<"Con un total de "<<palabra<<" palabras"<<endl;
	cout<<"Con un total de "<<longitud<<" caracteres"<<endl;
	cout<<"Con un total de "<<vocales<<" vocales"<<endl;
	cout<<"Con un total de "<<a<<" [A]; "<<e<<" [E]; "<<i<<" [I]; "<<o<<" [O] y "<<u<<" [U]."<<endl;
}
int main() {
	cadena p1;
	p1.entrada();
	p1.proceso();
	p1.salida();
	return 0;
}
