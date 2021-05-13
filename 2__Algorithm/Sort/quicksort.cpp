#include <iostream>

using namespace std;

void quickSort(int a[], int left, int right){
    if(left < right){
        int i = left, j = right + 1;
        int pivot = a[left];
        
        while(1) {
            do { i++; } while(a[i] < pivot);
            do { j--; } while(a[j] > pivot);
          if(i < j)
                swap(a[i], a[j]);
            else break;
        }
        swap(a[j], a[left]);

        quickSort(a, left, j - 1);
        quickSort(a, j + 1, right);
    }

    
}

int main(){
    
    int a[11] = {0, 26, 5, 37, 1, 61, 11, 59, 15, 48, 19};
    int left = 1, right = 10;

    cout << "Before the quicksort a : ";
    for(int i = 0; i < right; i++){
        cout << a[i] << " ";
    }cout << endl << endl;

    quickSort(a, left, right);

    cout << "After the quicksort a : ";
    for(int i = 0; i < right; i++){
        cout << a[i] << " ";
    }cout << endl << endl;


    return 0;
}