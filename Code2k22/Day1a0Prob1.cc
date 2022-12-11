#include <iostream>

using namespace std;

void aumentaCiclo(int &ciclo, int &ret, int x){
    ciclo++; 
    if(ciclo == 20 or ciclo == 60 or ciclo == 100 or ciclo == 140 or ciclo == 180 or ciclo == 220){
            ret+=x*ciclo;
            //cout << "ciclo " << ciclo << ", valor " << ret << endl;
    }
    
}

int main()
{
    int ciclo = 0; 
    int x = 1; 
    int ret = 0; 
    string op; 
    int opval; 
    while(cin >> op){
        if(op == "noop") aumentaCiclo(ciclo, ret, x); 
        else if(op == "addx"){
            cin >> opval;
            aumentaCiclo(ciclo, ret, x);
            aumentaCiclo(ciclo, ret, x); 
            x += opval;
            
        }
        else break; 
        
    }
    cout << "Valor: " << ret; 
}
