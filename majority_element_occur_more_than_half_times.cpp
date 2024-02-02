//Program to find the Majority Element that occurs more than N/2 times
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int majority_element(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         int cnt=0;
//         for(int j=0;j<n;j++)
//         {
//             if(arr[i]=arr[j])
//             cnt++;
//         }
//         if(cnt>(n/2))
//         return arr[i];
//     }
//     return -1;
// }

//method 2:using hash map
// int majority_element(int arr[],int n)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp)
//     {
//         if(it.second>(n/2))
//         return it.first;
//     }
//     return -1;
// }

//method 3: Using moore's voting algorithm (optimal approach)
int majority_element(int arr[], int n )
{
    int cnt=0;
    int element;

    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt=1;
            element=arr[i];
        }
        else if(arr[i]==element)
        cnt++;
        else
        cnt--;
    }
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        cnt1++;
    }
    if(cnt1>(n/2))
    return element;

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

    cout<<"Majority element that occurs more than N/2 times is: "<<majority_element(arr,n);

    return 0;
}