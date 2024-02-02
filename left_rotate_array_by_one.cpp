//Program to left roatate array by one

#include<bits/stdc++.h>
using namespace std;

// void left_rotate(int arr[],int n)
// {
//     int temp[n];
//     for(int i=1;i<n;i++)
//     {
//         temp[i-1]=arr[i];
//     }
//     temp[n-1]=arr[0];
    
//     cout<<"Elements of array after one left rotation are: ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<temp[i]<<" ";
//     }
// }

void left_rotate(int arr[],int n)
{
    int temp=arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;

    cout<<"Elements of array after one left rotation are: ";
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

    left_rotate(arr,n);
    return 0;
}