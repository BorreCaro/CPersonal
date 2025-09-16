#include <iostream>
using namespace std;

char letras[7] = {'I','V','X','L','C','D','M'};

int calcDigitos(int num, int *digitos){ // Llena el arreglo con los digitos y retorna la cantidad de digito
    int cant=0;
    for (; num>0; num/=10, digitos++, cant++) *digitos = num%10;
    return cant;
}
void conversion(int *digitos, char* romano, int cantDigitos){
    char *letra = &letras[2*cantDigitos-1];
    digitos = digitos + cantDigitos - 1;
    for(int i=cantDigitos; i>=0; i--, digitos--, letra-=2){
        if (*digitos!=0){
            if (*digitos<5) {

                if (*digitos==4) {

                    *romano = *(letra-1);
                    romano++;
                    *romano = *letra;
                    romano++;

                } else for (int j=0; j<*digitos; j++, romano++) *romano = *(letra-1); 
            
            } else if (*digitos==5) *romano = *letra;
            else {
                if (*digitos==9) {

                    *romano = *(letra-1);
                    romano++;
                    *romano = *(letra+1);
                    romano++;

                } else {
                    *romano = *letra;
                    romano++;
                    for (int j=0; j<*digitos-5; j++, romano++) *romano = *(letra-1);
                }
            }
        }
    }
}
void imprimir(char *romano){
    for (int i=0; *romano!=0; romano++) cout<<*romano;
    cout<<endl;
}
int main(){
    int digitos[4]={0}; // unidades, decenas, centenas, miles
    char romano[17]={0}; // El numero con mas letras (3888) tiene 15 
    int numero;
    do {
        cout<<"Ingrese el numero en sistema decimal (maximo 3999): "; 
        cin>>numero;
        if(numero<1||numero>3999) cout<<"Debes ingresar un numero entre 1 y 3999"<<endl;
    } while(numero<1||numero>3999);
    
    int cantDigitos = calcDigitos(numero, digitos);
    conversion(digitos, romano, cantDigitos);
    cout<<"Ese numero en romano se escribe: ";
    imprimir(romano);
    system("pause");
    return 0;
}