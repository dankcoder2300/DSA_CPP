//Program to left rotate array by k places

#include<bits/stdc++.h>
using namespace std;

// //method 1
// void left_rotate_k_places(int arr[],int n,int k)
// {
//     if(n==0)
//     return ;

//     k%n;
//     if(k>n)
//     return ;

//     int temp[k];
//     //copying k left element to temp array
//     for(int i=0;i<k;i++)
//     {
//         temp[i]=arr[i];
//     }
//     //shifting array by k places
//     for(int i=0;i<n-k;i++)
//     {
//         arr[i]=arr[i+k];
//     }
//     //moving k elements to their places
//     for(int i=n-k;i<n;i++)
//     {
//         arr[i]=temp[i-(n-k)];
//     }

//     cout<<"Elements of array after "<<k<<" times left roatation are: ";
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

void left_rotate_k_places(int arr[],int n,int k)
{
    //reverse first k elements
    reverse(arr,0,k-1);
    //reverse last n-k elements
    reverse(arr,k,n-1);
    //revesre whole array
    reverse(arr,0,n-1);

    cout<<"Elements of array after "<<k<<" times left roatation are: ";
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

    left_rotate_k_places(arr,n,k);
    return 0;
}