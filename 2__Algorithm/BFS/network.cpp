#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int check[200];

void BFS(int start, int n, vector<vector<int>> arr){
    queue<int> q;
    q.push(start);
    check[start] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        check[x] = 1;
        
        for(int i = 0; i < n; i++){
            
            if(!check[i] && arr[x][i]){
                
                q.push(i);
                check[i] = 1;
                
            }
        }
        
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(check[i]) continue;
            
        BFS(i, n, computers);
        answer++;
        
    }
    
    return answer;
}

int main(){

    vector<vector<int>> computers;
    int n;

    cin >> n;

    for(int i = 0; i < 3; i++){
        vector<int> temp;

        for(int j = 0; j < 3; j++){

            int a, b, c;

            cin >> a >> b >> c;

            temp.push_back(a);
            temp.push_back(b);
            temp.push_back(c);

        }

        computers.push_back(temp);
        
    }

    cout << solution(n, computers);

    return 0;
}