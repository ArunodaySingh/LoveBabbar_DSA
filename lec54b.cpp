// Stack Implementation using Linkedlist

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int data;
    Stack *Next;
    Stack *top = 0;
    // function

    void push(int data);
    void pop();
    int peek();
    bool isEmpty();
    void traverse();
};

//Push new element 
void Stack::push(int data)  // Incase of LinkedList Implementation of stack there is no Overflow condition arises.
{
    Stack *temp = new Stack();
    temp->data = data;
    if (top == 0)
    {
        top=temp;
        temp->Next==NULL;
    }
    else
    {
        temp->Next=top; // 0(1) It's takes to insert the new elemeent
        top=temp;
    }
}

//Pop top element 
void Stack::pop()
{
    Stack *temp=new Stack();
    temp=top;
    if(temp==NULL)
    {
        cout<<"UnderFlow"<<endl;
        return;
    }
    if(temp->Next==NULL)
    {
        top=NULL;
        delete temp;
        return;
    }

    top=top->Next;
    delete temp;
}

// peek element
int Stack::peek()
{
    if(top==0)
    {
        return -1;
    }
    else{
        return top->data;
    }
}

//isEmpty

bool Stack::isEmpty()
{
    return (top==0)?true:false;
}

//traverse
void Stack::traverse()
{
    Stack *temp=new Stack();
    temp=top;
    if(temp==NULL)
    {
        cout<<"Stack is Empty "<<endl;
        return;
    }
    while(temp->Next!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->Next;
    }
    cout<<temp->data<<endl;

    

}

int main()
{
    Stack *obj=new Stack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->traverse();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->pop();
    obj->traverse();
    cout<<"top data of the stack is: "<<obj->peek()<<endl;
    cout<<"Is't Stack is Empty :"<<(obj->isEmpty())<<endl;
    return 0;
}