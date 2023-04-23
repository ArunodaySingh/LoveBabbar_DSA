// Binary Search
/*
It's take O(log n) time complexity also but there is one condition array should be sorted
*/

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int *arr, int size, int K)
{
  int start = 0;
  int end = size - 1;
  while (start < end)
  {
    int mid = (start + end) / 2;
    if (arr[mid] == K)
    {
      return mid + 1;
      break;
    }
    else if (arr[mid] > K)
    {
      start = 0;
      end = mid - 1;
    }
    else if (arr[mid] < K)
    {
      start = mid + 1;
      end = size;
    }
  }
  return -1;
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 11, 76, 89};
  cout << "Enter the value you want to Search " << endl;
  int n;
  cin >> n;
  int size = sizeof(arr) / sizeof(arr[0]);
  int store = BinarySearch(arr, size, n);
  cout << store;
  return 0;
}