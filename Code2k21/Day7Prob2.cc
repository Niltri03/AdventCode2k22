/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
            if(dist[j] >= i){
                int tmp = 1; 
                for(int i2 = i; i2 < dist[j];++i2){
                    total += tmp; 
                    tmp++;
                } 
            }
                
            else{
                int tmp = 1; 
                for(int i2 = dist[j]; i2 < i; ++i2){
                    total += tmp; 
                    tmp++;
                } 
            } 
        }
        if (total < optimal){
            optimal = total; 
        }
        total = 0; 
    }
    
    cout << "El valor optimo es " << optimal << endl; 
    
}
