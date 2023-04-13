#pragma once
#include <iostream>
using namespace std;

template <class T> class Stack {
private:
    T* data;
    int topIndex;
    int capacity;
public:
    Stack();
    Stack(int n);
    ~Stack();
    void clear();
    bool isFull();
    bool isEmpty();
    void push(const T & item);
    T pop();
    T getTop();
};

template <class T> Stack<T>::Stack()
{
    capacity = 500;
    data = new T[capacity];
    topIndex= -1;
}

template <class T> Stack<T>::Stack(int n)
{
    capacity = n;
    data = new T[capacity];
    topIndex= -1;
}


template <class T> Stack<T>::~Stack()
{
    delete[] data;
}
template <class T> void Stack<T>::clear(){
    delete[] data;
    data = new T[capacity];
    topIndex= -1;
}
template <class T> bool Stack<T>::isEmpty(){
    if (topIndex == -1)
        return true;
    return false;
}
template <class T> bool Stack<T>::isFull(){
    if (topIndex==capacity-1){
        return true;
    }
    return false;
}
template <class T> void Stack<T>::push(const T& item)
{
    if (isFull()) 
    {
        cout << "Stack is full. Cannot push.\n"; 
        return; 
    }
    if (isEmpty())
    {
        topIndex = 0;
    }
    else 
    {
        topIndex = (topIndex + 1) % capacity;
    }
    data[topIndex] = item; 
}
template <class T> T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty. Cannot pop.\n";
        return -1; 
    }
    T temp = data[topIndex];
    topIndex--;
    return temp;
}

template <class T> T Stack<T>::getTop(){
    return data[topIndex];
}
