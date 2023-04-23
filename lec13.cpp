/*
Implement Application and Question on Binary Search
1. First and last occurence of tha number
2. Total no. of occurene of the number
3. Peak index of mountain array
*/

#include <iostream>
using namespace std;

int leftSearch(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int rightSearch(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int key = k;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 5};
    cout << "I am called" << endl;
    cout << leftSearch(arr, 7, 8) << endl;
    cout << rightSearch(arr, 7, 8);
    return 0;
}