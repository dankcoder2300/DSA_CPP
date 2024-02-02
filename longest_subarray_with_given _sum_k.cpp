//Program to find Longest Subarray with given Sum K

#include<bits/stdc++.h>
using namespace std;

// method 1: brute force approach
// int longest_subarray(int arr[], int n, int k)
// {
//     int len=0;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             int sum=0;
//             for(int p=i;p<=j;p++)
//             {
//                 sum=sum+arr[p];
//             }
//             if(sum==k)
//             {
//                 len=max(len,j-i+1);
//             }
//         }
//     }
//     return len;
// }

// method 2: using two for loops
// int longest_subarray(int arr[], int n, int k)
// {
//     int len=0;

//     for(int i=0;i<n;i++)
//     {
//         int sum=0;
//         for(int j=i;j<n;j++)
//         {
//             sum=sum+arr[j];
//             if(sum==k)
//             {
//                 len=max(len,j-i+1);
//             }
//         }
//         }
//     return len;
// }

//method 3: using hashing(prefix sum approach)
// int longest_subarray(int arr[],int n,int k)
// {
//     map<int,int> preSumMap;
//     long long sum=0;
//     int max_len=0;
//     for(int i=0;i<n;i++)
//     {
//         sum=sum+arr[i];
//         if(sum==k)
//         {
//             max_len=max(max_len,i+1);
//         }
//         long long rem=sum-k;
//         if(preSumMap.find(rem)!=preSumMap.end())
//         {
//             int len=i-preSumMap[rem];
//             max_len=max(len,max_len);
//         }
//         if(preSumMap.find(sum)==preSumMap.end())
//         {
//             preSumMap[sum]=i;
//         }
//     }
//     return max_len;
// }

//method 4: using two pointers approach(optimal)
int longest_subarray(int arr[],int n,int k)
{
    int left=0,right=0;
    long long sum=arr[0];
    int max_len=0;
    while(right<n)
    {
        while(left<=right && sum>k)     //if sum becomes greater than k left move left pointer by 1 and then move right ptr by one
        {
            sum=sum-arr[left];
            left++;
        }
        if(sum==k)
        {
            max_len=max(max_len,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum=sum+arr[right];
        }
    }
    return max_len;
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
    cout<<"The lenghth of longest subarray with given sum "<<k<<" is: "<<longest_subarray(arr,n,k)<<endl;
    return 0;
}
