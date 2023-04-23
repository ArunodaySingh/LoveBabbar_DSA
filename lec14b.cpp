//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        int s = 1;
        int h = x - 1;
        long long mid = s + (h - s) / 2;
        long long ans = 1;
        while (s <= h)
        {
            if (x == mid * mid)
            {
                ans = mid;
                break;
            }
            if (mid * mid > x)
            {
                h = mid - 1;
            }
            else
            {
                ans = mid;
                s = mid + 1;
            }
            mid = s + (h - s) / 2;
        }
        return ans;
    }

    double addprecession(int p, int res, int n)
    {
        double pre = 1;
        double temp = res;
        for (int i = 0; i < p; i++)
        {
            pre = pre / 10;
            cout << pre << endl;
            for (double j = temp; j * j < n; j = j + pre)
            {
                cout << j << endl;
                temp = j;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.

int main()
{
    long long n;
    int precession;
    cin >> n;
    cin >> precession;
    Solution obj;
    int result = obj.floorSqrt(n);
    cout << obj.addprecession(precession, result, n);
    return 0;
}

// } Driver Code Ends

/*
Note=> If function is long long type and it's return even when i use in above code
double temp=res; it's store there garbage value.
*/