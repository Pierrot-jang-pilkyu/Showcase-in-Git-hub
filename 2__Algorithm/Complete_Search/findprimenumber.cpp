#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000000

using namespace std;

bool primenum[10000000];
vector<int> prime;
int Count = 0;

void Eratos(int n){
    if(n <= 1) return;

    for(int i = 0; i < 2; i++)
        primenum[i] = false;

    for(int i = 2; i <= n; i++)
        primenum[i] = true;

    for(int i = 2; i <= n; i++)
        if(primenum[i])
            for(int j = i * i; j <= n; j += i){

                if(j < 0 || j >= MAX) break;

                primenum[j] = false;

            }
            
}

void Find(string numbers, string num, int biggest, vector<bool> visit){

    if(num != ""){
        if(stoi(num) > biggest) return;

        if(primenum[stoi(num)]){
            bool yes = false;

            for(int i : prime){
                if(i == stoi(num)) yes = true;
            }

            if(!yes){
                Count++;
                prime.push_back(stoi(num));
            }
        }
    }

    string temp = num;

    for(int i = 0; i < numbers.length(); i++){
        if(visit[i]) continue;

        num += numbers[i];
        visit[i] = true;

        Find(numbers, num, biggest, visit);

        num = temp;
        visit[i] = false;

    }
}

int solution(string numbers) {
    int answer = 0;

    vector<int> reSort;

    for(int i = 0; i < numbers.length(); i++){
        reSort.push_back(numbers[i] - '0');
    }

    sort(reSort.begin(), reSort.end(), greater<int>());

    string temp = "";
    int biggest;

    for(int i = 0; i < reSort.size(); i++)
        temp += to_string(reSort[i]);

    biggest = stoi(temp);

    Eratos(biggest);

    vector<bool> v;

    for(int i = 0; i < numbers.length(); i++)
        v.push_back(false);
    
    Find(numbers, "", biggest, v);

    answer = Count;

    return answer;
}

int main(){

    cout << solution("17501");

    return 0;
}