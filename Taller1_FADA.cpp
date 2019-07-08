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

// Implementación del algoritmo intuitivo para hallar las inversiones de un arreglo
void invCountIntuitivo(vector<int> array, int n){

	int count = 0;

	for(int i = 0; i < n; i++){
		
		for (int j = i+1; j < n; j++){
			
			if (array [i] > array[j]){
				count++;
			}
		}
	}

	cout << count << endl;
}

int mergeSortInvCount(vector<int> array, int izq, int der);
int mergeInvCount(vector<int> array, int izq, int mitad, int der);

void invCountRecursivo(vector<int> array, int n){

	int numInversiones = mergeSortInvCount(array, 0, n-1);
	cout << numInversiones << endl;
}

int mergeSortInvCount(vector<int> array, int izq, int der){

	int invCount = 0;

	if(izq < der){

		int mitad = (izq + der)/2;

		invCount = mergeSortInvCount(array, izq, mitad);
		invCount += mergeSortInvCount(array, mitad+1, der);
		invCount += mergeInvCount(array, izq, mitad, der);
	}

	return invCount;
}

int infinito = numeric_limits<int>::max();

int mergeInvCount(vector<int> array, int izq, int mitad, int der){

	int n1 = mitad;
	int n2 = mitad + 1;

	int invCount = 0;

	vector<int> vectorIzq(array[izq], array[n1]);
	vectorIzq.push_back(infinito);

	vector<int> vectorDer(array[n2], array[der]);
	vectorDer.push_back(infinito);

	int i = 0;
	int j = 0;

	for(int k = izq; k < der; i++){
		
		if(vectorIzq[i] < vectorDer[j]){

			array[k] = vectorIzq[i];
		}
		else{

			array[k] = vectorDer[j];
			invCount += mitad - i;
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

	cout << "Punto 3: " << endl;
	//Llamado punto 3
	//invCountIntuitivo({4,3,1,8,2}, 5);

	invCountRecursivo({4,3,1,8,2}, 5);

	return 0;
}