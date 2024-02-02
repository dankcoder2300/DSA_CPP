// Program to find largest element in array

#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the size of array: ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the elements of array: ";
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }

//     sort(arr,arr+n);
//     cout<<"Largest element in given array is: "<<arr[n-1]<<endl;

//     return 0;
// }

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
    int maxi=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
        {
            maxi=arr[i];
        }
    }
    cout<<"Largest element in given array is: "<<maxi<<endl;

    return 0;
}