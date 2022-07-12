#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Implementacion del algoritmo intuitivo para hallar las inversiones de un arreglo
void invCountIntuitivo(vector<int> arr, int n){

    int count = 0;

    for(int i = 0; i < n; i++){

        for (int j = i+1; j < n; j++){

            if (arr [i] > arr[j]){
                count++;
            }
        }
    }

    cout << "Num inversiones:" << count << endl;
}

// Implementacion del algoritmo para hallar las inversiones de un arreglo utilizando tecnica divide y venceras
// Basado en mergesort
int mergeSortInvCount(vector<int> &arr, int izq, int der);
int mergeInvCount(vector<int> &arr, int izq, int mitad, int der);

void invCountRecursivo(vector<int> &arr, int n){

    int numInversiones = mergeSortInvCount(arr, 1, n);
    cout << "Num inversiones:" << numInversiones << endl;
}

int mergeSortInvCount(vector<int> &arr, int izq, int der){

    int invCount = 0;

    if(izq < der){

        int mitad = (izq + der)/2;
        invCount = mergeSortInvCount(arr, izq, mitad);
        invCount += mergeSortInvCount(arr, mitad+1, der);
        invCount += mergeInvCount(arr, izq, mitad, der);
    }

    return invCount;
}

int infinito = numeric_limits<int>::max();

int mergeInvCount(vector<int> &arr, int izq, int mitad, int der){

    int n1 = mitad - izq + 1;
    int n2 = der - mitad;

    int invCount = 0;

    vector<int> vectorIzq;
    vector<int> vectorDer;

    for(int k=0;k<n1;k++){

        vectorIzq.push_back(arr[izq+k-1]);
    }

    vectorIzq.push_back(infinito);

    for(int k=0;k<n2;k++){

        vectorDer.push_back(arr[mitad+k]);
    }

    vectorDer.push_back(infinito);

    int i = 0;
    int j = 0;

    for(int k = izq; k <= der; k++){

        if(vectorIzq[i] <= vectorDer[j]){

            arr[k-1] = vectorIzq[i];
            i++;
        }
        else{

            arr[k-1] = vectorDer[j];
            j++;
            invCount += (n1 - i);
        }
    }

    return invCount;
}

// main
int main(){

    cout<<"Inversiones de un vector"<<endl<<endl;

    vector<int> v = {4,3,1,8,2};
    int n = v.size();

    cout<<"Vector: { ";
    for(int i=0; i < n; i++){
        cout<<v[i]<<" ";
    }
    cout<<"}"<<endl<<endl;

    cout << "Conteo de inversiones, algoritmo intuitivo." << endl;
    invCountIntuitivo(v, n);

    cout<<endl;

    cout << "Conteo de inversiones, algoritmo recursivo." << endl;
    invCountRecursivo(v, n);

    return 0;
}
