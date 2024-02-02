//Program to find the element in a rotated sorted array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// bool searchRotatedArray(int arr[], int n, int x)
// {
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==x)
//         return true;
//     }
//     return false;
// }

//method 2: using binary search approach
bool searchRotatedArray(int arr[], int n ,int x)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==x)
        return true;

        if(arr[mid]==arr[low] && arr[mid]==arr[high])
        {
            low=low+1;
            high=high-1;
            continue;
        }

        //checks if left part is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=x && arr[mid]>=x)
            high=mid-1;
            else
            low=mid+1;
        }
            //checks if right part is sorted
        else
            {
            if(arr[mid]<=x && arr[high]>=x)
            low=mid+1;
            else
            high=mid-1;
            } 
    }
    return false;
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

    if(searchRotatedArray(arr,n,x))
    {
        cout<<"Element is present in an array"<<endl;
    }
    else
    {
        cout<<"Element is not present in an array"<<endl;
    }

    return 0;
}