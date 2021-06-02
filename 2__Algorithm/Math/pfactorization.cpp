#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> result;

void Input(){

    cin >> N;

}

void Solution(){

    while(N != 1){

        for(int i = 2; i <= N; i++){

            if (N % i == 0){

                result.push_back(i);
                N /= i;
                break;

            }
        }

        if(N < 1) {
            cout << endl << "Error : N < 1" << endl << endl;
            break;
        }
    }

    for(int i : result){

        cout << i << endl;

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