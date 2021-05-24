// BeakJun. No. 11052.

#include <iostream>
#define N_MAX 1000 + 1

using namespace std;

int N, result;
int P[N_MAX] = {0, };
int DP[N_MAX] = {0, };

void Input(){
    
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }

    for(int i = 1; i <= N; i++){
        DP[i] = P[i];
    }

}

void Solution(){

    for(int i = 2; i <= N; i++){

        for(int j = 1; j < i; j++){

            DP[i] = max(DP[i - j] + P[j], DP[i]);

        }

    }

    result = DP[N];

    cout << result << endl;
}

void Solve(){

    Input();

    Solution();

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}

