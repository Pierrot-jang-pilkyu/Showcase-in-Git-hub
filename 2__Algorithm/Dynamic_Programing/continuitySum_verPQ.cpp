#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N_MAX 100000 + 1

using namespace std;

int DP[N_MAX];
int N;
int S[N_MAX];
priority_queue<int> pq;

void Input(){

    cin >> N;

    int val, add = 0;

    for(int i = 1; i <= N; i++){

        cin >> val;

        pq.push(val);

        if(add >= 0){


            add += val;

            if(add != val) pq.push(add);

        }
        else{

            if(val >= 0) add = val;
        	else add = 0;

        }
        
        cout << "\n add : " << add << endl;

    }

}

void Solution(){
	
	cout << pq.top() << "\n";
    
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