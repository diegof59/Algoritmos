#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    cout << "Permutaciones de un conjunto" << endl;
    permutaciones(0,{},{0,0,0});
    cout << endl;
    return 0;
}