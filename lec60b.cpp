// Queue using linkedlist

#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
int data;
Queue *next;
Queue *front;
Queue *rear;
void equeue(int data);
void pop();
void traverse();
};

// Push new elment
void Queue::equeue(int data)
{
 Queue *temp=new Queue();
 temp->data=data;
 if(rear==NULL)
 {
  temp->next=NULL;
  front=temp;
  rear=temp;
  return;
 }
 rear->next=temp;
 temp->next=NULL;
 rear=temp;
}

// delete from front
void Queue::pop()
{
    Queue *temp=new Queue;
        temp=front;
    if(front==0){
        cout<<"Queue UnderFlow "<<endl;
        return;
    }
    // cout<<front->data<<"<---->"<<front->next<<"----"<<front<<" "<<rear<<endl;
    if(front==rear)
    { 
      front=NULL;
      delete temp;
      return;
    }

    front=front->next;
    temp->next=NULL;
    delete temp;

}

// Traverse a Queue
void Queue::traverse()
{
    Queue *temp=new Queue();
    temp=front;
    if(temp==NULL)
    {
        cout<<"Queue is empty "<<endl;
        return;
    }
    while(temp->next!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;

}
int main()
{
 Queue *obj=new Queue();
 obj->equeue(1);
 obj->equeue(2);
 obj->equeue(3);
 obj->equeue(4);
 obj->equeue(5);
 obj->traverse();
 obj->pop();
 obj->pop();
 obj->pop();
 obj->pop();
 obj->pop();
 obj->pop();
 obj->traverse();

 return 0;
}