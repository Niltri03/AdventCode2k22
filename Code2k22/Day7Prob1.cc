#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

struct Directory{      
  string name; 
  Directory* father;   
  vector<Directory> subdir;
  int nestedSize; 
} ;

void readLS(Directory &dir){
    string a;
    while(cin >> a){
        if (a == "$")break;  
        else if(a == "dir"){
            Directory newD; 
            cin >> a; 
            newD.name=a;
            newD.father=&dir; 
            newD.nestedSize = 0; 
            dir.subdir.push_back(newD);
            
        }
        else{
            dir.nestedSize += stoi(a);
            cin >> a;
        } 
    }
}

Directory* findDirectory(string nam, vector<Directory> &s){
    
    for(int i = 0; i < s.size(); ++i) if(s[i].name == nam) return &s[i];
    return NULL;
}

int calc(Directory dir, int &res){
    int total = 0; 
    for(int i = 0; i < dir.subdir.size(); ++i) total += calc(dir.subdir[i], res);
    total += dir.nestedSize;
    if(total < 100000) res+=total; 
    return total; 
}

int main()
{
    Directory slash; 
    slash.name = "slash";
    slash.father = NULL; 
    slash.nestedSize = 0; 
    Directory* actual; 
    actual = &slash; 
    string dollar, cmd, auxS; 
    int auxI;
    cin >> dollar >> cmd; 
    while(1){
        if(cmd == "cd"){
            cin >> auxS; 
            if(auxS == "/") actual = &slash; 
            else if(auxS == "..") actual = actual->father;
            else{
                string tilt = actual->subdir[0].name;
                actual = findDirectory(auxS, actual->subdir);
                
            } 
             
            cin >> dollar >> cmd; 
        }
        else if(cmd == "ls"){
            readLS(*actual); 
            cin >> cmd; 
        }
        else{
            int res = 0; 
            int total = calc(slash, res); 
            cout << "Total total: " << res << endl;
            break;
        }
    }
}
