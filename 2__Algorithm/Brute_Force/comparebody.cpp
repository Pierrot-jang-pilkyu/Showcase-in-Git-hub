#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#define N_MAX 50 + 1

using namespace std;

int N;
int result[N_MAX][3];
// [][0] : weight, [][1] : height, [][2] : rank

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> result[i][0] >> result[i][1];
        result[i][2] = 1;

    }

}

void Solution(){

    for(int i = 1; i <= N; i++){

        for(int j = 1; j <= N; j++){

            if(i != j){
                int count = 0;

                if (result[i][0] > result[j][0])
                    count++;
                if (result[i][1] > result[j][1])
                    count++;
                if (result[i][0] == result[j][0] || result[i][1] == result[j][1])
                    count = 1;

                result[i][2] += count == 0 ? 1 : count == 1 ? 0 : 0;

            }
        }
    }

    for(int i = 1; i <= N; i++){

        cout << result[i][2] << " ";

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