#include <iostream>
using namespace std;

class operacion{
	private:	

	public:
	
	int lectura(void);
	int potencia(int,int);
	void imprimir(int,int,int);
	};
int operacion::lectura(){
int x;
cout<<"Por favor ingrese el numero"<<endl;
cin>>x;
return x;
}
int operacion::potencia(int e,int b){
int res=1;
if(e==0){
res=1;
}else{
for(int i=0;i<e;i++){
res*=b;
  }
 }
return res;
}
void operacion::imprimir(int b,int e,int res){
cout<<"la potencia de base "<<b<<" al exponente "<<e<<" es igual a "<<res<<endl; 
}
	
int main(){
int b,e,res;
operacion t3;
b=t3.lectura();
e=t3.lectura ();
res=t3.potencia(e,b);
t3.imprimir(b,e,res);
return 0;
}
