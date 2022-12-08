#include <iostream>
#include <vector>
using namespace std;

using Row = vector<int>; 
using Forest = vector<Row>; 
using Row2 = vector<bool>; 
using Forest2 = vector<Row2>; 

void writeF2(Forest2 &f){
    int c = 0; 
    cout << "-------------" << endl;
    for(int i = 0; i < f.size(); ++i){
        for(int j = 0; j < f.size(); ++j){
            cout << f[i][j];
            if(f[i][j]) c++; 
        }
        cout << endl; 
    }
    cout << "----------------" << endl;
    cout << "En total hay " << c << " árboles visibles." << endl;
    
    
}

int main()
{
    Forest f(99, vector<int>(99));
    //Forest f (5, vector<int>(5)); 
    cout << f.size() << endl; 
  
    for(int i = 0; i < 99;++i){
        for(int j = 0; j < 99; ++j){
            char c; 
            cin >> c;
            f[i][j] = c - '0'; //Lee de izq a derecha y abajo arriba
        }
    }
    Forest2 f2(f.size(), vector<bool>(f.size(), false));

    for(int i = 0; i < f.size(); ++i){
        f2[i][0] = true; 
        f2[i][f.size()-1]  = true; 
    }
    for(int i = 0; i < f.size(); ++i){
        f2[0][i] = true; 
        f2[f.size()-1][i]  = true; 
    }
    
    
    for(int i = 1; i < f.size()-1; ++i){
        for(int j = 1; j < f.size()-1; ++j){
            bool t, b, r, l; //Bools indican si está tapado por algún lado.
            t = false;
            b = false; 
            r = false; 
            l = false; 
            for(int i2 = i-1; i2 >= 0; --i2) if(f[i][j] <= f[i2][j]) t=true;
            for(int i2 = f.size()-1; i2 > i; --i2) if(f[i][j] <= f[i2][j]) b=true;
            for(int j2 = j-1; j2 >= 0; --j2) if(f[i][j] <= f [i][j2]) l = true; 
            for(int j2 = f.size()-1; j2 > j; --j2) if(f[i][j] <= f[i][j2]) r=true;
            if(not t or not b or not r or not l)f2[i][j] = true; 
        }
    }
    
    
    
    

    writeF2(f2); 
    
    
    
}
