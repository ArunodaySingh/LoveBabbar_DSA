#include <bits/stdc++.h>
using namespace std;

// decimal to binary

// int main()
// {
//     int i = 0;
//     long long int n = -15;
//     long long unsigned int answer = 0;
//     while (n != 0)
//     {
//         int bit = n&1;
//         answer= (bit*pow(10,i))+answer;
//         n=n>>1;
//        i++;
//     }
//     cout << answer;
//     return 0;
// }


// binary to decimal

// int main()
// {
//     int n=10111;
//     int ans=0;
//     int i=0;
//     while(n!=0)
//     {
//         int digit=n%10;
//         ans+=(digit*(pow(2,i)));
//         n=n/10;
//         i++;
//     }
//     cout<<ans;
// }

// output

int update(int a)
{
  a-=5;
  return a;
}

int main()
{
    int a=5;
    int store=update(a);
    cout<<store;
}