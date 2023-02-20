// Stack work on LIFO order
/*
Insertion (push)
deletion (pop)
peek (top)
Empty (underflow)
*/

// Implementation using Array

#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
int top=-1;
int size;
int *arr;
//constructor
Stack(int size)
{
    this->size=size;
    arr=new int[size];
}
void push(int data);
void pop();
void traverse();
int peek();
bool isEmpty();
};

//push element in the array
void Stack::push(int data)
{
    if(top==size-1)
    {
        cout<<"Array overflow"<<endl;
        return;
    }
    else{
        top++;
        arr[top]=data;
    }

}
//pop element in the array
void Stack::pop()
{
    if(top==-1)
    {
        cout<<"Array underflow"<<endl;
        return;
    }
    else{
        top--;
    }
}
// check top element
int Stack::peek()
{
  if(top==-1)
  {
    return -1;
  }
  else{
    return arr[top];
  }
}
// check empty stack or not
bool Stack::isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else{
        return false;
    }
}

void Stack::traverse()
{
    for (int i = top; i > -1 ; i--)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//main function
int main()
{
 int n;
 cout<<"Enter the size of the array "<<endl;   
 cin>>n;
 Stack obj(n);
 obj.push(1);
 obj.push(2);
 obj.push(3);
 obj.push(4);
 cout<<obj.peek()<<endl;
 cout<<obj.isEmpty()<<endl;
 obj.traverse();
 obj.pop();
 obj.traverse();

 return 0;
}