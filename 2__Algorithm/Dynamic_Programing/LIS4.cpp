#include <iostream>
#include <stack>
#define m(a, b) a = a > b? a : b

#define N_MAX 1000 + 1
using namespace std;

int DP[N_MAX]; // memoization
int N;
int S[N_MAX];
stack<int> st;

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        cin >> S[i];

    }

}

void Solution(){

    int max = 1;

    for(int i = 1; i <= N; i++){

        for(int j = 0; j <= i; j++){

            if(S[i] > S[j]) {
            	
            	int temp = DP[i];

                m(DP[i], DP[j] + 1);

                if(max < DP[i]) max = DP[i];

            }

        }

    }

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
