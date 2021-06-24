#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int score[4] = {0, };
    
    int ans1[5] = {1, 2, 3, 4, 5};
    int ans2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int ans3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i  = 0; i < answers.size(); i++){
        int idx1 = i % 5, idx2 = i % 8, idx3 = i % 10;
        
        if(answers[i] == ans1[idx1]) score[1]++;
        if(answers[i] == ans2[idx2]) score[2]++;
        if(answers[i] == ans3[idx3]) score[3]++;
        
    }
    
    int maxScore = 0;
    for(int i = 1; i < 4; i++) maxScore = max(maxScore, score[i]);
    
    for(int i = 1; i < 4; i++){
        
        if(maxScore == score[i]) answer.push_back(i);
        
    }
    
    return answer;
}

int main(){

    vector<int> ans;
    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(2);
    ans.push_back(4);
    ans.push_back(2);

    vector<int> result = solution(ans);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}