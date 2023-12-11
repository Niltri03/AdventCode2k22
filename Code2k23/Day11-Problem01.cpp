#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 

using namespace std; 


vector<string> c;

void checkAllDotsVerticales(){
    vector<int> aDuplicar; 
    for(int i = 0; i < c[0].length(); ++i){
        int tmp = 0; 
        for(int j = 0; j < c.size(); ++j) if(c[j][i] != '.') tmp++; 
        if(tmp == 0) aDuplicar.push_back(i);  
    }
    for(int i = 0; i < aDuplicar.size(); ++i) {
        for(int j = 0; j < c.size(); ++j){
            c[j].insert(c[j].begin()+aDuplicar[i]+i, '.');
        }
    }
}

void writeMatrix(){
    cout << "-----------------" << endl;
    for(int i = 0; i < c.size(); ++i){
        for(int j = 0; j < c[i].size(); ++j)cout << c[i][j] << " "; 
        cout << endl; 
    }
    cout << "-----------------" << endl;
}

bool checkAllDots(string v){
    int aux = 0; 
    for(int i = 0; i < v.size(); ++i) if(v[i] != '.') return false; 
    return true; 
}


int main(){
    int ret = 0; 
    ifstream file("input1.txt"); 
    string line; 
    while(getline(file, line)){
        //creamos la matriz 
        c.push_back(line);//añadimos los primeros valores 
        if(checkAllDots(line)) c.push_back(line); 
        
    }
    checkAllDotsVerticales(); 
    writeMatrix(); 
    cout << "solucion: " << ret;
}    
