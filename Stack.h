#pragma once
class Stack
{
private:
    int* arr;
    int n;
    int topIndex;
    int bottomIndex;
    int size;
public:
    Stack();
    Stack(int sizeArr);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int a);
    int pop();
    int getSize();
    int getTopValue();
};
