#include <iostream>
using namespace std;
int arreglo[100];
int length;
void llenarArreglo(){
    int* puntero;
    cout<<"Ingrese "<<length<<" numeros: ";
    for(int i=0; i<length; i++){
        puntero = &arreglo[i];
        cin>>*puntero;
    }
}
void mostrarArreglo(){
    int* puntero;
    for(int i=0; i<length; i++) {
        puntero = &arreglo[i];
        cout<<" "<<*puntero;
    }
    cout<<endl;
}
void intercambio(){
    int* pA = &arreglo[0];
    int* pB = &arreglo[length-1];
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}
int sumaElementos(){
    int suma = 0;
    for(int i=0; i<length; i++){
        int* current = &arreglo[i];
        suma += *current;
    }
    return suma;
}
float promedio(){
    return sumaElementos()*1.f/length;
}
int* menorElemento(arreglo, length){
    int* menor = arreglo;
    for (int i=1; i<length; arreglo++) if(*menor>*arreglo) menor = *arreglo;
    return menor;
}

int main(){
    
    cout<<"Ingrese el tamaño del arreglo: "; cin>>length;
    llenarArreglo();
    cout<<"El arreglo es:";
    mostrarArreglo();
    cout<<"La suma de los elementos es: "<<sumaElementos()<<endl;
    cout<<"El promedio de los elementos es: "<<promedio()<<endl;
    cout<<"El menor elemento es: "<<*menorElemento()<<endl;
    cout<<"Despues del intercambio:";
    intercambio();
    mostrarArreglo();

    return 0;
}