#include <iostream>
#include <vector>

#define N_MAX 10000 + 1

using namespace std;

int M, N;
int fistPrime = 0, primeSum = 0;
vector<int> primeNum;

// LCM : a * b = gcd(a, b) * lcm(a, b) -> lcm(a, b) = a * b / gcd(a, b)
int gcd(int a, int b){  // Euclidean algorithm

    int c;
    while(b != 0){

        c = a % b;
        a = b;
        b = c;

    }
    return a;

}


void Input(){

    cin >> M >> N;

}

int allSum(vector<int> &_primeNum){

    int sum = 0;

    for(int i : _primeNum){
        sum += i;
    }

    return sum;
}

void Solution(){

    bool prime = false;
    int j;

    for(int k = M; k <= N; k++){

        if(k == 2) primeNum.push_back(2);

        for(j = 2; j < k; j++){

            if(gcd(j, k) != 1) { prime = false; break; }
            else if(gcd(j, k == 1)) prime = true;

        }

        if(prime) primeNum.push_back(k);

    }

    if(primeNum.size() == 0)
        cout << -1 << endl;
    else{

        primeSum = allSum(primeNum);

        cout << primeSum << endl;

        fistPrime = primeNum[0];

        cout << fistPrime << endl;

    }


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