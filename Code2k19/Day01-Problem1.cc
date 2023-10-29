#include <iostream>
using namespace std; 



int main(){
    int valor; 
    int total;
    while(cin>>valor){
        valor /= 3; 
        valor -=2; 
        cout << valor << endl; 
        cout << (total += valor) << endl;
        cout << "-----------" << endl; 
    }

}
