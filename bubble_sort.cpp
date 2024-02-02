#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int did_swap=0;         // count the no of swaps in each iteration 
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                did_swap++;
            }
        }
        if(did_swap==0)         // if there is no swaps possible then break
        break;
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

    bubble_sort(arr,n);
    
    cout<<"\nThe elements of after sorting are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}