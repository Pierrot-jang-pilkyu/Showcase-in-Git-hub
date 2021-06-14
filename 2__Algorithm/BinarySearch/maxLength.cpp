#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 10000 + 1

using namespace std;

typedef long long int ll;

int N, K;
ll lineL[N_MAX];
vector<ll> result;


void Input(){

    cin >> K >> N;

    for(int i = 0; i < K; i++) { cin >> lineL[i]; }

}

void getSettingH(ll arr[]){

    ll left = 1, right = arr[K - 1];
    ll add = 0, mid = 0;

    while(left <= right){

        add = 0;

        mid = (left + right) / 2;

        for(int i = 0; i < K; i++) add += arr[i] / mid;

        if(add == N) result.push_back(mid);

        if(add < N) right = mid - 1;
        else left = mid + 1;

    }

    if(add > N) result.push_back(mid);
    else if(add < N) result.push_back(mid - 1);

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    sort(lineL, lineL + K);

    getSettingH(lineL);

    ll  maxVal = 0;

    for(ll ans : result) maxVal = max(maxVal, ans);
    
    cout << maxVal << "\n";
    

    return 0;

}