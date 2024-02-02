//Program to find the count of inversion in an array 
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force approach
// int countInversion(int arr[],int n)
// {
//     int cnt=0;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             cnt++;
//         }
//     }
//     return cnt;
// }

//method 2: using merge sort method 
int merge(int arr[],int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    int cnt=0;
    vector<int> temp;

    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }

    return cnt;
}

int mergeSort(int arr[],int low,int high)
{
    int cnt=0;
    if(low>=high)
    return cnt;

    int mid=(low+high)/2;

    cnt+= mergeSort(arr,low,mid);
    cnt+= mergeSort(arr,mid+1,high);
    cnt+= merge(arr,low,mid,high);

    return cnt;
}

int countInversion(int arr[], int n)
{
    return mergeSort(arr,0,n-1);
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
    
    cout<<"Number of inversions in an array is: "<<countInversion(arr,n)<<endl;
    return 0;
}