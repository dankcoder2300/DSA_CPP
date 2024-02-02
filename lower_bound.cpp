//Program to find loer bound of a number in a sorted array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int lowerBound(int arr[], int n, int x)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]>=x)
//         return i;
//     }
//     return n;
// }

//method 2:using binary search approach
int lowerBound(int arr[], int n,int x)
{
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]>=x)
        {
            ans=mid;
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

    cout<<"Lower bound is at index: "<<lowerBound(arr,n,x)<<endl;
    return 0;
}