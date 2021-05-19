// BeakJun No. 2839. Problem
// Dynamin Programing problem

#include <iostream>
#define N_MAX 5001

using namespace std;

int N, result;
int MN[N_MAX];

int Min(int a, int b) { if( (unsigned int)a < (unsigned int)b ) return a; return b;}

void Input(){

	cin >> N;

	MN[0] = 0;
	MN[1] = -1;
	MN[2] = -1;
	MN[3] = 1;
	MN[4] = -1;
	MN[5] = 1;

}

void Solution(){

	for(int i = 6; i <= N; i++){

		if((MN[i - 3] == -1) && (MN[i - 5] == -1)) { MN[i] = -1; continue; }
		MN[i] = Min(MN[i - 3], MN[i - 5]) + 1;

	}

	result = MN[N];

	cout << result << endl;

}

void Solve(){

	Input();

	Solution();


}


int main(){
    
	Solve();
		
    return 0;
}