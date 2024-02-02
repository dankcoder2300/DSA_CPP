//Program to find intersection of two sorted arrays

#include<bits/stdc++.h>
using namespace std;

// method 1:
// void intersection_sorted_arrays(int arr1[],int arr2[],int n,int m)
// {
//     int visited[m]={0};
//     vector<int> intersection_array;

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(arr1[i]==arr2[j] && visited[j]==0)
//             {
//                 intersection_array.push_back(arr1[i]);
//                 visited[j]=1;
//                 break;
//             }
//             if(arr2[j]>arr1[i])
//             break;
//         }
//     }
//     cout<<"Elements of intersection of two arrays are: ";
//     for(auto it:intersection_array)
//     {
//         cout<<it<<" ";
//     }
// }

//method 2: using two pointer approach
void intersection_sorted_arrays(int arr1[],int arr2[],int n,int m)
{
    vector<int> intersection_array;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            intersection_array.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout<<"Elements of intersection of two arrays are: ";
    for(auto it:intersection_array)
    {
        cout<<it<<" ";
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array 1: ";
    cin>>n;
    int arr1[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    int m;
    cout<<"Enter the size of array 2: ";
    cin>>m;
    int arr2[m];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    intersection_sorted_arrays(arr1,arr2,n,m);

    return 0;
}