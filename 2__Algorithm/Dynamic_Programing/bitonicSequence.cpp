#include <iostream>

#define N_MAX 1000 + 2
using namespace std;

int natureDP[N_MAX];  // memoization
int reverseDP[N_MAX]; // memoization
int bitonicDP[N_MAX]; // memoization
int N;
int S[N_MAX] = { 0, };

inline int max(int a, int b) { if(a > b) return a; return b; }

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> S[i];

    }

    for(int i = 1; i <= N; i++){

        natureDP[i] = 1;
        reverseDP[i] = 1;
        bitonicDP[i] = 1;

    }

}

void Solution(){

    int result = 0;

    for(int i = 1; i <= N; i++){

        int length = natureDP[i];

        for(int j = 1; j <= i; j++){

            if(S[j] < S[i])
                if(length < natureDP[j] + 1)
                    length = natureDP[j] + 1;

        }

        natureDP[i] = length;
        
    }

    for(int i = N; i >= 1; i--){

        int length = reverseDP[i];

        for(int j = i; j <= N; j++){

            if(S[j] < S[i])
                if(length < reverseDP[j] + 1)
                    length = reverseDP[j] + 1;

        }

        reverseDP[i] = length;

    }

    for(int i = 1; i <= N; i++){

        bitonicDP[i] = natureDP[i] + reverseDP[i] - 1;
        
    }

    for(int i = 1; i <= N; i++){

        result = max(result, bitonicDP[i]);

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
