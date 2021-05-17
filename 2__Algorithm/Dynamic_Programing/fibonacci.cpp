#include <iostream>
#include <deque>


using namespace std;

int sequence[100]; // memoization

int fibonacci(int n) {
    if(n == 1) return sequence[n] = 1;
    if(n == 2) return sequence[n] = 1;
    if(sequence[n] != 0) return sequence[n];
    
    return sequence[n] = fibonacci(n - 1) + fibonacci(n - 2);
}


int main() {

    int n;

    cout << "Enter the fibonacci sequence's N = ";
    cin >> n;

    cout << endl;
    cout << "If fibonacci sequence N = " << n << ", result : " << fibonacci(n);
    cout << endl << endl;

    return 0;
}

