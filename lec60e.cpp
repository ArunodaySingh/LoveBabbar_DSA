// Implement Queue using STL library
#include<iostream>
#include<queue>
using namespace std;
void traverse(queue<int>*q)
{
    while (!(*q).empty())
    {
     cout<<(*q).front()<<endl;
     (*q).pop();
    }
    
}
int main()
{
 queue<int>q;
 q.push(10);
 q.push(20);
 q.push(30);
 q.push(40);
 q.push(50);
 q.push(60);
traverse(&q);
cout<<q.front();
 return 0;
}

/*
Queues are a type of container adaptors that operate
in a first in first out (FIFO) type of arrangement. 
Elements are inserted at the back (end) and are deleted from the front. 
Queues use an encapsulated object of deque or list (sequential container class)
as its underlying container, providing a specific set of member functions to 
access its elements.
*/
