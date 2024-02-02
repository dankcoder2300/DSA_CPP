//program to find the maximum product subarray in an array
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int maximumProductSubarray(int arr[], int n)
// {
//     int maxi=INT_MIN;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int prod=1;
//             for(int k=i;k<=j;k++)
//             {
//                 prod*=arr[k];
//             }
//             maxi=max(prod,maxi);
//         }
//     }
//     return maxi;
// }

//method 2: better approach (using two loops)
// int maximumProductSubarray(int arr[], int n)
// {
//     int maxi=INT_MIN;

//     for(int i=0;i<n;i++)
//     {
//         int prod=1;
//         for(int j=i;j<n;j++)
//         {
//             prod*=arr[j];
//             maxi=max(maxi,prod);
//         }
//     }
//     return maxi;
// }

//method 3: optimal approach
int maximumProductSubarray(int arr[], int n)
{
    long long prefix=1;
    long long suffix=1;
    long long maxi=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(prefix==0)
        prefix=1;
        
        if(suffix==0)
        suffix=1;

        prefix*=arr[i];
        suffix*=arr[n-i-1];

        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
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
    
    cout<<"Maximum subarray sum in an array is: "<<maximumProductSubarray(arr,n);
    return 0;
}