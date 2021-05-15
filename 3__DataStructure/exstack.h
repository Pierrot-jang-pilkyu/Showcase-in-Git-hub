// stack practice

#ifndef EXSTACK_H
#define EXSTACK_H

#include <iostream>

using namespace std;


// template < typename T, typename Container = deque<T> >
template < typename T >
class Stack {
private :
    T* stack;
    int top;
    int capacity;

public : 
    Stack() : top(0), capacity(10){
        this->stack = new T[capacity];
    }
    T& Top() const;
    void Push(const T& var);
    void Swap(Stack* var);
    void Pop();
    int Size() const;
    bool Empty() const;
};

template < typename T >
void changeSize(T*& a, const int oldSize, const int newSize){
    if(newSize < 0) {
        cout << "New length must be >= 0" << endl << endl;
        return;
    }

    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a + number, temp);

    delete []a;
    a = temp;

}

template < typename T >
inline T& Stack<T>::Top() const { return this->stack[this->top]; }

template < typename T >
void Stack<T>::Push(const T& var) { 
    if((this->capacity - 1) == this->top){
        changeSize(this->stack, this->capacity, 2 * this->capacity);
        this->capacity *= 2;
    }

    this->stack[++this->top] = var;
}

template < typename T >
void Stack<T>::Swap(Stack* var){
    T *temp = new T[this->capacity];

    copy(this->stack, this->stack + this->Size(), temp);

    delete []this->stack;
    this->stack = var;
    delete []var;
    var = temp;

    delete []temp;
}


template < typename T >
void Stack<T>::Pop() { 
    if(this->top < (this->capacity / 2 && this->capacity >= 20)){
       changeSize(this->stack, this->capacity, 2 * this->capacity);
        this->capacity /= 2;
    }

    this->stack[this->top] = 0;
    this->top--;
}

template < typename T >
int Stack<T>::Size() const{
    return (this->top + 1);
}

template < typename T >
inline bool Stack<T>::Empty() const{
    return (this->top == -1);
}

#endif
















