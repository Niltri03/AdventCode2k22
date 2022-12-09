
#include <iostream>
#include <vector>

using namespace std;

using Row = vector<int>; 
using mInt = vector<Row>; 
using Row2 = vector<char>; 
using mChar = vector<Row2>; 


void countVisited(mInt &f){
    int max = 0; 
    cout << "-------------" << endl;
    for(int i = 0; i < f.size(); ++i){
        for(int j = 0; j < f.size(); ++j){
            if (f[i][j] > 0) max++; 
        }
    }
    cout << "Casillas visitadas: " << max << endl;
}

void writeMatC(mChar &m){
    cout << "-----------------------" << endl;
    for(int i = 0; i < m.size(); ++i){
        for(int j = 0; j < m.size(); ++j){
            cout << m[i][j];
        }
        cout << endl; 
    }
    cout << "-----------------------" << endl; 
    
}

bool inRange(pair<int, int> h, pair<int, int> t){
    if(h.first == t.first + 1){
        if((h.second == t.second - 1) or (h.second == t.second + 1) or (h.second == t.second)) return true; 
    } 
    if(h.first == t.first - 1){
        if((h.second == t.second - 1) or (h.second == t.second + 1) or (h.second == t.second)) return true;
    }
    if(h.second == t.second + 1){
        if((h.first == t.first + 1) or (h.first == t.first - 1) or(h.first == t.first)) return true;
    } 
    if(h.second == t.second - 1){
        if((h.first == t.first + 1) or (h.first == t.first - 1) or(h.first == t.first)) return true;
    } 
    return false; 
}

void actualizaColas(pair<int, int> &H, pair<int, int> &T, char dir ){
     if(inRange(H, T));
        else {
                if(dir == 'D'){
                    T.first = H.first - 1; 
                    T.second = H.second; 
                }
                if(dir == 'U'){
                    T.first = H.first + 1; 
                    T.second = H.second; 
                } 
                if(dir == 'R'){
                    T.first = H.first;
                    T.second = H.second - 1; 
                } 
                if(dir == 'L'){
                    T.first = H.first;
                    T.second = H.second + 1; 
                }
        }
        
}


void guardaColas(mChar &m, vector<pair<int, int>> v){
    for(int i = 9; i > 0; --i){
        m[v[i].first][v[i].second] = '0' + i;
    }
    m[v[0].first][v[0].second] = 'H';
}

int main()
{
    mInt mark(26, Row(26, 0));
    mChar VP(26, Row2(26, '.'));
    vector<pair<int, int>> colas(10, make_pair(20,10)); 
    char dir; 
    int i;
    while(cin >> dir){
        cin >> i; 
        while(i > 0){
            vector<pair<int, int>> old = colas;
            for(int i = 0; i < colas.size(); i++)VP[colas[i].first][colas[i].second] = '.';
            if(dir == 'D') colas[0].first += 1;
            if(dir == 'U') colas[0].first -= 1; 
            if(dir == 'R') colas[0].second += 1; 
            if(dir == 'L') colas[0].second -= 1; 
            for(int i = 1; i < colas.size(); ++i)actualizaColas(colas[i-1], colas[i], dir); 
            mark[colas[9].first][colas[9].second] += 1;
            guardaColas(VP, colas);
            --i; 
            writeMatC(VP);
        }
        
    }
    
    countVisited(mark); 
}
