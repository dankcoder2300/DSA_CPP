#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[mini])
            {
                int temp=arr[mini];
                arr[mini]=arr[j];
                arr[j]=temp;
            }
        }
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
    cout<<"\nThe elements of array before sorting are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    selection_sort(arr,n);
    
    cout<<"\nThe elements of after sorting are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}