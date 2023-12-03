
#include <iostream>
#include <vector>
#include <cmath>

int SIZE_ROW = 140; 


using namespace std;

int seekANumber(int x, int y, vector<vector<char>>& mapita){//Busca y devuelve números cercanos a un signo. 
    bool searchingLeft = true; 
    bool searchingRight = true;
    vector<char> result;
    char c = mapita[x][y];
    result.push_back(c);
    int i = 1; 
    while(searchingLeft and y-i >= 0){//buscamos los numeros hacia la izquierda y sustituimos para que no se cuenten doble
        if(mapita[x][y-i] <= '9' and mapita[x][y-i] >= '0'){
            result.insert(result.begin(), mapita[x][y-i]);
            mapita[x][y-i] = '.';
            
            i++;
        }
        else searchingLeft = false; 
    }
    i=1;
    while(searchingRight and y+i < SIZE_ROW){//lo mismo con los nums a la derecha
        if(mapita[x][y+i] <= '9' and mapita[x][y+i] >= '0'){
            result.push_back(mapita[x][y+i]);
            mapita[x][y+i] = '.';
            
            i++;
        }
        else searchingRight = false; 
    }
    int ret = 0; 
    if(result.size() == 0){
        return result[0] - '0';
    }
    //for(int i = 0; i < result.size(); ++i) cout << result[i];
    //cout << endl; 
    for(int i = result.size()-1; i >= 0; --i){
        double aux = result[i] - '0'; 
        double ex = result.size() - i; 
        ret += aux * pow(10, ex-1);
         
    }
    //cout << "encuentro el numero "<<ret << endl;
    return ret; 
}

int checkAll(int x, int y, vector<vector<char>> mapa){
    char auxC; 
    vector<int> ret; 
    auxC = mapa[x-1][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x-1,y-1,mapa)); 
    auxC = mapa[x-1][y]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x-1,y,mapa)); 
    auxC = mapa[x-1][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x-1,y+1,mapa)); 
    auxC = mapa[x][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x,y-1,mapa)); 
    auxC = mapa[x][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x,y+1,mapa)); 
    auxC = mapa[x+1][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x+1,y-1,mapa)); 
    auxC = mapa[x+1][y]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x+1,y,mapa)); 
    auxC = mapa[x+1][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret.push_back(seekANumber(x+1,y+1,mapa));
    if(ret.size() == 2){
        cout << "Lo logre" << endl;
        return ret[0] * ret[1]; 
    }
    return 0; 
}

int main()
{
    vector<vector<char>> mapa(SIZE_ROW , vector<char> (SIZE_ROW, 0)); 
    vector<pair<int, int>> checkLater; 
    char auxC;
    for(int i = 0; i < SIZE_ROW;++i){
        for(int j = 0; j < SIZE_ROW;++j){
            cin >> auxC;
            if(auxC == '*') {
                checkLater.push_back(make_pair(i,j));
            }
            //cout << "itero" << i << j << endl; 
            mapa[i][j] = auxC; 
        }
    }
    cout << checkLater.size() << endl; 
    int ret; 
    for(int i = 0; i < checkLater.size(); ++i){
        int x = checkLater[i].first;
        int y = checkLater[i].second; 
        ret += checkAll(x,y,mapa);
    }
    cout<<ret<<endl;
}
