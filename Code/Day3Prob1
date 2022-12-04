#include <iostream>
#include <vector> 

using namespace std;


int main()
{
    string c; 
    int sumOfPrios; 
    sumOfPrios = 0; 
    vector<int> rucksack; 
    char rep; 
    while(1){
        while(getline(cin, c)){
            int half_size = c.size() / 2;
            vector<int> split_lo(c.begin(), c.begin() + half_size);
            vector<int> split_hi(c.begin() + half_size, c.end());
            for(int i = 0; i < half_size; ++i){
                for(int j = 0; j < half_size; ++j){
                    if (split_lo[i] == split_hi[j]){
                        rep = split_lo[i];
                        i = half_size; 
                        j = half_size;
                    } 
                }
            }
            //cout << "Letra encontrada: " << rep << endl; 
            if(rep == '1'){}
            else if(rep >= 'a' and rep <= 'z') sumOfPrios += rep - 'a' + 1; 
            else sumOfPrios += rep - 'A' + 27; 
            //cout << "Prios so far: " << sumOfPrios << endl;
            rep = '1'; 
        }
    }
}
