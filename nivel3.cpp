#include <iostream>
using namespace std;
bool hayCambio(char* string1, char* string2){ // Retorna true si array1 deberia ir antes que array2
    while(*string1!='\0'&&*string2!='\0'){ // Mientras que ninguno de los dos termine
        if (tolower(*string1)!=tolower(*string2)){
            return (tolower(*string1)>tolower(*string2));
        }
        string1++;
        string2++;
    }
    return (*string1>*string2); 
    // Si string2 termina antes, retorna true
    // si termina antes string1 o terminan al mismo tiempo (strings iguales) retorna false
}
void ordenarArray(char **array, int length){
    for (int i=0; i<length-1; i++){
        for (int j=0; j<length-i-1; j++){
            if (hayCambio(*(array+j),*(array+j+1))){
                char* temp = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = temp;
            }
        }
    }
}
void imprimir(char **array, int length){
    for (int i=0; i<length; i++){
        char *string = *(array+i);
        for (int j=0; *(string+j)!='\0'; j++) cout<<*(string+j);
        if(i<length-1) cout<<" , ";
    }
    cout<<endl;
}
int main(){
    char* nombres[] = {"Carlos", "Ana", "Bruno"};
    char* nombres2[] = {"Carlos", "Ana", "Bruno", "Juan", "Anais", "Jordan", "Juana", "Juanito", "Bernardo"};
    imprimir(nombres, 3);
    ordenarArray(nombres, 3);
    imprimir(nombres, 3);
    imprimir(nombres2, 9);
    ordenarArray(nombres2, 9);
    imprimir(nombres2, 9);
    return 0;
}