// Heap Tree
#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int);
    void print();
    void deleteheap();
};

// Creation of the Heap function
void heap::insert(int data)
{
    size = size + 1;
    int index = size;
    arr[index] = data;

    while (index > 1)
    {
        int parent = index / 2;
        if (arr[index] > arr[parent])
        {
            swap(arr[index], arr[parent]);
            index = parent;
        }
        else
        {

            return;
        }
    }
}

// Delete node

void heap::deleteheap()
{
    int i = 1;
    if (size == 0)
    {
        cout << "Heap is Empty \n";
        return;
    }
    arr[1] = arr[size];
    size--;
    while (i < size)
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;
        if (leftIndex <= size && arr[leftIndex] > arr[i])
        {
            swap(arr[leftIndex], arr[i]);
            i = leftIndex;
        }
        else if (rightIndex <= size && arr[rightIndex] > arr[i])
        {
            swap(arr[rightIndex], arr[i]);
            i = rightIndex;
        }
        else
        {
            return;
        }
    }
}

// Heapify Algorithm

// Traversing the Heap
void heap::print()
{
    cout << "I am called " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    heap obj;
    int data;
    cout << "Enter the data which you want to insert " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> data;
        obj.insert(data);
    }
    obj.print();
    obj.deleteheap();
    obj.print();
    return 0;
}