//Program to find floor and ceil of number in a sorted array
#include<bits/stdc++.h>
using namespace std;

//floor value
int floor(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]<=x)
        {
            ans=arr[mid];
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

//Ceil value
int ceil(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    int ans=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]>=x)
        {
            ans=arr[mid];
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
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
    sort(arr,arr+n);
    int x;
    cout<<"Enter the number: ";
    cin>>x;

    cout<<"Floor value of number is: "<<floor(arr,n,x)<<endl;
    cout<<"Ceil value of number is: "<<ceil(arr,n,x)<<endl;
    return 0;
}