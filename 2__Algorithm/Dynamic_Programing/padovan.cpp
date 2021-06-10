#include <iostream>

#define N_MAX 100 + 1
using namespace std;

long long P[N_MAX] = { 0, 1, 1, 1, 2,  }; // memoization
int T;
int *N;

void Input(){

    cin >> T;

    N = new int[T + 1];

    for(int i = 1; i <= T; i++){

        cin >> N[i];

    }

}

void Solution(){

    for(int i = 1; i <= T; i++){

        for(int j = 5; j <= N[i]; j++){

            P[j] = P[j - 1] + P[j - 5];

        }

    }

    for(int i = 1; i <= T; i++){

        cout << P[N[i]] << endl;

    }

    delete []N;


}

void Solve(){

    Input();

    Solution();

}


int main() {

    Solve();

    return 0;

}
