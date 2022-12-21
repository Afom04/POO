/*5 Programa que llene una matriz de orden N entrado por teclado con
[1][0][1]
[0][1][0]
[1][0][1]
*/
#include <iostream>
using namespace std;

class m5{//Declaracion de la clase
    public:
    void entrada();//Metodos de la clase
    void proceso(int);
    void salida(int**,int);
};
void m5::entrada(){//Metodo encargado de recibir la dimension de la matriz a llenar
    int n=0;
    cout<<"Por favor ingrese la dimension de la matriz"<<endl;
    cin>>n;
    proceso(n);
}
void m5::proceso(int n){//Metodo encargado de llenar la matriz y crearla de manera dinamica
    int **matriz;
    matriz=new int*[n];//Creacion de la matriz dinamica
    if(matriz==NULL){cout<<"Error de matriz1";}
    for(int i=0;i<n;i++){
        matriz[i]=new int[n];
        if (matriz[i] == NULL) {
			cout << "Error de memoria matriz2";
		}
    }
    for(int i=0;i<n;i++){//Ciclo que recorre la matriz creada
        for(int j=0;j<n;j++){
            matriz[i][j]=0;//Llenar espacios con ceros
         	if(i==j)
				matriz[i][j]=1;//Llenado de la diagonal principal
			if(j==n - i - 1)
				matriz [ i ][ j ]=1 ;//Llenado de la diagonal secundaria   
        }
    }
    salida(matriz,n);
}
void m5::salida(int**matriz,int n){//Metodo encargado de mostrar la matriz rellenada
    for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<"[ "<< matriz[i][j]<<" ] ";//Impresion de la matriz
		}
		cout<<endl;
	}
	for(int i=0; i<n; i++) {
		delete matriz[n];
	}
	delete matriz;
	
}
int main(){
    m5 mat;//Creacion del objeto
    mat.entrada();//Invocacion del metodo
    return 0;
}
