#include<bits/stdc++.h>
using namespace std;

int partition_index(int arr[],int low,int high)
{
    int i=low,j=high;
    int pivot=arr[low];

        while(i<j)
        {
            while(pivot>=arr[i]&& i<=high)
            i++;

            while(pivot<arr[j]&& j>=low)
            j--;

            if(i<j)
            swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);

    return j;
}

void quick_sort(int arr[],int low,int high)
{
if(low<high)
{
    int part_index=partition_index(arr,low,high);
    quick_sort(arr,low,part_index-1);
    quick_sort(arr,part_index+1,high);

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

   quick_sort(arr,0,n);
    
    cout<<"\nThe elements of after sorting are: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}