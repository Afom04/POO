#include <iostream>
using namespace std;
class datos{
	public:
	struct estudiante{
	char nom[40];
	long long int cod;
	float nota[6],prom,promp;
	};
	void entrada(estudiante);
	void proceso(estudiante);
	void salida(estudiante);
};
void datos::entrada(estudiante pilo){
cout<<"De nombre del estudiante "<<endl;
cin.getline(pilo.nom,40);
cout<<"De codigo"<<endl;
cin>>pilo.cod;
cout<<"De nota"<<endl;
for(int j=0;j<6;j++){
	cin>>pilo.nota[j];
	}
cout<<endl;
proceso(pilo);
}
void datos::proceso(estudiante pilo){
float ponderado[6]={0.1,0.25,0.2,0.15,0.2,0.1};
    pilo.promp=0;
    pilo.prom=0;
for(int i=0;i<6;i++){
	pilo.prom+=pilo.nota[i];
	pilo.promp+=(pilo.nota[i]*ponderado[i]);
	}
pilo.prom/=6;
salida(pilo);
}
void datos::salida(estudiante pilo){
cout<<"Nombre "<<" :"<<pilo.nom<<endl;
cout<<"Codigo :"<<pilo.cod<<endl;
cout<<"Notas : ";
    for(int j=0;j<6;j++){
	    cout<<pilo.nota[j]<<" ";
	}
cout<<endl<<"Promedio aritmetico "<<pilo.prom<<endl;
cout<<"Promedio ponderado "<<pilo.promp<<endl;
cout<<endl;
}


int main (){
datos::estudiante x;
datos objeto;
objeto.entrada(x);
}