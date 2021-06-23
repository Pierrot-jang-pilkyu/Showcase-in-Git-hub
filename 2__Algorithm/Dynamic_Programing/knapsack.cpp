#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

#define N_MAX 100 + 1
#define K_MAX 100000 + 1

using namespace std;

typedef pair<int, int> pii;

int N, K;
int DP[N_MAX][K_MAX];   // the biggest value of the n-th items and the k-th weight.
vector<pii> item;

bool comparator(const pii &a, const pii &b){
    return a.first < b.first;
}

int max(int a, int b) { if(a > b) return a; return b; }

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for(int i = 1; i <= N; i++){

        int w, v;
        cin >> w >> v;
        item.push_back(make_pair(w, v));

    }

    sort(item.begin(), item.end(), comparator);

    for(int i = 1; i <= K; i++){

        if(item[0].first <= i) DP[1][i] = item[0].second;

    }

    for(int i = 2; i <= N; i++){

        for(int j = 1; j <= K; j++){

            if(item[i - 1].first <= j) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - item[i - 1].first] + item[i - 1].second);
            else DP[i][j] = DP[i - 1][j];

        }
    }

    cout << DP[N][K] << endl;

    return 0;

}

