

#include <iostream>
#include <vector>
using namespace std;
// z > Z

typedef vector < vector < int >> graph;


void backtracking(graph m, int it, int &curRet, int r, int c){
        if((m[r][c] == 26) and (it < curRet)){
            curRet = it;

        }
        else if ((it >= curRet) or (m[r][c] == 2147483647));
        else{
            //cout << "Funciona en la operacion" << r << "," << c << endl;
            if((m[r][c+1] == m[r][c]+1) or (m[r][c+1] <= m[r][c])){
                int aux;
                aux = m[r][c];
                m[r][c] = 2147483647;
                backtracking(m,it+1,curRet, r, c+1);
                m[r][c] = aux;
            }
            if((m[r+1][c] == m[r][c]+1) or (m[r+1][c] <= m[r][c])){
                int aux;
                aux = m[r][c];
                m[r][c] = 2147483647;
                backtracking(m,it+1,curRet, r+1, c);
                m[r][c] = aux;
            }
            if((m[r-1][c] == m[r][c]+1) or (m[r-1][c] <= m[r][c])){
                int aux;
                aux = m[r][c];
                m[r][c] = 2147483647;
                backtracking(m,it+1,curRet, r-1, c);
                m[r][c] = aux;
            }

            if((m[r][c-1] == m[r][c]+1)or (m[r][c-1] <= m[r][c])){
                int aux;
                aux = m[r][c];
                m[r][c] = 2147483647;
                backtracking(m,it+1,curRet, r, c-1);
                m[r][c] = aux;
            }
            cout << "sigo vivo, it: " << it << ", ret: " << curRet << endl;
        }

    }

int main()
{
    int ret = 50;
    int nrow = 41;
    int ncol = 173;
    graph mapps(nrow+2, vector<int>(ncol+2,200));
    int x0, y0;
    for(int i = 1; i <= nrow; ++i){
        for(int i2 = 1; i2 <= ncol; ++i2){
            char c;
            cin >> c;
            if(c == 'S'){
                mapps[i][i2] = 0;
                x0 = i;
                y0 = i2;
            }
            else if (c == 'E'){
                mapps[i][i2] = 26;
            }
            else mapps[i][i2] = c - 'a';
        }

    }
    cout << "He leído bien" << endl;
    backtracking(mapps, 0, ret, x0, y0);
    cout << "Resultado: " << ret << endl;
}


/*
 * map<pair<int1, int2>, pair<intx, inty>> mp; //int1 distancia al objetivo, int2 distancia recorrida
 * int rec(){
 * if(mp.begin().first.first == 1) mira si estas en una z y si estas return mp.begin().first.second second;
 *
 * int Rec = mp.begin().first.second;
 *  pair<int, int> pa = mp.begin().second;
 *  //calcular distancias para cada casilla de alrededor si se puede
 * //insertar las posibles en el mapa: distancia recorrida = distancia + 1, distancia al objetivo = calculada, marcar en mapa mp[
 * return rec(); 
 *
 * }
 * main{
 *
 * mp.insert(make_pair(0, 0), make_pair(x0, y0));
 * int a = rec()
 * cout << a;
    }

 */
