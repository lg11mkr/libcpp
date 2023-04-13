#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue()
{
    n= 500;
    arr = new int[n];
    frontIndex= -1,
    rearIndex=-1;
    size=0;
}
Queue::Queue(int sizeArr)
{
    n = sizeArr;
    arr = new int[n];
    frontIndex= -1,
    rearIndex=-1;
    size=0;
}


Queue::~Queue()
{
    delete[] arr;
}
bool Queue::isEmpty(){
    if (size==0)
        return true;
    return false;
}
bool Queue::isFull(){
    if (size==n){
        return true;
    }
    return false;
}
void Queue::enqueue(int a)
{
    if (isFull()) 
    {
        cout << "Queue is full. Cannot enqueue.\n"; 
        return; 
    }
    if (isEmpty())
    {
        frontIndex = 0;
        rearIndex = 0;
    }
    else 
    {
        rearIndex = (rearIndex + 1) % n;
    }
    arr[rearIndex] = a; 
    size++;

}
int Queue::getSize(){
    return size;
}
int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Cannot dequeue.\n";
        return 0; 
    }
    int temp = arr[frontIndex];
    if (frontIndex == rearIndex) 
    {
        frontIndex = -1;
        rearIndex = -1; 
    }
    else 
    {
        frontIndex = (frontIndex + 1) % n;
    }
    size--;
    return temp;
}

int Queue::getFrontValue(){
    return arr[frontIndex];
}
