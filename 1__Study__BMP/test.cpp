#include <iostream>
#include <queue>

using namespace std;



int main(){
    queue<int> q1, q2;

    for(int i = 0; i < 10; i++){
        q1.push(i + 1);
        q2.push(10 - i);
    }

    if(q1 != q2){
        cout << "q1 != q2" << endl;
    }

    for(int i = 0; i < 10; i++){
        q1.pop();
        q2.pop();
    }

    for(int i = 0; i < 10; i++){
        q1.push(i + 1);
        q2.push(i + 1);
    }

    if(q1 == q2){
        cout << "q1 == q2" << endl;
    }

    return 0;
}



