// Program to rearrange elements by sign with positive elements first and negative after positive no alternatively
#include<bits/stdc++.h>
using namespace std;

//method 1: using two arrays positive and negative
// vector<int> rearrange_elements(vector<int> arr, int n)
// {
//     vector<int> pos_arr;
//     vector<int> neg_arr;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]>0)
//         pos_arr.push_back(arr[i]);
//         else
//         neg_arr.push_back(arr[i]);
//     }

//     for(int i=0;i<n/2;i++)
//     {
//         arr[i*2]=pos_arr[i];
//         arr[(i*2)+1]=neg_arr[i];
//     }

//     return arr;
// }

//method 2: using single array 
// vector<int> rearrange_elements(vector<int> arr, int n)
// {
//     vector<int> ans(n,0);
//     int pos_ind=0;
//     int neg_ind=1;

//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]>0)
//         {
//             ans[pos_ind]=arr[i];
//             pos_ind+=2;
//         }

//         else{
//             ans[neg_ind]=arr[i];
//             neg_ind+=2;
//         }
//     }
//     return ans;
// }

// case: when no. of positive and negative elements are not equal
vector<int> rearrange_elements(vector<int> arr,int n)
{
    vector<int> pos_arr;
    vector<int> neg_arr;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        pos_arr.push_back(arr[i]);
        else
        neg_arr.push_back(arr[i]);
    }

    if(pos_arr.size()<neg_arr.size())
    {
        for(int i=0;i<pos_arr.size();i++)
        {
            arr[i*2]=pos_arr[i];
            arr[(i*2)+1]=neg_arr[i];
        }
        int index=pos_arr.size()*2;
        for(int i=pos_arr.size();i<neg_arr.size();i++)
        {
            arr[index]=neg_arr[i];
            index++;
        }
    }

    else
    {
        for(int i=0;i<neg_arr.size();i++)
        {
            arr[i*2]=pos_arr[i];
            arr[(i*2)+1]=neg_arr[i];
        }
        int index=neg_arr.size()*2;
        for(int i=neg_arr.size();i<pos_arr.size();i++)
        {
            arr[index]=pos_arr[i];
            index++;
        }
    }
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
    vector<int> ans_arr(n);
    ans_arr=rearrange_elements(arr,n);
    cout<<"Elements after rearranging are: ";
    for(auto it:ans_arr)
    {
        cout<<it<<" ";
    }
   
    return 0;
}