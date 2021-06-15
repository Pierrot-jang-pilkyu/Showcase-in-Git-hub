#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define N_MAX 1000000 + 1

using namespace std;

int DP[N_MAX];
int N;
int S[N_MAX];
vector<int> Si;
stack<int> st;

void Input(){

    cin >> N;
    
    Si.reserve(N);

    for(int i = 1; i <= N; i++){

        cin >> S[i];
        
        auto iter = lower_bound(Si.begin(), Si.end(), S[i]);

        if(iter == Si.end()) Si.push_back(S[i]);

        else *iter = S[i];
        
        DP[i] = iter - Si.begin() + 1;

    }

}

void Solution(){
	
	int max = Si.size();
	
	for(int i = N; i > 0; i--){

        if(max == 0) break;

        if(max == DP[i]){ st.push(S[i]); max--; }

    }
    
    int stsize = st.size();

    cout << stsize << '\n';

    for(int i = 0; i < stsize; i++){

        cout << st.top() << " ";
        st.pop();

    }
    
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