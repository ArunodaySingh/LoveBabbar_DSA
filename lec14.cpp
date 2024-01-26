/*
Q1=> pivot element index using binaray search
Q2=> Search in rotated array using O(logn)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int pivot(int arr[], int l, int h)
    {
        int s = l;
        int e = h;
        int ans;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] >= arr[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }

    int search(int arr[], int s, int e, int k)
    {
        int pivotindex = pivot(arr, s, e);
        if (arr[0] <= k <= arr[pivotindex])
        {
            return binary_search(arr[0], arr[pivotindex], k);
        }
        else if (arr[pivotindex + 1] <= k <= arr[e])
        {
            return binary_search(arr[pivotindex + 1], arr[e], k);
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int n, k = 2;
    int arr[] = {7, 9, 1, 2, 3};
    Solution ob;
    cout << ob.search(arr, 0, n - 1, k) << endl;
}
// } Driver Code Ends