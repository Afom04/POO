/*4 Programa que le un N dado y construya la matriz mágica correspondiente (eje. Para N=3)*/
#include <iostream>
using namespace std;

class m4{//Declaracion de la clase
    public://Metodos de la clase
    void entrada();
    void proceso(int);
    void par(int**,int);
    void impar(int**,int);
    void salida(int**,int);
};
void m4::entrada(){//Metodo encargado de la entrada de el tamano de la matriz
    int n=0;
    cout<<"Por favor ingrese la dimension de la matriz"<<endl;
    cin>>n;
    if(n==2){
	    cout<<"Tamano invalido"<<endl;
	    entrada();
	}
    proceso(n);
}
void m4::proceso(int n){//Metodo encargado de crear la matriz y diferenciar de si es orden par o impar
    int **matriz;
    matriz=new int *[n];//Asignacion dinamica de memoria
    if (matriz == NULL) {
		cout << "Error de memoria matriz";
	}
	for (int i = 0; i < n; i++) {
		matriz[i] = new int[n];
		if (matriz[i] == NULL) {
			cout << "Error de memoria matriz2";
		}
	}
	for(int i=0;i<n;i++){//Llenado de la matriz dinamica
	    for(int j=0;j<n;j++){
	        matriz[i][j]=0;
	    }
	}
	if(n%2==0){//Matriz par
	    par(matriz,n);
	} 
	if(n%2==1){//Matriz impar
	    impar(matriz,n);
	}
}
void m4::par(int **matriz,int n){//Metodo encargado de crear la matriz par
int contador=1,I[n][n],J[n][n];//Contador que acumula los numeros de 1 a n*n, y matrices auxiliares
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
      I[i][j]=((i+1)%4)/2;//Llenado de matrices auxiliares por medio del modelo matematico de matriz par
      J[j][i]=((i+1)%4)/2;//Llenado de matrices auxiliares traspuesta por medio del modelo matematico de matriz par
      matriz[i][j]=contador;//Llenado de matriz normal 
      contador++;
    }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    {
      if (I[i][j]==J[i][j])//Evalua cuando los valores de la auxiliar 1 es igual a su transversa
        matriz[i][j]=n*n+1-matriz[i][j];//Asignacion de numero por medio de la definicion de numero magico, para la matriz magica
    }
        salida(matriz,n);
}

void m4::impar(int**matriz,int n){//Metodo encargado de crear la matriz impar
    int x=0,y=0,vx=0,vy=0;//Variables posición
    int limite=n*n,limitex=n-1,limitey=n-1,contador=0;
    x=n/2;
    y=0;
    for(contador=1;contador<=limite;contador++)
    {
       // Asignar la posición del numero en la matriz
        matriz[y][x] = contador;
        // Guardar la posición actual
        vx = x;
        vy = y;
        // Aumentar la posición de x si sobrepasa el limite derecho
        // situarla en el limite izquierdo
        x++;
        if( x > limitex ) x = 0;
        // Disminuir la posición de y, ya que se pretende avanzar en
        // diagonal
        y--;
        if( y < 0 ) y = limitey;
        // Se comprueba si la posición ya esta ocupada por un numero
        // si es así se vuelve a la posición original y se resitúa el
        // numero justo en la casilla inferior
        if (matriz[y][x]>0)
        {
            // La casilla esta ocupada y se asigna el numero en la
            // casilla situada debajo de la casilla de donde intentaba
            x = vx ;
            y = vy +1 ;
        }
    }
    salida(matriz,n);
}
void m4::salida(int**matriz,int n){//Metodo encargado de la impresion de la matriz magica
    cout<<"Cuadro magico de dimension "<<n<<endl;
    for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	       printf("|%3d|",matriz[i][j]);
	    }
	    cout<<endl;
	}
	//Destruccion de memoria dinamica
	for(int i=0; i<n; i++) {
		delete matriz[n];
	}
	delete matriz;
}
int main(){
    m4 mat;//Creacion de objeto
    mat.entrada();//Invocacion del metodo del objeto
    
    return 0;
}
