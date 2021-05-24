// BeakJun N0. 11726. Problem.

#include <iostream>
#define N_MAX 1001

using namespace std;

int N, result;
int caseNum[N_MAX];      // Memoization

void Input(){
    
    cin >> N;

    caseNum[1] = 1;     // Number of case at N = 1
    caseNum[2] = 2;     // Number of case at N = 2

}

void Solution(){

    for(int i = 3; i <= N; i++){

        caseNum[i] = (caseNum[i - 1] + caseNum[i - 2]) % 10007;

    }

    result = caseNum[N];

    cout << result << endl;
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
