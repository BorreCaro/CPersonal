#include <iostream>
using namespace std;
void intercambiar(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a,b;
    cout<<"Ingrese el primer numero: ";cin>>a;
    cout<<"Ingrese el segundo numero: ";cin>>b;
    cout<<"Antes de intercambiar: a = "<<a<<" b = "<<b<<endl;
    intercambiar(&a,&b);
    cout<<"Despues de intercambiar: a = "<<a<<" b = "<<b<<endl;

    return 0;
}