#include <iostream>
using namespace std; 

int main()
{
    int x = 0; 
    int y = 0; 
    string act; 
    int a; 
    while(cin >> act >> a){
         if(act == "forward"){
            x+=a;
         }
         else if(act == "down"){
            y+=a;
         }
         else if(act == "up"){
            y-=a;
         }
         cout << "act:" << x*y << endl; 
    }
}
