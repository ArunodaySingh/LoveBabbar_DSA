#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 32;
    while (n != 0)
    {
        int digit = n >> 1;
        cout << digit << endl;
        n = n >> 1;
    }
    return 0;
}