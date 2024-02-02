//Program to check whether a pair with given sum exists in array or not
#include<bits/stdc++.h>
using namespace std;

//method 1.1: using brute force approach to print YES or NO
// string check_pair(int arr[],int n,int k)
// {
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]+arr[j]==k)
//             {
//                 return "YES"; 
//             }
//         }
//     }
//     return "NO";
// } 

//method 1.2: using brute force approach to print the two indices which adds upto target
// vector<int> check_pair(int arr[],int n,int k)
// {
//     vector<int> ans;
    
//     for(int i=0;i<n;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]+arr[j]==k)
//             {
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return {-1,-1};
// }

// method 2.1: using hashing
// string check_pair(int arr[],int n,int k)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         int num=arr[i];
//         int rem=k-num;

//         if(mpp.find(rem)!=mpp.end())
//         {
//             return "YES";
//         }
//         mpp[num]=i;
//     }
//     return "NO";
// }

//method 2.2 using hashing
// vector<int> check_pair(int arr[],int n,int k)
// {
//     map<int,int> mpp;
//     for(int i=0;i<n;i++)
//     {
//         int num=arr[i];
//         int rem=k-num;

//         if(mpp.find(rem)!=mpp.end())
//         {
//             return{mpp[rem],i};
//         }
//         mpp[num]=i;
//     }
//     return {-1,-1};
// }

//method 3.1: using two pointer approach to print yes or no
// string check_pair(int arr[],int n,int k)
// {
//     int left=0,right=n-1;
//     while(left<right)
//     {
//         if(arr[left]+arr[right]==k)
//         return "YES";

//         else if(arr[left]+arr[right]>k)
//         right--;

//         else
//         left++;
//     }
//     return "NO";
// }

//method 3.2: using two pointers approach to print two indices that adds upto target sum
vector<int> check_pair(int arr[],int n,int k)
{
    int left=0,right=n-1;
    while(left<right)
    {
        if(arr[left]+arr[right]==k)
        {
            return {left,right};
        }
        else if(arr[left]+arr[right]>k)
        right--;

        else
        left++;
    }
    return {-1,-1};
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
    int k;
    cout<<"Enter the target: ";
    cin>>k;
    // cout<<check_pair(arr,n,k);
    vector<int> ans=check_pair(arr,n,k);
    cout<<"The two indices are : ["<<ans[0]<<","<<ans[1]<<"]"<<endl;

    return 0;
}