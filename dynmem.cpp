#include <iostream>
using namespace std;
int main(){
    int N;
    
    cout<<"Cuantos estudiantes tiene el curso?: "; cin>>N;
    float *array = new float[N];
    float *notaBaja=array, *notaAlta=array;
    float sumatoria=0;
    for(int i=0; i<N; i++){
        cout<<"Ingrese la nota del estudiante #"<<i+1<<": ";
        cin>>array[i]; sumatoria+=array[i];
        if(*notaAlta<array[i]) notaAlta = &array[i];
        else if (*notaBaja>array[i]) notaBaja = &array[i];
    }
    float notaPromedio = sumatoria/N;
    cout<<"La nota promedio de los estudiantes fue: "<<notaPromedio<<endl;
    cout<<"La nota mas baja fue "<<*notaBaja<<" del estudiante #"<<notaBaja-array+1<<endl;
    cout<<"La nota mas alta fue "<<*notaAlta<<" del estudiante #"<<notaAlta-array+1<<endl;
    delete[] array;
    return 0;
}