#include <iostream>

using namespace std;

// Rock -> A 
// Lose -> X
// Paper -> B 
// Draw -> Y
// Scissors -> C 
// Win -> Z

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
    if(allyPlay == 'X'){ //Must lose
        if (enemyPlay == 'A'){//enemy played Rock
            pointsTotal += scissorsValue;
        }
        else if(enemyPlay == 'B'){//Enemy played paper
            pointsTotal += rockValue;
        }
        else {//Enemy played scissors
            pointsTotal += paperValue; 
        }    
    }
    if(allyPlay == 'Y'){ //Must draw 
    pointsTotal += drawValue;
        if (enemyPlay == 'A'){//enemy played Rock
            pointsTotal += rockValue;
        }
        else if(enemyPlay == 'B'){//Enemy played paper
            pointsTotal += paperValue;
        }
        else {//Enemy played scissors
            pointsTotal += scissorsValue; 
        }  
    }
    if(allyPlay == 'Z'){ //Must win 
        pointsTotal += winValue;
        if (enemyPlay == 'A'){//enemy played Rock
            pointsTotal += paperValue;
        }
        else if(enemyPlay == 'B'){//Enemy played paper
            pointsTotal += scissorsValue; 
        }
        else {//Enemy played scissors
            pointsTotal += rockValue;
        }  
    }
    cout << "valor actual:" << pointsTotal << endl; 
 }

}
