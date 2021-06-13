#include <iostream>

#define N_MAX 100 + 1
using namespace std;

int DP[N_MAX][10] = { 0, }; // memoization
int N;

void Input(){

    cin >> N;

}

void Solution(){

    int result = 0;

    DP[1][0] = 0;

    for(int i = 1; i <= 9; i++) DP[1][i] = 1;

    for(int i = 2; i <= N; i++){

       DP[i][0] = DP[i - 1][1];
       DP[i][9] = DP[i - 1][8];

       for(int j = 1; j <= 8; j++){

           DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;

       }

    }

    for(int i = 0; i <= 9; i++){

        result += DP[N][i];
        result %= 1000000000;

    }

    cout << result << "\n";

}

void Solve(){

    Input();

    Solution();

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;

}
