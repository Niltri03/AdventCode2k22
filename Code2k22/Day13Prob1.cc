#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main{
    string caso == "";
    char c;
    vector<char> v1;
    vector<char> v2;
    openv1 = 0;
    openv2 = 0;
    while(1){
        cin >> c
        if(c != '[') break;
        openv1++;
        while(openv1 != 0){
            cin >> c;
            if (c == '[') openv1++;
            if (c == ']') openv1--;
            v1.push_back(c);
        }
        cin >> c;
        openv2++;
        while(openv2 != 0){
            cin >> c;
            if (c == '[') openv2++;
            if (c == ']') openv2--;
            v2.push_back(c);
        }
        int size = max(v1.size(), v2.size());
        for(int i = 1; i < size; ++i){
        }

}
