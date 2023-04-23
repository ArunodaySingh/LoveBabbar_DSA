//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages. (Book allocation problem)

    bool search(int arr[], int n, int m, int mid)
    {
        int sum = 0;
        int stu = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] + sum <= mid)
            {
                sum += arr[i];
            }
            else
            {
                stu++;
                if (stu > m)
                {
                    return false;
                }
                else
                {
                    sum = arr[i];
                }
            }
        }
        return true;
    }

    int findPages(int arr[], int n, int m)
    {
        int sum = 0;
        int e = 0;
        int s = -1;
        for (int i = 0; i < n; i++)
        {
            if (s < arr[i])
            {
                s = arr[i];
            }
            sum = sum + arr[i];
        }
        e = sum;
        int mid = s + (e - s) / 2;
        while (s <= e)
        {
            bool check = search(arr, n, m, mid);
            if (check == true)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends