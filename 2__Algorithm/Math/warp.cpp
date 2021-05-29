#include <iostream>
#include <cmath>

using namespace std;

int T;
int *X, *Y;
int *gap;


void Input(){

    cin >> T;

    X = new int[T + 1];
    Y = new int[T + 1];
    gap = new int[T + 1];

    for(int i = 1; i <= T; i++){

        cin >> X[i] >> Y[i];

    }

    for(int i = 1; i <= T; i++){
        gap[i] = Y[i] - X[i];
    }

}

void Solution(){

    

    for(int i = 1; i <= T; i++){

        long long count = sqrt(Y[i] - X[i]);

        if(count * count == gap[i])
            cout << 2 * count - 1 << endl;

        else if((count * count) < gap[i] && gap[i] <= (count * (count + 1)))
            cout << 2 * count << endl;

        else if((count * (count + 1)) < gap[i] && gap[i] <= ((count + 1) * (count + 2)))
            cout << 2 * count + 1 << endl;

    } 

    delete []X;
    delete []Y;
    delete []gap;

}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;

}



