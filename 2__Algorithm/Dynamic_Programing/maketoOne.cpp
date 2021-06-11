#include <iostream>
#include <cmath>
#include <limits>

#define N_MAX 1000000 + 1
using namespace std;

int DP[N_MAX] = { INT_MAX, 0, 1, 1, }; // memoization
int N;

void Input(){

    cin >> N;

}

// 32506 ~ error!!
int makeToOne(int n){

    if(n < 1) return INT_MAX;
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n == 3) return 1;

    if(DP[n] != 0) return DP[n];

    return DP[n] = min(min(makeToOne(n % 3 == 0? n / 3 : 0), makeToOne(n % 2 == 0? n / 2 : 0)), makeToOne(n - 1)) + 1;

}

void Solution(){

    /* int result = makeToOne(N);

    cout << result << endl; */

    // success
    for(int i = 4; i <= N; i++){

        DP[i] = min(min(DP[i % 3 == 0? i / 3 : 0], DP[i % 2 == 0? i / 2 : 0]), DP[i - 1]) + 1;

    }

    cout << DP[N] << endl;

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
