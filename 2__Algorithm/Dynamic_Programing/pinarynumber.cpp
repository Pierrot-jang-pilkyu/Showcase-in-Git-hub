#include <iostream>
#define N_MAX 90 + 1

using namespace std;

/* 이 문제는 처음 1자리와 2자리에 배치되는 숫자는 무조건 1가지 경우밖에 없다.

 N = 1 -> 1
 N = 2 -> 10

 그러나 이대로는 3번째 자리에서부터 0, 1이 모두 자리할 수 있기 때문에 큰 문제가 작은 문제를 포함하지 않는다.

 그래서 처음 2자리와 나머지 N-2자리를 분리해서

 N-2자리 이진수를 만들 때 규칙 -> 1이 연속해서 두번 올 수 없다. 가 있고, M = N - 2라 하고 규칙을 지키는 DP[M]를 만들면,

 1. 첫 자리가 0일 때 -> 0이 위치하고 M-1자리의 규칙을 지키는 이진수 즉, DP[M - 1]가지의 경우의 수.

 2. 첫 자리가 1일 때 -> 10이 위치하고 M-2자리의 규칙을 지키는 이진수 즉, DP[M - 2] 가지의 경우의 수가 있다.

 결국 M의 자리 이진수를 만드는 경우의 수 DP[M] = DP[M - 1] + DP[M - 2]가 되고 초깃값은 DP[1] = 2, DP[2] = 3

 M = 1 -> (1 or 0), M = 2 -> (10, 01, 00) 이다.

 여기서 흥미로운 점은 N가지 이친수를 구하는 규칙 하에서는 N = 1 일 때는 한 가지, N = 2 일 때도 한 가지의 경우의 수가 나오고,

 이를 나열할 경우

 1, 1, 2, 3, ... 이 된다. 즉, 피보나치 수열인 것이다.

 이 문제는 M = N - 2로 놓고 점화식을 만들고 M = 1 -> N = 3이라 해주면 되게 끔 하되 경계값을 1일 때 2, 2일 때 3을 넣고 N이 1, 2일 때를 직접

 설정하던지, 문제 자체에 집중해서 N = 1, 2 일 때의 경우의 수 1, 1을 경계값으로 주고 시작하면 된다.

 */

int N;
long long DP[N_MAX] = {0, };


void Input(){

    cin >> N;

    DP[1] = 1;

}

void Solution(){

    for(int i = 2; i <= N; i++){

        DP[i] = DP[i - 1] + DP[i - 2];

    }

    cout << DP[N] << endl;

}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;

}