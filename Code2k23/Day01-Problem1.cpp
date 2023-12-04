#include <vector>
#include <iostream>
using namespace std; 

int main(){
    string st;
    int firstDigit, lastDigit, aux, result;
    aux = result = 0; 
    while(cin >> st and st != "amongus"){
        for(int i = 0; i < st.length(); i++){
            if(st[i] > '0' and st[i] <= '9'){
                int a = st[i] - '0';
                if(firstDigit == 0) firstDigit = a; 
                else lastDigit = a; 
            }
        }
        if(lastDigit == 0) lastDigit = firstDigit; 
        aux += lastDigit; 
        aux += 10 * firstDigit;
        result += aux;  
        aux = 0; 
        lastDigit = 0; 
        firstDigit = 0; 
    }
    cout << result;
}
