// BeckJun No. 2156.

#include <iostream>
#define N_MAX 10000 + 1

using namespace std;

int N, result;
int amount[N_MAX] = {0, };
int MA[N_MAX][3] = {0, };

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> amount[i];

    }

}

void Solution(){

    for(int i = 1; i <= N; i++){

        MA[i][0] = max(MA[i - 1][0], max(MA[i - 1][1], MA[i - 1][2]));    // Don't select i th glass. (Can't drink in a row)
        MA[i][1] = MA[i - 1][0] + amount[i];                              // Select first.
        MA[i][2] = MA[i - 1][1] + amount[i];                              // Select second.

    }

    result= max(max(MA[N][0], MA[N][1]), MA[N][2]);

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
