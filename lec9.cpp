#include<bits/stdc++.h>
using namespace std;
int main()
{
 int arr[6]={1,2,3,4,5,6};
 int temp;
 for(int i=0;i<5;i+2)
 {
    temp=arr[i];
    arr[i]=arr[i+1];
    arr[i+1]=temp;
 }
 for(int i=0;i<5;i++)
 {
    cout<<arr[i]<<endl;
 }
 return 0;
}