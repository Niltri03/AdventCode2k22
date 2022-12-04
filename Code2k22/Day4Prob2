#include <iostream>

using namespace std;

int main()
{
   int s1, e1, s2, e2; 
   char fill; 
   int overlaps = 0; 
   while(cin >> s1 >> fill >> e1 >> fill >> s2 >> fill >> e2){
       if (s1 >= s2 and s1 <= e2) overlaps++; 
       else if (s2 >= s1 and s2 <= e1)overlaps++; 
       cout << "Overlaps so far: " << overlaps << endl;
   }
}
