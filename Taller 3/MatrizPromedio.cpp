/*2 Programa que lea una matriz de M X N y halle la suma total, el promedio, que diga cuantos y
cuales son mayores al promedio, que diga cuantos y cuales son menores al promedio. (imprimir
todo)*/
#include <iostream>
using namespace std;

class m2 {//Declaracion de la clase
    public:
    void entrada(int**,int,int);
	void proceso(int**,int,int);
	void salida(int**,int,int,int,float,int,int,int*,int*);
};
void m2::entrada(int**matriz,int m,int n){
    cout<<"Por favor llene la matriz a evaluar"<<endl;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout<<i+1<<"-"<<j+1<<" ";
			cin>>matriz[i][j];
		}
	}
}
void m2::proceso(int**matriz,int m,int n){
    int cum1=0,cum2=0,suma=0;
    float prom=0.0;
    int *map,*mep;
    map=new int[m*n];//Asignacion de memoria dinamica
	mep=new int[m*n];
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			suma+=matriz[i][j];//Suma de los componentes
		}
	}
	prom=(suma)/(m*n);//Calculo de promedio de la matriz
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(matriz[i][j]>prom) {//Separacion de mayores al promedio
				map[cum1]=matriz[i][j];
				cum1++;
			}
			if(matriz[i][j]<prom) {//Separacion de menores al promedio
				mep[cum2]=matriz[i][j];
				cum2++;
			}
		}
	}
	salida(matriz,m,n,suma,prom,cum1,cum2,map,mep);
}
void m2::salida(int**matriz,int m,int n,int suma,float prom,int cum1,int cum2,int*map,int*mep) {//Metodo encargado de la salida de datos
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout<<"[ "<<matriz[i][j]<<" ] ";//Impresion de la matriz
		}
		cout<<endl;
	}
	cout<<"La suma de los componentes de la matriz es "<<suma<<endl;//Salida suma
	cout<<"El promedio de los componentes de la matriz es "<<prom<<endl;//Salida promedio
	cout<<"Los componentes que superan el promedio son "<<cum1<<" [";
	for(int i=0; i<cum1; i++) {
		cout<<map[i]<<" ";//Impresion de mayores al promedio
	}
	cout<<"] "<<endl;
	cout<<"Los componentes que son menores al promedio son "<<cum2<<" [";
	for(int i=0; i<cum2; i++) {
		cout<<mep[i]<<" ";//Impresion de menores al promedio
	}
	cout<<"] "<<endl;
	
	delete mep;
	delete map;
}

int main(){
    int m=0,n=0;
    int **matriz;
	cout<<"Ingrese el numero de filas"<<endl;
	cin>>m;
	cout<<"Ingrese el numero de columnas"<<endl;
	cin>>n;
	//Asignacion dinamica de memoria
    matriz=new int*[m];
    if(matriz==NULL){
        cout<<"Error de matriz1";
    }else{
	for(int i=0; i<m; i++) {
		matriz[i]=new int[n];
		if(matriz[i]==NULL) {
			cout<<"Error de matriz2";
		}
	}
    }
    m2 mat;
    mat.entrada(matriz,m,n);
    mat.proceso(matriz,m,n);
    //Destruyendo memoria dinamica
    for(int i=0; i<m; i++) {
		delete matriz[i];
	}
	delete matriz;
    return 0;
}