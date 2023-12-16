#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 

using namespace std; 

typedef  vector<long long> iteracion; 
typedef vector<iteracion> codigo; 


void writeMatrix(codigo c){
    cout << "-----------------" << endl;
    for(int i = 0; i < c.size(); ++i){
        for(int j = 0; j < c[i].size(); ++j)cout << c[i][j] << " "; 
        cout << endl; 
    }
    cout << "-----------------" << endl;
}

bool checkAllZeros(iteracion v){
    int aux = 0; 
    for(int i = 0; i < v.size(); ++i)if(v[i] != 0) return false; 
    return true; 
}

iteracion extrapolate(iteracion v){
        iteracion v2; 
        for(int i = 0; i < v.size() - 1; ++i) {
            v2.push_back(v[i+1] - v[i]); 
        }
        return v2; 
}

int main(){
    int ret = 0; 
    ifstream file("input.txt"); 
    string line; 
    long long sol = 0; 
    while(getline(file, line)){
        codigo valores;//creamos la matriz 
        iteracion tmpVec;
        valores.push_back(tmpVec);//añadimos los primeros valores 
        
        stringstream separados(line); 
        long long tmp; 
        while(separados >> tmp) valores[0].push_back(tmp); 

        int contador = 0; 
        tmpVec = extrapolate(valores[contador]); 
        while(!checkAllZeros(tmpVec)){
            valores.push_back(tmpVec);
            contador++;
            tmpVec = extrapolate(valores[contador]);
        } 
        tmpVec = {0}; 
        valores.push_back(tmpVec); 
        //writeMatrix(valores); 
        for(int i = valores.size()-1; i > 0; --i){
            valores[i-1].insert(valores[i-1].begin(), valores[i-1].front() - valores[i].front());
        }
        sol += valores[0].front(); 
    }
    cout << "solucion: " << sol;
}    
