/*
Problema: Sistema de Gestión de Vida en un Videojuego (2 Puntos). En un
videojuego de acción, cada jugador tiene un valor de vida. El sistema debe permitir
lo siguiente:
a. Inicializar la vida de un jugador.
b. Reducir la vida de un jugador tras recibir daño
c. Mostrar la vida restante del jugador
d. Utiliza punteros para manipular directamente la vida del jugador
*/
#include <iostream>
using namespace std;
void inicializarVida(int* jugador, int vida){
	if(vida<0) vida = 0;
	*jugador = vida;
}
void sumarVida(int* jugador, int vida){
	if(vida<0) vida = 0;
	*jugador += vida;
	if(*jugador==0) cout<<"El jugador esta muerto"<<endl;
	else cout<<"Vida actual del jugador: "<<*jugador<<endl;
}
void dealDamage(int* jugador, int damage){ // Lo puse en ingles pq no hay ñ
	if (damage<0) damage = 0;
	else *jugador -= damage;
	if (*jugador<0) *jugador = 0;
	if(*jugador==0) cout<<"El jugador ha muerto"<<endl;
	else cout<<"Vida restante: "<<*jugador<<endl;
}
void mostrarVida(int* jugador){
	if (*jugador==0) cout<<"El jugador esta muerto"<<endl;
	else cout<<"Vida del jugador: "<<*jugador<<endl;
}
int main(){
	setlocale(LC_ALL, "spanish");
	int jugador;
	bool vidaInicializada = false;
	for(int op;;){
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"1. Inicializar vida del jugador"<<endl;
		cout<<"2. Hacer daño a un jugador"<<endl;
		cout<<"3. Sumar vida a un jugador"<<endl;
		cout<<"4. Mostrar vida del jugador"<<endl;
		cout<<"0. Salir"<<endl;
		do {
			cout<<"Ingrese su eleccion: ";cin>>op;	
			if (op<0||op>4) cout<<"Opcion invalida"<<endl;
		} while(op<0||op>4);
		system("cls");
		switch(op){
			
			case 1:{
				int vida;
				cout<<"Ingrese la vida (Valores negativos = 0): "; cin>>vida;
				inicializarVida(&jugador, vida);
				vidaInicializada = true;
				break;
			}
			case 2:{
				if (!vidaInicializada) {
					cout<<"Debe inicializar la vida del jugador primero"<<endl;					
					break;
				}
				int damage;
				cout<<"Ingrese el daño (Valores negativos = 0): "; cin>>damage;
				dealDamage(&jugador, damage);
				break;
			}
			case 3:{
				if (!vidaInicializada) {
					cout<<"Debe inicializar la vida del jugador primero"<<endl;				
					break;
				}
				int vida;
				cout<<"Ingrese la vida a sumar (Valores negativos = 0): "; cin>>vida;
				sumarVida(&jugador, vida);
				break;
			}
			case 4:{
				if (!vidaInicializada) {
					cout<<"Debe inicializar la vida del jugador primero"<<endl;					
					break;
				}
				mostrarVida(&jugador);
				break;
			}
			case 0: {
				cout<<"Gracias por jugar"<<endl;
				return 0;
				break;
			}
		}
		system("pause");
	}
	return 0;
}
