#pragma once
class Queue
{
private:
    int* arr; 
    int n;
    int frontIndex= -1, rearIndex=-1;
    int size=0; 
public:
    Queue();
    Queue(int sizeArr);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(int a);
    int dequeue();
    int getSize();
    int getFrontValue();    
};  
