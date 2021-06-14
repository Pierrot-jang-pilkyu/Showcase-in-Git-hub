#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 1000000 + 1

using namespace std;


int N, M;
int treeH[N_MAX];
int result;

void Input(){

    cin >> N >> M;

    for(int i = 0; i < N; i++) { cin >> treeH[i]; }

}

void getSettingH(int arr[]){

    int left = 0, right = arr[N - 1];
    long long int add = 0, mid = 0;

    while(left <= right){

        add = 0;

        mid = (left + right) / 2;

        for(int i = 0; i < N; i++) add += (arr[i] - mid)  > 0 ?  (arr[i] - mid) : 0;

        if(add == M) break;

        if(add < M) right = mid - 1;
        else left = mid + 1;

    }

    if(add >= M) result = mid;
    else result = mid - 1;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    sort(treeH, treeH + N);

    getSettingH(treeH);
    
    cout << result << "\n";
    

    return 0;

}