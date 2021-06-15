#include <iostream>
#include <vector>
#include <algorithm>

#define N_MAX 100000 + 1

using namespace std;


int N, M;
int A[N_MAX];
int X[N_MAX];
int result[N_MAX];

void Input(){

    int input;

    cin >> N;

    for(int i = 0; i < N; i++) { cin >> input; A[i] = input; }

    cin >> M;

    for(int i = 0; i < M; i++) { cin >> input; X[i] = input; }

}

void binarySearch(int key, int index, int arr[]){

    int left = 0, right = N - 1;

    while(left <= right){

        int mid = (left + right) / 2;

        if(arr[mid] == key) { result[index] = 1; return; }

        if(arr[mid] > key) right = mid - 1;
        else left = mid + 1;

    }

    result[index] = 0;

}

/* int BS(int key, vector<int> arr){        // return index

    int left = 0, right = arr.size();

    while(left < right){
    	
        int mid = (left + right) / 2;

        if(arr[mid] >= key) right = mid;
        else left = mid + 1;

    }

    return right;

} */

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    sort(A, A + N);

    for(int i = 0; i < M; i++) binarySearch(X[i], i, A);

    for(int i = 0; i < M; i++) cout << result[i] << "\n";

    return 0;

}