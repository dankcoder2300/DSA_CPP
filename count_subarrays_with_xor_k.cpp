//Program to find the count of subarrays with given xor k
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// int count_subarrays(int arr[],int n,int k)
// {
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int xorr=0;
//             for(int K=i;K<=j;K++)
//             {
//                 xorr=xorr^arr[K];
//             }
//             if(xorr==k)
//             cnt++;
//         }
//     }
//     return cnt;
// }

//method 2: using two for loops (better approach)
// int count_subarrays(int arr[],int n,int k)
// {
//     int cnt=0;

//     for(int i=0;i<n;i++)
//     {
//         int xorr=0;
//         for(int j=i;j<n;j++)
//         {
//             xorr=xorr^arr[j];
            
//             if(xorr==k)
//             cnt++;
//         }
//     }
//     return cnt;
// }

//method 3: using hashmap (optimal approach)
int count_subarrays(int arr[],int n, int k)
{
    int xorr=0;
    map<int,int> mpp;
    mpp[0]++;       //{0,1} is included
    int cnt=0;

    for(int i=0;i<n;i++)
    {
        xorr=xorr^arr[i];
        int x=xorr^k;

        cnt=cnt+mpp[x];

        mpp[x]++;
    }
    return cnt;
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
    cout<<"Enter the value of xor: ";
    int k;
    cin>>k;

    cout<<"No. of subarrays with given xor "<<k<<" is: "<<count_subarrays(arr,n,k);
    return 0;
}