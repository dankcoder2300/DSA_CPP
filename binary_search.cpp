//Program to implement binary search
#include<bits/stdc++.h>
using namespace std;

//method 1: using iterative approach
// int binarySearch(int arr[],int n, int x)
// {
//     int low=0;
//     int high=n-1;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;
        
//         if(arr[mid]==x)
//         return mid;

//         else if(arr[mid]>x)
//         high=mid-1;

//         else
//         low=mid+1;
//     }
//     return -1;
// }

//method 2: using recursive approach
int binarySearch(int arr[], int low, int high, int x)
{
    if(low>high)
    return -1;

    int mid=(low+high)/2;

    if(arr[mid]==x)
    return mid;

    else if(arr[mid]>x)
    binarySearch(arr,0,mid-1,x);

    else 
    binarySearch(arr,mid+1,high,x);
    
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
    cout<<"Enter the element you want to search in an array: ";
    cin>>x;

    // cout<<"The element is present at index: "<<binarySearch(arr,n,x)<<endl;
    cout<<"The element is present at index: "<<binarySearch(arr,0,n-1,x)<<endl;
    return 0;
}