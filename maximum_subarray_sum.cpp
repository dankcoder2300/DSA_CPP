//Kadane’s Algorithm : program to find Maximum Subarray Sum in an Array
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// int maximum_subarray_sum(int arr[],int n)
// {
//     int maxi=INT_MIN;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int sum=0;
//             for(int k=i;k<=j;k++)
//             {
//                 sum=sum+arr[k];
//             }
//             maxi=max(maxi,sum);
//         }
//     }
//     return maxi;
// }

//method 2: using 2 for loops (better approach)
// int maximum_subarray_sum(int arr[],int n)
// {
//     int maxi=INT_MIN;
//     for(int i=0;i<n;i++)
//     {
//         int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//             maxi=max(maxi,sum);
//         }
//     }
//     return maxi;
// }

//method 3: kadane's algorithm (optimal approach)
int maximum_subarray_sum(int arr[],int n)
{
    long long maxi=LONG_MIN;
    long long sum=0;

    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];

        if(sum>maxi)
        maxi=sum;

        if(sum<0)
        sum=0;
    }
    return maxi;
}

void print_max_subarray(int arr[],int n)
{
    long long maxi=LONG_MIN;
    long long sum=0;
    int start=0;
    int ansstart=-1,ansend=-1;

    for(int i=0;i<n;i++)
    {
        if(sum==0)
        start=i;

        sum+=arr[i];

        if(sum>maxi)
        {
            maxi=sum;
            ansstart=start;
            ansend=i;
        }

        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<"The subarray with maximum sum is: [ ";
    for(int i=ansstart;i<=ansend;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"]";
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
    
    cout<<"Maximum subarray sum in an array is: "<<maximum_subarray_sum(arr,n);
    print_max_subarray(arr,n);
    return 0;
}