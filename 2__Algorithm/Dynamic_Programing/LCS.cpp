#include <iostream>
#include <vector>
#include <string>

#define N_MAX 1000 + 1
using namespace std;

int DP[N_MAX][N_MAX]; // memoization
int N1, N2;
string s1;
string s2;
vector<char> lis1;
vector<char> lis2;
vector<int> idx;

int max(int a, int b) { if(a > b) return a; return b; }

void Input(){
    
    cin >> s1 >> s2;

    N1 = s1.length();
    N2 = s2.length();

}

void Solution(){

    for(int i = N1 - 1; i >= 0; i--){

        for(int j = N2 - 1; j >= 0; j--){

            DP[i][j] = max(max(DP[i + 1][j], DP[i][j + 1]), DP[i + 1][j + 1] + (s1[i] == s2[j]));

        }

    }

    cout << DP[0][0] << "\n";

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