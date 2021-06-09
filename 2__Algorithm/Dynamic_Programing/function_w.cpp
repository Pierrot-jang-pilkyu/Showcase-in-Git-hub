#include <iostream>
#include <vector>
#include <utility>
#include <string>

#define ABC_MAX 101 + 1
using namespace std;

int DP[ABC_MAX][ABC_MAX][ABC_MAX] = {0, }; // memoization

vector<int> a;
vector<int> b;
vector<int> c;

vector<string> result;

void Input(){

    a.push_back(0);
    b.push_back(0);
    c.push_back(0);

    while(a[a.size() - 1] != -1 || b[b.size() - 1] != -1 || c[c.size() - 1] != -1){

        int x, y, z;

        cin >> x >> y >> z;

        a.push_back(x);
        b.push_back(y);
        c.push_back(z);

    }

    a.pop_back();
    b.pop_back();
    c.pop_back();

}

int w(int a, int b, int c){

    if(a <= 0 || b <= 0 || c <= 0) return DP[a + 50][b + 50][c + 50] = 1;
    if(a > 20 || b > 20 || c > 20) return DP[a + 50][b + 50][c + 50] = w(20, 20, 20);

    if(DP[a + 50][b + 50][c + 50] != 0) return DP[a + 50][b + 50][c + 50];

    if(a < b && b < c)
        return DP[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return DP[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

}

void Solution(){

    for(int i = 1; i < a.size(); i++){

        string temp = "w("+ to_string(a[i]) +", "+ to_string(b[i]) + ", " + to_string(c[i]) +") = "
                                                                 + to_string(w(a[i], b[i], c[i])) + "\n";

        result.push_back(temp);

    }

    for(string str : result)
        cout << str;

}

void Solve(){

    Input();

    Solution();

}


int main() {

    Solve();

    return 0;

}
