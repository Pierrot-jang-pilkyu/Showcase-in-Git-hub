#include <iostream>

using namespace std;

//부모를 찾는 함수
int getParent(int parent[], int node){
    if(parent[node] == node) return node;
    else return parent[node] = getParent(parent, parent[node]);
}

//두 부모를 합치는 함수
int unionParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a < b) return parent[b] = a;
    else parent[a] = b;
}

//같은 부모를 가지는지 확인하는 함수
int findParent(int parent[], int a, int b){
    a = getParent(parent, a);
    b = getParent(parent, b);

    if(a == b) return 1;
    return 0;
}

int main(){

    

    return 0;

}