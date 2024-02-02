//Program to find union of two sorted arrays

#include<bits/stdc++.h>
using namespace std;

// method 1:using set
// void union_sorted_arrays(int arr1[],int arr2[],int n,int m)
// {
//     set<int> st;

//     for(int i=0;i<n;i++)
//     {
//         st.insert(arr1[i]);
//     }
//     for(int i=0;i<m;i++)
//     {
//         st.insert(arr2[i]);
//     }
    
//     vector<int> union_array;
//     for(auto it:st)
//     {
//         union_array.push_back(it);
//     }

//     cout<<"Elements of Union of two sorted arrays are: ";
//     for(auto val:union_array)
//     {
//         cout<<val<<" ";
//     }
// }

//method 2:using map
// void union_sorted_arrays(int arr1[],int arr2[],int n,int m)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         mpp[arr1[i]]++;
//     }
//     for(int i=0;i<m;i++)
//     {
//         mpp[arr2[i]]++;
//     }
    
//     vector<int> union_array;
//     for(auto it:mpp)
//     {
//         union_array.push_back(it.first);
//     }
//     cout<<"Elements of Union of two arrays are: ";
//     for(auto val:union_array)
//     {
//         cout<<val<<" ";
//     }
// }

//method 3: using two pointers approach
void union_sorted_arrays(int arr1[],int arr2[],int n,int m)
{
    vector<int> union_array;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                if(union_array.size()==0 || union_array.back()!=arr1[i])
                union_array.push_back(arr1[i]);
                i++;
            }
            else
            {
                if(union_array.size()==0 || union_array.back()!=arr2[j])
                union_array.push_back(arr2[j]);
                j++;
            }
        }
        while(i<n)
        {
            if(union_array.size()==0 || union_array.back()!=arr1[i])
            union_array.push_back(arr1[i]);
            i++;
        }
        while(j<m)
        {
            if(union_array.size()==0 || union_array.back()!=arr2[j])
            union_array.push_back(arr2[j]);
            j++;
        }

    cout<<"Elements of union of given two arrays are: ";
    for(int i=0;i<union_array.size();i++)
    {
        cout<<union_array[i]<<" ";
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

    // union_sorted_arrays(arr1,arr2,n,m);     //using set
    //union_sorted_arrays(arr1,arr2,n,m);        //using map
    union_sorted_arrays(arr1,arr2,n,m);
    return 0;
}