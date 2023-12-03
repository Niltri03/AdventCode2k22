
#include <iostream>
#include <vector>
#include <cmath>

int SIZE_ROW = 10; 


using namespace std;

int seekANumber(int x, int y, vector<vector<char>>& mapita){//Busca y devuelve números cercanos a un signo. 
    bool searchingLeft = true; 
    bool searchingRight = true;
    vector<char> result;
    char c = mapita[x][y];
    result.push_back(c);
    cout << "Hago pushback de " << c; 
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
            result.insert(result.begin(), mapita[x][y+i]);
            mapita[x][y+i] = '.';
            
            i++;
        }
        else searchingRight = false; 
    }
    int ret = 0; 
    if(result.size() == 0){
        return result[0] - '0';
    }
    for(int i = result.size(); i >= 0; --i){
        double aux = result[i] - '0'; 
        cout << "aux: " << aux << endl; 
        double ex = result.size() - i; 
        ret += aux * pow(10, ex-1);
        cout << "sumo a ret" << pow(10, ex-1) << endl; 
         
    }
    cout << "encuentro el numero "<<ret << endl;
    return ret; 
}

int checkAll(int x, int y, vector<vector<char>>& mapa){
    char auxC; 
    int ret; 
    auxC = mapa[x-1][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x-1,y-1,mapa); 
    auxC = mapa[x-1][y]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x-1,y,mapa); 
    auxC = mapa[x-1][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x-1,y+1,mapa); 
    auxC = mapa[x][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x,y-1,mapa); 
    auxC = mapa[x][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x,y+1,mapa); 
    auxC = mapa[x+1][y-1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x+1,y-1,mapa); 
    auxC = mapa[x+1][y]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x+1,y,mapa); 
    auxC = mapa[x+1][y+1]; 
    if(auxC >= '0' and auxC <= '9') ret += seekANumber(x+1,y+1,mapa);
    cout << "añado " << ret << " para x" << x << " y " << y << endl; 
    return ret; 
}

int main()
{
    vector<vector<char>> mapa(SIZE_ROW , vector<char> (SIZE_ROW, 0)); 
    vector<pair<int, int>> checkLater; 
    char auxC;
    for(int i = 0; i < SIZE_ROW;++i){
        for(int j = 0; j < SIZE_ROW;++j){
            cin >> auxC;
            if(auxC != '.' and (auxC > '9' or auxC < '0')) {
                checkLater.push_back(make_pair(i,j));
            }
            //cout << "itero" << i << j << endl; 
            mapa[i][j] = auxC; 
        }
    }
    int ret; 
    for(int i = 0; i < checkLater.size(); ++i){
        int x = checkLater[i].first;
        int y = checkLater[i].second; 
        ret += checkAll(x,y,mapa);
    }
    cout<<ret<<endl;
}
