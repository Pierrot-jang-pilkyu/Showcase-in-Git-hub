#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <limits>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> Cards;
set<int> result;

void Input(){

    cin >> N >> M;
    
    pair<int, int> push;
    int in;

    for(int i = 1; i <= N; i++){

        cin >> in;
        
        Cards.push_back(push = make_pair(in, 0));
        
    }

}

void M_BlackJack(int n, int add){

    if(add > M) return;
    if(n > 3){
        result.insert(add);   
        return;
    }

    int temp = add;

    for(int i = 0; i < N; i++){

        if(Cards[i].second == 0){

            add += Cards[i].first;

            Cards[i].second = 1;

            M_BlackJack(n + 1, add);

            Cards[i].second = 0;

            add = temp;

        }

    }
    
}

void Solution(){

    M_BlackJack(1, 0);
    
    auto iter = result.rbegin();
    cout << *iter << "\n";
    
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