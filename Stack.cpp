// Stack using Linkedlist

#include <iostream>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;
    Stack *top;
    void push(int);
    void pop();
    void traverse();
};

void Stack::push(int data)
{
    Stack *temp = new Stack();
    temp->data = data;
    if (top == NULL)
    {
        temp->next = NULL;
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}

void Stack::pop()
{

    Stack *temp = new Stack();
    if (top == NULL)
    {
        cout << "Stack is Underflow " << endl;
    }
    else
    {
        if (top->next == NULL)
        {
            temp = top;
            top = NULL;
            delete(temp);
        }
        top = top->next;
    }
}

void Stack::traverse()
{
    Stack *temp = new Stack();
    temp = top;
    if (top == NULL)
    {
        cout << "Stack is Underflow " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    Stack *obj = new Stack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);
    obj->traverse();
    cout << "Pop top element " << endl;
    obj->pop();
    obj->traverse();

    return 0;
}