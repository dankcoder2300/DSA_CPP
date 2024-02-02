//Program to right rotate array by k places

#include<bits/stdc++.h>
using namespace std;

//method 1
// void right_rotate_k_places(int arr[],int n,int k)
// {
//     if(n==0)
//     return ;

//     k%n;
//     if(k>n)
//     return ;

//     int temp[k];
//     //copying k right element to temp array
//     for(int i=0;i<k;i++)
//     {
//         temp[i]=arr[n-k+i];
//     }
//     //shifting array by k places
//     for(int i=n-k-1;i>=0;i--)
//     {
//         arr[i+k]=arr[i];
//     }
//     //moving k elements to their places
//     for(int i=0;i<k;i++)
//     {
//         arr[i]=temp[i];
//     }

//     cout<<"Elements of array after "<<k<<" times right roatation are: ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

//method 2
void reverse(int arr[],int start,int end)
{
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void right_rotate_k_places(int arr[],int n,int k)
{
    //reverse last k elements
    reverse(arr,n-k,n-1);
    //reverse first n-k elements
    reverse(arr,0,n-k-1);
    //revesre whole array
    reverse(arr,0,n-1);

    cout<<"Elements of array after "<<k<<" times right roatation are: ";
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

    cout<<"Enter the value of k: ";
    int k;
    cin>>k;

    right_rotate_k_places(arr,n,k);
    return 0;
}