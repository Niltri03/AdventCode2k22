//WIP
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

using Row = vector<int>; 
using Matrix = vector<Row>; 



bool evaluate(Matrix& mat, int x, int y, int value){
    if(x == 0){
        if(y == 0){ // top left
            return ((value<mat[1][0]) and (value<mat[0][1]));
        }
        if(y == 99){ // top right
            return ((value<mat[0][98]) and (value<mat[1][99]));
        }
        else { // generic top row
            return ((value<mat[0][y+1]) and (value<mat[0][y+2]) and (value<mat[1][y]));
        }
    }
    if(x == 99){
        if(y == 0){//bottom left
            return ((value<mat[99][1]) and (value<mat[98][0]));
        }
        if(y == 99){//bottom right
            return ((value<mat[98][99]) and (value<mat[99][98]));
        }
        else{//generic bottom row
            return ((value<mat[99][y+1]) and (value<mat[99][y-1]) and (value<mat[98][y]));
        }
    }
    else{
        return((value<mat[x][y+1]) and (value<mat[x][y-1]) and (value<mat[x+1][y]) and (value<mat[x-1][y]));
    }
}
    

int main()
{
    int total = 0; 
    char c; 
    Matrix graph(100, Row(100)) ; 
    for(int i = 0; i < 100; ++i){
        for(int j = 0 ; j < 100; ++j) {
            cin >> c; 
            graph[i][j] = c - '0'; 
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j) {
            if(evaluate(graph, i, j, graph[i][j])){
                cout << "evaluated" << endl; 
                total += 1;
                total+=graph[i][j];
            } 
        }
    }
    cout << "----------" << endl; 
    cout << "---" << total << "---" << endl; 
    cout << "----------" << endl; 
}
