//Program to remove duplicates elements from array

#include<bits/stdc++.h>
using namespace std;

// int remove_duplicates(int arr[],int n)
// {
//     set<int> st;
//     for(int i=0;i<n;i++)
//     {
//         st.insert(arr[i]);
//     }

//     int k=st.size();
//     int i=0;
//     for(auto it:st)
//     {
//         arr[i]=it;
//         i++;
//     }

//     return k;
// }
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

//     int k=remove_duplicates(arr,n);
    
//     cout<<"The elements of array after removing duplicates elements are: ";
//     for(int i=0;i<k;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }

//two pointer approach
int remove_duplicates(int arr[],int n)
{
    int i=0;
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
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

    int k=remove_duplicates(arr,n);
    
    cout<<"The elements of array after removing duplicates elements are: ";
    for(int i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}