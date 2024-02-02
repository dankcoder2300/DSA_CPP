//Program to merge two sorted arrays of size n and m such that arr1 contains first n elements and arr2w contains last m elements
// without using any extra space
#include<bits/stdc++.h>
using namespace std;

//method 1: using extra space (brute force approach)
// void mergeSortedArray(int arr1[],int arr2[],int n, int m)
// {
//     int arr3[n+m];
//     int left=0,right=0;
//     int index=0;
//     while(left<n && right<m)
//     {
//         if(arr1[left]<=arr2[right])
//         {
//             arr3[index]=arr1[left];
//             left++,index++;
//         }
//         else
//         {
//             arr3[index]=arr2[right];
//             right++,index++;
//         }
//     }
//     while(left<n)
//     {
//         arr3[index]=arr1[left];
//         left++,index++;
//     }
//     while(right<m)
//     {
//         arr3[index]=arr2[right];
//         right++,index++;
//     }

//     for(int i=0;i<(n+m);i++)
//     {
//         if(i<n)
//         {
//             arr1[i]=arr3[i];
//         }
//         else{
//             arr2[i-n]=arr3[i];
//         }
//     }
// }

//method 2: optimal approach 1
// void mergeSortedArray(int arr1[],int arr2[],int n, int m)
// {
//     int left=n-1;
//     int right=0;

//     while(left>=0 && right<m)
//     {
//         if(arr1[left]>arr2[right])
//         {
//             swap(arr1[left],arr2[right]);
//             left--;
//             right++;
//         }
//         else{
//             break;
//         }
//     }
//     sort(arr1,arr1+n);
//     sort(arr2,arr2+m);
// }

//method 3: optimal approach 2
void swapIfGreater(int arr1[],int arr2[],int left, int right)
{
    if(arr1[left]>arr2[right])
    {
        swap(arr1[left],arr2[right]);
    }
}

void mergeSortedArray(int arr1[],int arr2[], int n, int m)
{
    int len=(m+n);
    int gap=(len/2)+(len%2);
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<len)
        {
            //arr1 and arr2
            if(left<n && right>=n)
            {
                swapIfGreater(arr1,arr2,left,right-n);
            }
            //arr2 and arr2
            else if(left>=n)
            {
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            //arr1 and arr1
            else{
                swapIfGreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap==1)
        break;
        gap=(gap/2)+(gap%2);
    }
}

int main()
{
    int n,m;
    cout<<"Enter the size of array 1: ";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements of array 1: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    cout<<"Enter the size of array 2: ";
    cin>>m;
    int arr2[m];
    cout<<"Enter the elements of array 2: ";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    

    mergeSortedArray(arr1,arr2,n,m);
    
    cout<<"\nThe elements of arr1  after sorting are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }

    cout<<"\nThe elements of arr2  after sorting are: ";
    for(int i=0;i<m;i++)
    {
        cout<<arr2[i]<<" ";
    }

    return 0;
}