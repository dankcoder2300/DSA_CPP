//Program to find the position in a sorted array where element should be inserted
#include<bits/stdc++.h>
using namespace std;

int searchInsertPosition(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;
    int ans=n;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]>=x)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;    
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
    sort(arr,arr+n);
    int x;
    cout<<"Enter the number: ";
    cin>>x;

    cout<<"The element should be inserted at index: "<<searchInsertPosition(arr,n,x)<<endl;
    return 0;
}