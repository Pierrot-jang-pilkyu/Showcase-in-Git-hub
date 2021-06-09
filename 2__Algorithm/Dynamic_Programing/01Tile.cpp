#include <iostream>

#define N_MAX 1000000 + 1
using namespace std;

int DP[N_MAX] = { 0, 1, 2,  }; // memoization
int N;

void Input(){

    cin >> N;

}

void Solution(){

    for(int i = 3; i <= N; i++){

        DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;

    }


    cout << DP[N] << endl;

}

void Solve(){

    Input();

    Solution();

}


int main() {

    Solve();

    return 0;

}
