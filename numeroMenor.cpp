#include <iostream>
using namespace std;

void rellenar(int* array, int length){
	for(int i=0; i<length; i++){
		cout<<"Ingrese el numero para la posicion #"<<i<<": ";
		cin>>*(array+i);
	}
}
int* numMenor(int* array, int length){
	int* menor = array;
	for(int i=0; i<length; i++){
		if (*menor>*(array+i)) menor = (array+i);
	}
	return menor;
}
int main(){
	int n;
	cout<<"Ingrese el tamaño del arreglo: "; cin>>n;
	int numeros[n];
	rellenar(numeros, n);
	int* numeroMenor = numMenor(numeros, n);
	cout<<"El numero menor es: "<<*numeroMenor<<endl;
	cout<<"Esta en la posicion #"<<numeroMenor-numeros<<" del arreglo"<<endl;
	cout<<"Su direccion de memoria es: "<<numeroMenor<<endl;
}
