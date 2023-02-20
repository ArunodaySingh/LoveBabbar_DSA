// Heap Sort implemented using Priority Queue

#include<bits/stdc++.h>
using namespace std;
int main()
{
 priority_queue<int>pq;  // Its make a max heap
 pq.push(4);
 pq.push(14);   
 pq.push(43);
 pq.push(44);
 pq.push(24);
 while(!pq.empty())
 {
    cout<<pq.top()<<" ";
    pq.pop();
 }
 cout<<endl;

 priority_queue<int,vector<int>,greater<int>>minheap; // Used to make a Min Heap
  minheap.push(4);
 minheap.push(14);   
 minheap.push(43);
 minheap.push(44);
 minheap.push(24);
  while(!minheap.empty())
 {
    cout<<minheap.top()<<" ";
    minheap.pop();
 }
 return 0;
}