//Program to print next permutation of an array
#include<bits/stdc++.h>
using namespace std;

//method 1: brute force 
// Not written because it takes O(n!*n) time.

//method 2: using c++ stl next_permutation (better approach)
// void permuatation_next(int arr[],int n)
// {
//     next_permutation(arr,arr+n);
//     cout<<"[ ";
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
//     cout<<"1]";
// }

//method 3: using three for loops(finding breakpoint, finding next greater element and reversing array)
vector<int> permutation_next(vector<int> arr,int n)
{
    //finding the breakpoint
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind=i;
            break;
        }
    }
    //if it's last permutation then reverse the array
    if(ind==-1)
    {
    reverse(arr.begin(),arr.end());
    return arr;
    }

    //finding the next greater element than arr[ind]
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>arr[ind])
        swap(arr[i],arr[ind]);
    }

    //reversing the array from index+1 to last element
    reverse(arr.begin()+ind+1,arr.end());

    return arr;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> ans_array=permutation_next(arr,n);
    cout<<"Next permutation is: [ ";
    for(int i=0;i<ans_array.size();i++)
    cout<<ans_array[i]<<" ";
    cout<<"]";
    return 0;
}