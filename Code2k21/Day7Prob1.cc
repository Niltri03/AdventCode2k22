

#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int main()
{
    int a, optimal; 
    int total = 0; 
    char c; 
    int maxval = 0; 
    optimal = INT_MAX;
    vector<int> dist; 
    while(cin >> a >> c){
        dist.push_back(a);
        if (a > maxval)maxval = a; 
    }
    
    for(int i = 0; i < maxval; ++i){
        for(int j = 0 ; j < dist.size(); ++j){
            if(dist[j] >= i) total += dist[j]-i; 
            else total += i-dist[j]; 
        }
        if (total < optimal){
            optimal = total; 
        }
        total = 0; 
    }
    
    cout << "El valor optimo es " << optimal << endl; 
    
}
