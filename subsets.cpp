#include <iostream>
#include <vector>
using namespace std;

int n = 3;
vector<int> conjunto = {1,6,-5};

/*  Halla e imprime los subconjuntos de conjunto */
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

int main(){
    cout << "Subconjuntos de un conjunto" << endl;
    subConjuntos(0, {});
    cout << endl;
    return 0;
}