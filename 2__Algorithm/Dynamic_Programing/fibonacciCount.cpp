#include <iostream>
#include <vector>
#include <utility>

#define N_MAX 40 + 1
using namespace std;

int sequence[100]; // memoization
int T;
int *N;
int Count[N_MAX][2] = { {1, 0}, {0, 1} };

void Input(){

    cin >> T;

    N = new int[T + 1];

    for(int i = 1; i <= T; i++){

        cin >> N[i];

    }

}

void Solution(){

    for(int i = 2; i < N_MAX; i++){

        Count[i][0] = Count[i - 1][0] + Count[i - 2][0];
        Count[i][1] = Count[i - 1][1] + Count[i - 2][1];

    }


    for(int i = 1; i <= T; i++){

        printf("%d %d\n", Count[N[i]][0], Count[N[i]][1]);
        
    }

}

void Solve(){

    Input();

    Solution();

}


int main() {

    Solve();

    return 0;

}
