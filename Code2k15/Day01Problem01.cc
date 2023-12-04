#include <vector>
#include <iostream>
using namespace std; 

int main(){
    //string s = /*your input*/ 
    int floor = 0; //result
    bool finding = true; //for problem 2
    for(int i = 0; i < s.length(); ++i){//for each char in our string
        
            if(s[i] == '(') floor++; 
            else floor--; 
            if(floor < 0 and finding){//aka the first time we enter the basement
                cout << i++ << endl;//solution to problem 2
                finding = !finding;//we dont need to search anymore
            }
            
        
    }
    cout << "Floor: " << floor; //solution to problem 1
      

}
