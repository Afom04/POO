#include <iostream>
using namespace std;
class datos{
	public:
	struct estudiante{
	char nom[40];
	long long int cod;
	float nota[6],prom,promp;
	};
	void entrada(estudiante[],int);
	void proceso(estudiante[],int);
	void salida(estudiante[],int);
};
void datos::entrada(estudiante pilo[],int n){
for(int i=0;i<n;i++){
getchar();
cout<<"De nombre del estudiante #"<<i+1<<endl;
cin.getline(pilo[i].nom,40);
cout<<"De codigo"<<endl;
cin>>pilo[i].cod;
cout<<"De nota"<<endl;
for(int j=0;j<6;j++){
	cin>>pilo[i].nota[j];
	}
cout<<endl;
}
proceso(pilo,n);
}
void datos::proceso(estudiante pilo[],int n){
float ponderado[6]={0.1,0.25,0.2,0.15,0.2,0.1};
for(int j=0;j<n;j++){
    pilo[j].promp=0;
    pilo[j].prom=0;
for(int i=0;i<6;i++){
	pilo[j].prom+=pilo[j].nota[i];
	pilo[j].promp+=(pilo[j].nota[i]*ponderado[i]);
	}
pilo[j].prom/=6;
}
salida(pilo,n);
}
void datos::salida(estudiante pilo[],int n){
for(int i=0;i<n;i++){
cout<<"Nombre del estudiante #"<<i+1<<" :"<<pilo[i].nom<<endl;
cout<<"Codigo :"<<pilo[i].cod<<endl;
cout<<"Notas :"<<endl;
    for(int j=0;j<6;j++){
	    cout<<pilo[i].nota[j]<<" ";
	}
cout<<endl<<"Promedio aritmetico "<<pilo[i].prom<<endl;
cout<<"Promedio ponderado "<<pilo[i].promp<<endl;
cout<<endl;
}
}

int main (){
int n=0;
cout<<"Ingrese la cantidad de estudiantes "<<endl;
cin>>n;
datos::estudiante x[n];
datos objeto;
objeto.entrada(x,n);
}