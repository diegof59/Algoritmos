#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Taller 1 FADA.

// Punto 1.

int n = 3;
vector<int> conjunto = {1,6,-5};

// Halla e imprime los subconjuntos de conjunto
void subConjuntos(int pos, vector<int> funVect){

    if(pos == n){

        for (int n : funVect){
            cout << n << ' ';
                    }
        cout << endl;
    }
    else{
        funVect.push_back(conjunto[pos]);
        subConjuntos(pos+1, funVect);
        funVect.pop_back();
        subConjuntos(pos+1, funVect);
    }
}


// Punto 2

int m = 3;
vector<int> arreglo = {-1, 7, 18};

// Halla e imprime las permutaciones de arreglo
void permutaciones(int pos, vector<int> funVect, vector<bool> usado){

    if(pos == m){

        for (int m : funVect){
            cout << m << ' ';
        }
        cout << endl;
    }
    else{

        for (int i = 0; i < m; i++)
        {
            if (usado[i] == true){
                continue;
            }
            else{
                funVect.push_back(arreglo[i]);
                usado[i] = true;
                permutaciones(pos+1, funVect, usado);
                usado[i] = false;
                funVect.pop_back();
            }
        }
    }
}

// Punto 3

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

    cout << count << endl;
}


// Implementacion del algoritmo para hallar las inversiones de un arreglo utilizando tecnica divide y venceras
// Basado en mergesort
void mergeSortInvCount(vector<int> &arr, int izq, int der);
void mergeInvCount(vector<int> &arr, int izq, int mitad, int der);

void invCountRecursivo(vector<int> &arr, int n){

    int numInversiones = mergeSortInvCount(arr, 1, n);
    cout << "Num inversiones:" << numInversiones << endl;
    for(int i=0; i < n; i++){

        cout<<arr[i]<<endl;
    }
}

void mergeSortInvCount(vector<int> &arr, int izq, int der){

    //int invCount = 0;

    if(izq < der){

        int mitad = (izq + der)/2;

        invCount = mergeSortInvCount(arr, izq, mitad);
        invCount += mergeSortInvCount(arr, mitad+1, der);
        invCount += mergeInvCount(arr, izq, mitad, der);
    }

    return invCount;
}

int infinito = numeric_limits<int>::max();

void mergeInvCount(vector<int> &arr, int izq, int mitad, int der){

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
            invCount += (mitad - i);
        }
    }

    return invCount;
}

// main
int main(){

    cout << "Punto 1: Subconjuntos" << endl;
    // Llamado Punto 1
    subConjuntos(0, {});
    cout << endl;

    cout << "Punto 2: Permutaciones" << endl;
    // Llamado Punto 2
    permutaciones(0,{},{0,0,0});
    cout << endl;

    cout << "Punto 3: Conteo de inversiones" << endl;
    //Llamado punto 3
    //invCountIntuitivo({4,3,1,8,2}, 5);

    // Llamado implementación de algoritmo planteado.
    vector<int> v = {4,3,1,8,2};
    invCountRecursivo(v, 5);

    return 0;
}
