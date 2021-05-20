// BeakJun No. 2579.

#include <iostream>
#define N_MAX 301

using namespace std;

int N, result;
int SP[N_MAX] = {0, };      // Stair Point
int MP[N_MAX][3] = {0, };      // Max Point, Memoization

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> SP[i];

    }
}

void Solution(){

    for(int i = 1; i <= N; i++){

        MP[i][0] = max(MP[i - 1][2], MP[i - 1][1]);             // i th stair don't climb
        MP[i][1] = MP[i - 1][0] + SP[i];                        // i th stair climb first
        MP[i][2] = MP[i - 1][1] + SP[i];                        // i th stair climb second

    }

    result = max(MP[N][1], MP[N][2]);

    cout << result << endl;

}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;

}



