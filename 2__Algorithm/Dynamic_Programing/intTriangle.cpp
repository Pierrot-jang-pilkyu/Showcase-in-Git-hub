#include <iostream>
#include <cmath>

#define N_MAX 500 + 1
using namespace std;

int DP[N_MAX][N_MAX] = { 0, }; // memoization
int N;
short inVal[N_MAX][N_MAX] = { 0, };

inline int max(int a, int b) { return a > b? a : b; }

void Input(){

    cin >> N;

    int j = 1;

    for(int i = 1; i <= N; i++){

        for(j = 1; j <= i; j++){

            cin >> inVal[i][j];

        }
        
    }

}

void Solution(){

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= i; j++){

            DP[i][j] = inVal[i][j] + max(DP[i - 1][j - 1], DP[i - 1][j]);

        }

    }

    int maxVal = 0;

    for(int i = 1; i <= N; i++){

        maxVal = max(maxVal, DP[N][i]);

    }

    cout << maxVal << endl;

}

void Solve(){

    Input();

    Solution();

}


int main() {

    Solve();

    return 0;

}
