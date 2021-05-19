// BeakJun No. 1149. Problem.
// next or last house don't same color.
// and painting cost exists each color red, green and blue.

#include <iostream>
#define N_MAX 1001

using namespace std;

enum Color { // 0 = Non choice
    COLOR_RED = 1,
    COLOR_GREEN,
    COLOR_BLUE 
};

int N, result;
int CC[N_MAX][4] = {0, };  // ColorCost
int MC[N_MAX][4] = {0, };  // MinCost, Memoization

void Input(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j < 4; j++){
            cin >> CC[i][j];
        }
    }
}

void Solution(){
    
    for(int i = 1; i <= N; i++){
        // Default Value : CC[0][1] = CC[0][2] = CC[0][3] = 0, MC[0][1] = MC[0][2] = MC[0][3] = 0
        MC[i][COLOR_RED] = min(MC[i - 1][COLOR_GREEN], MC[i - 1][COLOR_BLUE]) + CC[i][COLOR_RED];
        MC[i][COLOR_GREEN] = min(MC[i - 1][COLOR_RED], MC[i - 1][COLOR_BLUE]) + CC[i][COLOR_GREEN];
        MC[i][COLOR_BLUE] = min(MC[i - 1][COLOR_RED], MC[i - 1][COLOR_GREEN]) + CC[i][COLOR_BLUE];

    }

    result = min(min(MC[N][COLOR_RED], MC[N][COLOR_GREEN]), MC[N][COLOR_BLUE]);

    cout << result << endl;
}

void Solve(){\
    Input();

    Solution();
}

int main(){
    
    Solve();

    return 0;
}
