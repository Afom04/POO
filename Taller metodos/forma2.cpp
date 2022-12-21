#include <iostream>
using namespace std;

class operacion{
	private:	
	public:

	void lectura();
	void potencia(int,int);
	void imprimir(int,int,int);
	
	};
void operacion::lectura(){
int b,e;
cout<<"Por favor ingrese la base"<<endl;
cin>>b;
cout<<"Por favor ingrese el exponente"<<endl;
cin>>e;
potencia(e,b);
}
void operacion::potencia(int e,int b){
int res=1;
if(e==0){
res=1;
}else{
for(int i=0;i<e;i++){
res*=b;
  }
 }
imprimir(e,b,res);
}
void operacion::imprimir(int e,int b,int res){
cout<<"la potencia de base "<<b<<" al exponente "<<e<<" es igual a "<<res<<endl; 
}
	
int main(){
operacion t2;
t2.lectura();
return 0;
}
