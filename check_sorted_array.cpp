//Program to check whether given array is sorted or not

#include<bits/stdc++.h>
using namespace std;

bool is_sorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
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

    int ans=is_sorted(arr,n);
    
    if(ans==0)
    cout<<"Given array is unsorted!"<<endl;
    else
    cout<<"Given array is sorted!"<<endl;

    return 0;
}