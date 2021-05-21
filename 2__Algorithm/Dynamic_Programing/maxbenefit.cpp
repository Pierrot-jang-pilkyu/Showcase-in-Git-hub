// BeakJun No. 14501.

#include <iostream>
#include <algorithm>
#define N_MAX 15 + 5 + 1    // 1 <= N <= 15, 1<= T <= 5, index sync 1

using namespace std;

enum Select { NO, YES };

int N, SelTx = 1, result = 0;
int TP[N_MAX][3] = {0, };       // 1. Time, 2. Price  TP[0][0] = TP[0][1] = TP[0][2] = 0
int MP[N_MAX] = {0, };       // Max Price    MP[0][0] = MP[0][1] = MP[0][2] = 0

void Input() {

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j < 3; j++){

            cin >> TP[i][j];

        }
    }

}

void Solution(){

    for(int i = N; i >= 1; i--){

        if(i + TP[i][1] <= N + 1){
            MP[i] = max(MP[i + 1], MP[i + TP[i][1]] + TP[i][2]);
        }

    }

    result = MP[1];

    cout << result << endl;
}

void Solve() {

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;
}

