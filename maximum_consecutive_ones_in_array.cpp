//Program to find Maximum Consecutive One’s in the array
#include<bits/stdc++.h>
using namespace std;

int Maximum_consecutive_ones_in_array(int arr[],int n)
{
    int cnt=0,max_cnt=0;
for(int i=0;i<n;i++)
{
    if(arr[i]==1)
    cnt++;

    else{
        max_cnt=cnt;
        cnt=0;
    }
}
if(cnt>max_cnt)
return cnt;
else
return max_cnt;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum Consecutive One’s in the array are: "<<Maximum_consecutive_ones_in_array(arr,n)<<endl;
    return 0;
}