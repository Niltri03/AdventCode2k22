#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <iostream> 

using namespace std; 


vector<string> c;

const int GALACTIC_SPREAD = 10; //100 o 1 000 000 dependiendo de la pregunta


/* 
    KEY: 
        Dos pairs <int, int> representando las coordenadas de las dos galaxias. 
*/


void checkAllDotsVerticales(set<int>& v){
    vector<int> aDuplicar; 
    for(int i = 0; i < c[0].length(); ++i){
        int tmp = 0; 
        for(int j = 0; j < c.size(); ++j) if(c[j][i] != '.') tmp++; 
        if(tmp == 0) v.insert(i);
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
    ifstream file("input11.txt"); 
    string line; 
    int lineaActual = 0; 
    set<int> verticalesExpandidas, horizontalesExpandidas; //HORIzONTALES EPXANDIDAS: LAS FILAS MULTIPLICADAS
    while(getline(file, line)){
        //creamos la matriz 
        c.push_back(line);//añadimos los primeros valores
        lineaActual++; 
        if(checkAllDots(line)) horizontalesExpandidas.insert(lineaActual);
        
    }
    checkAllDotsVerticales(verticalesExpandidas); 
    cout << horizontalesExpandidas.size() << " " << verticalesExpandidas.size() << endl;
    //writeMatrix(); 
    set<pair<int, int>> cosasACheckear;
    for(int i = 0; i < c.size(); ++i){
        for(int j = 0; j < c[i].size(); ++j) if(c[i][j] == '#'){
            cosasACheckear.insert(make_pair(i,j));//añadimos a un vector las posiciones a comprobar posteriorment,.
        }
    }
    for(set<pair<int, int>>::iterator it = cosasACheckear.begin(); it != cosasACheckear.end(); ++it){
        for(set<pair<int, int>>::iterator it2 = it; it2 != cosasACheckear.end(); ++it2){
            it2++;
            if(it2 != cosasACheckear.end()){ 
            int x1 = it->first;
            int x2 = it2->first;
            int y1 = it->second;
            int y2 = it2->second; 
            
            
            int cc = 0; 
            for(set<int>::iterator xIt = horizontalesExpandidas.begin(); xIt != horizontalesExpandidas.end(); ++xIt){
                int k;
                k = *xIt;  
                if(k > x1 && k < x2) cc++; 
            }
            x2 += cc*GALACTIC_SPREAD; //las horizontales expandidas son FILAS que tienen que alargarse. 
            x2 -= cc; 
            cc = 0;
            for(set<int>::iterator xIt = verticalesExpandidas.begin(); xIt != verticalesExpandidas.end(); ++xIt){
                int k = *xIt;  
                if(k > y1 && k < y2) cc++; 
            }
            y2 += cc*GALACTIC_SPREAD;
            y2 -= cc; 
            ret += abs(x1-x2)+abs(y1-y2); 
            cout << "distancia calculada:" << abs(x1-x2)+abs(y1-y2) << ", actualmente tengo " << ret << endl; 
            }//ctrl ç coemnta una linea
            it2--;
        }

    }
    cout << "solucion: " << ret;
}    
