
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
int main()
{
    //mInt VP(100, Row(100, 0));
    mChar VP(5, Row2(5, '.'));
    pair<int, int> T; 
    pair<int, int> H; 
    T.first = 0; 
    T.second = 0; 
    H.first = 0; 
    H.second = 0; 
    char dir; 
    int i;
    while(cin >> dir){
        cin >> i; 
        while(i > 0){
            VP[H.first][H.second] = '.';
            VP[T.first][T.second] = '.';
            if(dir == 'D') H.first += 1;
            if(dir == 'U') H.first -= 1; 
            if(dir == 'R') H.second += 1; 
            if(dir == 'L') H.second -= 1; 
            if(H == T);
            else if(inRange(H, T)){
                VP[T.first][T.second] = 'T';
            }
            cout << H.first << " " << H.second << endl; 
            VP[H.first][H.second] = 'H';
            --i; 
            writeMatC(VP); 
        }
        
    }
    
    //countVisited(VP); 
}
