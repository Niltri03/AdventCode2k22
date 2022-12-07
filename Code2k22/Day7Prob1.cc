#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

struct Directory{      
  Directory* father;   
  string name;        
  vector<Directory> subdir;
  int nestedSize; 
} ;

void readLS(Directory& dir){
    string a;
    while(cin >> a){
        if (a == "$") break; 
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
        cout << "subdirectorios de " << dir.name <<": " << dir.subdir.size();
        cout << "tamaño nested de " << dir.name <<": " << dir.nestedSize;
    }
}

Directory findDirectory(string nam, vector<Directory> s){
    
    for(int i = 0; i < s.size(); ++i) if(s[i].name == nam) return s[i]; 
    Directory d; 
    return d;
    
}

int calc(Directory dir){
    int total = 0; 
    for(int i = 0; i < dir.subdir.size(); ++i) total += calc(dir.subdir[i]);
    total += dir.nestedSize;
    cout << "Tamaño del directorio " << dir.name << ": " << total << endl; 
    return total; 
}

int main()
{
    Directory slash; 
    slash.name = "/";
    slash.father = NULL; 
    slash.nestedSize = 0; 
    Directory cd; 
    cd = slash; 
    string dollar, cmd, auxS; 
    int auxI;
    cin >> dollar >> cmd; 
    while(1){
        if(cmd == "cd"){
            cout << "es un CMD" << endl; 
            cin >> auxS; 
            if(auxS == "/") cd = slash; 
            if(auxS == "..") cd = *cd.father;
            else cd = findDirectory(auxS, cd.subdir);
            cin >> dollar >> cmd; 
        }
        else if(cmd == "ls"){
            cout << "es un ls" << endl; 
            readLS(cd); 
            cin >> cmd; 
        }
        else{
            cout << "me voy" << endl; 
            int total = calc(slash); 
            break;
        }
    }
}
