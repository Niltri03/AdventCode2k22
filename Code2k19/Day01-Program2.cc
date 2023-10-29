
#include <iostream>
using namespace std; 



int main(){
    int valor; 
    int total;
    while(cin>>valor){
        while(valor/3 - 2 > 0){
            valor /= 3; 
            valor -=2; 
            cout << valor << endl; 
            total += valor;
        }
        cout << (total) << endl;
        cout << "-----------" << endl; 
    }

}
