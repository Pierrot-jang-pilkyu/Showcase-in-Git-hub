#include <iostream>
#define N_MAX 10000 + 1

using namespace std;

int N;
int result[N_MAX] = {0, };

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        int inVal;

        cin >> inVal;

        result[inVal] += 1;

    }

}

void Solution(){

    for(int i = 1; i < N_MAX; i++){

        for(int j = 1; j <= result[i]; j++){

            cout << i << "\n";

        }

    }
    
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