#include <iostream>
#include <string>
#include <vector>
#define RANGE 2700000

using namespace std;

int N;
int result = 0;


void Input(){

    cin >> N;

}

void Solution(){

    int count = 0;

    for(int i = 666; i < RANGE; i++){

        string temp = to_string(i);

        if (temp.find("666") < temp.length()){
        	
        	count++;
            if (count == N)
                result = i;
            
        }

        if(result != 0) break;

    }

    cout << result << "\n";
    
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