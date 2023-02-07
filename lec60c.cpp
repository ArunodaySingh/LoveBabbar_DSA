// Circular Queue using Array4

#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int data, size, front, rear;
    int *arr;
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void equeue(int data);
    void dequeue();
    void traverse();
};

// Perform insertion
void Queue::equeue(int data)
{
    if ((rear == size - 1 && front==0) || (rear == (front - 1) ))
    {
        cout << "Queue is Full " << endl;
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else if (front != 0 && rear == size - 1)
    {
        rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}

//pop element
void Queue::dequeue()
{
    if(front==-1)
    {
        cout<<"Queue Underfloe"<<endl;
    }
    else if(front==size-1 && front!=rear)
    {
        arr[front]=-1;
        front=0;
    }
    else if(front==rear)
    {
        arr[front]==-1;
        front=-1;
        rear==-1;
    }
    else{
        arr[front]=-1;
        front++;
    }
}

// traverse
void Queue::traverse()
{
    int temp = front;
    if (temp == -1)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    while (temp != rear)
    {
        if (temp == size)
        {
            temp = 0;
        }
        cout << arr[temp++]<<" ";
    }
    cout<<arr[temp]<<endl;
}

int main()
{
    int n;
    cout << "Enter the array size " << endl;
    cin >> n;
    Queue obj(n);
    obj.equeue(1);
    obj.equeue(2);
    obj.equeue(3);
    obj.equeue(4);
    obj.equeue(5);
    obj.dequeue();
    obj.dequeue();
    obj.traverse();
    obj.equeue(1);
    obj.equeue(2);
    obj.traverse();
    obj.equeue(2);
    cout<<endl;

    return 0;
}