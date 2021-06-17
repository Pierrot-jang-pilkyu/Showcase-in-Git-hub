#include <iostream>
#include <map>
#include <algorithm>
#define N_MAX 100 + 1
#define m(a, b) a = a > b? a : b

using namespace std;

int DP_LIS[N_MAX];
int N;
int S[N_MAX];
map<int, int> EL;

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        int A, B;

        cin >> A >> B;

        EL[A] = B;

    }

}

void Solution(){

    int i = 1;

    for(auto iter = EL.begin(); iter != EL.end(); iter++){

        S[i] = iter->second;
        i++;

    }

    for(int i = 1; i <= N; i++){

        DP_LIS[i] = 1;

        for(int j = 1; j <= i; j++){

            if(S[i] > S[j]) m(DP_LIS[i], DP_LIS[j] + 1);

        }
        
    }

    int _max = 0;

    for(int i = 1; i <= N; i++) _max = max(_max, DP_LIS[i]);
	
    int result = N - _max;

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