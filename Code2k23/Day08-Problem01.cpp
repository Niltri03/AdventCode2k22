#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


string cleanString(string s){//Removes the junk parentheses and commas from the string 
    //cout << "string " << s;
    string s2; 
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z'){
            s2 += s[i];        
        }
    }
    //cout << " limpia: pasa a ser " << s2 << "." << endl; 
    return s2; 
}



int main()
{
    map<string, pair<string, string>> mapa;
    string instrucciones; 
    cin >> instrucciones;//reads the instructions    
    string aux1, equ, aux2, aux3; 
    while(cin >> aux1){//tenemos que añadir "done" al final del input
        if(aux1 == "done")break; 
        cin >> equ >> aux2 >> aux3;
        mapa.insert(make_pair(aux1, make_pair(cleanString(aux2), cleanString(aux3))));//saves the strings in a map<key: where we at, value: where we can go>
    }
    int pasos, contador = 0; //start the counters
    string dondeEstoy = "AAA";//we start at "AAA" 
    while(1){
        //cout << "llevo " << pasos << " pasos, voy por la instruccion "<< contador << " que representa " << instrucciones[contador] << " y estoy en la palabra " << dondeEstoy << endl; 
        pair<string, string> p = mapa.find(dondeEstoy)->second;//sees where we are 
        string dir;//checks the next instruction to follow
        if(instrucciones[contador] == 'R') {
            dir = p.second; 
        } 
        else{
            dir = p.first;
        }
        dondeEstoy = dir;//goes to wherever instructions tells us 
        pasos++;//we took a step so we increase the counter
        if(dondeEstoy == "ZZZ"){//if we're done 
             cout << "Pasos minimos: " << pasos << endl;//write the answer
             exit(1); // and exit program 
        }
        contador++;//else we fetch next instruction 
        if(contador == instrucciones.size()) contador = 0;//if counter overflows we reset it  
    }
}
