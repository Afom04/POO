#include <iostream>
using namespace std;

class operacion{
	private:	
	int b,e,res;
	public:
	operacion();
	~operacion();
	void lectura();
	void potencia();
	void imprimir();
	
	};
operacion::operacion(){
b=e=0;
res=1;
}
operacion:: ~operacion(){
}
void operacion::lectura(){
cout<<"Por favor ingrese la base"<<endl;
cin>>b;
cout<<"Por favor ingrese el exponente"<<endl;
cin>>e;
}
void operacion::potencia(){
if(e==0){
res=1;
}else{
for(int i=0;i<e;i++){
res*=b;
  }
 }
}
void operacion::imprimir(){
cout<<"la potencia de base "<<b<<" al exponente "<<e<<" es igual a "<<res<<endl; 
}
	
int main(){
operacion t;
t.lectura();
t.potencia();
t.imprimir();
return 0;
}
