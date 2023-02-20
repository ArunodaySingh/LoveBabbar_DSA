// Heap Sort
#include <bits/stdc++.h>
using namespace std;

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int leftChild = 2 * largest;
    int rightChild = 2 * largest + 1;
    if (leftChild <= size && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }
    if (rightChild <= size && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }
    if (i != largest)
    {
        swap(arr[i], arr[largest]);
        heapify(arr,size,largest);
    }
}

// Driver code for Heapify
void HeapDriver(int *arr,int size)
{
    // Make a Max Heap First
    for(int i=size/2;i>0;i--)
    { 
        heapify(arr,size,i);
    }
}



int main()
{
    int arr[] = {-1, 15, 5, 20, 1, 17, 10, 30};
    int size=sizeof(arr)/sizeof(arr[0])-1;
    int n=size;
    HeapDriver(arr,size);

    cout<<"Before Heap after Heap Sort ="<<size<<endl;
    for(int i=1;i<=size;i++)
    {
        cout<<arr[i]<<" ";
    }
    // Heap Sort
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;
        HeapDriver(arr,size);
    }
    cout<<"\n After Heap Sort of the array "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}