

#include <iostream>

using namespace std;


void bubbleSort(int a[], int left, int right){
    int i = left;
    
    if(left < right){
        for(; i < right; i++){
            if(a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }

    bubbleSort(a, left, (i - 1));

    }
}


int main(){
    
    int a[11] = {0, 26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int left = 1, right = 10;

    cout << "Before the bubbleSort a : ";
    for(int i = 1; i <= right; i++){
        cout << a[i] << " ";
    }cout << endl << endl;

    bubbleSort(a, left, right);

    cout << "After the bubbleSort a : ";
    for(int i = 1; i <= right; i++){
        cout << a[i] << " ";
    }cout << endl << endl;


    return 0;
}