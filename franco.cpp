/*
crear un programa para un banco que registre n cantidad de cedulas, y saldo inicial, con base a esto crear un menu
en el que se permitan ejecutar las sgtes opciones
1. consultar
2. consignar
3. retirar
4. listado de cedulas y saldos
5. finalizar
*/
#include <iostream>
#include <iomanip>
using namespace std;

int N; // La declaro global por simplicidad

long long* cedulaEsta(long long *cedulas, long long cedula, int cantidad){

    for(int i=0; i<cantidad; i++) if(cedula==*(cedulas+i)) return (cedulas+i);
    return 0;

}

void consultar(long long *cedulas, double *saldos){
    long long cedula;
    long long *pCedula;
    do{
        cout<<"Ingrese el numero de cedula a consultar: "; 
        cin>>cedula;
        pCedula = cedulaEsta(cedulas,cedula,N);
        if (!pCedula) cout<<"Ese numero de cedula no aparece en la base de datos"<<endl;
        else break;

    } while(true);
    int index = pCedula - cedulas;
    double *saldo = &saldos[index];
    cout<<"Saldo: $"<<*saldo<<endl;
    system("pause");
}

void listado(long long *cedulas, double *saldos){
    cout<<"Listado"<<endl;
    cout<<setw(15)<<"Cedula"<<setw(15)<<"Saldo";
    for (int i=0; i<N; i++) cout<<endl<<setw(15)<<*(cedulas+i)<<setw(14)<<*(saldos+i)<<"$";
    cout<<endl;
    system("pause");
}

void rellenar(long long *cedulas, double *saldos){

    for(int i=0; i<N; i++){
        system("cls");
        long long cedula;
        cout<<"Cliente #"<<i+1<<endl;
        do{
            cout<<"Ingrese el numero de cedula: "; 
            cin>>cedula;
            if (cedulaEsta(cedulas,cedula,i)) cout<<"Ese numero de cedula ya esta en la base de datos"<<endl;
            else break;

        } while(true);
        *(cedulas+i) = cedula;
        do{ 
            cout<<"Ingrese el saldo inicial: $"; 
            cin>>*(saldos+i);
            if (*(saldos+i)<0) cout<<"El saldo no puede ser negativo"<<endl;
        } while (*(saldos+i)<0);
    }

}

void consignar(long long *cedulas, double *saldos){
    long long cedula;
    long long *pCedula;
    do{
        cout<<"Ingrese el numero de cedula: "; 
        cin>>cedula;
        pCedula = cedulaEsta(cedulas,cedula,N);
        if (!pCedula) cout<<"Ese numero de cedula no aparece en la base de datos"<<endl;
        else break;

    } while(true);
    int index = pCedula - cedulas;
    double *saldo = &saldos[index];
    double monto;

    cout<<"Tiene $"<<*saldo<<" de saldo"<<endl;
    do{ 
            cout<<"Ingrese cuanto dinero va a consignar: $"; 
            cin>>monto;
            if (monto<0) cout<<"Tiene que poner una cantidad positiva"<<endl;
        } while (monto<0);
    *saldo += monto;
    cout<<"Nuevo saldo: $"<<*saldo<<endl;
    system("pause");
    
}

void retirar(long long *cedulas, double *saldos){
    long long cedula;
    long long *pCedula;
    do{
        cout<<"Ingrese el numero de cedula: "; 
        cin>>cedula;
        pCedula = cedulaEsta(cedulas,cedula,N);
        if (!pCedula) cout<<"Ese numero de cedula no aparece en la base de datos"<<endl;
        else break;

    } while(true);
    int index = pCedula - cedulas;
    double *saldo = &saldos[index];
    double monto;

    cout<<"Tiene $"<<*saldo<<" de saldo"<<endl;
    do{ 
            cout<<"Ingrese cuanto dinero va a retirar: $"; 
            cin>>monto;
            if (monto<0) cout<<"Tiene que poner una cantidad positiva"<<endl;
            if (monto>*saldo) cout<<"No tiene suficiente saldo"<<endl;
        } while (monto<0||monto>*saldo);
    *saldo -= monto;
    cout<<"Nuevo saldo: $"<<*saldo<<endl;
    system("pause");
}

int main(){

    cout<<"Ingrese el numero de clientes: "; cin>>N;
    long long cedulas[N] = {0};
    double saldos[N] = {0};
    rellenar(cedulas, saldos);
    while(true){
        int opcion;
        system("cls");
        cout<<"MENU"<<endl;
        cout<<"1. Consultar"<<endl;
        cout<<"2. Consignar"<<endl;
        cout<<"3. Retirar"<<endl;
        cout<<"4. Listado de cedulas y saldos"<<endl;
        cout<<"5. Salir"<<endl<<endl;
        do {
            cout<<"Opcion: ";
            cin>>opcion;
            if(opcion<1||opcion>5) cout<<"Opcion invalida"<<endl;
        } while(opcion<1||opcion>5);
        system("cls");
        switch(opcion){
            case 1: {
                consultar(cedulas, saldos);
                break;
            }
            case 2:{
                consignar(cedulas, saldos);
                break;
            }
            case 3:{
                retirar(cedulas, saldos);
                break;
            }
            case 4: {
                listado(cedulas, saldos);
                break;
            }
            case 5: return 0;
        }
    }


    return 0;

}