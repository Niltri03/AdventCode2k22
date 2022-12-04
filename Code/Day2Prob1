#include <iostream>

using namespace std;

// Rock -> A -> X
// Paper -> B -> Y
// Scissors -> C -> Z

static const int rockValue = 1;
static const int paperValue = 2;
static const int scissorsValue = 3;
static const int drawValue = 3;
static const int winValue = 6;




int main()
{
 char enemyPlay; 
 char allyPlay; 
 int pointsTotal;
 pointsTotal = 0; 
 while(cin >> enemyPlay >> allyPlay){
    if(allyPlay == 'X'){ //Rock played
        pointsTotal += rockValue;
        if(enemyPlay == 'A') pointsTotal += drawValue;
        else if (enemyPlay == 'C') pointsTotal += winValue; 
        else {}; 
    }
    if(allyPlay == 'Y'){ //Paper played
        pointsTotal += paperValue;
        if(enemyPlay == 'B') pointsTotal += drawValue;
        else if (enemyPlay == 'A') pointsTotal += winValue; 
        else {}; 
    }
    if(allyPlay == 'Z'){ //Scissors played
        pointsTotal += scissorsValue;
        if(enemyPlay == 'C') pointsTotal += drawValue;
        else if (enemyPlay == 'B') pointsTotal += winValue; 
        else {}; 
    }
    cout << "valor actual:" << pointsTotal << endl; 
 }

}
