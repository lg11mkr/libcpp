#include "Stack.h"
#include <iostream>
using namespace std;
Stack::Stack()
{
    n= 500;
    arr = new int[n];
    topIndex= -1,
    size=0;
}
Stack::Stack(int sizeArr)
{
    n = sizeArr;
    arr = new int[n];
    topIndex= -1,
    size=0;
}


Stack::~Stack()
{
    delete[] arr;
}
bool Stack::isEmpty(){
    if (size==0)
        return true;
    return false;
}
bool Stack::isFull(){
    if (size==n){
        return true;
    }
    return false;
}
void Stack::push(int a)
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
        topIndex = (topIndex + 1) % n;
    }
    arr[topIndex] = a; 
    size++;
}
int Stack::getSize(){
    return size;
}
int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty. Cannot pop.\n";
        return 0; 
    }
    int temp = arr[topIndex];
    topIndex--;
    size--;
    return temp;
}

int Stack::getTopValue(){
    return arr[topIndex];
}
