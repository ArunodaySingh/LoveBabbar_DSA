// Queue using arrray
/*
Its based on the concept of FIFO
Types
-> Queue
-> Circular Queue
-> Input Restricted Queue
-> Output Resticted Queue
-> Dequeue
*/

#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int font ;
    int rear ;
    int data;
    int size;
    int *arr;
    Queue(int n)
    {
        arr = new int[n];
        size = n;
        font=0;
        rear=0;
    }
    void push(int data);
    void pop();
    bool isEmpty();
    void traverse();
};

//push new element
void Queue::push(int data)
{
    if (rear == size )
    {
        cout << "Overflow Queue" << endl;
        return;
    }
    arr[rear] = data;
    rear++;
   
}

//pop element
void Queue::pop()
{
    if (rear==font)
    {
        cout << "Underflow Queue " << endl;
        rear=0;
        font=0;
        return;
    }
    arr[font]=-1;
    font++;
}
bool Queue::isEmpty()
{
    return (font==rear)?true:false;
}


// traverse element
void Queue::traverse()
{
    for (int i = rear-1 ; i >= font; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    Queue obj(5);
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.traverse();
    cout<<"...................."<<endl;
    obj.pop();
    obj.pop();
     obj.pop();
    obj.pop();
     obj.pop();
    obj.pop();
    obj.traverse();
    cout<<obj.isEmpty()<<endl;
    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);
    obj.push(6);
    cout<<obj.isEmpty()<<endl;
    obj.traverse();

    return 0;
}
