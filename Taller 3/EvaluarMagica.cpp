/*3 Programa que le una matriz de orden N y diga si es mágica o no, imprimir las evidencias*/
#include <iostream>
using namespace std;

class m3 {//Declaracion de la clase
    public://Declaracion de los metodos de la clase
    void entrada(int**,int);
	void proceso(int**,int);
	bool magico(int,int);
	void salida(int**,int,int*,int*,int,int,bool);
};
void m3::entrada(int**matriz,int n) {//Metodo encargado de llenar la matriz
	cout << "Por favor llene la matriz " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << i+1  << "-" << j+1  << " ";
			cin >> matriz[i][j];
		}
	}
}
void m3::proceso(int**matriz,int n) {//Metodo encargado de sumar y crear acumulador para ver si es magica
	int cum=0,*f,*c,dp=0,ds=0;
	//Asignacion dinamica de memoria
	f = new int[n];
	c = new int[n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			f[i]+=matriz[i][j];//Suma de filas
			c[i]+=matriz[j][i];//Suma de columnas
			if(i==j)
				dp+=matriz[i][i];//Suma de la diagonal principal
			if(j==n - i - 1)
				ds += matriz [ i ][ j ] ;//Suma de la diagonal secundaria
		}
	}
	for(int i=0; i<n; i++) {
		if(dp==f[i] && dp==c[i] && dp==ds) {//Validacion de la suma de filas,columnas y diagonales 
			cum++;
		}
	}
	bool magic=magico(cum,n);//Invocacion de metodo booleano para ver si la matriz es magica
	salida(matriz,n,f,c,dp,ds,magic);//Invocacion de metodo que muestra el resultado
}
bool m3::magico(int cum,int n){//Metodo encargado de validar el acumulador con el total de sumas
    if(cum==n) {
		return true;
	}
	return false;
}

void m3::salida(int**matriz,int n,int*f,int*c,int dp,int ds,bool magic) {//Metodo encargado de la salida de datos
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<"[ "<< matriz[i][j]<<" ] ";//Impresion de la matriz
		}
		cout<<endl;
	}
	if(magic) {
		cout<<"La matriz insertada es magica porque "<<endl;
	} else {
		cout<<"La matriz insertada no es magica porque "<<endl;
	}
	cout<<"Suma filas ";
	for(int m=0; m<n; m++) {//Impresion de la sumatoria de las filas
		cout<<f[m]<<" ";
	}
	cout<<endl<<"Suma columnas ";
	for(int m=0; m<n; m++) {//Impresion de la sumatoria de las columnas
		cout<<c[m]<<" ";
	}
	cout<<endl<<"Diagonal principal "<<dp<<endl;//Impresion de la diagonal principal
	cout<<"Diagonal secundaria "<<ds<<endl;//Impresion de la diagonal secundaria
	//Destruccion de memoria dinamica
	delete f;
	delete c;
}

int main(){
    int n=0,**matriz;
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
	
	m3 mat;
	mat.entrada(matriz,n);
	mat.proceso(matriz,n);
	//Destruccion de memoria dinamica
	for(int i=0; i<n; i++) {
		delete matriz[n];
	}
	delete matriz;
	
	return 0;
}
