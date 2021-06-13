#include <iostream>
#define m(a, b) a = a > b? a : b

#define N_MAX 1000 + 2
using namespace std;

int DP[N_MAX]; // memoization
int N;
int S[N_MAX] = { 1001, };

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> S[i];

    }

}

void Solution(){

    for(int i = 1; i <= N; i++){

        for(int j = 0; j <= i; j++){

            if(S[i] < S[j]) 
                m(DP[i], DP[j] + 1);

        }

    }

    int result = 0;

    for(int i = 1; i <= N; i++) m(result, DP[i]);

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
