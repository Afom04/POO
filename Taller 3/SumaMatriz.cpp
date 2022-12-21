/*1 Programa que lea una matriz de N X N y halle la suma de cada fila, de cada columna, de la
diagonal principal, de la diagonal secundaria y la sumatoria total. (imprimir todo)*/
#include <iostream>

using namespace std;

class m1{//Declaracion de la clase
    public://Prototipos de metodos
    void entrada(int**,int);
    void proceso(int**,int);
    void salida(int**,int,int*,int*,int,int,int);
};
void m1::entrada(int **matriz,int n){//Metodo de entrada para llenar la matriz
    cout << "Por favor llene la matriz " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << i+1  << "-" << j+1  << " ";
			cin >> matriz[i][j];
		}
	}
}
void m1::proceso(int **matriz,int n){//Metodo encargado de sumar los valores de la matriz
    int total ,ds ,dp;//Declaracion de variables 
    int *f, *c;//Declaracion de punteros para arrays de memoria dinamica
    f = new int[n];//Asignacion de memoria dinamica
	c = new int[n];//Asignacion de memoria dinamica
	if (f == NULL || c == NULL) {
		cout << "Error de memoria en vector";
	}
	total = ds = dp = 0;
    	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			f[i]+=matriz[i][j];//Suma de filas
			c[i]+=matriz[j][i];//Suma de columnas
			if(i==j)
				dp+=matriz[i][i];//Suma de la diagonal principal
			if(j==n - i - 1)
				ds += matriz [ i ][ j ] ;//Suma de la diagonal secundaria
			total+=matriz[i][j];
		}
	}
	salida(matriz,n,f,c,dp,ds,total);
}
void m1::salida(int **matriz,int n,int*f,int*c,int dp,int ds,int total) {//Metodo encargado de la salida de la matriz y la sumatoria
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<"[ "<< matriz[i][j]<<" ] ";//Impresion de la matriz
		}
		cout<<endl;
	}
	cout<<"Suma de filas ";
	for(int m=0; m<n; m++) {//Impresion de la sumatoria de las filas
		cout<<f[m]<<" ";
	}
	cout<<endl<<"Suma de columnas ";
	for(int m=0; m<n; m++) {//Impresion de la sumatoria de las columnas
		cout<<c[m]<<" ";
	}
	cout<<endl<<"Suma de la diagonal principal "<<dp<<endl;//Impresion de la diagonal principal
	cout<<"Suma de la diagonal secundaria "<<ds<<endl;//Impresion de la diagonal secundaria
	cout<<"La sumatoria de la matriz es "<<total<<endl;
	//Destruyendo memoria dinamica
	delete f;
	delete c;
}
int main(){
    int n = 0;
    int **matriz;
	cout << "Por favor ingrese el tamano de filas y columnas" << endl;
	cin >> n;
	//Asignacion dinamica de memoria
	matriz = new int *[n];
	if (matriz == NULL) {
		cout << "Error de memoria matriz";
	}
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
		if (matriz[i] == NULL) {
			cout << "Error de memoria matriz2";
		}
	}
	
    m1 mat;
    mat.entrada(matriz,n);
    mat.proceso(matriz,n);
    //Destruyendo memoria dinamica
    for(int i=0; i<n; i++) {
		delete matriz[n];
	}
	delete matriz;
	
    return 0;
}