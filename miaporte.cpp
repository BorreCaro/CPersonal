#include <iostream>
using namespace std;
bool cumple(int numero, int digitoD){
    int digitos[3]= {10,10,10};
    for(int i=0; i<3; i++, numero/=10){
        int digitoActual = numero%10;
        for (int j=0; j<i; j++){
            if (digitoActual==digitos[j]) return false;
        }
        digitos[i] = digitoActual;
        if (numero%10==digitoD) return false;
    } 
    return true;
}
int main(){
    unsigned int N, digitoD;
    cout<<"Ingrese N: "; cin>>N;
    do {
        cout<<"Ingrese el digito D: "; cin>>digitoD;
        if (digitoD>9) cout<<"Debe estar entre 0 y 9"<<endl;
    } while(digitoD>9);
    
    cout<<"Todos los numeros de tres cifras menores que "<<N<<" que no contienen el digito "<<digitoD<<endl;
    for(int i=100; i<N&&i<1000; i++){
        if (cumple(i, digitoD)) cout<<i<<endl;
    }
    return 0;
}