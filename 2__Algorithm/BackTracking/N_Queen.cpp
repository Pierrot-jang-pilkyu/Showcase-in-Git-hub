#include <iostream>
#include <cmath>

#define N_MAX 14

using namespace std;

int N;
int *column;
int result = 0;

void Input(){

    cin >> N;

    column = new int[N];
    
}

bool promising(int row){
	
	for(int i = 0; i < row; i++){
		
		if(column[i] == column[row])
			return false;
			
		if(abs(row - i) == abs(column[row] - column[i]))
			return false;
			
	}
	
	return true;
	
}

void N_Queen(int row){

    if (row == N){
    	
    	result++;

        return;
    }

    for (int i = 0; i < N; i++){

        column[row] = i;
		
		if(promising(row)){
			
			N_Queen(row + 1);
			
		} 
		
    }

}

void Solution(){

    N_Queen(0);

    cout << result << "\n";

    delete []column;

}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;

}
