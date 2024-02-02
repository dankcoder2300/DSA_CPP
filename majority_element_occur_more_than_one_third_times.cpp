//Program to find the majority element thayt occurs more than n/3 times
#include<bits/stdc++.h>
using namespace std;

//method 1: using brute force approach
// vector<int> majorityElement(int arr[],int n)
// {
//     vector<int> ans;
//     for(int i=0;i<n;i++)
//     {
//         if(ans.size()==0 || ans[0]!=arr[i])
//         {
//             int cnt=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(arr[j]==arr[i])
//                 cnt++;
//             }
//         if(cnt>(n/3))
//         ans.push_back(arr[i]);
//         }
//         if(ans.size()==2)
//         break;
//     }
//     return ans;
// }

//method 2: using hash map
// vector<int> majorityElement(int arr[],int n)
// {
//     map<int,int> mpp;
//     vector<int> ans;

//     for(int i=0;i<n;i++)
//     {
//         mpp[arr[i]]++;
//     }

//     for(auto it:mpp)
//     {
//         if(it.second>n/3)
//         ans.push_back(it.first);
//     }
//     return ans;
// }

//method 3: using extended version of moore's voting algorithm
vector<int> majorityElement(int arr[],int n)
{
    vector<int> ans;
    int cnt1=0,el1;
    int cnt2=0,el2;

    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && arr[i]!=el2)
        {
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=el1)
        {
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1)
        {
            cnt1++;
        }
        else if(arr[i]==el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int cnt_1=0,cnt_2=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==el1)
        cnt_1++;
        
        if(arr[i]==el2)
        cnt_2++;
    }

    if(cnt_1>n/3)
    ans.push_back(el1);

    if(cnt_2>n/3)
    ans.push_back(el2);

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

    cout<<"Majority element that occurs more than N/3 times is: ";
    vector<int> ans=majorityElement(arr,n);
    for(auto it:ans)
    cout<<it<<" ";

    return 0;
}