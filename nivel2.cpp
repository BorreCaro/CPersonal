#include <iostream>
using namespace std;

int calcLength(char* array){
    int length=0;
    for (int i=0; *(array+i)!='\0'; length++, i++);
    return length;
}
template <typename T>
void mostrarArray(T* array, int length=0){
    if (length==0&&sizeof(*array)==sizeof(char)) length = calcLength(array);
    if (length==0) cout<<"Error, no se pudo mostrar el arreglo";
    for(int i=0; i<length; i++) cout<<*(array+i)<<" "; 
    cout<<endl;
}
int miStrcmp(char* array1, char* array2){
    int diferencia=0;
    for(; diferencia==0; array1++, array2++){
        diferencia = *array1-*array2;
        if(*array1==0||*array2==0) break;
    }
    return diferencia;
}
void miStrcpy(char* arrayOrigen, char* arrayDestino){
    for(;*arrayOrigen;arrayOrigen++, arrayDestino++) *arrayDestino = *arrayOrigen;
    *arrayDestino = '\0';
}

template <typename T>
void rotarDerecha(T* array, int posiciones, int length=0){
    if(length==0&&sizeof(*array)==sizeof(char)) length = calcLength(array);
    if(length==0) cout<<"Error, no se pudo rotar el arreglo"; return;
    for (int i=0; i<posiciones; i++){
        T last = *(array+length-1);
        for (int j=length-1; j>0; j--){
            *(array+j) = *(array+j-1);
        }
        *array = last;
    }
}
// last = 2
// temp = 2
// 1 2 3 4 5
int main(){
    char array1[] = "huevo gas";
    char array2[] = "huevo gas";
    char array3[] = "huevo gaso";
    char array4[] = "gaso huevo";
    char array5[20] = {0};
    int array6[] = {1,2,3,4,5};


    miStrcpy(array1, array5);
    mostrarArray(array1);
    rotarDerecha(array1, 2);
    mostrarArray(array1);
}