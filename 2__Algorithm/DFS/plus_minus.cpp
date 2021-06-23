#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Count = 0;

void DFS(int depth, vector<int> arr, int add, int target){
    
    if(depth == arr.size()) {
        
        if(add == target)
            Count++;
        
        return;
        
    }

    int temp = add;
    
    for(int i = 1; i <= 2; i++){
        
        if(i == 1) add += arr[depth];
        else add -= arr[depth];
        
        DFS(depth + 1, arr, add, target);

        add = temp;
        
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, numbers, 0, target);
    
    answer = Count;
    
    return answer;
}

int main(){

    vector<int> numbers;
    int target;

    for(int i = 1; i <= 5; i++){

        int inVal;
        cin >> inVal;
        numbers.push_back(inVal);

    }

    cin >> target;

    cout << solution(numbers, target);

    return 0;
}