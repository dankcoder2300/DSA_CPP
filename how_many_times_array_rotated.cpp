//Program to find how many times sorted array has been rotated
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int func(int arr[], int n)
// {
//     int ans=INT_MAX;
//     int index=-1;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]<=ans)
//         {
//             ans=arr[i];
//             index=i;
//         }
//     }
//     return index;
// }

//method 2: using binary search approach
int func(int arr[], int n)
{
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        //if search space is sorted then minimum element will be arr[low]
        if(arr[low]<=arr[high])
        {
            if(arr[low]<=ans)
            {
            ans=arr[low];
            index=low;
            }
            break;
        }

        //checks if left part is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=ans)
            {
                ans=arr[low];
                index=low;
            }
            low=mid+1;
        }

        //checks if right part is sorted
        else
        {
            if(arr[mid]<=ans)
            {
            ans=arr[mid];
            index=mid;
            }
            high=mid-1;
        }
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

    cout<<"The array is roated "<<func(arr,n)<<" times"<<endl;
    return 0;
}