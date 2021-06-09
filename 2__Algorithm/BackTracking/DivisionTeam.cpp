#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int **S;
bool *visit;
int gapMin = 2000000000;
vector<int> startTeam;

void Input(){

    cin >> N;

    S = new int*[N + 1];

    for(int i = 0; i <= N; i++)
        S[i] = new int[N + 1];

    visit = new bool[N + 1];

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            cin >> S[i][j];
    
}

void addTeam(){

    int SA = 0, LA = 0;

    for(int i = 1; i <= N; i ++){

        for(int j = i; j <= N; j++){

            if(visit[i] && visit[j]) SA += S[i][j] + S[j][i];
            if(!visit[i] && !visit[j]) LA += S[i][j] + S[j][i];

        }

    }

    int gap = abs(SA - LA);

    gapMin = min(gapMin, gap);

}

void divisionTeam(){

    if(startTeam.size() == N /2){

        addTeam();

        return;

    }

    for(int i = 1; i <= N; i++){

        if(!visit[i] && (startTeam.size() == 0 || startTeam[startTeam.size() - 1] < i)){

            visit[i] = true;

            startTeam.push_back(i);

            divisionTeam();

            startTeam.pop_back();

            visit[i] = false;

        }

    }

}

void Solution(){

    divisionTeam();

    cout << gapMin << "\n";

    for(int i = 0; i <= N; i++)
        delete []S[i];

    delete []S;

    delete []visit;
}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;

}