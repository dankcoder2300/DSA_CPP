//Program to find longest consecutive sequence in an array
#include<bits/stdc++.h>
using namespace std;

//method 1: sorting and then finding max_cnt
// int longestConsecutiveSequence(int arr[],int n)
// {
//     int cnt=1,max_cnt=INT_MIN;
    
//     sort(arr,arr+n);

//     for(int i=0;i<n-1;i++)
//     {
//         if(arr[i]==arr[i+1]-1)
//         {
//             cnt++;
//             max_cnt=max(cnt,max_cnt);
//         }
//         else if(arr[i]==arr[i+1])
//         continue;

//         else{
//             cnt=0;
//         }
//     }
//     return max_cnt;
// }

//method 2: using an unordered set (optimal approach)
int longestConsecutiveSequence(int arr[],int n)
{
    if(n==0)
    return 0;

    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    int longest=1;
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;
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
    
    int ans=longestConsecutiveSequence(arr,n);
    cout<<"Longest consecutive sequence in an array is: "<<ans<<endl;
   
    return 0;
}