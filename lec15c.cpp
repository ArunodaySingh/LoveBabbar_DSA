//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isAvail(int arr[], int n, int k, int mid)
    {
        int sum = 0;
        int painter = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] + sum > mid)
            {

                painter++;
                if (painter > k)
                {
                    return false;
                }
                sum = arr[i];
            }
            else
            {
                sum = sum + arr[i];
            }
        }
        return (painter == k);
    }

    long long minTime(int arr[], int n, int k)
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
            bool check = isAvail(arr, n, k, mid);
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
        int k, n;
        cin >> k >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minTime(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends