/*
Desarrolla un programa en C++ (1 Punto), que permita registrar los votos para tres
candidatos en una elección presidencial. El programa debe:
a. Usar punteros para manejar los votos de cada candidato
b. Mostrar los votos totales para cada candidato y determinar el ganador
c. Funcionar para n cantidad de votantes ingresados por el usuario
*/
#include <iostream>
using namespace std;
void votosTotales(int* votos){
	int* ganador = votos;
	bool empate = false;
	int indiceEmpate;
	cout<<"Votos:"<<endl;
	for(int i=0; i<3; i++){
		cout<<"Candidato "<<i+1<<": "<<*(votos+i)<<endl;
		if(i>0){
			if(*(votos+i)>*ganador) {
			empate = false;
			}
			else if (*(votos+i)==*ganador){
				empate=true;
				indiceEmpate = i;
			}
		}
		
	}
	cout<<"Ganador: "<<endl;
	if(empate){
		cout<<"Hubo un empate entre los candidatos "<<indiceEmpate+1<<" y "<<indiceEmpate+2<<endl;
	} else {
		cout<<"El candidato ganador fue el #"<<ganador-votos+1<<" con "<<*ganador<<" votos"<<endl;
	}
	
}
void recibirVotos(int* votos, int n){
	for(int i=0; i<n; i++){
		system("cls");
		int voto;
		cout<<"Votante #"<<i+1<<endl;
		do {
			cout<<"Ingrese el candidato por quien votara (1,2,3): "; cin>>voto;
			if (voto>3||voto<1) cout<<"Ingrese un candidato valido"<<endl;	
		} while(voto>3||voto<1);
		*(votos+voto-1) += 1;
	}
}
int main(){
	int votos[3] = {0};
	unsigned int n;
	cout<<"Ingrese la cantidad de votantes: ";cin>>n;
	recibirVotos(votos, n);
	votosTotales(votos);
	
}
