#include <iostream>
#include <queue>

using namespace std;

bool evaluate(vector<char>& cola, int id1, int id2){
    for(int i = id1; i < id2; ++i){
        for(int j = i+1; j < id2; ++j){
            //cout << "Comparo " << cola[j] << " con " << cola[i] << endl; 
            if(cola[j]==cola[i]) return true; 
            
        }
    }
    return false; 
}

int main()
{
    char c; 
    vector<char> cola(4095);
    bool found = true; 
    int id1, id2; 
    id1 = 0; 
    id2 = 14; 
    for(int i = 0; i < 4095; ++i){
        cin >> cola[i];
    }
    while(found){
        if(not evaluate(cola, id1, id2)) break; 
        id1++; 
        id2++; 
    } 
    cout << "----------" << endl; 
    cout << "---" << id2  << "---" << endl; 
    cout << "----------" << endl; 
}

