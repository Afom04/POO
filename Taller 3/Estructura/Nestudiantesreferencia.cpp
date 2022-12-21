/*Hacer programa con struct que calcule el promedio de notas aritmetico y ponderado para n estudiantes*/
#include <iostream>
using namespace std;
class datos{
	public:
	struct estudiante{
	char nom[40];
	long long int cod;
	float nota[6],prom,promp;
	};
	void entrada(estudiante*,int);
	void proceso(estudiante*,int);
	void salida(estudiante*,int);
};

void datos::entrada(estudiante *pilo,int n){
for(int i=0;i<n;i++){
    getchar();
    cout<<"De nombre del estudiante #"<<i+1<<endl;
    cin.getline(pilo->nom,40);
    cout<<"De codigo"<<endl;
    cin>>pilo->cod;
    cout<<"De nota"<<endl;
    for(int j=0;j<6;j++){
        cin>>pilo->nota[j];
    }
    pilo++;
    }
}

void datos::proceso(estudiante *pilo,int n){
float ponderado[6]={0.1,0.25,0.2,0.15,0.2,0.1};
for(int j=0;j<n;j++){
    pilo->prom=0;
    for(int i=0;i<6;i++){
	    pilo->prom+=pilo->nota[i];
	    pilo->promp+=(pilo->nota[i]*ponderado[i]);
	}
    pilo->prom/=6;
    pilo++;
    }
}

void datos::salida(estudiante *pilo,int n){
    for(int i=0;i<n;i++){
        cout<<endl<<"Estudiante #"<<i+1<<endl;
        cout<<"Nombre :"<<pilo->nom<<endl;
        cout<<"Codigo :"<<pilo->cod<<endl;
        cout<<"Notas :"<<endl;
        for(int j=0;j<6;j++){
	        cout<<pilo->nota[j]<<" ";
	    }
    cout<<endl<<"Promedio aritmetico "<<pilo->prom<<endl;
    cout<<"Promedio ponderado "<<pilo->promp<<endl;
    pilo++;
    }
}

int main(){
    int n=0;
    cout<<"Por favor ingrese la cantidad de estudiantes"<<endl;
    cin>>n;
    datos objeto;
    datos::estudiante x[n],*p;
    p=&x[0];
    objeto.entrada(p,n);
    p=&x[0];
    objeto.proceso(p,n);
    p=&x[0];
    objeto.salida(p,n);
    return 0;
}