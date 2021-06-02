#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int M, N;
bool *primeNum;
vector<int> result;

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

    primeNum = new bool[N + 1];

}

void Eratos(int n)  // 에라토스테네스의 체
{
    /*  만일 n이 1보다 작거나 같으면 함수 종료 */
    if (n <= 1) return;

    /*	2부터 n까지 n-1개를 저장할 수 있는 배열 할당
		배열 참조 번호와 소수와 일치하도록 배열의 크기는
		n+1 길이만큼 할당(인덱스 번호 0과 1은 사용하지 않음)	*/
	//bool* PrimeArray = new bool[n + 1];

	/*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
	
	for(int i = 0; i <= 1; i++)
		primeNum[i] = false;
	
	for (int i = 2; i <= n; i++)
	    primeNum[i] = true;

	/*	에라토스테네스의 체에 맞게 소수를 구함
		만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2 에서 i*i로 개선할 수 있다.
	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (primeNum[i])
			for (int j = i * i; j <= n; j += i)
			    primeNum[j] = false;
	}

}

void Solution(){

    Eratos(N);

    for (int i = M; i <= N; i++){

        if (primeNum[i]){

            result.push_back(i);
        }
    }

    for(int i : result){

        cout << i << '\n';  // 출력 시간을 획기적으로 줄일 수 있는 것 - endl -> '\n'

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