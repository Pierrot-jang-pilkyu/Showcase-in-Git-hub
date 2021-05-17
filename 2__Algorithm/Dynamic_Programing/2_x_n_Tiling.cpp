#include <iostream>

using namespace std;

int caseNum[1001];      // Memoization

int tiling(int n) {
    if(n == 1) return caseNum[n] = 1;
    if(n == 2) return caseNum[n] = 2;
    if(caseNum[n] != 0) return caseNum[n];

    return caseNum[n] = ((tiling(n - 1) + tiling(n - 2)) % 10007);
}


int main(){
    int n;

    cin >> n;

    cout << tiling(n);

    return 0;
}
