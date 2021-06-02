#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int N, Count = 0;
vector<string> result;

void Input(){

    cin >> N;

}

void hanoi(int n, int source, int other, int destination){

    string _source = to_string(source);
    string _destination = to_string(destination);

    if(n == 0) return;

    hanoi(n - 1, source, destination, other);
    Count++;
    result.push_back(_source + " " + _destination + "\n");
    hanoi(n - 1, other, source, destination);


}

void Solution(){

    hanoi(N, 1, 2, 3);

    cout << Count << "\n";

    for(string _print : result)
        cout << _print << "\n";
    
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