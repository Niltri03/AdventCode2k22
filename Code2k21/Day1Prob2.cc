#include <iostream>
using namespace std; 

int main()
{
    int act, old1, old2; 
    int oldmax, newmax; 
    cin >> act >> old1 >> old2; 
    int re = 0; 
    oldmax = act + old1 + old2; 
    old2 = old1; 
    old1 = act;  
    while(cin >> act){
        newmax = act + old2 + old1; 
        if (newmax > oldmax) re++; 
        oldmax = newmax; 
        old2 = old1; 
        old1 = act;  
    }
    cout << re << endl; 
}
