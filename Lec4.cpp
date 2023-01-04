// tagda homework

#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 int i=n;
 while (i>=1)
 {
   int l=i;
   int j=1;
   int k=2*(n-i);
   while (j<=i)
   {
      cout<<j<<" ";
      j++;
   }
   while (k>0)
   {
      cout<<"* ";
      k--;
   }
   while(l>=1)
   {
      cout<<l<<" ";
      l--;
   }
 cout<<endl;
   i--;

 }
   
 return 0;
}