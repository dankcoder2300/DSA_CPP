//Program to buy and sells stocks to maximize profits
#include<bits/stdc++.h>
using namespace std;

//method 1: using two loops (brute force approach)
// int max_profit(int arr[],int n)
// {
//     int max_profit=0;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i;j<n;j++)
//         {
//             if(arr[j]>arr[i])
//             {
//                 max_profit=max(max_profit,arr[j]-arr[i]);
//             }
//         }
//     }
//     return max_profit;
// }

//method 2: using poniters approach (optimal approach)
int max_profit(int arr[],int n)
{
    int max_profit=0;
    int mini=INT_MAX;

    for(int i=0;i<n;i++)
    {
        mini=min(mini,arr[i]);
        max_profit=max(max_profit,arr[i]-mini);
    }
    return max_profit;
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
    
    cout<<"Max profit is: "<<max_profit(arr,n);
    return 0;
}