// naver boostcamp self-test function making
// number's overlap

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#define N_MAX 100 + 1

using namespace std;

int N, result;
map<int, int> AllCount;
vector<int> IN;     // Input Numbers
vector<int> ON;      // Output Numbers
set<int> val;

void Input(){

    string strin;
    int j = 0;

    getline(cin, strin);

    int check = 0;      // if 1st index data is number, check is 1. <-> check is 0.

    for(int i = 0; i < 10; i++){
        if(strin[0] == i) check = 1;
    }

    if(check == 0){
    
        size_t sz;
        for(int i = 0; i < strin.length(); i++){

            if(strin.compare(i, 1, "a") == 0) continue;
            if(strin.compare(i, 1, "r") == 0) continue;
            if(strin.compare(i, 1, "r") == 0) continue;
            if(strin.compare(i, 1, "=") == 0) continue;
            if(strin.compare(i, 1, "[") == 0) continue;
            if(strin.compare(i, 1, ",") == 0) continue;
            if(strin.compare(i, 1, " ") == 0) continue;
            if(strin.compare(i, 1, "]") == 0) continue;
        
            IN.push_back(stoi(strin.substr(i), &sz));
            i += sz;
        }

    }
    else if(check == 1){
        size_t sz;
        for(int i = 0; i < strin.length(); i++){
            IN.push_back(stoi(strin.substr(i), &sz));
            i += sz;
        }
    }

    cout << endl;
    for(int i = 0; i < IN.size(); i++){
        cout << "IN["<<i<<"] : " << IN[i] << endl;
    }cout << endl;

    for(int i = 1; i <= IN.size(); i++){
        val.insert(IN[i]);
        AllCount[IN[i]] = -1;
    }

}

void Solution(){


    for(int i = 1; i <= IN.size(); i++){

        for(auto iter = val.begin(); iter != val.end(); iter++){
            if(IN[i] == *iter) AllCount[*iter]++;
        }
        

    }

    for(auto iter = val.begin(); iter != val.end(); iter++){
        if(AllCount[*iter] != 0) { ON.push_back(++AllCount[*iter]); }
    }

    if(ON.empty())
        cout << -1 << endl;
    else{
        cout << "[";
        for(int i = 0; i < ON.size(); i++){
            cout << ON[i];
            if(i < ON.size() - 1){
            	cout << ", ";
			}
        }cout << "]" << endl;
    }

}

void Solve(){

    Input();

    Solution();

}

int main(){

    Solve();

    return 0;
}
