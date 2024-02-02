#include <iostream>
using namespace std;

void rec_insertion_sort(int arr[],int i,int n)
{
    if(i==n)
    return;
    
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
        int temp=arr[j];
        arr[j]=arr[j-1];
        arr[j-1]=temp;
        j--;
    }
    rec_insertion_sort(arr,i+1,n);
}
int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"\nThe elements of array before sorting are: ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    rec_insertion_sort(arr,0,n);
    
    cout<<"\nThe elements of array after sorting are: ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}