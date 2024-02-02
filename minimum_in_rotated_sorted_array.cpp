//Program to find the minimum element in a rotated sorted array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int minElement(int arr[], int n)
// {
//     int ans=INT_MAX;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]<=ans)
//         {
//             ans=arr[i];
//         }
//     }
//     return ans;
// }

//method 2: using binary search approach
// int minElement(int arr[], int n)
// {
//     int low=0;
//     int high=n-1;
//     int ans=INT_MAX;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;

//         //check if left part is sorted
//         if(arr[low]<=arr[mid])
//         {
//             ans=min(ans,arr[low]);
//             low=mid+1;
//         }
//         else
//         {
//             ans=ans=min(ans,arr[mid]);
//             high=mid-1;
//         }
//     }
//     return ans;
// }

//method 3: using binary search approach (optimised)
int minElement(int arr[], int n)
{
    int low=0;
    int high=n-1;
    int ans=INT_MAX;

    while(low<=high)
    {
        int mid=(low+high)/2;

        //if search space is sorted then arr[low] will always be minimum element in that space
        if(arr[low]<=arr[high])
        {
            ans=min(ans,arr[low]);
            break;
        }
        
        //check if left part is sorted
        if(arr[low]<=arr[mid])
        {
            ans=min(ans,arr[low]);
            low=mid+1;
        }
        else
        {
            ans=ans=min(ans,arr[mid]);
            high=mid-1;
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

    cout<<"The minimum element in array is: "<<minElement(arr,n)<<endl;
    return 0;
}