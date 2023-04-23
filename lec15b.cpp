// Aggressive cows problem

#include <iostream>
using namespace std;
int check(int arr[], int n, int m, int mid)
{
    int cowcount = 1;
    int cowpos = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - cowpos >= mid)
        {
            cowcount++;
            if (cowcount >= m)
            {
                return true;
            }
            cowpos = arr[i];
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4}; // should be sorted array   actual array {4,2,1,3,6}
    int n = 4;
    int m = 2;
    int min = 1;
    int max = 9;
    int ans = -1;
    int mid = min + (max - min) / 2;
    while (min <= max)
    {
        bool issoln = check(arr, n, m, mid);
        if (issoln)
        {
            ans = mid;
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
        mid = min + (max - min) / 2;
    }
    cout << ans;
    return 0;
}