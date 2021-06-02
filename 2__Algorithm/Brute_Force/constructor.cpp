#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

int N;
int result;
set<int> con_Num;

void Input(){

    cin >> N;

}

void constuctor(int n){

    string nString = to_string(n);
    int i, add = N - 1;

    for(i = N - 1; i > N / 2; i--){
    	
    	add = i;

        for(int j = 0; j < nString.length(); j++){

            add += (i % (int)pow(10, (j + 1))) / (int)pow(10, j);
            
            if(N == add && j == nString.length() - 1) break;

        }

        if(N == add) con_Num.insert(i);

    }

    result = *con_Num.begin();

}

void Solution(){

    constuctor(N);

    cout << result << "\n";
    
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