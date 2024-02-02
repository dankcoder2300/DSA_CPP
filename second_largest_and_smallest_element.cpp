//Program to find second smallest and second largest element in given array

#include<bits/stdc++.h>
using namespace std;

//1st method
// int main()
// {
//     int n;
//     cout<<"Enter the size of array: ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of array: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     if(n==0 || n==1)        //edge case
//     cout<<"-1"<<endl;
    
//     int small=INT_MAX,second_small=INT_MAX;
//     int large=INT_MIN,second_large=INT_MIN;

//     for(int i=0;i<n;i++)
//     {
//         small=min(small,arr[i]);
//         large=max(large,arr[i]);
//     }
//     cout<<"Smallest element in given array is: "<<small<<endl;
//     cout<<"Largest element in given array is: "<<large<<endl;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]<second_small && arr[i]!=small)
//         second_small=arr[i];

//         if(arr[i]>second_large && arr[i]!=large)
//         second_large=arr[i];
//     }

//     cout<<"Second smallest element in given array is: "<<second_small<<endl;
//     cout<<"Second largest element in given array is: "<<second_large<<endl;

//     return 0;
// }

//2nd method

int second_smallest(int arr[],int n)
{
    int small=INT_MAX,second_small=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            second_small=small;
            small=arr[i];
        }
        else if(arr[i]<second_small && arr[i]!=small)
        {
            second_small=arr[i];
        }
    }
    return second_small;
}
int second_largest(int arr[],int n)
{
    int large=INT_MIN,second_large=INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>large)
        {
            second_large=large;
            large=arr[i];
        }
        else if(arr[i]>second_large && arr[i]!=large)
        {
            second_large=arr[i];
        }
    }
    return second_large;
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

    if(n<2)
    cout<<"-1"<<endl;
    cout<<"Second smallest element in given array is: "<<second_smallest(arr,n)<<endl;
    cout<<"Second largest element in given array is: "<<second_largest(arr,n)<<endl;

    return 0;
}