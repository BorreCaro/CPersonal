#include <iostream>
using namespace std;
int cadenaLength(char* cadena){
    int length = 0;
    while (true){
        if(*cadena!='\0'){
            length++;
            cadena++;
        } else break;
    }
    return length;
}
void mostrarOracion(char *cadena, int length, bool invertida=false){
    if (!invertida){
        for (int i=0; i<length; i++) {
        cout<<*cadena;
        cadena++;
        }
    }
    if (invertida){
        cadena+=length-1;
        for (int i=length-1; i>=0; i--) {
        cout<<*cadena;
        cadena--;
        }
    }
    cout<<endl;
}
int cantidadVocales(char *cadena, int length){
    int vocales = 0;
    for (int i=0; i<length; i++){
        switch(tolower(*cadena)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': vocales++;
        }
        cadena++;
    }
    return vocales;
}
int main(){
    char cadena[51] = {0};
    cout<<"Porfavor ingrese una oracion (max 50 caracteres)"<<endl;
    cin.getline(cadena, 51);

    int length = cadenaLength(cadena); // Para mayor facilidad

    cout<<"Esta es la oracion: ";
    mostrarOracion(cadena, length);
    cout<<"La longitud es: "<<length<<endl;
    cout<<"La cantidad de vocales es: "<<cantidadVocales(cadena, length)<<endl;
    cout<<"La oracion invertida es: ";
    mostrarOracion(cadena, length, true);
    return 0;
}