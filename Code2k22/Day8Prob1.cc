/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

using Row = vector<int>; 
using Forest = vector<Row>; 
using Row2 = vector<bool>; 
using Forest2 = vector<Row2>; 

int main()
{
    //Forest f(99, vector<int>(99));
    Forest f (5, vector<int>(5)); 
    cout << f.size() << endl; 
    for(int i = 0; i < 5;++i){
        for(int j = 0; j < 5; ++j){
            char c; 
            cin >> c;
            f[i][j] = c - '0'; //Lee de izq a derecha y abajo arriba
        }
    }
    Forest2 f2(f.size(), vector<bool>(f.size(), false));
    int contador = 0; 
    for(int i = 0; i < f.size();++i){
    bool b = true; 
    contador++;
        for(int j = 0; j < f.size(); ++j){
            for(int i2 = 0; i2 < i; ++i2){
                cout << "itero el valor" << i << j << " y lo comparo con " << i2 << j << endl; 
                if(f[i2][j] > f[i][j]){
                        b = false; 
                        i2 = i; 
                }
                if(b) f2[i][j] = true; 
                b = false; 
            }
            
        }
    }
    cout << contador << endl; 
    for(int i = f.size()-1; i >= 0;++i){
    contador++; 
    bool b = true; 
        for(int j = f.size()-1; j >= 0; ++j){
            for(int i2 = f.size()-1; i2 > i; --i2){
                if(f[i2][j] > f[i][j]){
                        b = false; 
                        i2 = i; 
                }
                if(b) f2[i][j] = true; 
                b = false; 
            }
            
        }
    }
    cout << contador << endl; 
    for(int i = 0; i < f.size();++i){
    bool b = true; 
    contador++;
        for(int j = 0; j < f.size(); ++j){
            for(int j2 = 0; j2 < j; ++j2){
                if(f[i][j2] > f[i][j]){
                        b = false; 
                        j2 = j; 
                }
                if(b) f2[i][j] = true; 
                b = false; 
            }
            
        }
    }
    cout << contador << endl; 
    for(int i = f.size()-1; i >= 0;++i){
    contador++; 
    bool b = true; 
        for(int j = f.size()-1; j >= 0; ++j){
            for(int j2 = f.size()-1; j2 > j; ++j2){
                if(f[i][j2] > f[i][j]){
                        b = false; 
                        j2 = j; 
                }
                if(b) f2[i][j] = true; 
                b = false; 
            }
            
        }
    }
    cout << contador << endl; 
    for(int i = 0; i < f.size(); ++i){
        for(int j = 0; j < f.size(); ++j){
            cout << f2[i][j];
        }
        cout << endl; 
    }
    
}
