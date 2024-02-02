//Program to find the single element in sorted array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int singleElement(int arr[], int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(i==0)
//         {
//             if(arr[i]!=arr[i+1])
//             return arr[i];
//         }

//         if(i==n-1)
//         {
//             if(arr[i-1]!=arr[i])
//             return arr[i];
//         }

//         if(arr[i-1]!=arr[i] && arr[i+1]!=arr[i])
//         return arr[i];
//     }
// }

//method 2: using brute force approach(xor operation)
// int singleElement(int arr[], int n)
// {
//     int ans=0;

//     for(int i=0;i<n;i++)
//     {
//         ans=ans^arr[i];
//     }
//     return ans;
// }

//method 3: using binary search approach (optimal)
int singleElement(int arr[], int n)
{
    if(n==1)
    return arr[0];

    if(arr[0]!=arr[1])
    return arr[0];

    if(arr[n-1]!=arr[n-2])
    return arr[n-1];

    int low=1;
    int high=n-2;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
        return arr[mid];

        //left half part and element is persent is right half
        if((mid%2==1) && arr[mid]==arr[mid-1] || (mid%2==0 && arr[mid]==arr[mid+1]))
        low=mid+1;

        else
        high=mid-1;
    }
    return -1;
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

    cout<<"The single element in array is: "<<singleElement(arr,n)<<endl;
    return 0;
}