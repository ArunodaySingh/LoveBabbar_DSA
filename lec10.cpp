#include<bits/stdc++.h>
using namespace std;
int main()
{
 int arr[8]={1,2,3,4,5,6,7,8};
 for(int i=0;i<8;i+=2)
 {
    int j=i+1;
    swap(arr[i],arr[j]);
 }
 for(int i=0;i<8;i++)
 {
    cout<<arr[i];
 }
 return 0;
}