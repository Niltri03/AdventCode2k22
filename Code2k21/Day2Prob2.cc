#include <iostream>
using namespace std; 

int main()
{
    int x = 0; 
    int y = 0; 
    int aim = 0; 
    string act; 
    int a; 
    while(cin >> act >> a){
         if(act == "forward"){
            x+=a;
            y += a * aim;
         }
         else if(act == "down"){
            aim+=a;
         }
         else if(act == "up"){
            aim-=a;
         }
         cout << "act:" << x*y << endl; 
    }
}
