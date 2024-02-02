//Program to find the length of longest subarray with sum as 0
#include<bits/stdc++.h>
using namespace std;

int longest_subarray(int arr[],int n)
{
    unordered_map<int,int> mpp;
    long long sum=0;
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            max_len=i+1;
        }
        else if(mpp.find(sum)!=mpp.end())
        {
            max_len=max(max_len,i-mpp[sum]);
        }
        else if(mpp.find(sum)==mpp.end())
        {
            mpp[sum]=i;
        }
    }
    return max_len;
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

    cout<<"Length of longest subarray with sum equal to 0 is: "<<longest_subarray(arr,n);
    return 0;
}