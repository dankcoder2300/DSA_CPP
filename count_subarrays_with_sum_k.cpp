//Program to find count of subarrays with sum equal to k
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// int count_subarray(int arr[],int n, int k)
// {
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int sum=0;
//             for(int p=i;p<=j;p++)
//             {
//                 sum+=arr[p];
//             }
//             if(sum==k)
//             cnt++;
//         }
//     }
//     return cnt;
// }

//method 2: using two loops (better approach)
// int count_subarray(int arr[],int n, int k)
// {
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum+=arr[j];
//             if(sum==k)
//             cnt++;
//         }
//     }
//     return cnt;
// }

//method 3: using map
// int count_subarray(int arr[],int n,int k)
// {
//     map<int,int> preSumMap;
//     long long sum=0;
//     int cnt=0;
//     for(int i=0;i<n;i++)
//     {
//         sum=sum+arr[i];
//         if(sum==k)
//         {
//             cnt++;
//         }
//         long long rem=sum-k;
//         if(preSumMap.find(rem)!=preSumMap.end())
//         {
//             cnt++;
//         }
//         if(preSumMap.find(sum)==preSumMap.end())
//         {
//             preSumMap[sum]=i;
//         }
//     }
//     return cnt;
// }

//method 4: using two pointers (optimal approach)
int count_subarray(int arr[],int n, int k)
{
    int left=0,right=0;
    int sum=arr[0];
    int cnt=0;

    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }

        if(sum==k)
        {
            cnt++;
        }
        right++;
        
        if(right<n)
        {
            sum+=arr[right];
        }
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
    int k;
    cout<<"Enter the sum: ";
    cin>>k;
    cout<<"The number of subarrays with given sum "<<k<<" is: "<<count_subarray(arr,n,k)<<endl;
    return 0;
}