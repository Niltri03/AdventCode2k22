#include <iostream>
using namespace std; 

int main()
{
    int a, max; 
    cin >> max; 
    int re = 0; 
    while(cin >> a){
        if (a > max) re++;
        max = a; 
    }
    cout << re << endl; 
}
