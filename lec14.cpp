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
    int search(int arr[], int l, int h)
    {
        int s = l;
        int e = h;
        int ans;
        int mid = s + (e - s) / 2;
        while (s < e)
        {
            if (arr[mid] > arr[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{

    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    Solution ob;
    cout << ob.search(A, 0, n - 1) << endl;
}
// } Driver Code Ends