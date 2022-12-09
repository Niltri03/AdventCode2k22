
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

void writeMatI(mInt &m){
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
    mInt mark(1000, Row(1000, 0));
    mChar VP(1000, Row2(1000, '.'));
    pair<int, int> T; 
    pair<int, int> H; 
    T.first = 500; 
    T.second = 500; 
    H.first = 500; 
    H.second = 500; 
    mark[T.first][T.second] += 1;
    char dir; 
    int i;
    while(cin >> dir){
        cin >> i; 
        while(i > 0){
            VP[H.first][H.second] = '.';
            VP[T.first][T.second] = '.';
            if(dir == 'D') H.first += 1;
            else if(dir == 'U') H.first -= 1; 
            else if(dir == 'R') H.second += 1; 
            else if(dir == 'L') H.second -= 1; 
            if(H == T);
            else if(inRange(H, T)){
                VP[T.first][T.second] = 'T';
            }
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
                VP[T.first][T.second] = 'T';
                
            }
            mark[T.first][T.second] += 1;
            VP[H.first][H.second] = 'H';
            --i; 
        }
        
    }
    
    countVisited(mark); 
}
