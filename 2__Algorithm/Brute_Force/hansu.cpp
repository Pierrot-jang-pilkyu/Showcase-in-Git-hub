// BeakJun No. 1065. Problem.

#include <iostream>

using namespace std;

int hCount = 0;

int hansu(int n){
    int first = 0;
    int second = 0;
    int third = 0;

    for(int i = 1; i <= n; i++){
        first = i / 100;
        second = (i % 100)/ 10;
        third = i % 10;
        if(first == 0){
            hCount++;
        }
        else if((first - second) == (second - third))
            hCount++;
    }
    return hCount;
}

int main(){
    int n;

    cin >> n;

    cout << hansu(n);

    return 0;
}

