//Program to Find the number that appears once, and the other numbers twice
#include<bits/stdc++.h>
using namespace std;

// method 1:brute force approach
// int appeared_once(int arr[],int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         int num=arr[i],cnt=0;

//         for(int j=0;j<n;j++)
//         {
//             if(arr[j]==num)
//             cnt++;
//         }
//         if(cnt==1)
//         return num;
//     }
//     return -1;
// }

// method 2:using hashing
// int appeared_once(int arr[],int n)
// {
//     //finding max element in array to declare hash size
//     int maxi=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>maxi)
//         {
//             maxi=arr[i];
//         }
//     }
//     int hash[maxi+1]={0};
//     for(int i=0;i<n;i++)
//     {
//         hash[arr[i]]++;
//     }

//     for(int i=1;i<n;i++)
//     {
//         if(hash[i]==1)
//         return i;
//     }
//     return -1;
// }

// method 3: using map
// int appeared_once(int arr[],int n)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp)
//     {
//         if(it.second==1)
//         return it.first;
//     }
//     return -1;
// }

//method 4: using XOR opeartion
int appeared_once(int arr[],int n)
{
    int xorr=0;
    for(int i=0;i<n;i++)
    {
        xorr=xorr^arr[i];
    }
    return xorr;
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
    cout<<"The number that appears once is: "<<appeared_once(arr,n)<<endl;
    return 0;
}