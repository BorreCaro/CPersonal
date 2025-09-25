/*
Problema: Sistema de Control de Misiles (2 Puntos) Se necesita desarrollar un
sistema básico para gestionar el lanzamiento de misiles en una simulación de
guerra. El sistema debe permitir:
a. Inicializar la cantidad de misiles disponibles en un lanzador
b. Lanzar un misil y actualizar la cantidad restante
c. Mostrar cuántos misiles quedan en el lanzador
d. Utiliza punteros para manipular directamente la cantidad de misiles
*/
#include <iostream>
using namespace std;
void inicializarMisiles(int* misiles, int cantidad){
	*misiles = cantidad;
}
void lanzarMisil(int* misiles){
	if(*misiles==0) cout<<"No se puede lanzar un misil porque ya no quedan misiles"<<endl;
	else {
		cout<<"Misil lanzado"<<endl;
		*(misiles)-=1;
		cout<<"Misiles restantes: "<<*misiles<<endl;
	}
}
void misilesRestantes(int* misiles){
	if(*misiles==0) cout<<"No quedan misiles"<<endl;
	else cout<<"Misiles restantes: "<<*misiles<<endl;
}
int main(){
	int misiles=0;
	bool inicializado = false;
	for(int op;;){
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"1. Inicializar cantidad de misiles"<<endl;
		cout<<"2. Lanzar misil"<<endl;
		cout<<"3. Mostrar misiles restantes"<<endl;
		cout<<"0. Salir"<<endl;
		do{
			cout<<"Ingrese su eleccion: ";cin>>op;
			if (op<0||op>3) cout<<"Opcion invalida"<<endl;
		} while(op<0||op>3);
		system("cls");
		switch(op){
			
			case 1:{
				int cantidad;
				cout<<"Ingrese la cantidad de misiles: "; cin>>cantidad;
				if(cantidad<0) cantidad=0;
				if(cantidad==0) cout<<"Entonces no tienes misiles"<<endl;
				inicializarMisiles(&misiles, cantidad);
				inicializado=true;
				break;
			}
			case 2:{
				if(!inicializado){
					cout<<"Debe inicializar la cantidad de misiles primero"<<endl;
					break;
				}
				lanzarMisil(&misiles);
				break;
			}
			case 3:{
				if(!inicializado){
					cout<<"Debe inicializar la cantidad de misiles primero"<<endl;
					break;
				}
				misilesRestantes(&misiles);
				break;
			}
			case 0:{
				cout<<"Gracias por jugar"<<endl;
				return 0;
				break;
			}
		}
		system("pause");
	}
}
