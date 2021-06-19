#include <iostream>
#include <vector>
#include <algorithm>
#define N_MAX 100000 + 1

using namespace std;

int DP[N_MAX];
int N;
int maxVal = -1001;

void Input(){

    cin >> N;

    int val;

    for(int i = 1; i <= N; i++){

        cin >> val;

        DP[i] = DP[i - 1] + val > val ? DP[i - 1] + val : val;

        maxVal = max(maxVal, DP[i]);

    }

}

void Solution(){
	
	cout << maxVal << "\n";
    
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