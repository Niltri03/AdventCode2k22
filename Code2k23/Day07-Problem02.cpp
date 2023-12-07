#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


//N _ _ _ _ _ 


bool hasJoker(string m){
    
    for(int i = 0; i < m.size(); ++i) if (m[i] == 'J') return true; 
    return false; 
}

string creaStringSortable(string s)
{
    string ret; 
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'J') ret.append("a");
        else if(s[i] == '2') ret.append("b");
        else if(s[i] == '3') ret.append("c");
        else if(s[i] == '4') ret.append("d");
        else if(s[i] == '5') ret.append("e");
        else if(s[i] == '6') ret.append("f");
        else if(s[i] == '7') ret.append("g");
        else if(s[i] == '8') ret.append("h");
        else if(s[i] == '9') ret.append("i");
        else if(s[i] == 'T') ret.append("j");
        else if(s[i] == 'Q') ret.append("k");
        else if(s[i] == 'K') ret.append("l");
        else ret.append("m");
        

    }
    cout << ret << endl; 
    return ret; 

}

map<string, string> sortVector(vector<string>& v){
map<string, string> aux;
for(int i = 0; i < v.size(); ++i){
    aux.insert(make_pair(creaStringSortable(v[i]), v[i])); 
}
return aux; 

}

vector<int> sortAMap(map<string, int> m){
    vector<string> stringsOrdenadas; 
    for(map<string, int>::iterator  i = m.begin(); i != m.end(); ++i){
        stringsOrdenadas.push_back(i->first); 
    }
    map<string, string> cosaSorted; 
    cosaSorted = sortVector(stringsOrdenadas); 
    vector<int> ret; 

    for(map<string, string>::iterator it = cosaSorted.begin(); it != cosaSorted.end(); ++it){
        map<string, int>::iterator it2 = m.find(it->second); 
        ret.push_back(it2->second);
    }
    return ret; 
}

string poderJoker(string s){
    map<char, int> auxSet;
    for (int i = 0; i < s.length(); ++i){
        map<char, int>::iterator it = auxSet.find(s[i]);
        if (it != auxSet.end())it->second++;
        else auxSet.insert(make_pair(s[i], 1));
    }
    if(auxSet.size() == 2 or auxSet.size() == 1) return "REPOKER"; 
    if(auxSet.size() == 3){
        //2 opciones: AABBJ, (AAABJ, ABJJJ) AAJJB
        for(map<char, int>::iterator it = auxSet.begin(); it != auxSet.end(); ++it){
            if(it->second == 3) return "POKER";
            if(it->second == 2 and it->first == 'J') return "POKER"; 
        }
        return "FH"; 
    }
    if(auxSet.size() == 4){//AABCJ, ABCJJ
        return "TRIO"; 
    }
    return "PAREJA"; 
}

string poder(string s)
{
    map<char, int> auxSet;
    for (int i = 0; i < s.length(); ++i){
        map<char, int>::iterator it = auxSet.find(s[i]);
        if (it != auxSet.end())it->second++;
        else auxSet.insert(make_pair(s[i], 1));
    }
    vector<int> values; 
    for(map<char, int>::iterator i = auxSet.begin(); i != auxSet.end(); ++i){
        values.push_back(i->second); 
    }
    if(values.size() == 1) return "REPOKER"; 
    if(values.size() == 2){//dos tipos distintos de cartas
        if(values[1]*values[0] == 4) return "POKER";
        else return "FH"; 
    }
    else if(values.size() == 3){//tres tipos distintos de cartas
        if(values[0]*values[1]*values[2] == 3) return "TRIO"; 
        else return "DPAREJA"; 
    }
    else if (values.size() == 4)return "PAREJA"; 
    return "NADA"; 
}


int main()
{
    
    map<string, int> repoker;
    map<string, int> poker;
    map<string, int> full;
    map<string, int> trios;
    map<string, int> dPareja;
    map<string, int> parejas;
    map<string, int> resto;
     
    long long results = 0;
    string mano;
    int apuesta;
    while (cin >> mano >> apuesta and mano != "done")//lee valores de entrada
    {
        string check; 
        
        if(!hasJoker(mano))check = poder(mano);
        
        else check = poderJoker(mano); 
        
        if (check == "POKER")poker.insert(make_pair(mano, apuesta));

        else if (check == "REPOKER") repoker.insert(make_pair(mano, apuesta)); 

        else if (check == "FH") full.insert(make_pair(mano, apuesta));

        else if (check == "TRIO") trios.insert(make_pair(mano, apuesta));

        else if (check == "DPAREJA") dPareja.insert(make_pair(mano, apuesta));

        else if (check == "PAREJA") parejas.insert(make_pair(mano, apuesta));

        else resto.insert(make_pair(mano, apuesta));
    }
    vector<map<string, int>> manos; 
    manos.push_back(repoker);
    manos.push_back(poker);
    manos.push_back(full);
    manos.push_back(trios);
    manos.push_back(dPareja);
    manos.push_back(parejas);
    manos.push_back(resto);
    int rank = 0;
    //cout << results << endl; 
    for(int i = manos.size()-1; i >= 0; --i){
        vector<int> aux = sortAMap(manos[i]); 
        for(int j = 0; j < aux.size(); ++j){
            rank++; 
            results += aux[j] * rank; 
            //cout << aux[j] << "*" << rank << endl; 
        }
        //cout << "manos[" << i << "], ret->" << results << endl; 
    }
    cout <<"Resultado: " << results;
}
