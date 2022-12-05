//wip
#include <iostream>
#include <vector>
#include <set>
using namespace std; 

using Row = vector<int>; 
using Board = vector<Row>; 
bool found = false; 

void LeeBoard(Board& b){
    int a;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cin >> b[i][j];
            
        } 
    }
}

void escribeBoard(Board b){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            cout << b[i][j] << " ";
        } 
        cout << endl; 
    }
    cout << endl; 
}

void victoria(Board b, int num){
    int sumatorio = 0; 
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            if(b[i][j] != -1) sumatorio+=b[i][j];
        }
    }
    sumatorio *= num; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    cout<< "-=-=-=" << sumatorio <<"-=-=-=" << endl; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    escribeBoard(b);
    found = true;
}

void marcaNum(Board& b, int x, int y){
    b[x][y] = -1; 
}

bool checkWin(Board b){
    for(int i = 0; i < 5; ++i){
        if((b[i][0] == -1) and (b[i][1] == -1) and (b[i][2] == -1) and (b[i][3] == -1) and (b[i][4] == -1)) return true;
    }
    for(int y = 0; y < 5; ++y){
         if((b[0][y] == -1) and  (b[1][y] == -1) and (b[2][y] == -1) and (b[3][y] == -1) and (b[4][y] == -1)) return true;
    }
    return false; 
}
void sacarNumero(vector<Board>& tableros, int num){
    
    for(int cnt = 0; cnt < tableros.size(); ++cnt){
        if(not found){
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(tableros[cnt][i][j] == num){
                        marcaNum(tableros[cnt], i, j);
                        //cout << "Marco en el tablero " << cnt << endl; 
                    } 
                }
            }
        }
        if(checkWin(tableros[cnt])){
            //cout << "borro" << endl;
            tableros.erase(tableros.begin()+cnt);
        }
    } 
}




int main()
{
    vector<Board> boards(100); 
    vector<int> values;
    int a;
    char c; 
    
    while(cin >> a >> c and a != 41)values.push_back(a);
    values.push_back(41);
    
    Board b(5, vector<int>(5)); 
    for(int i = 0; i < 100; ++i){
        LeeBoard(b);
        boards[i] = b; 
    }
    int i = 0; 
    while(not found and i < values.size()){
        sacarNumero(boards, values[i]);
        //cout << "Saco el " << values[i] << " y quedan en juego " << boards.size() << endl;
        if(boards.size() == 1)victoria(boards[0], values[i]);
        ++i; 
    }
}
