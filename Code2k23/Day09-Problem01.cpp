#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 

using namespace std; 

typedef vector<long long> iteracion; 
typedef vector<iteracion> codigo; 


void writeAFile(codigo c){
    cout << "ULTIMA FILA MATRIZ:" << endl; 
    int fila = c.size() - 2; 
    for(int i = 0; i < c[fila].size(); ++i) cout << c[fila][i] << " "; 
    cout << endl; 
    cout << "---------------" << endl; 
}
void writeMatrix(codigo c){
    cout << "-----------------" << endl;
    for(int i = 0; i < c.size(); ++i){
        for(int j = 0; j < c[i].size(); ++j)cout << c[i][j] << " "; 
        cout << endl; 
    }
    cout << "-----------------" << endl;
}

bool checkAllZeros(vector<long long> v){
    int aux = 0; 
    for(int i = 0; i < v.size(); ++i)aux += v[i]; 
    return aux == 0;  
}

vector<long long> extrapolate(vector<long long> v){
        vector<long long> v2; 
        for(int i = 0; i < v.size() - 1; ++i) {
            v2.push_back(v[i+1] - v[i]); 
        }
        return v2; 
}

int addToLastValue(vector<int> v, int i){
     return v.back() + i; 
}

int main(){
    int ret = 0; 
    ifstream file("input.txt"); 
    string line; 
    long long sol = 0; 
    while(getline(file, line)){
        codigo valores;//creamos la matriz 
        vector<long long> tmpVec;
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
        writeMatrix(valores); 
        for(int i = valores.size()-1; i > 0; --i){
            valores[i-1].push_back(valores[i-1].back() + valores[i].back());
        }
        cout << valores[0].back() << endl; 
        sol += valores[0].back(); 
        writeMatrix(valores); 
        cout << sol<<endl;    
         
    }
    cout << "solucion: " << sol;
}    
