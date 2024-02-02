//Program to move zeros to end in an array

#include<bits/stdc++.h>
using namespace std;

//method 1
// void move_zeros_to_end(int arr[],int n)
// {
//     int temp[n];
//     int k=0;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]!=0)
//         {
//             temp[k]=arr[i];
//             k++;
//         }
//     }
//     while(k<n)
//     {
//         temp[k]=0;
//         k++;
//     }

//     cout<<"Elements of array after moving zeros to end are: ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<temp[i]<<" ";
//     }
// }

//method 2
void move_zeros_to_end(int arr[],int n)
{
    //finding first occurence of 0
    int k=0;
    while(k<n)
    {
        if(arr[k]==0)
        break;
        else
        k++;
    }

    int i=k,j=k+1;
    while(i<n && j<n)
    {
        if(arr[j]!=0)
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
        j++;
    }
    cout<<"Elements of array after moving zeros to end are: ";
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

    move_zeros_to_end(arr,n);
    return 0;
}