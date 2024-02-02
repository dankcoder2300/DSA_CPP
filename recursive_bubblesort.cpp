#include <iostream>
using namespace std;

void rec_bubble_sort(int arr[],int n)
{
    if(n==1)
    return;
    
    int did_swap=0;
    for(int j=0;j<=n-2;j++)
    {
       if(arr[j]>arr[j+1])
       {
        int temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        did_swap++;
       } 
    }
    if(did_swap==0)         // optimizing it 
    return;

    rec_bubble_sort(arr,n-1);
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
    
    rec_bubble_sort(arr,n);
    
    cout<<"\nThe elements of array before sorting are: ";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}