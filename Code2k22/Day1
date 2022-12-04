#include <iostream>

using namespace std;


int main()
{
    string s;
    int a; 
    int max; // top 3
    int max2; // top 2 
    int max3; // top 1
    int sum; 
    max = max2 = max3= sum = 0;
    while(getline(cin, s)){
        if (s != ""){
            a = stoi(s);
            sum += a; 
            
        }
        else {
            if (sum > max3){ 
                max = max2; 
                max2 = max3; 
                max3 = sum; 
            } 
            else if(sum > max2){
                max = max2; 
                max2 = sum; 
            }
            else if(sum > max){
            max = sum;
            }
            else {};
            cout << "Max3 so far: " << max3 << endl; 
            cout << "Max2 so far: " << max2 << endl; 
            cout << "Max so far: " << max << endl; 
            cout << "MAX TOTAL SO FAR -> " << max3 + max2 + max << "<-" << endl;
            sum = 0; 
        }
    }

}
