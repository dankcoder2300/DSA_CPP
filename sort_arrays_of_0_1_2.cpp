//Program to Sort an array of 0s, 1s and 2s
#include<bits/stdc++.h>
using namespace std;

// method 1: brute force approach 
// void sort_arrays(int arr[],int n)
// {
//     sort(arr,arr+n);
//     for(int i=0;i<n;i++)
//     cout<<arr[i]<<" ";
// }

// method 2: keeping track of count of 0,1 and 2 and updating the array element
// void sort_arrays(int arr[],int n)
// {
//     int cnt_0=0,cnt_1=0,cnt_2=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==0)
//         cnt_0++;
//         else if(arr[i]==1)
//         cnt_1++;
//         else
//         cnt_2++;
//     }

//     for(int i=0;i<cnt_0;i++)
//     arr[i]=0;
//     for(int i=cnt_0;i<(cnt_0+cnt_1);i++)
//     arr[i]=1;
//     for(int i=(cnt_0+cnt_1);i<n;i++)
//     arr[i]=2;

//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

//method 3: using three pointers approach(optimal)
void sort_arrays(int arr[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
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

    sort_arrays(arr,n);

    return 0;
}