#include <iostream>
using namespace std;
void copiarTareas(string* tareas, string* nuevo, int n){
    for(int i=0; i<n; i++){
        nuevo[i]=tareas[i];
    }
}
void agregarTarea(string*& tareas, int* n){
    string* nuevo = new string[*n+1];
    copiarTareas(tareas, nuevo, *n);
    cout<<"Ingrese el nombre de la nueva tarea: ";
    cin.ignore();
    getline(cin, nuevo[*n]);
    delete[] tareas;
    tareas = nuevo;
    *n+=1;
}
void eliminarTarea(string*& tareas, int* n){
    if (*n==0){
        cout<<"Aun no hay tareas"; return;
    }
    if (*n==1) {
        delete[] tareas;
        tareas = nullptr;
        *n=0;
        cout<<"Tarea eliminada con exito"<<endl;
        return;
    }
    string* nuevo = new string[*n-1];
    copiarTareas(tareas, nuevo, *n-1);
    delete[] tareas;
    tareas = nuevo;
    cout<<"Tarea eliminada con exito"<<endl;
    *n-=1;
}
void mostrarTareas(string* tareas, int n){
    if(n==0) {
        cout<<"No hay tareas para mostrar"; return;
    }
    cout<<"Lista de tareas: "<<endl;
    for(int i=0; i<n; i++){
        cout<<i+1<<". "<<tareas[i]<<endl;
    }
}
int main(){
    int n=0;
    string* tareas = nullptr;
    for(int opcion=1; opcion!=0;){
        system("cls");
        cout<<"MENU"<<endl;
        cout<<"1. Agregar una tarea"<<endl;
        cout<<"2. Eliminar la ultima tarea agregada"<<endl;
        cout<<"3. Mostrar todas las tareas actuales"<<endl;
        cout<<"0. Salir"<<endl;
        do {
            cout<<"Escoja una opcion: "; cin>>opcion;
            if(opcion<0||opcion>3) cout<<"Opcion invalida"<<endl;
        } while(opcion<0||opcion>3);
        system("cls");
        switch(opcion){
            case 0: cout<<"Gracias por usar el programa"; return 0;
            case 1: agregarTarea(tareas, &n); break;
            case 2: eliminarTarea(tareas, &n); break;
            case 3: mostrarTareas(tareas, n); break;
        }
        cout<<endl;
        system("pause");
    }
    delete[] tareas;
    tareas = nullptr;
    return 0;
}