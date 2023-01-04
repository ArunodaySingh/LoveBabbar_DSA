// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// int a=2;
// int b=4;
// cout<<"Or operation a|b="<<(a|b)<<endl;
// cout<<"And operation a&b="<<(a&b)<<endl;
// cout<<"Not operation ~a="<<(~a)<<endl; 
// cout<<"Xor operation a^b="<<(a^b)<<endl;
// cout<<"Left shift operation 3<<2="<<(3<<2)<<endl;
// cout<<"Right shift operation 15>>1="<<(15>>1)<<endl;

// return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n=5;
 int store;
 long long unsigned int ans=0;
 while(n!=0)
 {
    int bit=n&1;
    store=((bit=1)?0:1);
    ans=ans*10+store;
    n=n>>1;
 }
 cout<<ans;
 return 0;
}