#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    string s; 
    cin >> s; 
    int l = s.size(); 
    vector<int> times(l); 
    int valores = 1; 
    for(int i = 0; i < l; ++i){
        if(s[i]=='1') times[i]++;
    }
    while(cin >> s){
        if(s == "x") break; 
        for(int i = 0; i < l; ++i){
            if(s[i]=='1') times[i]++;
        }
        valores++;
    }
    l = valores / 2; 
    for(int i = 0; i < times.size(); ++i){
        if (times[i] > l) cout << 1; 
        else cout << 0; 
    }
    cout << endl; 
    for(int i = 0; i < times.size(); ++i){
        if (times[i] > l) cout << 0; 
        else cout << 1; 
    }
}
