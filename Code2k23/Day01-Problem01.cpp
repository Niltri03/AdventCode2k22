#include <vector>
#include <iostream>
using namespace std; 

int main(){
    string st;
    int firstDigit, lastDigit, aux, result;
    aux = result = 0; 
    while(cin >> st and st != "amongus"){//after you enter your input, add a word so that the program knows it's done. 
        for(int i = 0; i < st.length(); i++){//checks the entire string
            if(st[i] > '0' and st[i] <= '9'){//if the char at our position is a number... 
                int a = st[i] - '0';//get its integer value...
                if(firstDigit == 0) firstDigit = a; //if we haven't found any yet, it's our first value 
                else lastDigit = a; //else, we keep as our last found value. 
            }
        }
        if(lastDigit == 0) lastDigit = firstDigit;//if we only found a number, it's both our first and last.  
        aux += lastDigit; //add 1st value
        aux += 10 * firstDigit; // add 2nd value
        result += aux; //add value to result
        aux = 0; 
        lastDigit = 0; 
        firstDigit = 0; //Reset variables
    }
    cout << result;
}
