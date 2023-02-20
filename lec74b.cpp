#include<bits/stdc++.h>
using namespace std;
class heapifyalgo{
public:
void Heapify(int *arr, int size, int i)
{
    int largest=i;
    int leftchild=2*i;
    int rightchild=2*i+1;
    // take largest index of the largest child by comparing both side left child or right
    if(arr[largest]<arr[leftchild] && leftchild<=size)
    {
        largest=leftchild;  
    }
    if(arr[largest]<arr[rightchild] && rightchild<=size)
    {
        largest=rightchild;
    }
    if(i!=largest)
    {
        swap(arr[largest],arr[i]);
        Heapify(arr,size,largest);
    }
}
};

int main()
{
 heapifyalgo obj;   
 int arr[]={-1,54,58,55,57,59};
 int size=sizeof(arr)/sizeof(arr[0])-1;
 for(int i=size/2;i>0;i--)
 {
    obj.Heapify(arr,size,i);
 }
 for(int i=1;i<=size;i++)
 {
    cout<<arr[i]<<" ";
 }
 return 0;
}