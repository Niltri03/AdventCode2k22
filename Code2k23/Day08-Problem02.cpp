#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


string cleanString(string s){
    //cout << "string " << s;
    string s2; 
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z' || s[i] >= '0' and s[i] <= '9'){
            s2 += s[i];        
        }
    }
    //cout << " limpia: pasa a ser " << s2 << "." << endl; 
    return s2; 
}

bool areWeDone(vector<string>& s){
    for(int i = 0; i < s.size(); ++i){
        if(s[i].back() != 'Z') return false; 
    }
    return true; 
}

vector<string> findStartingSquares(map<string, pair<string, string>> m){//finds all starting positions (those ending on 'A')
    vector<string> ret; 
    for(map<string, pair<string, string>>:: iterator it = m.begin(); it != m.end(); ++it){
        string aux = it->first; 
        if(aux.back() == 'A') ret.push_back(aux); 
    }
    return ret; 
}


int main()
{
    map<string, pair<string, string>> mapa;
    string instrucciones; 
    cin >> instrucciones;   
    string aux1, equ, aux2, aux3; 
    while(cin >> aux1){//tenemos que añadir "done" al final del input
        if(aux1 == "done")break; 
        cin >> equ >> aux2 >> aux3;
        mapa.insert(make_pair(aux1, make_pair(cleanString(aux2), cleanString(aux3))));
    }
    vector<string> valores = findStartingSquares(mapa); 
    int pasos = 0; 
    int contador = 0;   
    while(1){
        char dir = instrucciones[contador]; 
        for(int i = 0; i < valores.size(); ++i){
            pair<string, string> temp = mapa.find(valores[i])->second; 
            if(dir == 'L') valores[i] = temp.first; 
            else valores[i] = temp.second; 
        }
        pasos++; 
        if(areWeDone(valores)){
            cout << "found! ";
            for(int i = 0; i < valores.size(); ++i){
                cout << valores[i] << " "; 
            } 
            cout << "Pasos minimos: " << pasos << endl; 
            exit(1); 
        }
        contador++;
        if(contador == instrucciones.size()) contador = 0; 
    }
}
