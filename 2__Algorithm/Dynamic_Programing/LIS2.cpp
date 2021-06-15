#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> Si;

void Input(){

    cin >> N;

    for(int i = 1; i <= N; i++){

        int inVal;

        cin >> inVal;

        if(Si.empty() || Si.back() < inVal) Si.push_back(inVal);

        else *lower_bound(Si.begin(), Si.end(), inVal) = inVal;

    }

}

void Solution(){

    cout << Si.size() << "\n";
    
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
