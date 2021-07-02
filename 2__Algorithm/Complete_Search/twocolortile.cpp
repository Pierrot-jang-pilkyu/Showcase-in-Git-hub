#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int area = brown + yellow;
    
    for(int high = 1; high <= yellow; high++){
        int width = yellow / high;
        if(yellow % high == 0){

            if((high + 2) * (width + 2) == area){
                answer.push_back(width + 2);
                answer.push_back(high + 2);
                break;
            }
        }
    }

    return answer;
}

int main(){

    vector<int> result = solution(24, 24);

    for(int print : result)
        cout << print << " ";
    cout << endl;

    return 0;
}