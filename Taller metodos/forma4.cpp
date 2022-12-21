#include <iostream>
using namespace std;

class operacion{
	private:	

	public:
	
	void lectura(int*,int*);
	void potencia(int*,int*,int*);
	void imprimir(int*,int*,int*);
	};
void operacion::lectura(int*b,int*e){
cout<<"Por favor ingrese la base"<<endl;
cin>>*b;
cout<<"Por favor ingrese el exponente"<<endl;
cin>>*e;
}
void operacion::potencia(int*e,int* b,int* res){
*res=1;
if(e==0){
*res=1;
}else{
for(int i=0;i<*e;i++){
*res*=(*b);
  }
 }
}
void operacion::imprimir(int* b,int* e,int* res){
cout<<"la potencia de base "<<*b<<" al exponente "<<*e<<" es igual a "<<*res<<endl; 
}
	
int main(){
int b,e,res;
operacion t4;
t4.lectura(&b,&e);
t4.potencia(&e,&b,&res);
t4.imprimir(&b,&e,&res);
return 0;
}
