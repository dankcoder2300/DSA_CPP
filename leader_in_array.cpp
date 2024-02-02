//Program to find leaders in an array(leader: an element which is greater than its rightmost elements)
#include<bits/stdc++.h>
using namespace std;

//method 1 : brute force approach
// vector<int> leaderInArray(int arr[],int n)
// {
//     vector<int> ans;
//     for(int i=0;i<n;i++)
//     {
//         int flag=0;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[i]<arr[j])
//             flag++;
//         }
//         if(flag==0)
//         ans.push_back(arr[i]);
//     }
//     return ans;
// }

//method 2: using one loop (optimal approach)
vector<int> leaderInArray(int arr[],int n)
{
    vector<int> ans;

    int max=arr[n-1];
    ans.push_back(arr[n-1]);

    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            ans.push_back(arr[i]);
        }
    }
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
    vector<int> ans=leaderInArray(arr,n);
    for(auto it=ans.end()-1;it>=ans.begin();it--)
    cout<<*it<<" ";

    return 0;
}