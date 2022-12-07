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
                cout << "Estoy en el else y busco el directorio " << auxS << endl;
                string tilt = actual->subdir[0].name;
                cout << "El directorio actual contiene a, mira: " << tilt << endl;
                actual = findDirectory(auxS, actual->subdir);
                cout << "Estoy en el directorio " << actual->name << endl; 
            } 
            cout << "Estoy en el directorio " << actual->name << endl; 
            cin >> dollar >> cmd; 
        }
        else if(cmd == "ls"){
            readLS(*actual); 
            cout << "size slash: " << slash.subdir.size() << endl;
            cin >> cmd; 
        }
        else{
            int total = calc(slash); 
            break;
        }
    }
}
