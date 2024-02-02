//Program to find the peak element in an array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int peakElement(int arr[], int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if((i==0 || arr[i]>arr[i-1]) && (i==n-1) || arr[i]>arr[i+1])
//         return arr[i];
//     }
//     return -1;
// }


//method 2: using binary search approach (optimal)
int peakElement(int arr[], int n)
{
    if(n==1)
    return arr[0];

    if(arr[0]>arr[1])
    return arr[0];

    if(arr[n-1]>arr[n-2])
    return arr[n-1];

    int low=1;
    int high=n-2;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return arr[mid];

        //left part and peak is in right half
        if(arr[mid]>arr[mid-1])
        low=mid+1;
        //right part and peak is in left half
        else
        high=mid-1;
    }
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

    cout<<"The Peak element in array is: "<<peakElement(arr,n)<<endl;
    return 0;
}