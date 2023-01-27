// Dequeue Implementation using Array

#include <bits/stdc++.h>
using namespace std;

class deQueue
{
public:
    int data;
    int size;
    int front;
    int rear;
    int *arr;
    deQueue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = rear = -1;
    }
    void push_front(int data);
    void pop_front();
    void push_rear(int data);
    void pop_rear();
    void traverse();
};

// Implement push front
void deQueue::push_front(int data)
{
    if (front == -1)
    {
        front++;
        rear++;
        arr[front] = data;
    }
    else if ((front == 0 && rear == size - 1) || (rear == front - 1))
    {
        cout << "Queue is Full" << endl;
    }
    else if (front == 0)
    {
        front = size - 1;
        arr[front] = data;
    }
    else
    {
        front--;
        arr[front] = data;
    }
}

// Impelement pop front
void deQueue::pop_front()
{
    if (front == -1)
    {
        cout << "Queue is Empty " << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Implement push rear
void deQueue::push_rear(int data)
{
    if (rear == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else if ((front == 0 && rear == size - 1) || (rear == front - 1))
    {
        cout << "Queue is Full";
    }
    else if (rear == size - 1)
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

// pop rear implementation
void deQueue::pop_rear()
{
    if (rear == -1)
    {
        cout << "Queue is Empty" << endl;
    }
    else if (rear == 0)
    {
        rear = size - 1;
    }
    else if (rear == front)
    {
        rear = front = -1;
    }
    else
    {
        rear--;
    }
}

// traverse the array
void deQueue::traverse()
{
    int temp=front;
    if (rear == -1)
    {
        cout << "deQueue is Empty " << endl;
    }
    while (temp != rear)
    {
        if (temp == size)
        {
            temp=0;
        }
        else{
        cout<<arr[temp++]<<" ";
        }
       
    }
    cout<<arr[temp]<<" ";
}

int main()
{
    int n;
    cout<<"size of the deQueue"<<endl;
    cin>>n;
    deQueue obj(n);
    obj.push_rear(1);
    obj.push_rear(2);
    obj.push_front(3);
    obj.push_front(4);
    obj.pop_front();
    obj.pop_rear();
    obj.traverse();

    return 0;
}