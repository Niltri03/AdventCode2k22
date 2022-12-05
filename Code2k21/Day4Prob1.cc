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
    cout<< "-=-=" << sumatorio <<"-=-=-=" << endl; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    cout<< "-=-=-=-=-=-=-=-=" << endl; 
    //escribeBoard(b);
    found = true;
}

void marcaNum(Board& b, int x, int y, int num){
    b[x][y] = -1; 
    if((b[x][0] == -1) and  (b[x][1] == -1) and (b[x][2] == -1) and (b[x][3] == -1) and (b[x][4] == -1)) victoria(b, num);
    if((b[0][y] == -1) and  (b[1][y] == -1) and (b[2][y] == -1) and (b[3][y] == -1) and (b[4][y] == -1)) victoria(b, num);
}

void sacarNumero(vector<Board>& tableros, int num){ //Devuelve el valor de tablero ganador * 
    
    for(int cnt = 0; cnt < 100; ++cnt){
        if(not found){
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(tableros[cnt][i][j] == num){
                        //cout << "marco un num; " << endl; 
                        marcaNum(tableros[cnt], i, j, num);
                    } 
                }
            }
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
        //cout << "Saco el numero " << values[i] << endl; 
        sacarNumero(boards, values[i]);
        ++i; 
    }
}
