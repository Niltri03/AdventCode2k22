#include <iostream>
using namespace std; 
#include <vector>

using row = vector<int>;
using mapaV = vector<row>; 


int x = 100;
mapaV mapa(x+2, row(x+2, 11));

bool evaluate(int i, int j){
    int aux = mapa[i][j];
    if(aux >= mapa[i][j+1]) return false;
    if(aux >= mapa[i][j-1]) return false;
    if(aux >= mapa[i+1][j]) return false;
    if(aux >= mapa[i-1][j]) return false;
    return true;  
}

int main()
{
    char c; 

    for(int i = 1; i <= x; ++i){
        for(int j = 1; j <= x; ++j) {
            cin >> c; 
            mapa[i][j] = c - '0';
        }
    }
    int count = 0; 
    for(int i = 1; i <= x; ++i){
        for(int j = 1; j <= x; ++j) if(evaluate(i, j)) count += mapa[i][j] + 1; 
    }
    cout << "count: " << count << endl; 

}
