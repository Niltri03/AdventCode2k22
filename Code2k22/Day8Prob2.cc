#include <iostream>
#include <vector>
using namespace std;

using Row = vector<int>; 
using Forest = vector<Row>; 
using Row2 = vector<int>; 
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

void calcF2(Forest &f){
    int max = 0; 
    cout << "-------------" << endl;
    for(int i = 0; i < f.size(); ++i){
        for(int j = 0; j < f.size(); ++j){
            if (max < f[i][j]) max = f[i][j];
        }
    }
    cout << "El maximo valor posible es  " << max << endl;
}

int main()
{
    Forest f(99, vector<int>(99));
    //Forest f (5, vector<int>(5)); //para debug
    cout << f.size() << endl; 
  
    for(int i = 0; i < f.size();++i){
        for(int j = 0; j < f.size(); ++j){
            char c; 
            cin >> c;
            f[i][j] = c - '0'; 
        }
    }
    Forest f2(f.size(), vector<int>(f.size(), 0));

    for(int i = 0; i < f.size(); ++i){
        f2[i][0] = true; 
        f2[i][f.size()-1]  = true; 
    }
    for(int i = 0; i < f.size(); ++i){
        f2[0][i] = true; 
        f2[f.size()-1][i]  = true; 
    }
    
    
    for(int i = 0; i < f.size(); ++i){
        for(int j = 0; j < f.size(); ++j){
            int t, b, r, l; //Ints indican la distancia al arbol mas cercano que "le tapa".
            t = 0;
            b = 0; 
            r = 0; 
            l = 0; 
            for(int i2 = i-1; i2 >= 0; --i2){
                t++; 
                if(f[i][j] <= f[i2][j]){
                   i2 = 0; 
                } 
            } 
            for(int i2 = i+1; i2 < f.size(); ++i2){
                b++; 
                if(f[i][j] <= f[i2][j]){
                    i2 =f.size();
                } 
            } 
            for(int j2 = j-1; j2 >= 0; --j2){
                l++; 
                if(f[i][j] <= f [i][j2]){
                    j2 = 0; 
                }  
            } 
            for(int j2 = j+1; j2 < f.size(); ++j2){
                r++;
                if(f[i][j] <= f[i][j2]){
                    j2 = f.size(); 
                } 
            } 
            int total = r * l; 
            total *= t; 
            total *= b; 
            f2[i][j] = total; 
        }
    }
    
    
    
    

    calcF2(f2); 
    
    
    
}
