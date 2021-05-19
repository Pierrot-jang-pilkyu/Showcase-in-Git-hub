// stack practice

#include "exstack.h"



int main(){

    Stack<int> st;

	for(int i = 0; i < 20; i++){
		st.Push(i+1);
		cout << " stack top 1 -> 10 : ["<<(i+1)<<"] : top : " << st.Top() << endl;
	}
	
	
	
	for(int i = 0 ; i < 20; i++){
		cout << " stack top -> 1 : ["<<(i+1)<<"] : top : " << st.Top() << endl;
		st.Pop();
	}

    return 0;
}