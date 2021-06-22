#include <iostream>
#define N_MAX 10 + 1
using namespace std;

int N, K;
int DP[N_MAX][N_MAX];

int nCr(int n, int r){

    if(r == 0 || r == n) return 1;
    if(DP[n][r] != 0) return DP[n][r];

    return DP[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);

}

int main(){

    cin >> N >> K;

    int result = nCr(N, K);

    cout << result << endl;
    
    return 0;
}