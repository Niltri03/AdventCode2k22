#include <vector>
#include <string>
#include <set>
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
    //writeMatrix(); 
    set<pair<int, int>> cosasACheckear;
    for(int i = 0; i < c.size(); ++i){
        for(int j = 0; j < c[i].size(); ++j) if(c[i][j] == '#'){
            cosasACheckear.insert(make_pair(i,j));//añadimos a un vector las posiciones a comprobar posteriorment,.
        }
    }
    int contador = 0; 
    for(set<pair<int, int>>::iterator it = cosasACheckear.begin(); it != cosasACheckear.end(); ++it){
        for(set<pair<int, int>>::iterator it2 = it; it2 != cosasACheckear.end(); ++it2){
            it2++;
            if(it2 != cosasACheckear.end()){ 
            int x1 = it->first;
            int x2 = it2->first;
            int y1 = it->second;
            int y2 = it2->second; 
            ret += abs(x1-x2)+abs(y1-y2); 
            contador++; 
            }
            it2--;
        }

    }
    cout << "solucion: " << ret;
}    
